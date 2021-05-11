---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/euler_tour_subtree_query.hpp
    title: Euler Tour (subtree queries, with commutative monoids)
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour_preorder.hpp
    title: Euler Tour (preorder)
  - icon: ':heavy_check_mark:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 2 \"data_structure/euler_tour_subtree_query.hpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"graph/euler_tour_preorder.hpp\"\
    \n#include <functional>\n#line 4 \"graph/euler_tour_preorder.hpp\"\n\n/**\n *\
    \ @brief Euler Tour (preorder)\n * @arg g must be a rooted tree, directed or undirected\n\
    \ */\nvoid do_euler_tour_preorder(std::vector<std::vector<int> > const & g, int\
    \ root, std::vector<int> & tour, std::vector<int> & left, std::vector<int> & right)\
    \ {\n    int n = g.size();\n    tour.clear();\n    left.assign(n, -1);\n    right.assign(n,\
    \ -1);\n    std::function<void (int, int)> go = [&](int x, int parent) {\n   \
    \     left[x] = tour.size();\n        tour.push_back(x);\n        for (int y :\
    \ g[x]) if (y != parent) {\n            go(y, x);\n        }\n        right[x]\
    \ = tour.size();\n    };\n    go(root, -1);\n}\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n#include <algorithm>\n#line 6 \"data_structure/segment_tree.hpp\"\n\n/**\n *\
    \ @brief Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
    \u4E8C\u5206\u6728)\n * @docs data_structure/segment_tree.md\n * @tparam Monoid\
    \ (commutativity is not required)\n */\ntemplate <class Monoid>\nstruct segment_tree\
    \ {\n    typedef typename Monoid::value_type value_type;\n    Monoid mon;\n  \
    \  int n;\n    std::vector<value_type> a;\n    segment_tree() = default;\n   \
    \ segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {\n       \
    \ n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n  \
    \  }\n    void point_set(int i, value_type b) {  // 0-based\n        assert (0\
    \ <= i and i < n);\n        a[i + n - 1] = b;\n        for (i = (i + n) / 2; i\
    \ > 0; i /= 2) {  // 1-based\n            a[i - 1] = mon.mult(a[2 * i - 1], a[2\
    \ * i]);\n        }\n    }\n    value_type range_get(int l, int r) {  // 0-based,\
    \ [l, r)\n        assert (0 <= l and l <= r and r <= n);\n        value_type lacc\
    \ = mon.unit(), racc = mon.unit();\n        for (l += n, r += n; l < r; l /= 2,\
    \ r /= 2) {  // 1-based loop, 2x faster than recursion\n            if (l % 2\
    \ == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);\n            if (r % 2 == 1) racc\
    \ = mon.mult(a[(-- r) - 1], racc);\n        }\n        return mon.mult(lacc, racc);\n\
    \    }\n\n    value_type point_get(int i) {  // 0-based\n        assert (0 <=\
    \ i and i < n);\n        return a[i + n - 1];\n    }\n\n    /**\n     * @note\
    \ O(min(n, (r - l) log n))\n     */\n    void range_set(int l, int r, value_type\
    \ b) {\n        assert (0 <= l and l <= r and r <= n);\n        range_set(0, 0,\
    \ n, l, r, b);\n    }\n    void range_set(int i, int il, int ir, int l, int r,\
    \ value_type b) {\n        if (l <= il and ir <= r and ir - il == 1) {  // 0-based\n\
    \            a[i] = b;\n        } else if (ir <= l or r <= il) {\n           \
    \ // nop\n        } else {\n            range_set(2 * i + 1, il, (il + ir) / 2,\
    \ l, r, b);\n            range_set(2 * i + 2, (il + ir) / 2, ir, l, r, b);\n \
    \           a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n    }\n\n\
    \    /**\n     * @brief a fast & semigroup-friendly version constructor\n    \
    \ * @note $O(n)$\n     */\n    template <class InputIterator>\n    segment_tree(InputIterator\
    \ first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {\n \
    \       int size = std::distance(first, last);\n        n = 1; while (n < size)\
    \ n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n        std::copy(first,\
    \ last, a.begin() + (n - 1));\n        unsafe_rebuild();\n    }\n    /**\n   \
    \  * @brief update a leaf node without updating ancestors\n     * @note $O(1)$\n\
    \     */\n    void unsafe_point_set(int i, value_type b) {  // 0-based\n     \
    \   assert (0 <= i and i < n);\n        a[i + n - 1] = b;\n    }\n    /**\n  \
    \   * @brief re-build non-leaf nodes from leaf nodes\n     * @note $O(n)$\n  \
    \   */\n    void unsafe_rebuild() {\n        REP_R (i, n - 1) {\n            a[i]\
    \ = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n    }\n};\n#line 7 \"data_structure/euler_tour_subtree_query.hpp\"\
    \n\n/**\n * @brief Euler Tour (subtree queries, with commutative monoids)\n *\
    \ @docs data_structure/euler_tour_subtree_query.md\n */\ntemplate <class CommutativeMonoid>\n\
    class euler_tour_subtree_query {\n    typedef typename CommutativeMonoid::value_type\
    \ value_type;\n    segment_tree<CommutativeMonoid> data;\n    std::vector<int>\
    \ left, right;\n\npublic:\n    euler_tour_subtree_query(const std::vector<std::vector<int>\
    \ > & g, int root, const CommutativeMonoid & mon_ = CommutativeMonoid())\n   \
    \         : data(g.size(), mon_) {\n        std::vector<int> tour;\n        do_euler_tour_preorder(g,\
    \ root, tour, left, right);\n    }\n    template <class InputIterator>\n    euler_tour_subtree_query(const\
    \ std::vector<std::vector<int> > & g, int root, InputIterator first, InputIterator\
    \ last, const CommutativeMonoid & mon_ = CommutativeMonoid())\n            : data(std::distance(first,\
    \ last), mon_) {\n        assert ((int)g.size() == std::distance(first, last));\n\
    \        std::vector<int> tour;\n        do_euler_tour_preorder(g, root, tour,\
    \ left, right);\n        REP (x, g.size()) {\n            data.unsafe_point_set(left[x],\
    \ *(first ++));\n        }\n        data.unsafe_rebuild();\n    }\n\n    void\
    \ vertex_set(int x, value_type a) {\n        assert (0 <= x and x < (int)left.size());\n\
    \        return data.point_set(left[x], a);\n    }\n    value_type vertex_get(int\
    \ x) {\n        assert (0 <= x and x < (int)left.size());\n        return data.point_get(left[x]);\n\
    \    }\n    value_type subtree_get(int x) {\n        assert (0 <= x and x < (int)left.size());\n\
    \        return data.range_get(left[x], right[x]);\n    }\n};\n#line 2 \"monoids/plus.hpp\"\
    \n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return value_type(); }\n    value_type mult(value_type a, value_type\
    \ b) const { return a + b; }\n};\n#line 2 \"hack/fastio.hpp\"\n#include <cstdint>\n\
    #include <cstdio>\n#include <string>\n#include <type_traits>\n\ntemplate <class\
    \ Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\ninline Char in()\
    \ { return getchar_unlocked(); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked();\
    \ } while (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while\
    \ (not isspace(c = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer,\
    \ std::enable_if_t<std::is_integral_v<Integer> and not std::is_same_v<Integer,\
    \ char>, int> = 0>\ninline Integer in() {\n    char c; do { c = getchar_unlocked();\
    \ } while (isspace(c));\n    if (std::is_signed<Integer>::value and c == '-')\
    \ return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10 + c - '0'; }\
    \ while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\ntemplate <class\
    \ Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\ninline void out(char\
    \ c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n#line 7 \"data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n = in<int>();\n    int q = in<int>();\n\
    \n    // initialize\n    vector<int64_t> a(n);\n    REP (i, n) {\n        a[i]\
    \ = in<int64_t>();\n    }\n    vector<vector<int> > g(n);\n    REP3 (i, 1, n)\
    \ {\n        int p_i = in<int>();\n        g[i].push_back(p_i);\n        g[p_i].push_back(i);\n\
    \    }\n    constexpr int root = 0;\n    euler_tour_subtree_query<plus_monoid<int64_t>\
    \ > euler(g, root, ALL(a));\n\n    // answer to queries\n    while (q --) {\n\
    \        int t = in<int>();\n        if (t == 0) {\n            int u = in<int>();\n\
    \            int64_t x = in<int64_t>();\n            euler.vertex_set(u, euler.vertex_get(u)\
    \ + x);\n        } else if (t == 1) {\n            int u = in<int>();\n      \
    \      out<int64_t>(euler.subtree_get(u));\n            out<char>('\\n');\n  \
    \      }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"data_structure/euler_tour_subtree_query.hpp\"\n#include \"monoids/plus.hpp\"\
    \n#include \"utils/macros.hpp\"\n#include \"hack/fastio.hpp\"\n#include <vector>\n\
    using namespace std;\n\nint main() {\n    int n = in<int>();\n    int q = in<int>();\n\
    \n    // initialize\n    vector<int64_t> a(n);\n    REP (i, n) {\n        a[i]\
    \ = in<int64_t>();\n    }\n    vector<vector<int> > g(n);\n    REP3 (i, 1, n)\
    \ {\n        int p_i = in<int>();\n        g[i].push_back(p_i);\n        g[p_i].push_back(i);\n\
    \    }\n    constexpr int root = 0;\n    euler_tour_subtree_query<plus_monoid<int64_t>\
    \ > euler(g, root, ALL(a));\n\n    // answer to queries\n    while (q --) {\n\
    \        int t = in<int>();\n        if (t == 0) {\n            int u = in<int>();\n\
    \            int64_t x = in<int64_t>();\n            euler.vertex_set(u, euler.vertex_get(u)\
    \ + x);\n        } else if (t == 1) {\n            int u = in<int>();\n      \
    \      out<int64_t>(euler.subtree_get(u));\n            out<char>('\\n');\n  \
    \      }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/euler_tour_subtree_query.hpp
  - utils/macros.hpp
  - graph/euler_tour_preorder.hpp
  - data_structure/segment_tree.hpp
  - monoids/plus.hpp
  - hack/fastio.hpp
  isVerificationFile: true
  path: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 23:22:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
- /verify/data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp.html
title: data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp
---
