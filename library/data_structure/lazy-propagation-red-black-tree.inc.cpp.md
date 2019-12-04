<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data_structure/lazy-propagation-red-black-tree.inc.cpp
* category: data_structure


[Back to top page](../../index.html)



## Code
```cpp
/**
 * @note almost all operations are O(log N)
 */
template <class Monoid, class OperatorMonoid>
class lazy_propagation_red_black_tree {
    typedef typename Monoid::value_type value_type;
    typedef typename OperatorMonoid::value_type operator_type;

    enum color_t { BLACK, RED };
    struct node_t {
        bool is_leaf;
        value_type data;
        operator_type lazy;  // NOTE: this->lazy is already applied to this->data
        bool reversed;
        color_t color;
        int rank;
        int size;
        node_t *left;
        node_t *right;
        node_t() = default;
        node_t(value_type const & a_data)
                : is_leaf(true)
                , data(a_data)
                , color(BLACK)
                , rank(0)
                , size(1) {
        }
        node_t(node_t *l, node_t *r, color_t c)  // non-leaf node
                : is_leaf(false)
                , data(Monoid().append(l->data, r->data))
                , lazy(OperatorMonoid().identity())
                , reversed(false)
                , color(c)
                , rank(max(l->rank + (l->color == BLACK),
                           r->rank + (r->color == BLACK)))
                , size(l->size + r->size)
                , left(l)
                , right(r) {
        }
    };
    struct node_deleter {
        void operator () (node_t *t) const {
            assert (t != nullptr);
            if (not t->is_leaf) {
                (*this)(t->right);
                (*this)(t->left);
            }
            delete t;
        }
    };

    static void propagate_only_operator(node_t *a) {
        OperatorMonoid op;
        if (not a->is_leaf) {
            if (a->lazy != op.identity()) {
                auto const & l = a->left;
                auto const & r = a->right;
                l->data = op.apply(a->lazy, l->data);
                r->data = op.apply(a->lazy, r->data);
                if (not l->is_leaf) l->lazy = op.compose(a->lazy, l->lazy);
                if (not r->is_leaf) r->lazy = op.compose(a->lazy, r->lazy);
                a->lazy = op.identity();
            }
        }
    }
    static void propagate_only_reverse(node_t *a) {
        if (not a->is_leaf) {
            if (a->reversed) {
                auto const & l = a->left;
                auto const & r = a->right;
                if (not l->is_leaf) l->reversed = not l->reversed;
                if (not r->is_leaf) r->reversed = not r->reversed;
                swap(a->left, a->right);  // CAUTION: auto const & l, r are destroyed
                a->reversed = false;
            }
        }
    }
    static void propagate(node_t *a) {
        propagate_only_operator(a);
        propagate_only_reverse(a);
    }

    /**
     * @note trees a, b are consumed  (at set_left()/set_right())
     */
    static node_t *merge(node_t *a, node_t *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        node_t *c = merge_relax(a, b);
        c->color = BLACK;
        return c;
    }
    /*
     * @note the root of returned tree may violates the color constraint
     */
    static node_t *merge_relax(node_t *a, node_t *b) {
        if ((a->rank) < b->rank) {
            assert (not b->is_leaf);
            propagate(b);
            return set_left(b, merge_relax(a, b->left));
        } else if (a->rank > b->rank) {
            assert (not a->is_leaf);
            propagate(a);
            return set_right(a, merge_relax(a->right, b));
        } else {
            a->color = BLACK;
            b->color = BLACK;
            return new node_t(a, b, RED);
        }
    }
    static node_t *set_left(node_t *b, node_t *c) {
        if (b->color == BLACK and c->color == RED and c->left->color == RED) {
            if (b->right->color == BLACK) {
                *b = node_t(c->right, b->right, RED);
                *c = node_t(c->left, b, BLACK);
                swap(b, c);
            } else {
                b->right->color = BLACK;
                c->color = BLACK;
                *b = node_t(c, b->right, RED);
            }
        } else {
            *b = node_t(c, b->right, b->color);
        }
        return b;
    }
    static node_t *set_right(node_t *a, node_t *c) {
        if (a->color == BLACK and c->color == RED and c->right->color == RED) {
            if (a->left->color == BLACK) {
                *a = node_t(a->left, c->left, RED);
                *c = node_t(a, c->right, BLACK);
                swap(a, c);
            } else {
                a->left->color = BLACK;
                c->color = BLACK;
                *a = node_t(a->left, c, RED);
            }
        } else {
            *a = node_t(a->left, c, a->color);
        }
        return a;
    }

    /**
     * @note tree a is consumed  (at explicit delete and merge())
     */
    static pair<node_t *, node_t *> split(node_t *a, int k) {
        if (k == 0) {
            return make_pair( nullptr, a );
        }
        assert (a != nullptr);
        if (k == a->size) {
            return make_pair( a, nullptr );
        }
        assert (not a->is_leaf);
        propagate(a);
        node_t *a_left  = a->left;
        node_t *a_right = a->right;
        delete a;
        if (k < a_left->size) {
            node_t *l, *r; tie(l, r) = split(a_left, k);
            return make_pair( l, merge(r, a_right) );
        } else if (k > a_left->size) {
            node_t *l, *r; tie(l, r) = split(a_right, k - a_left->size);
            return make_pair( merge(a_left, l), r );
        } else {
            return make_pair( a_left, a_right );
        }
    }

    static void range_apply(node_t *a, int l, int r, operator_type const & func) {
        Monoid mon;
        OperatorMonoid op;
        if (l == r) return;
        if (l == 0 and r == a->size) {
            a->data = op.apply(func, a->data);
            if (not a->is_leaf) a->lazy = op.compose(func, a->lazy);
            return;
        }
        assert (not a->is_leaf);
        propagate(a);
        int k = a->left->size;
        if (r <= k) {
            range_apply(a->left, l, r, func);
        } else if (k <= l) {
            range_apply(a->right, l - k, r - k, func);
        } else {
            range_apply(a->left, l, k, func);
            range_apply(a->right, 0, r - k, func);
        }
        a->data = op.apply(a->lazy, mon.append(a->left->data, a->right->data));
    }

    static value_type range_concat(node_t *a, int l, int r) {
        assert (l < r);
        if (l == 0 and r == a->size) return a->data;
        assert (not a->is_leaf);
        propagate(a);
        int k = a->left->size;
        if (r <= k) {
            return range_concat(a->left, l, r);
        } else if (k <= l) {
            return range_concat(a->right, l - k, r - k);
        } else {
            return Monoid().append(
                    range_concat(a->left, l, k),
                    range_concat(a->right, 0, r - k));
        }
    }

    static node_t *reverse(node_t *a, int l, int r) {
        // TODO: find ways to do without split. there may be clever ways using recursion
        if (l == r) return a;
        node_t *bl, *br; tie(bl, br) = split(a, r);
        node_t *bm; tie(bl, bm) = split(bl, l);
        if (not bm->is_leaf) bm->reversed = not bm->reversed;
        return merge(merge(bl, bm), br);
    }

    static void point_set(node_t *a, int i, value_type const & value) {
        if (a->is_leaf) {
            assert (i == 0);
            a->data = value;
        } else {
            propagate_only_reverse(a);  // should we do full propagation?
            if (i < a->left->size) {
                point_set(a->left, i, value);
            } else {
                point_set(a->right, i - a->left->size, value);
            }
            a->data = OperatorMonoid().apply(a->lazy,
                    Monoid().append(a->left->data, a->right->data));
        }
    }

    static value_type & point_get(node_t *a, int i) {
        if (a->is_leaf) {
            assert (i == 0);
            return a->data;
        } else {
            propagate(a);
            if (i < a->left->size) {
                return point_get(a->left, i);
            } else {
                return point_get(a->right, i - a->left->size);
            }
        }
    }

private:
    unique_ptr<node_t, node_deleter> root;

public:
    lazy_propagation_red_black_tree() = default;
    lazy_propagation_red_black_tree(node_t *a_root)
            : root(a_root) {
    }

    static lazy_propagation_red_black_tree merge(lazy_propagation_red_black_tree & l, lazy_propagation_red_black_tree & r) {
        node_t *a = l.root.release();
        node_t *b = r.root.release();
        if (a == nullptr) return lazy_propagation_red_black_tree(b);
        if (b == nullptr) return lazy_propagation_red_black_tree(a);
        return lazy_propagation_red_black_tree(merge(a, b));
    }
    pair<lazy_propagation_red_black_tree, lazy_propagation_red_black_tree> split(int k) {
        assert (0 <= k and k <= size());
        node_t *l, *r; tie(l, r) = split(root.release(), k);
        return make_pair( lazy_propagation_red_black_tree(l), lazy_propagation_red_black_tree(r) );
    }

    void insert(int i, value_type const & data) {
        assert (0 <= i and i <= size());
        if (empty()) {
            root.reset(new node_t(data));
            return;
        } else {
            node_t *l, *r; tie(l, r) = split(root.release(), i);
            root.reset( merge(merge(l, new node_t(data)), r) );
        }
    }
    void erase(int i) {
        assert (0 <= i and i < size());
        node_t *l, *r; tie(l, r) = split(root.release(), i + 1);
        node_t *m; tie(l, m) = split(l, i);
        node_deleter()(m);
        root.reset( merge(l, r) );
    }

    void point_set(int i, value_type const & value) {
        assert (0 <= i and i < size());
        point_set(root.get(), i, value);
    }
    value_type const & point_get(int i) const {
        assert (0 <= i and i < size());
        return point_get(const_cast<node_t *>(root.get()), i);
    }

    void range_apply(int l, int r, operator_type const & func) {
        assert (0 <= l and l <= r and r <= size());
        if (l == r) return;
        range_apply(root.get(), l, r, func);
    }
    value_type const range_concat(int l, int r) const {
        assert (0 <= l and l <= r and r <= size());
        if (l == r) return Monoid().unit();
        return range_concat(const_cast<node_t *>(root.get()), l, r);
    }
    void reverse(int l, int r) {
        assert (0 <= l and l <= r and r <= size());
        if (not root) return;
        root.reset( reverse(root.release(), l, r) );
    }

    void push_back(value_type const & data) {
        root.reset( merge(root.release(), new node_t(data)) );
    }
    void push_front(value_type const & data) {
        root.reset( merge(new node_t(data), root.release()) );
    }
    void pop_back() {
        int k = size() - 1;
        auto lr = split(root.release(), k);
        root.reset(lr.first);
        node_deleter()(lr.second);
    }
    void pop_front() {
        auto lr = split(root.release(), 1);
        node_deleter()(lr.first);
        root.reset(lr.second);
    }
    int size() const {
        return root ? root.get()->size : 0;
    }
    bool empty() const {
        return not root;
    }
    void clear() {
        root = nullptr;
    }
};

struct max_monoid {
    typedef int value_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return max(a, b); }
};
struct plus_operator_monoid {
    typedef int value_type;
    typedef int target_type;
    int identity() const { return 0; }
    int apply(value_type a, target_type b) const { return a + b; }
    int compose(value_type a, value_type b) const { return a + b; }
};
typedef lazy_propagation_red_black_tree<max_monoid, plus_operator_monoid> red_black_starry_sky_tree;

unittest {
    default_random_engine gen;
    auto generate = [&]() {
        red_black_starry_sky_tree rbtree;
        deque<int> dec;
        REP (iteration, 100) {
            int value = uniform_int_distribution<int>(0, 100)(gen);
            if (bernoulli_distribution(0.5)(gen)) {
                rbtree.push_back(value);
                dec.push_back(value);
            } else {
                rbtree.push_front(value);
                dec.push_front(value);
            }
        }
        return make_pair( move(rbtree), dec );
    };
    REP (iteration, 1000) {
        red_black_starry_sky_tree rbtree;
        deque<int> dec;
        tie(rbtree, dec) = generate();
        REP (iteration, 100) {
            assert (rbtree.size() == dec.size());
            int k = uniform_int_distribution<int>(0, rbtree.size())(gen);
            int l = uniform_int_distribution<int>(0, rbtree.size())(gen);
            int r = uniform_int_distribution<int>(0, rbtree.size())(gen);
            if (l > r) swap(l, r);
            int i = rbtree.empty() ? -1 : uniform_int_distribution<int>(0, rbtree.size() - 1)(gen);
            int value = uniform_int_distribution<int>(0, 100)(gen);
            int func  = uniform_int_distribution<int>(- 10, 10)(gen);
            switch (uniform_int_distribution<int>(0, 15)(gen)) {
                case 0:  // merge
                    {
                        red_black_starry_sky_tree rbtree2;
                        deque<int> dec2;
                        tie(rbtree2, dec2) = generate();
                        rbtree = red_black_starry_sky_tree::merge(rbtree, rbtree2);
                        copy(ALL(dec2), back_inserter(dec));
                    }
                    break;
                case 1:  // split
                    if (bernoulli_distribution(0.5)(gen)) {
                        rbtree = rbtree.split(k).first;
                        dec.erase(dec.begin() + k, dec.end());
                    } else {
                        rbtree = rbtree.split(k).second;
                        dec.erase(dec.begin(), dec.begin() + k);
                    }
                    break;
                case 2:  // insert
                    rbtree.insert(k, value);
                    dec.push_back(value);
                    rotate(dec.begin() + k, dec.begin() + (dec.size() - 1), dec.end());
                    break;
                case 3:  // erase
                    if (not rbtree.empty()) {
                        rbtree.erase(i);
                        rotate(dec.begin() + i, dec.begin() + (i + 1), dec.end());
                        dec.pop_back();
                    }
                    break;
                case 4:  // push_back
                    rbtree.push_back(value);
                    dec.push_back(value);
                    break;
                case 5:  // push_front
                    rbtree.push_front(value);
                    dec.push_front(value);
                    break;
                case 6:  // pop_back
                    if (not rbtree.empty()) {
                        rbtree.pop_front();
                        dec.pop_front();
                    }
                    break;
                case 7:  // pop_front
                    if (not rbtree.empty()) {
                        rbtree.pop_back();
                        dec.pop_back();
                    }
                    break;
                case 8:  // set
                    if (not rbtree.empty()) {
                        rbtree.point_set(i, value);
                        dec[i] = value;
                    }
                    break;
                case 9:  // reverse
                    rbtree.reverse(l, r);
                    reverse(dec.begin() + l, dec.begin() + r);
                    break;
                case 10:  // range_concat
                case 11:
                case 12:
                    {
                        int x = rbtree.range_concat(l, r);
                        int y = INT_MIN;
                        REP3 (i, l, r) y = max(y, dec[i]);
                        assert (x == y);
                    }
                    break;
                case 13:  // range_apply
                case 14:
                case 15:
                    rbtree.range_apply(l, r, func);
                    REP3 (i, l, r) dec[i] += func;
                    break;
                default:
                    assert (false);
            }
            REP (i, rbtree.size()) {
                assert (rbtree.point_get(i) == dec[i]);
            }
        }
    }
}

```

[Back to top page](../../index.html)

