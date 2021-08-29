---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_segment_tree.hpp
    title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus_min_action.hpp
    title: monoids/plus_min_action.hpp
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: utils/mo_algorithm.hpp
    title: utils/mo_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1270
    links:
    - https://yukicoder.me/problems/no/1270
  bundledCode: "#line 1 \"utils/mo_algorithm.yuki1270.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1270\"\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\
    #line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n);\
    \ ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 6 \"data_structure/segment_tree.hpp\"\n\n/**\n * @brief Segment\
    \ Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\
    \u6728)\n * @docs data_structure/segment_tree.md\n * @tparam Monoid (commutativity\
    \ is not required)\n */\ntemplate <class Monoid>\nstruct segment_tree {\n    typedef\
    \ typename Monoid::value_type value_type;\n    Monoid mon;\n    int n;\n    std::vector<value_type>\
    \ a;\n    segment_tree() = default;\n    segment_tree(int n_, const Monoid & mon_\
    \ = Monoid()) : mon(mon_) {\n        n = 1; while (n < n_) n *= 2;\n        a.resize(2\
    \ * n - 1, mon.unit());\n    }\n    void point_set(int i, value_type b) {  //\
    \ 0-based\n        assert (0 <= i and i < n);\n        a[i + n - 1] = b;\n   \
    \     for (i = (i + n) / 2; i > 0; i /= 2) {  // 1-based\n            a[i - 1]\
    \ = mon.mult(a[2 * i - 1], a[2 * i]);\n        }\n    }\n    value_type range_get(int\
    \ l, int r) {  // 0-based, [l, r)\n        assert (0 <= l and l <= r and r <=\
    \ n);\n        value_type lacc = mon.unit(), racc = mon.unit();\n        for (l\
    \ += n, r += n; l < r; l /= 2, r /= 2) {  // 1-based loop, 2x faster than recursion\n\
    \            if (l % 2 == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);\n         \
    \   if (r % 2 == 1) racc = mon.mult(a[(-- r) - 1], racc);\n        }\n       \
    \ return mon.mult(lacc, racc);\n    }\n\n    value_type point_get(int i) {  //\
    \ 0-based\n        assert (0 <= i and i < n);\n        return a[i + n - 1];\n\
    \    }\n\n    /**\n     * @note O(min(n, (r - l) log n))\n     */\n    void range_set(int\
    \ l, int r, value_type b) {\n        assert (0 <= l and l <= r and r <= n);\n\
    \        range_set(0, 0, n, l, r, b);\n    }\n    void range_set(int i, int il,\
    \ int ir, int l, int r, value_type b) {\n        if (l <= il and ir <= r and ir\
    \ - il == 1) {  // 0-based\n            a[i] = b;\n        } else if (ir <= l\
    \ or r <= il) {\n            // nop\n        } else {\n            range_set(2\
    \ * i + 1, il, (il + ir) / 2, l, r, b);\n            range_set(2 * i + 2, (il\
    \ + ir) / 2, ir, l, r, b);\n            a[i] = mon.mult(a[2 * i + 1], a[2 * i\
    \ + 2]);\n        }\n    }\n\n    /**\n     * @brief a fast & semigroup-friendly\
    \ version constructor\n     * @note $O(n)$\n     */\n    template <class InputIterator>\n\
    \    segment_tree(InputIterator first, InputIterator last, const Monoid & mon_\
    \ = Monoid()) : mon(mon_) {\n        int size = std::distance(first, last);\n\
    \        n = 1; while (n < size) n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n\
    \        std::copy(first, last, a.begin() + (n - 1));\n        unsafe_rebuild();\n\
    \    }\n    /**\n     * @brief update a leaf node without updating ancestors\n\
    \     * @note $O(1)$\n     */\n    void unsafe_point_set(int i, value_type b)\
    \ {  // 0-based\n        assert (0 <= i and i < n);\n        a[i + n - 1] = b;\n\
    \    }\n    /**\n     * @brief re-build non-leaf nodes from leaf nodes\n     *\
    \ @note $O(n)$\n     */\n    void unsafe_rebuild() {\n        REP_R (i, n - 1)\
    \ {\n            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n        }\n   \
    \ }\n};\n#line 4 \"data_structure/lazy_propagation_segment_tree.hpp\"\n#include\
    \ <type_traits>\n#line 7 \"data_structure/lazy_propagation_segment_tree.hpp\"\n\
    \n/**\n * @brief Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @docs\
    \ data_structure/lazy_propagation_segment_tree.md\n * @tparam MonoidX is a monoid\n\
    \ * @tparam MonoidF is a monoid\n * @tparam Action is a function phi : F * X ->\
    \ X where the partial applied phi(f, -) : X -> X is a homomorphism on X\n */\n\
    template <class MonoidX, class MonoidF, class Action>\nstruct lazy_propagation_segment_tree\
    \ {\n    static_assert (std::is_invocable_r<typename MonoidX::value_type, Action,\
    \ typename MonoidF::value_type, typename MonoidX::value_type>::value, \"\");\n\
    \    typedef typename MonoidX::value_type value_type;\n    typedef typename MonoidF::value_type\
    \ operator_type;\n    MonoidX mon_x;\n    MonoidF mon_f;\n    Action act;\n  \
    \  int n;\n    std::vector<value_type> a;\n    std::vector<operator_type> f;\n\
    \n    lazy_propagation_segment_tree() = default;\n    lazy_propagation_segment_tree(int\
    \ n_, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_ = MonoidF(),\
    \ const Action & act_ = Action())\n            : mon_x(mon_x_), mon_f(mon_f_),\
    \ act(act_) {\n        n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n -\
    \ 1, mon_x.unit());\n        f.resize(n - 1, mon_f.unit());\n    }\n    template\
    \ <class InputIterator>\n    lazy_propagation_segment_tree(InputIterator first,\
    \ InputIterator last, const MonoidX & mon_x_ = MonoidX(), const MonoidF & mon_f_\
    \ = MonoidF(), const Action & act_ = Action())\n            : mon_x(mon_x_), mon_f(mon_f_),\
    \ act(act_) {\n        int size = std::distance(first, last);\n        n = 1;\
    \ while (n < size) n *= 2;\n        a.resize(2 * n - 1, mon_x.unit());\n     \
    \   f.resize(n - 1, mon_f.unit());\n        std::copy(first, last, a.begin() +\
    \ (n - 1));\n        REP_R (i, n - 1) {\n            a[i] = mon_x.mult(a[2 * i\
    \ + 1], a[2 * i + 2]);\n        }\n    }\n\n    void point_set(int i, value_type\
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
    };\n#line 3 \"utils/mo_algorithm.hpp\"\n#include <cmath>\n#include <numeric>\n\
    #include <tuple>\n#line 8 \"utils/mo_algorithm.hpp\"\n\n// struct mo_struct {\n\
    //     typedef int64_t value_type;\n//     typedef int64_t result_type;\n//  \
    \   void add_right(int nr, value_type x_r) {\n//     }\n//     void add_left(int\
    \ nl, value_type x_nl) {\n//     }\n//     void remove_right(int nr, value_type\
    \ x_nr) {\n//     }\n//     void remove_left(int nl, value_type x_l) {\n//   \
    \  }\n//     result_type query() {\n//         return 0;\n//     }\n// };\n\n\
    template <class Mo>\nstd::vector<typename Mo::result_type> run_mo_algorithm(Mo\
    \ mo, const std::vector<typename Mo::value_type>& values, const std::vector<std::pair<int,\
    \ int> >& queries) {\n    int n = values.size();\n    int m = queries.size();\n\
    \n    // sort queries\n    int sq_n = std::sqrt(n);\n    std::vector<int> order(m);\n\
    \    std::iota(ALL(order), 0);\n    std::sort(ALL(order), [&](int i, int j) {\n\
    \        int l_i, r_i; std::tie(l_i, r_i) = queries[i];\n        int l_j, r_j;\
    \ std::tie(l_j, r_j) = queries[j];\n        return std::make_pair(l_i / sq_n,\
    \ r_i) < std::make_pair(l_j / sq_n, r_j);\n    });\n\n    // compute queries\n\
    \    std::vector<typename Mo::result_type> ans(m);\n    int l = 0;\n    int r\
    \ = 0;\n    for (int j : order) {\n        int nl, nr; std::tie(nl, nr) = queries[j];\n\
    \        for (; r < nr; ++ r) mo.add_right(r + 1, values[r]);\n        for (;\
    \ nl < l; -- l) mo.add_left(l - 1, values[l - 1]);\n        for (; nr < r; --\
    \ r) mo.remove_right(r - 1, values[r - 1]);\n        for (; l < nl; ++ l) mo.remove_left(l\
    \ + 1, values[l]);\n        ans[j] = mo.query();\n    }\n    return ans;\n}\n\
    #line 15 \"utils/mo_algorithm.yuki1270.test.cpp\"\nusing namespace std;\n\n\n\
    struct mo_struct {\n    typedef int64_t value_type;\n    typedef int64_t result_type;\n\
    \nprivate:\n    typedef segment_tree<plus_monoid<int> > plus_segtree_type;\n \
    \   typedef lazy_propagation_segment_tree<min_monoid<int64_t>, plus_monoid<int64_t>,\
    \ plus_min_action<int64_t> > plus_min_segtree_type;\n\n    // input\n    int n;\n\
    \    const vector<int64_t>& a;\n\n    // static\n    unordered_map<int64_t, int>\
    \ compress;\n    int k;\n    vector<int64_t> dp_l;\n    vector<int64_t> dp_r;\n\
    \n    // dynamic\n    int l;\n    int r;\n    int64_t value_lr;\n    plus_segtree_type\
    \ segtree_l;\n    plus_min_segtree_type segtree_m;\n    plus_segtree_type segtree_r;\n\
    \npublic:\n    mo_struct(const vector<int64_t>& a_)\n            : n(a_.size())\n\
    \            , a(a_) {\n        // static compress\n        vector<int64_t> sorted_a\
    \ = a;\n        sort(ALL(sorted_a));\n        for (int64_t a_i : sorted_a) {\n\
    \            compress.emplace(a_i, compress.size());\n        }\n        k = compress.size();\n\
    \n        // static left\n        dp_l.resize(n + 1);\n        segtree_l = plus_segtree_type(k);\n\
    \        segtree_l.range_set(0, k, 0);\n        REP (i, n) {\n            dp_l[i\
    \ + 1] = dp_l[i] + segtree_l.range_get(compress[a[i]] + 1, k);\n            segtree_l.point_set(compress[a[i]],\
    \ segtree_l.point_get(compress[a[i]]) + 1);\n        }\n        segtree_l = plus_segtree_type(k);\n\
    \        segtree_l.range_set(0, k, 0);\n\n        // static right\n        dp_r.resize(n\
    \ + 1);\n        segtree_r = plus_segtree_type(k);\n        segtree_r.range_set(0,\
    \ k, 0);\n        REP_R (i, n) {\n            dp_r[i] = dp_r[i + 1] + segtree_r.range_get(0,\
    \ compress[a[i]]);\n            segtree_r.point_set(compress[a[i]], segtree_r.point_get(compress[a[i]])\
    \ + 1);\n        }\n\n        // dynamic\n        l = 0;\n        r = 0;\n   \
    \     value_lr = 0;\n        segtree_m = plus_min_segtree_type(k);\n        segtree_m.range_set(0,\
    \ k, 0);\n        REP (i, n) {\n            segtree_m.range_apply(compress[a[i]]\
    \ + 1, k, 1);\n        }\n    }\n\n    void add_right(int nr, int64_t x_r) {\n\
    \        assert (nr == r + 1);\n        int y = compress[x_r];\n        value_lr\
    \ -= segtree_l.range_get(y + 1, k);\n        segtree_m.range_apply(y + 1, k, -1);\n\
    \        segtree_r.point_set(y, segtree_r.point_get(y) - 1);\n        r = nr;\n\
    \    }\n\n    void add_left(int nl, int64_t x_nl) {\n        assert (nl == l -\
    \ 1);\n        int y = compress[x_nl];\n        value_lr -= segtree_r.range_get(0,\
    \ y);\n        segtree_l.point_set(y, segtree_l.point_get(y) - 1);\n        segtree_m.range_apply(0,\
    \ y, -1);\n        l = nl;\n    }\n\n    void remove_right(int nr, int64_t x_nr)\
    \ {\n        assert (nr == r - 1);\n        int y = compress[x_nr];\n        value_lr\
    \ += segtree_l.range_get(y + 1, k);\n        segtree_m.range_apply(y + 1, k, 1);\n\
    \        segtree_r.point_set(y, segtree_r.point_get(y) + 1);\n        r = nr;\n\
    \    }\n\n    void remove_left(int nl, int64_t x_l) {\n        assert (nl == l\
    \ + 1);\n        int y = compress[x_l];\n        value_lr += segtree_r.range_get(0,\
    \ y);\n        segtree_l.point_set(y, segtree_l.point_get(y) + 1);\n        segtree_m.range_apply(0,\
    \ y, 1);\n        l = nl;\n    }\n\n    int64_t query() {\n        int64_t ans\
    \ = 0;\n        ans += dp_l[l];  // the inversion number in [0, l)\n        ans\
    \ += dp_r[r];  // the inversion number in [r, n)\n        ans += value_lr;  //\
    \ the inversion number between [0, l) and [r, n)\n        ans += (int64_t)(r -\
    \ l) * segtree_m.range_get(0, k);  // the inversion number between [0, l) and\
    \ [l, r) plus the inversion number between [l, r) and [r, n)\n        return ans;\n\
    \    }\n};\n\nvector<int64_t> solve(int n, int q, const vector<int64_t>& a, const\
    \ vector<pair<int, int> >& queries) {\n    return run_mo_algorithm(mo_struct(a),\
    \ a, queries);\n}\n\nint main() {\n    int n, q; cin >> n >> q;\n    vector<int64_t>\
    \ a(n);\n    REP (i, n) {\n        cin >> a[i];\n    }\n    vector<pair<int, int>\
    \ > queries(q);\n    REP (i, q) {\n        int l, r; cin >> l >> r;\n        --\
    \ l;\n        queries[i] = make_pair(l, r);\n    }\n    auto ans = solve(n, q,\
    \ a, queries);\n    REP (i, q) {\n        cout << ans[i] << endl;\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1270\"\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <unordered_map>\n#include <utility>\n\
    #include <vector>\n#include \"../utils/macros.hpp\"\n#include \"../data_structure/segment_tree.hpp\"\
    \n#include \"../data_structure/lazy_propagation_segment_tree.hpp\"\n#include \"\
    ../monoids/min.hpp\"\n#include \"../monoids/plus.hpp\"\n#include \"../monoids/plus_min_action.hpp\"\
    \n#include \"../utils/mo_algorithm.hpp\"\nusing namespace std;\n\n\nstruct mo_struct\
    \ {\n    typedef int64_t value_type;\n    typedef int64_t result_type;\n\nprivate:\n\
    \    typedef segment_tree<plus_monoid<int> > plus_segtree_type;\n    typedef lazy_propagation_segment_tree<min_monoid<int64_t>,\
    \ plus_monoid<int64_t>, plus_min_action<int64_t> > plus_min_segtree_type;\n\n\
    \    // input\n    int n;\n    const vector<int64_t>& a;\n\n    // static\n  \
    \  unordered_map<int64_t, int> compress;\n    int k;\n    vector<int64_t> dp_l;\n\
    \    vector<int64_t> dp_r;\n\n    // dynamic\n    int l;\n    int r;\n    int64_t\
    \ value_lr;\n    plus_segtree_type segtree_l;\n    plus_min_segtree_type segtree_m;\n\
    \    plus_segtree_type segtree_r;\n\npublic:\n    mo_struct(const vector<int64_t>&\
    \ a_)\n            : n(a_.size())\n            , a(a_) {\n        // static compress\n\
    \        vector<int64_t> sorted_a = a;\n        sort(ALL(sorted_a));\n       \
    \ for (int64_t a_i : sorted_a) {\n            compress.emplace(a_i, compress.size());\n\
    \        }\n        k = compress.size();\n\n        // static left\n        dp_l.resize(n\
    \ + 1);\n        segtree_l = plus_segtree_type(k);\n        segtree_l.range_set(0,\
    \ k, 0);\n        REP (i, n) {\n            dp_l[i + 1] = dp_l[i] + segtree_l.range_get(compress[a[i]]\
    \ + 1, k);\n            segtree_l.point_set(compress[a[i]], segtree_l.point_get(compress[a[i]])\
    \ + 1);\n        }\n        segtree_l = plus_segtree_type(k);\n        segtree_l.range_set(0,\
    \ k, 0);\n\n        // static right\n        dp_r.resize(n + 1);\n        segtree_r\
    \ = plus_segtree_type(k);\n        segtree_r.range_set(0, k, 0);\n        REP_R\
    \ (i, n) {\n            dp_r[i] = dp_r[i + 1] + segtree_r.range_get(0, compress[a[i]]);\n\
    \            segtree_r.point_set(compress[a[i]], segtree_r.point_get(compress[a[i]])\
    \ + 1);\n        }\n\n        // dynamic\n        l = 0;\n        r = 0;\n   \
    \     value_lr = 0;\n        segtree_m = plus_min_segtree_type(k);\n        segtree_m.range_set(0,\
    \ k, 0);\n        REP (i, n) {\n            segtree_m.range_apply(compress[a[i]]\
    \ + 1, k, 1);\n        }\n    }\n\n    void add_right(int nr, int64_t x_r) {\n\
    \        assert (nr == r + 1);\n        int y = compress[x_r];\n        value_lr\
    \ -= segtree_l.range_get(y + 1, k);\n        segtree_m.range_apply(y + 1, k, -1);\n\
    \        segtree_r.point_set(y, segtree_r.point_get(y) - 1);\n        r = nr;\n\
    \    }\n\n    void add_left(int nl, int64_t x_nl) {\n        assert (nl == l -\
    \ 1);\n        int y = compress[x_nl];\n        value_lr -= segtree_r.range_get(0,\
    \ y);\n        segtree_l.point_set(y, segtree_l.point_get(y) - 1);\n        segtree_m.range_apply(0,\
    \ y, -1);\n        l = nl;\n    }\n\n    void remove_right(int nr, int64_t x_nr)\
    \ {\n        assert (nr == r - 1);\n        int y = compress[x_nr];\n        value_lr\
    \ += segtree_l.range_get(y + 1, k);\n        segtree_m.range_apply(y + 1, k, 1);\n\
    \        segtree_r.point_set(y, segtree_r.point_get(y) + 1);\n        r = nr;\n\
    \    }\n\n    void remove_left(int nl, int64_t x_l) {\n        assert (nl == l\
    \ + 1);\n        int y = compress[x_l];\n        value_lr += segtree_r.range_get(0,\
    \ y);\n        segtree_l.point_set(y, segtree_l.point_get(y) + 1);\n        segtree_m.range_apply(0,\
    \ y, 1);\n        l = nl;\n    }\n\n    int64_t query() {\n        int64_t ans\
    \ = 0;\n        ans += dp_l[l];  // the inversion number in [0, l)\n        ans\
    \ += dp_r[r];  // the inversion number in [r, n)\n        ans += value_lr;  //\
    \ the inversion number between [0, l) and [r, n)\n        ans += (int64_t)(r -\
    \ l) * segtree_m.range_get(0, k);  // the inversion number between [0, l) and\
    \ [l, r) plus the inversion number between [l, r) and [r, n)\n        return ans;\n\
    \    }\n};\n\nvector<int64_t> solve(int n, int q, const vector<int64_t>& a, const\
    \ vector<pair<int, int> >& queries) {\n    return run_mo_algorithm(mo_struct(a),\
    \ a, queries);\n}\n\nint main() {\n    int n, q; cin >> n >> q;\n    vector<int64_t>\
    \ a(n);\n    REP (i, n) {\n        cin >> a[i];\n    }\n    vector<pair<int, int>\
    \ > queries(q);\n    REP (i, q) {\n        int l, r; cin >> l >> r;\n        --\
    \ l;\n        queries[i] = make_pair(l, r);\n    }\n    auto ans = solve(n, q,\
    \ a, queries);\n    REP (i, q) {\n        cout << ans[i] << endl;\n    }\n   \
    \ return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - data_structure/segment_tree.hpp
  - data_structure/lazy_propagation_segment_tree.hpp
  - monoids/min.hpp
  - monoids/plus.hpp
  - monoids/plus_min_action.hpp
  - utils/mo_algorithm.hpp
  isVerificationFile: true
  path: utils/mo_algorithm.yuki1270.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: utils/mo_algorithm.yuki1270.test.cpp
layout: document
redirect_from:
- /verify/utils/mo_algorithm.yuki1270.test.cpp
- /verify/utils/mo_algorithm.yuki1270.test.cpp.html
title: utils/mo_algorithm.yuki1270.test.cpp
---
