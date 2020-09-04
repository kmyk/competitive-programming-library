---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n#line 2 \"data_structure/lazy_propagation_segment_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 7 \"data_structure/lazy_propagation_segment_tree.hpp\"\n\n/**\n * @brief Lazy\
    \ Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs data_structure/lazy_propagation_segment_tree.md\n\
    \ * @tparam MonoidX is a monoid\n * @tparam MonoidF is a monoid\n * @tparam Action\
    \ is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X\
    \ is a homomorphism on X\n */\ntemplate <class MonoidX, class MonoidF, class Action>\n\
    struct lazy_propagation_segment_tree {\n    static_assert (std::is_invocable_r<typename\
    \ MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value,\
    \ \"\");\n    typedef typename MonoidX::value_type value_type;\n    typedef typename\
    \ MonoidF::value_type operator_type;\n    const MonoidX mon_x;\n    const MonoidF\
    \ mon_f;\n    const Action act;\n    int n;\n    std::vector<value_type> a;\n\
    \    std::vector<operator_type> f;\n\n    lazy_propagation_segment_tree() = default;\n\
    \    lazy_propagation_segment_tree(int n_, const MonoidX & mon_x_ = MonoidX(),\
    \ const MonoidF & mon_f_ = MonoidF(), const Action & act_ = Action())\n      \
    \      : mon_x(mon_x_), mon_f(mon_f_), act(act_) {\n        n = 1; while (n <\
    \ n_) n *= 2;\n        a.resize(2 * n - 1, mon_x.unit());\n        f.resize(n\
    \ - 1, mon_f.unit());\n    }\n    template <class InputIterator>\n    lazy_propagation_segment_tree(InputIterator\
    \ first, InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF\
    \ & mon_f_ = MonoidF(), const Action & act_ = Action())\n            : mon_x(mon_x_),\
    \ mon_f(mon_f_), act(act_) {\n        int size = std::distance(first, last);\n\
    \        n = 1; while (n < size) n *= 2;\n        a.resize(2 * n - 1, mon_x.unit());\n\
    \        f.resize(n - 1, mon_f.unit());\n        std::copy(first, last, a.begin()\
    \ + (n - 1));\n        REP_R (i, n - 1) {\n            a[i] = mon_x.mult(a[2 *\
    \ i + 1], a[2 * i + 2]);\n        }\n    }\n\n    void point_set(int i, value_type\
    \ b) {\n        range_set(i, i + 1, b);\n    }\n    /**\n     * @note O(min(n,\
    \ (r - l) log n))\n     */\n    void range_set(int l, int r, value_type b) {\n\
    \        assert (0 <= l and l <= r and r <= n);\n        range_set(0, 0, n, l,\
    \ r, b);\n    }\n    void range_set(int i, int il, int ir, int l, int r, value_type\
    \ b) {\n        if (l <= il and ir <= r and ir - il == 1) {  // 0-based\n    \
    \        a[i] = b;\n        } else if (ir <= l or r <= il) {\n            // nop\n\
    \        } else {\n            range_apply(2 * i + 1, il, (il + ir) / 2, 0, n,\
    \ f[i]);\n            range_apply(2 * i + 2, (il + ir) / 2, ir, 0, n, f[i]);\n\
    \            f[i] = mon_f.unit();\n            range_set(2 * i + 1, il, (il +\
    \ ir) / 2, l, r, b);\n            range_set(2 * i + 2, (il + ir) / 2, ir, l, r,\
    \ b);\n            a[i] = mon_x.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n\
    \    }\n\n    void point_apply(int i, operator_type g) {\n        range_apply(i,\
    \ i + 1, g);\n    }\n    void range_apply(int l, int r, operator_type g) {\n \
    \       assert (0 <= l and l <= r and r <= n);\n        range_apply(0, 0, n, l,\
    \ r, g);\n    }\n    void range_apply(int i, int il, int ir, int l, int r, operator_type\
    \ g) {\n        if (l <= il and ir <= r) { // 0-based\n            a[i] = act(g,\
    \ a[i]);\n            if (i < f.size()) f[i] = mon_f.mult(g, f[i]);\n        }\
    \ else if (ir <= l or r <= il) {\n            // nop\n        } else {\n     \
    \       range_apply(2 * i + 1, il, (il + ir) / 2, 0, n, f[i]);\n            range_apply(2\
    \ * i + 2, (il + ir) / 2, ir, 0, n, f[i]);\n            f[i] = mon_f.unit(); \
    \ // unnecessary if the oprator monoid is commutative\n            range_apply(2\
    \ * i + 1, il, (il + ir) / 2, l, r, g);\n            range_apply(2 * i + 2, (il\
    \ + ir) / 2, ir, l, r, g);\n            a[i] = mon_x.mult(a[2 * i + 1], a[2 *\
    \ i + 2]);\n        }\n    }\n\n    value_type point_get(int i) {\n        return\
    \ range_get(i, i + 1);\n    }\n    value_type range_get(int l, int r) {\n    \
    \    assert (0 <= l and l <= r and r <= n);\n        if (l == 0 and r == n) return\
    \ a[0];\n        value_type lacc = mon_x.unit(), racc = mon_x.unit();\n      \
    \  for (int l1 = (l += n), r1 = (r += n) - 1; l1 > 1; l /= 2, r /= 2, l1 /= 2,\
    \ r1 /= 2) {  // 1-based loop, 2x faster than recursion\n            if (l < r)\
    \ {\n                if (l % 2 == 1) lacc = mon_x.mult(lacc, a[(l ++) - 1]);\n\
    \                if (r % 2 == 1) racc = mon_x.mult(a[(-- r) - 1], racc);\n   \
    \         }\n            lacc = act(f[l1 / 2 - 1], lacc);\n            racc =\
    \ act(f[r1 / 2 - 1], racc);\n        }\n        return mon_x.mult(lacc, racc);\n\
    \    }\n};\n#line 3 \"monoids/min.hpp\"\n#include <limits>\n\ntemplate <class\
    \ T>\nstruct min_monoid {\n    typedef T value_type;\n    value_type unit() const\
    \ { return std::numeric_limits<T>::max(); }\n    value_type mult(value_type a,\
    \ value_type b) const { return std::min(a, b); }\n};\n#line 2 \"monoids/plus.hpp\"\
    \n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return value_type(); }\n    value_type mult(value_type a, value_type\
    \ b) const { return a + b; }\n};\n#line 4 \"monoids/plus_min_action.hpp\"\n\n\
    template <class T>\nstruct plus_min_action {\n    typename min_monoid<T>::value_type\
    \ operator () (typename plus_monoid<T>::value_type f, typename min_monoid<T>::value_type\
    \ x) const {\n        return (x == min_monoid<T>().unit() ? x : f + x);\n    }\n\
    };\n#line 6 \"data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp\"\
    \n#include <cstdio>\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n\
    \    lazy_propagation_segment_tree<min_monoid<int>, plus_monoid<int>, plus_min_action<int>\
    \ > segtree(n);\n    segtree.range_set(0, n, 0);\n    while (q --) {\n       \
    \ int com, l, r; scanf(\"%d%d%d\", &com, &l, &r);\n        ++ r;\n        if (com\
    \ == 0) {\n            int x; scanf(\"%d\", &x);\n            segtree.range_apply(l,\
    \ r, x);\n        } else if (com == 1) {\n            printf(\"%d\\n\", segtree.range_get(l,\
    \ r));\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n#include \"data_structure/lazy_propagation_segment_tree.hpp\"\n#include \"monoids/min.hpp\"\
    \n#include \"monoids/plus.hpp\"\n#include \"monoids/plus_min_action.hpp\"\n#include\
    \ <cstdio>\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n    lazy_propagation_segment_tree<min_monoid<int>,\
    \ plus_monoid<int>, plus_min_action<int> > segtree(n);\n    segtree.range_set(0,\
    \ n, 0);\n    while (q --) {\n        int com, l, r; scanf(\"%d%d%d\", &com, &l,\
    \ &r);\n        ++ r;\n        if (com == 0) {\n            int x; scanf(\"%d\"\
    , &x);\n            segtree.range_apply(l, r, x);\n        } else if (com == 1)\
    \ {\n            printf(\"%d\\n\", segtree.range_get(l, r));\n        }\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - data_structure/lazy_propagation_segment_tree.hpp
  - utils/macros.hpp
  - monoids/min.hpp
  - monoids/plus.hpp
  - monoids/plus_min_action.hpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.hpp
    title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus_min_action.hpp
    title: monoids/plus_min_action.hpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
  requiredBy: []
  timestamp: '2020-03-08 03:43:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
layout: document
redirect_from:
- /verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
- /verify/data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp.html
title: data_structure/lazy_propagation_segment_tree.range_min_range_add.test.cpp
---
