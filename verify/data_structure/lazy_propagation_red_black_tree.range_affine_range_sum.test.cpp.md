---
layout: default
---

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


# :heavy_check_mark: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-04 20:56:55+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/lazy_propagation_red_black_tree.hpp.html">Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 赤黒木) <small>(data_structure/lazy_propagation_red_black_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function.hpp.html">monoids/linear_function.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function_plus_count_action.hpp.html">monoids/linear_function_plus_count_action.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/plus_count.hpp.html">monoids/plus_count.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "data_structure/lazy_propagation_red_black_tree.hpp"
#include "monoids/plus_count.hpp"
#include "monoids/linear_function.hpp"
#include "monoids/linear_function_plus_count_action.hpp"
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<pair<mint<MOD>, int> > a(n);
    REP (i, n) {
        int a_i; scanf("%d", &a_i);
        a[i].first = a_i;
        a[i].second = 1;
    }
    lazy_propagation_red_black_tree<plus_count_monoid<mint<MOD> >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD> > > segtree(ALL(a));
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, b, c; scanf("%d%d%d%d", &l, &r, &b, &c);
            pair<mint<MOD>, mint<MOD> > f(b, c);
            segtree.range_apply(l, r, f);
        } else if (t == 1) {
            int l, r; scanf("%d%d", &l, &r);
            mint<MOD> answer = segtree.range_get(l, r).first;
            printf("%d\n", answer.value);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#line 2 "data_structure/lazy_propagation_red_black_tree.hpp"
#include <algorithm>
#include <cassert>
#include <memory>
#include <type_traits>
#include <vector>

/**
 * @brief Lazy Propagation Segment Tree / 遅延伝播セグメント木 (monoids, 赤黒木)
 * @docs data_structure/lazy_propagation_red_black_tree.md
 * @tparam MonoidX is a monoid
 * @tparam MonoidF is a monoid
 * @tparam Action is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X is a homomorphism on X
 */
template <class MonoidX, class MonoidF, class Action>
class lazy_propagation_red_black_tree {
    static_assert (std::is_invocable_r<typename MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value, "");
    typedef typename MonoidX::value_type value_type;
    typedef typename MonoidF::value_type operator_type;

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
                , data(MonoidX().mult(l->data, r->data))
                , lazy(MonoidF().unit())
                , reversed(false)
                , color(c)
                , rank(std::max(l->rank + (l->color == BLACK),
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
        MonoidF mon_f;
        Action act;
        if (not a->is_leaf) {
            if (a->lazy != mon_f.unit()) {
                auto const & l = a->left;
                auto const & r = a->right;
                l->data = act(a->lazy, l->data);
                r->data = act(a->lazy, r->data);
                if (not l->is_leaf) l->lazy = mon_f.mult(a->lazy, l->lazy);
                if (not r->is_leaf) r->lazy = mon_f.mult(a->lazy, r->lazy);
                a->lazy = mon_f.unit();
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
                std::swap(a->left, a->right);  // CAUTION: auto const & l, r are destroyed
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
                std::swap(b, c);
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
                std::swap(a, c);
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
    static std::pair<node_t *, node_t *> split(node_t *a, int k) {
        if (k == 0) {
            return std::make_pair( nullptr, a );
        }
        assert (a != nullptr);
        if (k == a->size) {
            return std::make_pair( a, nullptr );
        }
        assert (not a->is_leaf);
        propagate(a);
        node_t *a_left  = a->left;
        node_t *a_right = a->right;
        delete a;
        if (k < a_left->size) {
            node_t *l, *r; tie(l, r) = split(a_left, k);
            return std::make_pair( l, merge(r, a_right) );
        } else if (k > a_left->size) {
            node_t *l, *r; tie(l, r) = split(a_right, k - a_left->size);
            return std::make_pair( merge(a_left, l), r );
        } else {
            return std::make_pair( a_left, a_right );
        }
    }

    static void range_apply(node_t *a, int l, int r, const operator_type & func) {
        MonoidX mon_x;
        MonoidF mon_f;
        Action act;
        if (l == r) return;
        if (l == 0 and r == a->size) {
            a->data = act(func, a->data);
            if (not a->is_leaf) a->lazy = mon_f.mult(func, a->lazy);
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
        a->data = act(a->lazy, mon_x.mult(a->left->data, a->right->data));
    }

    static value_type range_get(node_t *a, int l, int r) {
        MonoidX mon_x;
        assert (l < r);
        if (l == 0 and r == a->size) return a->data;
        assert (not a->is_leaf);
        propagate(a);
        int k = a->left->size;
        if (r <= k) {
            return range_get(a->left, l, r);
        } else if (k <= l) {
            return range_get(a->right, l - k, r - k);
        } else {
            return mon_x.mult(
                    range_get(a->left, l, k),
                    range_get(a->right, 0, r - k));
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

    static void point_set(node_t *a, int i, const value_type & value) {
        MonoidX mon_x;
        Action act;
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
            a->data = act(a->lazy,
                    mon_x.mult(a->left->data, a->right->data));
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
    std::unique_ptr<node_t, node_deleter> root;

public:
    lazy_propagation_red_black_tree() = default;
    lazy_propagation_red_black_tree(node_t *a_root)
            : root(a_root) {
    }
    template <class InputIterator>
    lazy_propagation_red_black_tree(InputIterator first, InputIterator last)
            : root(nullptr) {
        for (; first != last; ++ first) {
            this->push_back(*first);
        }
    }

    static lazy_propagation_red_black_tree merge(lazy_propagation_red_black_tree & l, lazy_propagation_red_black_tree & r) {
        node_t *a = l.root.release();
        node_t *b = r.root.release();
        if (a == nullptr) return lazy_propagation_red_black_tree(b);
        if (b == nullptr) return lazy_propagation_red_black_tree(a);
        return lazy_propagation_red_black_tree(merge(a, b));
    }
    std::pair<lazy_propagation_red_black_tree, lazy_propagation_red_black_tree> split(int k) {
        assert (0 <= k and k <= size());
        node_t *l, *r; tie(l, r) = split(root.release(), k);
        return std::make_pair( lazy_propagation_red_black_tree(l), lazy_propagation_red_black_tree(r) );
    }

    void insert(int i, const value_type & data) {
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

    void point_set(int i, const value_type & value) {
        assert (0 <= i and i < size());
        point_set(root.get(), i, value);
    }
    value_type const & point_get(int i) const {
        assert (0 <= i and i < size());
        return point_get(const_cast<node_t *>(root.get()), i);
    }

    void range_apply(int l, int r, const operator_type & func) {
        assert (0 <= l and l <= r and r <= size());
        if (l == r) return;
        range_apply(root.get(), l, r, func);
    }
    value_type const range_get(int l, int r) const {
        assert (0 <= l and l <= r and r <= size());
        if (l == r) return MonoidX().unit();
        return range_get(const_cast<node_t *>(root.get()), l, r);
    }
    void reverse(int l, int r) {
        assert (0 <= l and l <= r and r <= size());
        if (not root) return;
        root.reset( reverse(root.release(), l, r) );
    }

    void push_back(const value_type & data) {
        root.reset( merge(root.release(), new node_t(data)) );
    }
    void push_front(const value_type & data) {
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
#line 2 "monoids/plus_count.hpp"
#include <utility>

template <class T>
struct plus_count_monoid {
    typedef std::pair<T, int> value_type;
    value_type unit() const {
        return std::make_pair(T(), 0);
    }
    value_type mult(value_type a, value_type b) const {
        return std::make_pair(a.first + b.first, a.second + b.second);
    }
    static value_type make(T a) {
        return std::make_pair(a, 1);
    }
};
#line 2 "monoids/linear_function.hpp"
#include <utility>

template <class CommutativeRing>
struct linear_function_monoid {
    typedef std::pair<CommutativeRing, CommutativeRing> value_type;
    linear_function_monoid() = default;
    value_type unit() const {
        return std::make_pair(1, 0);
    }
    value_type mult(value_type g, value_type f) const {
        CommutativeRing fst = g.first * f.first;
        CommutativeRing snd = g.second + g.first * f.second;
        return std::make_pair(fst, snd);
    }
};
#line 2 "monoids/linear_function_plus_count_action.hpp"
#include <utility>
#line 4 "monoids/linear_function_plus_count_action.hpp"

/**
 * @note lazy_propagation_segment_tree<plus_count_monoid<T>, linear_function_monoid<T>, linear_function_plus_count_action<T> >
 */
template <class T>
struct linear_function_plus_count_action {
    typename plus_count_monoid<T>::value_type operator () (typename linear_function_monoid<T>::value_type f, typename plus_count_monoid<T>::value_type x) const {
        return std::make_pair(f.first * x.first + f.second * x.second, x.second);
    }
};
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#line 2 "modulus/modpow.hpp"
#include <cassert>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
#line 2 "modulus/modinv.hpp"
#include <algorithm>
#include <cassert>

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}
#line 7 "modulus/mint.hpp"


/**
 * @brief quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$
 */
template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 8 "data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp"
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<pair<mint<MOD>, int> > a(n);
    REP (i, n) {
        int a_i; scanf("%d", &a_i);
        a[i].first = a_i;
        a[i].second = 1;
    }
    lazy_propagation_red_black_tree<plus_count_monoid<mint<MOD> >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD> > > segtree(ALL(a));
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, b, c; scanf("%d%d%d%d", &l, &r, &b, &c);
            pair<mint<MOD>, mint<MOD> > f(b, c);
            segtree.range_apply(l, r, f);
        } else if (t == 1) {
            int l, r; scanf("%d%d", &l, &r);
            mint<MOD> answer = segtree.range_get(l, r).first;
            printf("%d\n", answer.value);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

