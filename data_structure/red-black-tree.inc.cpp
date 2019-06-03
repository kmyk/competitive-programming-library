/**
 * @note almost all operations are O(log N)
 */
template <class T>
class red_black_tree {

    enum color_t { BLACK, RED };
    struct node_t {
        bool is_leaf;
        union {
            T data;
            struct {
                color_t m_color;
                int m_rank;
                int m_size;
                node_t *left;
                node_t *right;
            };
        };
        node_t() = default;
        node_t(T const & a_data)
                : is_leaf(true)
                , data(a_data) {
        }
        node_t(node_t *l, node_t *r, color_t c)  // non-leaf node
                : is_leaf(false)
                , m_color(c)
                , m_rank(max(rank(l) + (color(l) == BLACK),
                             rank(r) + (color(r) == BLACK)))
                , m_size(size(l) + size(r))
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

    static inline color_t color(node_t const *t) {
        return t->is_leaf ? BLACK : t->m_color;
    }
    static inline int rank(node_t const *t) {
        return t->is_leaf ? 0 : t->m_rank;
    }
    static inline int size(node_t const *t) {
        return t->is_leaf ? 1 : t->m_size;
    }

    /**
     * @note trees a, b are consumed  (at set_left()/set_right())
     */
    static node_t *merge(node_t *a, node_t *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        node_t *c = merge_relax(a, b);
        c->m_color = BLACK;
        return c;
    }
    /*
     * @note the root of returned tree may violates the color constraint
     */
    static node_t *merge_relax(node_t *a, node_t *b) {
        if (rank(a) < rank(b)) {
            assert (not b->is_leaf);
            return set_left(b, merge_relax(a, b->left));
        } else if (rank(a) > rank(b)) {
            assert (not a->is_leaf);
            return set_right(a, merge_relax(a->right, b));
        } else {
            a->m_color = BLACK;
            b->m_color = BLACK;
            return new node_t(a, b, RED);
        }
    }
    static node_t *set_left(node_t *b, node_t *c) {
        if (b->m_color == BLACK and c->m_color == RED and color(c->left) == RED) {
            if (color(b->right) == BLACK) {
                *b = node_t(c->right, b->right, RED);
                *c = node_t(c->left, b, BLACK);
                swap(b, c);
            } else {
                b->right->m_color = BLACK;
                c->m_color = BLACK;
                *b = node_t(c, b->right, RED);
            }
        } else {
            *b = node_t(c, b->right, b->m_color);
        }
        return b;
    }
    static node_t *set_right(node_t *a, node_t *c) {
        if (a->m_color == BLACK and c->m_color == RED and color(c->right) == RED) {
            if (color(a->left) == BLACK) {
                *a = node_t(a->left, c->left, RED);
                *c = node_t(a, c->right, BLACK);
                swap(a, c);
            } else {
                a->left->m_color = BLACK;
                c->m_color = BLACK;
                *a = node_t(a->left, c, RED);
            }
        } else {
            *a = node_t(a->left, c, a->m_color);
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
        if (k == size(a)) {
            return make_pair( a, nullptr );
        }
        assert (not a->is_leaf);
        node_t *a_left  = a->left;
        node_t *a_right = a->right;
        delete a;
        if (k < size(a_left)) {
            node_t *l, *r; tie(l, r) = split(a_left, k);
            return make_pair( l, merge(r, a_right) );
        } else if (k > size(a_left)) {
            node_t *l, *r; tie(l, r) = split(a_right, k - size(a_left));
            return make_pair( merge(a_left, l), r );
        } else {
            return make_pair( a_left, a_right );
        }
    }

    /**
     * @tparam (A, B) = (node_t const *, T const &), (node_t *, T &)
     */
    template <class A, class B>
    static B get_generic(A a, int i) {
        if (a->is_leaf) {
            assert (i == 0);
            return a->data;
        } else {
            if (i < size(a->left)) {
                return get_generic<A, B>(a->left, i);
            } else {
                return get_generic<A, B>(a->right, i - size(a->left));
            }
        }
    }

private:
    unique_ptr<node_t, node_deleter> root;

public:
    red_black_tree<T>() = default;
    red_black_tree<T>(node_t *a_root) : root(a_root) {}

    static red_black_tree<T> merge(red_black_tree<T> & l, red_black_tree<T> & r) {
        node_t *a = l.root.release();
        node_t *b = r.root.release();
        if (a == nullptr) return red_black_tree<T>(b);
        if (b == nullptr) return red_black_tree<T>(a);
        return red_black_tree<T>(merge(a, b));
    }
    pair<red_black_tree<T>, red_black_tree<T> > split(int k) {
        assert (0 <= k and k <= size());
        node_t *l, *r; tie(l, r) = split(root.release(), k);
        return make_pair( red_black_tree<T>(l), red_black_tree<T>(r) );
    }

    void insert(int i, T const & data) {
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

    void set(int i, T const & data) {
        assert (0 <= i and i < size());
        get_generic<node_t *, T &>(root.get(), i) = data;
    }
    T const & get(int i) const {
        assert (0 <= i and i < size());
        return get_generic<node_t const *, T const &>(root.get(), i);
    }

    void push_back(T const & data) {
        root.reset( merge(root.release(), new node_t(data)) );
    }
    void push_front(T const & data) {
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
        return root ? size(root.get()) : 0;
    }
    bool empty() const {
        return not root;
    }
    void clear() {
        root = nullptr;
    }
};

unittest {
    default_random_engine gen;
    auto generate = [&]() {
        red_black_tree<double> rbtree;
        deque<double> dec;
        REP (iteration, 100) {
            double value = uniform_real_distribution<double>()(gen);
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
        red_black_tree<double> rbtree;
        deque<double> dec;
        tie(rbtree, dec) = generate();
        REP (iteration, 100) {
            assert (rbtree.size() == dec.size());
            int k = uniform_int_distribution<int>(0, rbtree.size())(gen);
            int i = rbtree.empty() ? -1 : uniform_int_distribution<int>(0, rbtree.size() - 1)(gen);
            double value = uniform_real_distribution<double>()(gen);
            switch (uniform_int_distribution<int>(0, 8)(gen)) {
                case 0:  // merge
                    {
                        red_black_tree<double> rbtree2;
                        deque<double> dec2;
                        tie(rbtree2, dec2) = generate();
                        rbtree = red_black_tree<double>::merge(rbtree, rbtree2);
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
                        rbtree.set(i, value);
                        dec[i] = value;
                    }
                    break;
                default:
                    assert (false);
            }
            REP (i, rbtree.size()) {
                assert (rbtree.get(i) == dec[i]);
            }
        }
    }
}
