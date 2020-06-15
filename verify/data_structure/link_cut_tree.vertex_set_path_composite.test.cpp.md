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


# :heavy_check_mark: data_structure/link_cut_tree.vertex_set_path_composite.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 07:51:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_set_path_composite">https://judge.yosupo.jp/problem/vertex_set_path_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/link_cut_tree.hpp.html">Link-Cut tree (monoids without commutativity, vertex set + path get) <small>(data_structure/link_cut_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/hack/fastio.hpp.html">hack/fastio.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/mint_core.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint_core.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/dual.hpp.html">monoids/dual.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/linear_function.hpp.html">monoids/linear_function.hpp</a>
* :heavy_check_mark: <a href="../../library/monoids/reversible.hpp.html">monoids/reversible.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "data_structure/link_cut_tree.hpp"
#include "modulus/mint.hpp"
#include "monoids/linear_function.hpp"
#include "monoids/dual.hpp"
#include "utils/macros.hpp"
#include "hack/fastio.hpp"
#include <stack>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n = in<int>();
    int q = in<int>();

    // initialize
    link_cut_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > lct(n);
    REP (i, n) {
        mint<MOD> a_i = in<int32_t>();
        mint<MOD> b_i = in<int32_t>();
        lct.vertex_set(i, make_pair(a_i, b_i));
    }
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int u = in<int>();
        int v = in<int>();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> used(n);
    stack<int> stk;
    stk.push(0);
    used[0] = true;
    while (not stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (int v : g[u]) if (not used[v]) {
            lct.link(v, u);
            stk.push(v);
            used[v] = true;
        }
    }

    // answer to queries
    while (q --) {
        int t = in<int>();
        if (t == 0) {
            int p = in<int>();
            mint<MOD> c = in<int32_t>();
            mint<MOD> d = in<int32_t>();
            lct.vertex_set(p, make_pair(c, d));
        } else if (t == 1) {
            int u = in<int>();
            int v = in<int>();
            mint<MOD> x = in<int32_t>();
            auto [a, b] = lct.path_get(u, v);
            out<int32_t>((a * x + b).value);
            out<char>('\n');
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/link_cut_tree.vertex_set_path_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#line 2 "data_structure/link_cut_tree.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <sstream>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "monoids/reversible.hpp"
#include <utility>

template <class Monoid>
struct reversible_monoid {
    typedef typename Monoid::value_type base_type;
    typedef std::pair<base_type, base_type> value_type;
    Monoid base;
    reversible_monoid() = default;
    reversible_monoid(const Monoid & base_) : base(base_) {}
    value_type unit() const { return std::make_pair(base.unit(), base.unit()); }
    value_type mult(const value_type & a, const value_type & b) const { return std::make_pair(base.mult(a.first, b.first), base.mult(b.second, a.second)); }
    static value_type make(const base_type & x) { return std::make_pair(x, x); }
    static value_type reverse(const value_type & a) { return std::make_pair(a.second, a.first); }
    static base_type get(const value_type & a) { return a.first; }
};
#line 9 "data_structure/link_cut_tree.hpp"


/**
 * @brief Link-Cut tree (monoids without commutativity, vertex set + path get)
 * @docs data_structure/link_cut_tree.md
 * @description manages a dynamic forest of rooted trees
 * @note in each splay tree, nodes are sorted from bottom to top. the rightmost node of the root splay tree of the auxiliary tree is the root of represented tree.
 */
template <class Monoid>
class link_cut_tree {
    typedef typename Monoid::value_type value_type;
    typedef typename reversible_monoid<Monoid>::value_type reversible_type;
    const reversible_monoid<Monoid> mon;
    std::vector<value_type> data;  // data of the original tree
    std::vector<reversible_type> path;  // sum of data of the sub-tree in the belonging splay tree
    std::vector<int> parent, left, right;  // of the auxiliary tree
    std::vector<bool> is_reversed;  // of the auxiliary tree; not applied to left, right, and path yet

    /**
     * @description returns whether `a` and `parent[a]` is in the same splay tree
     */
    int get_parent_edge_type(int a) const {
        if (parent[a] != -1 and left[parent[a]] == a) {
            assert (not is_reversed[parent[a]]);
            return -1;  // heavy (left-child)
        } else if (parent[a] != -1 and right[parent[a]] == a) {
            assert (not is_reversed[parent[a]]);
            return +1;  // heavy (right-child)
        } else {
            return 0;  // light
        }
    }

    /**
     * @description make `a` the parent of the current parent of `a`
     */
    void rotate(int a) {
        int b = parent[a];
        assert (b != -1);
        assert (not is_reversed[b]);
        assert (not is_reversed[a]);
        switch (get_parent_edge_type(b)) {
            case -1:  // left
                left[parent[b]] = a;
                break;
            case 1:  // right
                right[parent[b]] = a;
                break;
        }
        switch (get_parent_edge_type(a)) {
            case -1:  // left
                parent[a] = std::exchange(parent[b], a);
                left[b] = std::exchange(right[a], b);
                if (left[b] != -1) parent[left[b]] = b;
                break;
            case 1:  // right
                parent[a] = std::exchange(parent[b], a);
                right[b] = std::exchange(left[a], b);
                if (right[b] != -1) parent[right[b]] = b;
                break;
            default:  // root
                assert (false);
        }
        update_path(b);
        update_path(a);
    }

    /**
     * @description make `a` the root of the beloging splay tree
     */
    void splay(int a) {
        propagate_reverse_splay(a);
        while (get_parent_edge_type(a)) {
            // a is not the root of the splay tree
            if (not get_parent_edge_type(parent[a])) {
                // zig step: parent[a] is the root of the splay tree
                rotate(a);
            } else if (get_parent_edge_type(a) == get_parent_edge_type(parent[a])) {
                // zig-zig step
                rotate(parent[a]);
                rotate(a);
            } else {
                // zig-zag step
                rotate(a);
                rotate(a);
            }
        }
    }

    /**
     * @description make `a` the root of the auxiliary tree
     * @note `a` becomes a terminal of the heavy path
     */
    void expose(int a) {
        // make a light path from `a` to the root
        for (int b = a; b != -1; b = parent[b]) {
            splay(b);
        }
        // make `a` the terminal of the path
        assert (not is_reversed[a]);
        left[a] = -1;
        update_path(a);
        // make the path heavy
        for (int b = a; parent[b] != -1; b = parent[b]) {
            left[parent[b]] = b;
            update_path(parent[b]);
        }
        splay(a);
    }

    void propagate_reverse_node(int a) {
        if (is_reversed[a]) {
            is_reversed[a] = false;
            path[a] = reversible_monoid<Monoid>::reverse(path[a]);
            if (right[a] != -1) is_reversed[right[a]] = not is_reversed[right[a]];
            if (left[a] != -1) is_reversed[left[a]] = not is_reversed[left[a]];
            std::swap(left[a], right[a]);
        }
    }
    void propagate_reverse_splay(int a) {
        if (parent[a] != -1 and (left[parent[a]] == a or right[parent[a]] == a)) {
            propagate_reverse_splay(parent[a]);
        }
        propagate_reverse_node(a);
        if (right[a] != -1) propagate_reverse_node(right[a]);
        if (left[a] != -1) propagate_reverse_node(left[a]);
    }

    /**
     * @note `a` should be the root of the splay tree
     */
    void update_path(int a) {
        path[a] = reversible_monoid<Monoid>::make(data[a]);
        if (right[a] != -1) path[a] = mon.mult(path[a], path[right[a]]);
        if (left[a] != -1) path[a] = mon.mult(path[left[a]], path[a]);
    }

public:
    link_cut_tree(int size, const Monoid & mon_ = Monoid())
            : mon(mon_), data(size, mon.base.unit()), path(size, mon.unit()), parent(size, -1), left(size, -1), right(size, -1), is_reversed(size, false) {
    }

    /**
     * @description make a direct edge from `a` to `b`
     * @note `a` must be a root
     * @note `b` must not be a descendant of `a`
     */
    void link(int a, int b) {
        expose(b);  // for the time complexity
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        assert (right[a] == -1);  // `a` must be a root
        parent[a] = b;
    }

    /**
     * @description remove the direct edge from `a`
     * @note `a` must not be a root
     */
    void cut(int a) {
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        assert (right[a] != -1);  // `a` must not be a root
        parent[right[a]] = -1;
        right[a] = -1;
        update_path(a);
    }

    /**
     * @note -1 is returned when `a` and `b` are not in the same tree
     */
    int get_lowest_common_ancestor(int a, int b) {
        expose(b);  // for the time complexity
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        int preserved = -1;
        std::swap(left[a], preserved);  // make `a` and `b` belong different splay trees even if `b` is a descendant of `a`
        int result = b;
        int c = b;
        for (; c != a and c != -1; c = parent[c]) {
            assert (parent[c] != -1);
            if (not get_parent_edge_type(c)) {  // when it enters another splay tree
                result = parent[c];
            }
        }
        std::swap(left[a], preserved);
        return c == a ? result : -1;
    }

    bool are_connected(int a, int b) {
        return get_lowest_common_ancestor(a, b) != -1;
    }

    int get_parent(int a) {
        expose(a);
        assert (not is_reversed[a]);
        if (right[a] == -1) return parent[a];
        for (int b = right[a]; ; b = left[b]) {
            propagate_reverse_node(b);
            if (left[b] == -1) {
                splay(b);  // for the time complexity
                return b;
            }
        }
    }

    int get_root(int a) {
        expose(a);
        assert (not is_reversed[a]);
        while (right[a] != -1) {
            a = right[a];
        }
        splay(a);  // for the time complexity
        return a;
    }

    /**
     * @description make `a` the root of the represented tree
     */
    void evert(int a) {
        expose(a);  // to make `a` the root
        assert (not is_reversed[a]);
        assert (left[a] == -1);  // `a` is the terminal
        is_reversed[a] = true;
    }

    void vertex_set(int a, value_type value) {
        splay(a);  // to make `a` the root of a splay tree
        data[a] = value;
        update_path(a);
    }

    value_type vertex_get(int a) const {
        return data[a];
    }

    value_type path_get(int a, int b) {
        expose(a);  // for the time complexity
        expose(b);  // to make `b` the root
        assert (not is_reversed[a]);
        auto data_a = reversible_monoid<Monoid>::make(data[a]);
        reversible_type up = (right[a] == -1 ? data_a : mon.mult(data_a, path[right[a]]));
        reversible_type down = (left[a] == -1 ? data_a : mon.mult(path[left[a]], data_a));
        for (int c = a; c != b and c != -1; c = parent[c]) {
            assert (parent[c] != -1);
            assert (not is_reversed[parent[c]]);
            auto data_parent_c = reversible_monoid<Monoid>::make(data[parent[c]]);
            switch (get_parent_edge_type(c)) {
                case -1:  // heavy (left-child)
                    up = mon.mult(up, data_parent_c);
                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);
                    break;
                case 1:  // heavy (right-child)
                    down = mon.mult(data_parent_c, down);
                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);
                    break;
                case 0:  // light
                    down = reversible_monoid<Monoid>::reverse(up);
                    up = mon.mult(up, data_parent_c);
                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);
                    down = mon.mult(data_parent_c, down);
                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);
                    break;
            }
        }
        return reversible_monoid<Monoid>::get(reversible_monoid<Monoid>::reverse(down));
    }

    std::string to_graphviz() const {
        using namespace std;
        ostringstream oss;
        oss << "digraph G {" << endl;
        oss << "    graph [ rankdir = BT, bgcolor = \"#00000000\" ]" << endl;
        oss << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl;
        REP (a, parent.size()) {
            // oss << "    " << a << ";" << endl;
            oss << "    " << a << "[ label = \"" << a << "(" << data[a] << "," << path[a] << (is_reversed[a] ? " +rev" : "") << ")\"];" << endl;
        }
        function <void (int)> go = [&](int a) {
            if (parent[a] != -1 and not get_parent_edge_type(a)) {
                oss << "    " << a << " -> " << parent[a] << " [ style = dashed ]" << endl;
            }
            if (left[a] != -1 or right[a] != -1) {
                string l = (left[a] != -1 ? to_string(left[a]) : "l" + to_string(a));
                string r = (right[a] != -1 ? to_string(right[a]) : "r" + to_string(a));
                oss << "    " << l << " -> " << a << endl;
                oss << "    " << l << " -> " << r << " [ style = invis ]" << endl;
                oss << "    " << r << " -> " << a << endl;
                oss << "    { rank = same; " << l << "; " << r << "; }" << endl;
                if (left[a] == -1) oss << "    " << l << " [ style = invis ]" << endl;
                if (right[a] == -1) oss << "    " << r << " [ style = invis ]" << endl;
            }
            if (left[a] != -1) go(left[a]);
            if (right[a] != -1) go(right[a]);
        };
        REP (a, parent.size()) if (not get_parent_edge_type(a)) {
            go(a);
        }
        oss << "}";
        return oss.str();
    }
};
#line 3 "modulus/modpow.hpp"
#include <cstdint>

inline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);
    return y;
}
#line 5 "modulus/modinv.hpp"

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
#line 3 "modulus/mint_core.hpp"
#include <iostream>

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
    inline mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline bool operator == (mint<MOD> other) const { return value == other.value; }
    inline bool operator != (mint<MOD> other) const { return value != other.value; }
    inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline mint<MOD> operator / (mint<MOD> other) const { return *this * other.inv(); }
    inline mint<MOD> & operator /= (mint<MOD> other) { return *this *= other.inv(); }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> mint<MOD> operator / (int64_t value, mint<MOD> n) { return mint<MOD>(value) / n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 3 "monoids/linear_function.hpp"

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
#line 2 "monoids/dual.hpp"

/**
 * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual
 */
template <class Monoid>
struct dual_monoid {
    typedef typename Monoid::value_type value_type;
    Monoid base;
    value_type unit() const { return base.unit(); }
    value_type mult(const value_type & a, const value_type & b) const { return base.mult(b, a); }
};
#line 3 "hack/fastio.hpp"
#include <cstdio>
#include <string>
#include <type_traits>

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline Char in() { return getchar_unlocked(); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline std::string in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    std::string s;
    do { s.push_back(c); } while (not isspace(c = getchar_unlocked()));
    return s;
}
template <class Integer, std::enable_if_t<std::is_integral_v<Integer> and not std::is_same_v<Integer, char>, int> = 0>
inline Integer in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    if (std::is_signed<Integer>::value and c == '-') return -in<Integer>();
    Integer n = 0;
    do { n = n * 10 + c - '0'; } while (not isspace(c = getchar_unlocked()));
    return n;
}

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline void out(char c) { putchar_unlocked(c); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline void out(const std::string & s) { for (char c : s) putchar_unlocked(c); }
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline void out(Integer n) {
    char s[20];
    int i = 0;
    if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}
#line 8 "data_structure/link_cut_tree.vertex_set_path_composite.test.cpp"
#include <stack>
#line 10 "data_structure/link_cut_tree.vertex_set_path_composite.test.cpp"
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n = in<int>();
    int q = in<int>();

    // initialize
    link_cut_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > lct(n);
    REP (i, n) {
        mint<MOD> a_i = in<int32_t>();
        mint<MOD> b_i = in<int32_t>();
        lct.vertex_set(i, make_pair(a_i, b_i));
    }
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int u = in<int>();
        int v = in<int>();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> used(n);
    stack<int> stk;
    stk.push(0);
    used[0] = true;
    while (not stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (int v : g[u]) if (not used[v]) {
            lct.link(v, u);
            stk.push(v);
            used[v] = true;
        }
    }

    // answer to queries
    while (q --) {
        int t = in<int>();
        if (t == 0) {
            int p = in<int>();
            mint<MOD> c = in<int32_t>();
            mint<MOD> d = in<int32_t>();
            lct.vertex_set(p, make_pair(c, d));
        } else if (t == 1) {
            int u = in<int>();
            int v = in<int>();
            mint<MOD> x = in<int32_t>();
            auto [a, b] = lct.path_get(u, v);
            out<int32_t>((a * x + b).value);
            out<char>('\n');
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

