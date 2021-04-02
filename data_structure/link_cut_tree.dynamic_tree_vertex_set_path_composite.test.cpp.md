---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.hpp
    title: Link-Cut tree (monoids without commutativity, vertex set + path get)
  - icon: ':heavy_check_mark:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':heavy_check_mark:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':heavy_check_mark:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/dual.hpp
    title: monoids/dual.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/linear_function.hpp
    title: monoids/linear_function.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/reversible.hpp
    title: monoids/reversible.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#line 2 \"data_structure/link_cut_tree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <sstream>\n#include <vector>\n#line\
    \ 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++\
    \ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 2 \"monoids/reversible.hpp\"\n#include <utility>\n\ntemplate\
    \ <class Monoid>\nstruct reversible_monoid {\n    typedef typename Monoid::value_type\
    \ base_type;\n    typedef std::pair<base_type, base_type> value_type;\n    Monoid\
    \ base;\n    reversible_monoid() = default;\n    reversible_monoid(const Monoid\
    \ & base_) : base(base_) {}\n    value_type unit() const { return std::make_pair(base.unit(),\
    \ base.unit()); }\n    value_type mult(const value_type & a, const value_type\
    \ & b) const { return std::make_pair(base.mult(a.first, b.first), base.mult(b.second,\
    \ a.second)); }\n    static value_type make(const base_type & x) { return std::make_pair(x,\
    \ x); }\n    static value_type reverse(const value_type & a) { return std::make_pair(a.second,\
    \ a.first); }\n    static base_type get(const value_type & a) { return a.first;\
    \ }\n};\n#line 9 \"data_structure/link_cut_tree.hpp\"\n\n\n/**\n * @brief Link-Cut\
    \ tree (monoids without commutativity, vertex set + path get)\n * @docs data_structure/link_cut_tree.md\n\
    \ * @description manages a dynamic forest of rooted trees\n * @note in each splay\
    \ tree, nodes are sorted from bottom to top. the rightmost node of the root splay\
    \ tree of the auxiliary tree is the root of represented tree.\n */\ntemplate <class\
    \ Monoid>\nclass link_cut_tree {\n    typedef typename Monoid::value_type value_type;\n\
    \    typedef typename reversible_monoid<Monoid>::value_type reversible_type;\n\
    \    const reversible_monoid<Monoid> mon;\n    std::vector<value_type> data; \
    \ // data of the original tree\n    std::vector<reversible_type> path;  // sum\
    \ of data of the sub-tree in the belonging splay tree\n    std::vector<int> parent,\
    \ left, right;  // of the auxiliary tree\n    std::vector<bool> is_reversed; \
    \ // of the auxiliary tree; not applied to left, right, and path yet\n\n    /**\n\
    \     * @description returns whether `a` and `parent[a]` is in the same splay\
    \ tree\n     */\n    int get_parent_edge_type(int a) const {\n        if (parent[a]\
    \ != -1 and left[parent[a]] == a) {\n            assert (not is_reversed[parent[a]]);\n\
    \            return -1;  // heavy (left-child)\n        } else if (parent[a] !=\
    \ -1 and right[parent[a]] == a) {\n            assert (not is_reversed[parent[a]]);\n\
    \            return +1;  // heavy (right-child)\n        } else {\n          \
    \  return 0;  // light\n        }\n    }\n\n    /**\n     * @description make\
    \ `a` the parent of the current parent of `a`\n     */\n    void rotate(int a)\
    \ {\n        int b = parent[a];\n        assert (b != -1);\n        assert (not\
    \ is_reversed[b]);\n        assert (not is_reversed[a]);\n        switch (get_parent_edge_type(b))\
    \ {\n            case -1:  // left\n                left[parent[b]] = a;\n   \
    \             break;\n            case 1:  // right\n                right[parent[b]]\
    \ = a;\n                break;\n        }\n        switch (get_parent_edge_type(a))\
    \ {\n            case -1:  // left\n                parent[a] = std::exchange(parent[b],\
    \ a);\n                left[b] = std::exchange(right[a], b);\n               \
    \ if (left[b] != -1) parent[left[b]] = b;\n                break;\n          \
    \  case 1:  // right\n                parent[a] = std::exchange(parent[b], a);\n\
    \                right[b] = std::exchange(left[a], b);\n                if (right[b]\
    \ != -1) parent[right[b]] = b;\n                break;\n            default: \
    \ // root\n                assert (false);\n        }\n        update_path(b);\n\
    \        update_path(a);\n    }\n\n    /**\n     * @description make `a` the root\
    \ of the beloging splay tree\n     */\n    void splay(int a) {\n        propagate_reverse_splay(a);\n\
    \        while (get_parent_edge_type(a)) {\n            // a is not the root of\
    \ the splay tree\n            if (not get_parent_edge_type(parent[a])) {\n   \
    \             // zig step: parent[a] is the root of the splay tree\n         \
    \       rotate(a);\n            } else if (get_parent_edge_type(a) == get_parent_edge_type(parent[a]))\
    \ {\n                // zig-zig step\n                rotate(parent[a]);\n   \
    \             rotate(a);\n            } else {\n                // zig-zag step\n\
    \                rotate(a);\n                rotate(a);\n            }\n     \
    \   }\n    }\n\n    /**\n     * @description make `a` the root of the auxiliary\
    \ tree\n     * @note `a` becomes a terminal of the heavy path\n     */\n    void\
    \ expose(int a) {\n        // make a light path from `a` to the root\n       \
    \ for (int b = a; b != -1; b = parent[b]) {\n            splay(b);\n        }\n\
    \        // make `a` the terminal of the path\n        assert (not is_reversed[a]);\n\
    \        left[a] = -1;\n        update_path(a);\n        // make the path heavy\n\
    \        for (int b = a; parent[b] != -1; b = parent[b]) {\n            left[parent[b]]\
    \ = b;\n            update_path(parent[b]);\n        }\n        splay(a);\n  \
    \  }\n\n    void propagate_reverse_node(int a) {\n        if (is_reversed[a])\
    \ {\n            is_reversed[a] = false;\n            path[a] = reversible_monoid<Monoid>::reverse(path[a]);\n\
    \            if (right[a] != -1) is_reversed[right[a]] = not is_reversed[right[a]];\n\
    \            if (left[a] != -1) is_reversed[left[a]] = not is_reversed[left[a]];\n\
    \            std::swap(left[a], right[a]);\n        }\n    }\n    void propagate_reverse_splay(int\
    \ a) {\n        if (parent[a] != -1 and (left[parent[a]] == a or right[parent[a]]\
    \ == a)) {\n            propagate_reverse_splay(parent[a]);\n        }\n     \
    \   propagate_reverse_node(a);\n        if (right[a] != -1) propagate_reverse_node(right[a]);\n\
    \        if (left[a] != -1) propagate_reverse_node(left[a]);\n    }\n\n    /**\n\
    \     * @note `a` should be the root of the splay tree\n     */\n    void update_path(int\
    \ a) {\n        path[a] = reversible_monoid<Monoid>::make(data[a]);\n        if\
    \ (right[a] != -1) path[a] = mon.mult(path[a], path[right[a]]);\n        if (left[a]\
    \ != -1) path[a] = mon.mult(path[left[a]], path[a]);\n    }\n\npublic:\n    link_cut_tree(int\
    \ size, const Monoid & mon_ = Monoid())\n            : mon(mon_), data(size, mon.base.unit()),\
    \ path(size, mon.unit()), parent(size, -1), left(size, -1), right(size, -1), is_reversed(size,\
    \ false) {\n    }\n\n    /**\n     * @description make a direct edge from `a`\
    \ to `b`\n     * @note `a` must be a root\n     * @note `b` must not be a descendant\
    \ of `a`\n     */\n    void link(int a, int b) {\n        expose(b);  // for the\
    \ time complexity\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        assert (right[a] == -1);  // `a` must be a root\n\
    \        parent[a] = b;\n    }\n\n    /**\n     * @description remove the direct\
    \ edge from `a`\n     * @note `a` must not be a root\n     */\n    void cut(int\
    \ a) {\n        expose(a);  // to make `a` the root\n        assert (not is_reversed[a]);\n\
    \        assert (right[a] != -1);  // `a` must not be a root\n        parent[right[a]]\
    \ = -1;\n        right[a] = -1;\n        update_path(a);\n    }\n\n    /**\n \
    \    * @note -1 is returned when `a` and `b` are not in the same tree\n     */\n\
    \    int get_lowest_common_ancestor(int a, int b) {\n        expose(b);  // for\
    \ the time complexity\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        int preserved = -1;\n        std::swap(left[a],\
    \ preserved);  // make `a` and `b` belong different splay trees even if `b` is\
    \ a descendant of `a`\n        int result = b;\n        int c = b;\n        for\
    \ (; c != a and c != -1; c = parent[c]) {\n            assert (parent[c] != -1);\n\
    \            if (not get_parent_edge_type(c)) {  // when it enters another splay\
    \ tree\n                result = parent[c];\n            }\n        }\n      \
    \  std::swap(left[a], preserved);\n        return c == a ? result : -1;\n    }\n\
    \n    bool are_connected(int a, int b) {\n        return get_lowest_common_ancestor(a,\
    \ b) != -1;\n    }\n\n    int get_parent(int a) {\n        expose(a);\n      \
    \  assert (not is_reversed[a]);\n        if (right[a] == -1) return parent[a];\n\
    \        for (int b = right[a]; ; b = left[b]) {\n            propagate_reverse_node(b);\n\
    \            if (left[b] == -1) {\n                splay(b);  // for the time\
    \ complexity\n                return b;\n            }\n        }\n    }\n\n \
    \   int get_root(int a) {\n        expose(a);\n        assert (not is_reversed[a]);\n\
    \        while (right[a] != -1) {\n            a = right[a];\n        }\n    \
    \    splay(a);  // for the time complexity\n        return a;\n    }\n\n    /**\n\
    \     * @description make `a` the root of the represented tree\n     */\n    void\
    \ evert(int a) {\n        expose(a);  // to make `a` the root\n        assert\
    \ (not is_reversed[a]);\n        assert (left[a] == -1);  // `a` is the terminal\n\
    \        is_reversed[a] = true;\n    }\n\n    void vertex_set(int a, value_type\
    \ value) {\n        splay(a);  // to make `a` the root of a splay tree\n     \
    \   data[a] = value;\n        update_path(a);\n    }\n\n    value_type vertex_get(int\
    \ a) const {\n        return data[a];\n    }\n\n    value_type path_get(int a,\
    \ int b) {\n        expose(a);  // for the time complexity\n        expose(b);\
    \  // to make `b` the root\n        assert (not is_reversed[a]);\n        auto\
    \ data_a = reversible_monoid<Monoid>::make(data[a]);\n        reversible_type\
    \ up = (right[a] == -1 ? data_a : mon.mult(data_a, path[right[a]]));\n       \
    \ reversible_type down = (left[a] == -1 ? data_a : mon.mult(path[left[a]], data_a));\n\
    \        for (int c = a; c != b and c != -1; c = parent[c]) {\n            assert\
    \ (parent[c] != -1);\n            assert (not is_reversed[parent[c]]);\n     \
    \       auto data_parent_c = reversible_monoid<Monoid>::make(data[parent[c]]);\n\
    \            switch (get_parent_edge_type(c)) {\n                case -1:  //\
    \ heavy (left-child)\n                    up = mon.mult(up, data_parent_c);\n\
    \                    if (right[parent[c]] != -1) up = mon.mult(up, path[right[parent[c]]]);\n\
    \                    break;\n                case 1:  // heavy (right-child)\n\
    \                    down = mon.mult(data_parent_c, down);\n                 \
    \   if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]], down);\n\
    \                    break;\n                case 0:  // light\n             \
    \       down = reversible_monoid<Monoid>::reverse(up);\n                    up\
    \ = mon.mult(up, data_parent_c);\n                    if (right[parent[c]] !=\
    \ -1) up = mon.mult(up, path[right[parent[c]]]);\n                    down = mon.mult(data_parent_c,\
    \ down);\n                    if (left[parent[c]] != -1) down = mon.mult(path[left[parent[c]]],\
    \ down);\n                    break;\n            }\n        }\n        return\
    \ reversible_monoid<Monoid>::get(reversible_monoid<Monoid>::reverse(down));\n\
    \    }\n\n    std::string to_graphviz() const {\n        using namespace std;\n\
    \        ostringstream oss;\n        oss << \"digraph G {\" << endl;\n       \
    \ oss << \"    graph [ rankdir = BT, bgcolor = \\\"#00000000\\\" ]\" << endl;\n\
    \        oss << \"    node [ shape = circle, style = filled, fillcolor = \\\"\
    #ffffffff\\\" ]\" << endl;\n        REP (a, parent.size()) {\n            // oss\
    \ << \"    \" << a << \";\" << endl;\n            oss << \"    \" << a << \"[\
    \ label = \\\"\" << a << \"(\" << data[a] << \",\" << path[a] << (is_reversed[a]\
    \ ? \" +rev\" : \"\") << \")\\\"];\" << endl;\n        }\n        function <void\
    \ (int)> go = [&](int a) {\n            if (parent[a] != -1 and not get_parent_edge_type(a))\
    \ {\n                oss << \"    \" << a << \" -> \" << parent[a] << \" [ style\
    \ = dashed ]\" << endl;\n            }\n            if (left[a] != -1 or right[a]\
    \ != -1) {\n                string l = (left[a] != -1 ? to_string(left[a]) : \"\
    l\" + to_string(a));\n                string r = (right[a] != -1 ? to_string(right[a])\
    \ : \"r\" + to_string(a));\n                oss << \"    \" << l << \" -> \" <<\
    \ a << endl;\n                oss << \"    \" << l << \" -> \" << r << \" [ style\
    \ = invis ]\" << endl;\n                oss << \"    \" << r << \" -> \" << a\
    \ << endl;\n                oss << \"    { rank = same; \" << l << \"; \" << r\
    \ << \"; }\" << endl;\n                if (left[a] == -1) oss << \"    \" << l\
    \ << \" [ style = invis ]\" << endl;\n                if (right[a] == -1) oss\
    \ << \"    \" << r << \" [ style = invis ]\" << endl;\n            }\n       \
    \     if (left[a] != -1) go(left[a]);\n            if (right[a] != -1) go(right[a]);\n\
    \        };\n        REP (a, parent.size()) if (not get_parent_edge_type(a)) {\n\
    \            go(a);\n        }\n        oss << \"}\";\n        return oss.str();\n\
    \    }\n};\n#line 2 \"modulus/mint.hpp\"\n#include <cstdint>\n#include <iostream>\n\
    #line 4 \"modulus/modpow.hpp\"\n\ninline int32_t modpow(uint_fast64_t x, uint64_t\
    \ k, int32_t MOD) {\n    assert (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n \
    \   uint_fast64_t y = 1;\n    for (; k; k >>= 1) {\n        if (k & 1) (y *= x)\
    \ %= MOD;\n        (x *= x) %= MOD;\n    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n\
    \    return y;\n}\n#line 5 \"modulus/modinv.hpp\"\n\ninline int32_t modinv_nocheck(int32_t\
    \ value, int32_t MOD) {\n    assert (0 <= value and value < MOD);\n    if (value\
    \ == 0) return -1;\n    int64_t a = value, b = MOD;\n    int64_t x = 0, y = 1;\n\
    \    for (int64_t u = 1, v = 0; a; ) {\n        int64_t q = b / a;\n        x\
    \ -= q * u; std::swap(x, u);\n        y -= q * v; std::swap(y, v);\n        b\
    \ -= q * a; std::swap(b, a);\n    }\n    if (not (value * x + MOD * y == b and\
    \ b == 1)) return -1;\n    if (x < 0) x += MOD;\n    assert (0 <= x and x < MOD);\n\
    \    return x;\n}\n\ninline int32_t modinv(int32_t x, int32_t MOD) {\n    int32_t\
    \ y = modinv_nocheck(x, MOD);\n    assert (y != -1);\n    return y;\n}\n#line\
    \ 6 \"modulus/mint.hpp\"\n\n/**\n * @brief quotient ring / \u5270\u4F59\u74B0\
    \ $\\mathbb{Z}/n\\mathbb{Z}$\n */\ntemplate <int32_t MOD>\nstruct mint {\n   \
    \ int32_t value;\n    mint() : value() {}\n    mint(int64_t value_) : value(value_\
    \ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}\n    mint(int32_t\
    \ value_, std::nullptr_t) : value(value_) {}\n    explicit operator bool() const\
    \ { return value; }\n    inline mint<MOD> operator + (mint<MOD> other) const {\
    \ return mint<MOD>(*this) += other; }\n    inline mint<MOD> operator - (mint<MOD>\
    \ other) const { return mint<MOD>(*this) -= other; }\n    inline mint<MOD> operator\
    \ * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }\n    inline\
    \ mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value\
    \ >= MOD) this->value -= MOD; return *this; }\n    inline mint<MOD> & operator\
    \ -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value\
    \ += MOD; return *this; }\n    inline mint<MOD> & operator *= (mint<MOD> other)\
    \ { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this;\
    \ }\n    inline mint<MOD> operator - () const { return mint<MOD>(this->value ?\
    \ MOD - this->value : 0, nullptr); }\n    inline bool operator == (mint<MOD> other)\
    \ const { return value == other.value; }\n    inline bool operator != (mint<MOD>\
    \ other) const { return value != other.value; }\n    inline mint<MOD> pow(uint64_t\
    \ k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }\n    inline mint<MOD>\
    \ inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }\n    inline mint<MOD>\
    \ operator / (mint<MOD> other) const { return *this * other.inv(); }\n    inline\
    \ mint<MOD> & operator /= (mint<MOD> other) { return *this *= other.inv(); }\n\
    };\ntemplate <int32_t MOD> mint<MOD> operator + (int64_t value, mint<MOD> n) {\
    \ return mint<MOD>(value) + n; }\ntemplate <int32_t MOD> mint<MOD> operator -\
    \ (int64_t value, mint<MOD> n) { return mint<MOD>(value) - n; }\ntemplate <int32_t\
    \ MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value)\
    \ * n; }\ntemplate <int32_t MOD> mint<MOD> operator / (int64_t value, mint<MOD>\
    \ n) { return mint<MOD>(value) / n; }\ntemplate <int32_t MOD> std::istream & operator\
    \ >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value;\
    \ return in; }\ntemplate <int32_t MOD> std::ostream & operator << (std::ostream\
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 3 \"monoids/linear_function.hpp\"\
    \n\ntemplate <class CommutativeRing>\nstruct linear_function_monoid {\n    typedef\
    \ std::pair<CommutativeRing, CommutativeRing> value_type;\n    linear_function_monoid()\
    \ = default;\n    value_type unit() const {\n        return std::make_pair(1,\
    \ 0);\n    }\n    value_type mult(value_type g, value_type f) const {\n      \
    \  CommutativeRing fst = g.first * f.first;\n        CommutativeRing snd = g.second\
    \ + g.first * f.second;\n        return std::make_pair(fst, snd);\n    }\n};\n\
    #line 2 \"monoids/dual.hpp\"\n\n/**\n * @see http://hackage.haskell.org/package/base/docs/Data-Monoid.html#t:Dual\n\
    \ */\ntemplate <class Monoid>\nstruct dual_monoid {\n    typedef typename Monoid::value_type\
    \ value_type;\n    Monoid base;\n    value_type unit() const { return base.unit();\
    \ }\n    value_type mult(const value_type & a, const value_type & b) const { return\
    \ base.mult(b, a); }\n};\n#line 3 \"hack/fastio.hpp\"\n#include <cstdio>\n#include\
    \ <string>\n#include <type_traits>\n\ntemplate <class Char, std::enable_if_t<std::is_same_v<Char,\
    \ char>, int> = 0>\ninline Char in() { return getchar_unlocked(); }\ntemplate\
    \ <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> =\
    \ 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked(); } while\
    \ (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while (not isspace(c\
    \ = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>\
    \ and not std::is_same_v<Integer, char>, int> = 0>\ninline Integer in() {\n  \
    \  char c; do { c = getchar_unlocked(); } while (isspace(c));\n    if (std::is_signed<Integer>::value\
    \ and c == '-') return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10\
    \ + c - '0'; } while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline void out(char c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n#line 8 \"data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n#include <stack>\n#line 10 \"data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n\nconstexpr int MOD = 998244353;\nint main() {\n    int n = in<int>();\n   \
    \ int q = in<int>();\n\n    // initialize\n    link_cut_tree<dual_monoid<linear_function_monoid<mint<MOD>\
    \ > > > lct(n);\n    REP (i, n) {\n        mint<MOD> a_i = in<int32_t>();\n  \
    \      mint<MOD> b_i = in<int32_t>();\n        lct.vertex_set(i, std::make_pair(a_i,\
    \ b_i));\n    }\n    std::vector<std::vector<int> > g(n);\n    REP (i, n - 1)\
    \ {\n        int u = in<int>();\n        int v = in<int>();\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    std::vector<bool> used(n);\n    std::stack<int>\
    \ stk;\n    stk.push(0);\n    used[0] = true;\n    while (not stk.empty()) {\n\
    \        int u = stk.top();\n        stk.pop();\n        for (int v : g[u]) if\
    \ (not used[v]) {\n            lct.link(v, u);\n            stk.push(v);\n   \
    \         used[v] = true;\n        }\n    }\n\n    // answer to queries\n    while\
    \ (q --) {\n        int t = in<int>();\n        if (t == 0) {\n            int\
    \ u = in<int>();\n            int v = in<int>();\n            int w = in<int>();\n\
    \            int x = in<int>();\n            lct.cut(lct.get_parent(u) == v ?\
    \ u : v);\n            lct.evert(w);\n            lct.link(w, x);\n        } else\
    \ if (t == 1) {\n            int u = in<int>();\n            mint<MOD> c = in<int32_t>();\n\
    \            mint<MOD> d = in<int32_t>();\n            lct.vertex_set(u, std::make_pair(c,\
    \ d));\n        } else if (t == 2) {\n            int u = in<int>();\n       \
    \     int v = in<int>();\n            mint<MOD> x = in<int32_t>();\n         \
    \   auto [a, b] = lct.path_get(u, v);\n            out<int32_t>((a * x + b).value);\n\
    \            out<char>('\\n');\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include \"data_structure/link_cut_tree.hpp\"\n#include \"modulus/mint.hpp\"\
    \n#include \"monoids/linear_function.hpp\"\n#include \"monoids/dual.hpp\"\n#include\
    \ \"utils/macros.hpp\"\n#include \"hack/fastio.hpp\"\n#include <stack>\n#include\
    \ <vector>\n\nconstexpr int MOD = 998244353;\nint main() {\n    int n = in<int>();\n\
    \    int q = in<int>();\n\n    // initialize\n    link_cut_tree<dual_monoid<linear_function_monoid<mint<MOD>\
    \ > > > lct(n);\n    REP (i, n) {\n        mint<MOD> a_i = in<int32_t>();\n  \
    \      mint<MOD> b_i = in<int32_t>();\n        lct.vertex_set(i, std::make_pair(a_i,\
    \ b_i));\n    }\n    std::vector<std::vector<int> > g(n);\n    REP (i, n - 1)\
    \ {\n        int u = in<int>();\n        int v = in<int>();\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    std::vector<bool> used(n);\n    std::stack<int>\
    \ stk;\n    stk.push(0);\n    used[0] = true;\n    while (not stk.empty()) {\n\
    \        int u = stk.top();\n        stk.pop();\n        for (int v : g[u]) if\
    \ (not used[v]) {\n            lct.link(v, u);\n            stk.push(v);\n   \
    \         used[v] = true;\n        }\n    }\n\n    // answer to queries\n    while\
    \ (q --) {\n        int t = in<int>();\n        if (t == 0) {\n            int\
    \ u = in<int>();\n            int v = in<int>();\n            int w = in<int>();\n\
    \            int x = in<int>();\n            lct.cut(lct.get_parent(u) == v ?\
    \ u : v);\n            lct.evert(w);\n            lct.link(w, x);\n        } else\
    \ if (t == 1) {\n            int u = in<int>();\n            mint<MOD> c = in<int32_t>();\n\
    \            mint<MOD> d = in<int32_t>();\n            lct.vertex_set(u, std::make_pair(c,\
    \ d));\n        } else if (t == 2) {\n            int u = in<int>();\n       \
    \     int v = in<int>();\n            mint<MOD> x = in<int32_t>();\n         \
    \   auto [a, b] = lct.path_get(u, v);\n            out<int32_t>((a * x + b).value);\n\
    \            out<char>('\\n');\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/link_cut_tree.hpp
  - utils/macros.hpp
  - monoids/reversible.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  - monoids/linear_function.hpp
  - monoids/dual.hpp
  - hack/fastio.hpp
  isVerificationFile: true
  path: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2020-07-16 00:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp.html
title: data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp
---
