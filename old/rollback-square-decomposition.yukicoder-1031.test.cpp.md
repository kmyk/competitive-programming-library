---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
      \u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: monoids/max.hpp
    title: monoids/max.hpp
  - icon: ':heavy_check_mark:'
    path: old/rollback-square-decomposition.inc.cpp
    title: the extended Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1031
    links:
    - https://github.com/kmyk/online-judge-template-generator)
    - https://yukicoder.me/problems/no/1031
  bundledCode: "#line 1 \"old/rollback-square-decomposition.yukicoder-1031.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/1031\"\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 2 \"data_structure/sparse_table.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 5 \"data_structure/sparse_table.hpp\"\n\n/**\n * @brief Sparse Table (idempotent\
    \ monoid)\n * @note the unit is required just for convenience\n * @note $O(N \\\
    log N)$ space\n */\ntemplate <class IdempotentMonoid>\nstruct sparse_table {\n\
    \    typedef typename IdempotentMonoid::value_type value_type;\n    std::vector<std::vector<value_type>\
    \ > table;\n    IdempotentMonoid mon;\n    sparse_table() = default;\n\n    /**\n\
    \     * @note $O(N \\log N)$ time\n     */\n    template <class InputIterator>\n\
    \    sparse_table(InputIterator first, InputIterator last, const IdempotentMonoid\
    \ & mon_ = IdempotentMonoid())\n            : mon(mon_) {\n        table.emplace_back(first,\
    \ last);\n        int n = table[0].size();\n        int log_n = 32 - __builtin_clz(n);\n\
    \        table.resize(log_n, std::vector<value_type>(n));\n        REP (k, log_n\
    \ - 1) {\n            REP (i, n) {\n                table[k + 1][i] = i + (1ll\
    \ << k) < n ?\n                    mon.mult(table[k][i], table[k][i + (1ll <<\
    \ k)]) :\n                    table[k][i];\n            }\n        }\n    }\n\n\
    \    /**\n     * @note $O(1)$\n     */\n    value_type range_get(int l, int r)\
    \ const {\n        if (l == r) return mon.unit();  // if there is no unit, remove\
    \ this line\n        assert (0 <= l and l < r and r <= (int)table[0].size());\n\
    \        int k = 31 - __builtin_clz(r - l);  // log2\n        return mon.mult(table[k][l],\
    \ table[k][r - (1ll << k)]);\n    }\n};\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n#include <algorithm>\n#line 6 \"data_structure/segment_tree.hpp\"\n\n/**\n *\
    \ @brief Segment Tree / \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u5B8C\u5168\
    \u4E8C\u5206\u6728)\n * @docs data_structure/segment_tree.md\n * @tparam Monoid\
    \ (commutativity is not required)\n */\ntemplate <class Monoid>\nstruct segment_tree\
    \ {\n    typedef typename Monoid::value_type value_type;\n    const Monoid mon;\n\
    \    int n;\n    std::vector<value_type> a;\n    segment_tree() = default;\n \
    \   segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {\n     \
    \   n = 1; while (n < n_) n *= 2;\n        a.resize(2 * n - 1, mon.unit());\n\
    \    }\n    void point_set(int i, value_type b) {  // 0-based\n        assert\
    \ (0 <= i and i < n);\n        a[i + n - 1] = b;\n        for (i = (i + n) / 2;\
    \ i > 0; i /= 2) {  // 1-based\n            a[i - 1] = mon.mult(a[2 * i - 1],\
    \ a[2 * i]);\n        }\n    }\n    value_type range_get(int l, int r) {  // 0-based,\
    \ [l, r)\n        assert (0 <= l and l <= r and r <= n);\n        value_type lacc\
    \ = mon.unit(), racc = mon.unit();\n        for (l += n, r += n; l < r; l /= 2,\
    \ r /= 2) {  // 1-based loop, 2x faster than recursion\n            if (l % 2\
    \ == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);\n            if (r % 2 == 1) racc\
    \ = mon.mult(a[(-- r) - 1], racc);\n        }\n        return mon.mult(lacc, racc);\n\
    \    }\n\n    value_type point_get(int i) {  // 0-based\n        assert (0 <=\
    \ i and i < n);\n        return a[i + n - 1];\n    }\n\n    /**\n     * @brief\
    \ a fast & semigroup-friendly version constructor\n     * @note $O(n)$\n     */\n\
    \    template <class InputIterator>\n    segment_tree(InputIterator first, InputIterator\
    \ last, const Monoid & mon_ = Monoid()) : mon(mon_) {\n        int size = std::distance(first,\
    \ last);\n        n = 1; while (n < size) n *= 2;\n        a.resize(2 * n - 1,\
    \ mon.unit());\n        std::copy(first, last, a.begin() + (n - 1));\n       \
    \ unsafe_rebuild();\n    }\n    /**\n     * @brief update a leaf node without\
    \ updating ancestors\n     * @note $O(1)$\n     */\n    void unsafe_point_set(int\
    \ i, value_type b) {  // 0-based\n        assert (0 <= i and i < n);\n       \
    \ a[i + n - 1] = b;\n    }\n    /**\n     * @brief re-build non-leaf nodes from\
    \ leaf nodes\n     * @note $O(n)$\n     */\n    void unsafe_rebuild() {\n    \
    \    REP_R (i, n - 1) {\n            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);\n\
    \        }\n    }\n};\n#line 3 \"monoids/max.hpp\"\n#include <limits>\n\ntemplate\
    \ <class T>\nstruct max_monoid {\n    typedef T value_type;\n    value_type unit()\
    \ const { return std::numeric_limits<T>::lowest(); }\n    value_type mult(value_type\
    \ a, value_type b) const { return std::max(a, b); }\n};\n#line 6 \"old/rollback-square-decomposition.yukicoder-1031.test.cpp\"\
    \n#include <climits>\n#include <cmath>\n#include <deque>\n#include <functional>\n\
    #include <iostream>\n#include <optional>\n#include <tuple>\n#include <utility>\n\
    #line 15 \"old/rollback-square-decomposition.yukicoder-1031.test.cpp\"\nusing\
    \ namespace std;\n#line 1 \"old/rollback-square-decomposition.inc.cpp\"\n/**\n\
    \ * @brief the extended Mo's algorithm\n * @arg stupid is called O(Q) times, each\
    \ length is O(\\sqrt{N})\n * @arg mo si the following:\n *     struct rollback_mo_interface\
    \ {\n *         void reset(int l);  // called O(N) times\n *         void extend_left(\
    \ int l, int r);  // called O(Q) times, the sum of length is O(N \\sqrt {N})\n\
    \ *         void extend_right(int l, int r);  // called O(Q) times, the sum of\
    \ length is O(Q \\sqrt {N})\n *         void snapshot();  // called O(Q) times\n\
    \ *         void rollback();  // called O(Q) times\n *         void query(); \
    \    // called O(Q) times\n *     };\n * @see http://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    \ * @see http://codeforces.com/blog/entry/7383?#comment-161520\n */\ntemplate\
    \ <class Func, class RollbackMoInterface>\nvoid rollback_square_decomposition(int\
    \ n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid)\
    \ {\n    int bucket_size = sqrt(n);\n    int bucket_count = (n + bucket_size -\
    \ 1) / bucket_size;\n    vector<vector<int> > bucket(bucket_count);\n    REP (i,\
    \ int(range.size())) {\n        int l, r; tie(l, r) = range[i];\n        if (r\
    \ - l <= bucket_size) {\n            stupid(l, r);\n        } else {\n       \
    \     bucket[l / bucket_size].push_back(i);\n        }\n    }\n    REP (b, bucket_count)\
    \ {\n        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second <\
    \ range[j].second; });\n        int l = (b + 1) * bucket_size;\n        mo.reset(l);\n\
    \        int r = l;\n        for (int i : bucket[b]) {\n            int l_i, r_i;\
    \ tie(l_i, r_i) = range[i];\n            mo.extend_right(r, r_i);\n          \
    \  mo.snapshot();\n            mo.extend_left(l_i, l);\n            mo.query();\n\
    \            mo.rollback();\n            r = r_i;\n        }\n    }\n}\n#line\
    \ 17 \"old/rollback-square-decomposition.yukicoder-1031.test.cpp\"\n\ntemplate\
    \ <class T>\nstruct rollbackable_deque {\n    deque<T> data;\n    vector<pair<char,\
    \ optional<T> > > history;\n    rollbackable_deque() = default;\n    bool empty()\
    \ const { return data.empty(); }\n    size_t size() const { return data.size();\
    \ }\n    T operator [] (size_t i) const { return data[i]; }\n    const T & front()\
    \ const { return data.front(); }\n    const T & back() const { return data.back();\
    \ }\n    void push_front(T value) {\n        history.emplace_back('f', optional<T>());\n\
    \        data.push_front(value);\n    }\n    void pop_front() {\n        history.emplace_back('F',\
    \ data.front());\n        data.pop_front();\n    }\n    void push_back(T value)\
    \ {\n        history.emplace_back('b', optional<T>());\n        data.push_back(value);\n\
    \    }\n    void pop_back() {\n        history.emplace_back('B', data.back());\n\
    \        data.pop_back();\n    }\n    void snapshot() {\n        history.emplace_back('$',\
    \ optional<T>());\n    }\n    void rollback() {\n        while (history.back().first\
    \ != '$') {\n            char op = history.back().first;\n            optional<T>\
    \ value = history.back().second;\n            history.pop_back();\n          \
    \  if (op == 'f') {\n                data.pop_front();\n            } else if\
    \ (op == 'F') {\n                data.push_front(*value);\n            } else\
    \ if (op == 'b') {\n                data.pop_back();\n            } else if (op\
    \ == 'B') {\n                data.push_back(*value);\n            }\n        }\n\
    \        history.pop_back();\n    }\n};\n\nstruct rollback_mo_inc {\n    const\
    \ vector<int> & p;\n    int64_t & ans;\n    int l, r;\n    vector<pair<int, int>\
    \ > history;\n    rollbackable_deque<int> deq;\n    rollback_mo_inc(const vector<int>\
    \ & p_, int64_t & ans_) : p(p_), ans(ans_) {\n        reset(0);\n    }\n    void\
    \ reset(int l_) {\n        l = l_;\n        r = l_;\n        history.clear();\n\
    \        deq = rollbackable_deque<int>();\n    }\n    void extend_left(int nl,\
    \ int r) {\n        for (; nl < l; -- l) {\n            if (deq.empty() or p[l\
    \ - 1] < deq.front()) {\n                deq.push_front(p[l - 1]);\n         \
    \   }\n        }\n    }\n    void extend_right(int l, int nr) {\n        for (;\
    \ r < nr; ++ r) {\n            while (not deq.empty() and p[r] < deq.back()) {\n\
    \                deq.pop_back();\n            }\n            deq.push_back(p[r]);\n\
    \        }\n    }\n    void snapshot() {\n        deq.snapshot();\n        history.emplace_back(l,\
    \ r);\n    }\n    void rollback() {\n        deq.rollback();\n        tie(l, r)\
    \ = history.back();\n        history.pop_back();\n    }\n    void query() {\n\
    \        ans += deq.size();\n    }\n};\n\nint64_t solve1(int n, const vector<int>\
    \ & p) {\n    vector<pair<int, int> > query_inc;\n    vector<int> lookup(n);\n\
    \    REP (i, n) {\n        lookup[p[i]] = i;\n    }\n    sparse_table<max_monoid<int>\
    \ > table(ALL(p));\n    function<void (int, int)> go = [&](int l, int r) {\n \
    \       if (r - l < 2) return;\n        int m = lookup[table.range_get(l, r)];\n\
    \        query_inc.emplace_back(l, m);\n        go(l, m);\n        go(m + 1, r);\n\
    \    };\n    go(0, n);\n\n    int64_t ans = 0;\n    rollback_mo_inc interface_inc(p,\
    \ ans);\n    rollback_square_decomposition(n, query_inc, interface_inc, [&](int\
    \ l, int r) {\n        int last = INT_MAX;\n        REP3R (i, l, r) {\n      \
    \      if (p[i] < last) {\n                last = p[i];\n                ++ ans;\n\
    \            }\n        }\n    });\n    return ans;\n}\n\nint64_t solve(int n,\
    \ vector<int> p) {\n    int64_t ans = solve1(n, p);\n    reverse(ALL(p));\n  \
    \  return ans + solve1(n, p);\n}\n\n// generated by online-judge-template-generator\
    \ v4.1.0 (https://github.com/kmyk/online-judge-template-generator)\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    constexpr\
    \ char endl = '\\n';\n    int N;\n    cin >> N;\n    vector<int> p(N);\n    REP\
    \ (i, N) {\n        cin >> p[i];\n        -- p[i];\n    }\n    auto ans = solve(N,\
    \ p);\n    cout << ans << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1031\"\n#include \"utils/macros.hpp\"\
    \n#include \"data_structure/sparse_table.hpp\"\n#include \"data_structure/segment_tree.hpp\"\
    \n#include \"monoids/max.hpp\"\n#include <climits>\n#include <cmath>\n#include\
    \ <deque>\n#include <functional>\n#include <iostream>\n#include <optional>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n#include\
    \ \"old/rollback-square-decomposition.inc.cpp\"\n\ntemplate <class T>\nstruct\
    \ rollbackable_deque {\n    deque<T> data;\n    vector<pair<char, optional<T>\
    \ > > history;\n    rollbackable_deque() = default;\n    bool empty() const {\
    \ return data.empty(); }\n    size_t size() const { return data.size(); }\n  \
    \  T operator [] (size_t i) const { return data[i]; }\n    const T & front() const\
    \ { return data.front(); }\n    const T & back() const { return data.back(); }\n\
    \    void push_front(T value) {\n        history.emplace_back('f', optional<T>());\n\
    \        data.push_front(value);\n    }\n    void pop_front() {\n        history.emplace_back('F',\
    \ data.front());\n        data.pop_front();\n    }\n    void push_back(T value)\
    \ {\n        history.emplace_back('b', optional<T>());\n        data.push_back(value);\n\
    \    }\n    void pop_back() {\n        history.emplace_back('B', data.back());\n\
    \        data.pop_back();\n    }\n    void snapshot() {\n        history.emplace_back('$',\
    \ optional<T>());\n    }\n    void rollback() {\n        while (history.back().first\
    \ != '$') {\n            char op = history.back().first;\n            optional<T>\
    \ value = history.back().second;\n            history.pop_back();\n          \
    \  if (op == 'f') {\n                data.pop_front();\n            } else if\
    \ (op == 'F') {\n                data.push_front(*value);\n            } else\
    \ if (op == 'b') {\n                data.pop_back();\n            } else if (op\
    \ == 'B') {\n                data.push_back(*value);\n            }\n        }\n\
    \        history.pop_back();\n    }\n};\n\nstruct rollback_mo_inc {\n    const\
    \ vector<int> & p;\n    int64_t & ans;\n    int l, r;\n    vector<pair<int, int>\
    \ > history;\n    rollbackable_deque<int> deq;\n    rollback_mo_inc(const vector<int>\
    \ & p_, int64_t & ans_) : p(p_), ans(ans_) {\n        reset(0);\n    }\n    void\
    \ reset(int l_) {\n        l = l_;\n        r = l_;\n        history.clear();\n\
    \        deq = rollbackable_deque<int>();\n    }\n    void extend_left(int nl,\
    \ int r) {\n        for (; nl < l; -- l) {\n            if (deq.empty() or p[l\
    \ - 1] < deq.front()) {\n                deq.push_front(p[l - 1]);\n         \
    \   }\n        }\n    }\n    void extend_right(int l, int nr) {\n        for (;\
    \ r < nr; ++ r) {\n            while (not deq.empty() and p[r] < deq.back()) {\n\
    \                deq.pop_back();\n            }\n            deq.push_back(p[r]);\n\
    \        }\n    }\n    void snapshot() {\n        deq.snapshot();\n        history.emplace_back(l,\
    \ r);\n    }\n    void rollback() {\n        deq.rollback();\n        tie(l, r)\
    \ = history.back();\n        history.pop_back();\n    }\n    void query() {\n\
    \        ans += deq.size();\n    }\n};\n\nint64_t solve1(int n, const vector<int>\
    \ & p) {\n    vector<pair<int, int> > query_inc;\n    vector<int> lookup(n);\n\
    \    REP (i, n) {\n        lookup[p[i]] = i;\n    }\n    sparse_table<max_monoid<int>\
    \ > table(ALL(p));\n    function<void (int, int)> go = [&](int l, int r) {\n \
    \       if (r - l < 2) return;\n        int m = lookup[table.range_get(l, r)];\n\
    \        query_inc.emplace_back(l, m);\n        go(l, m);\n        go(m + 1, r);\n\
    \    };\n    go(0, n);\n\n    int64_t ans = 0;\n    rollback_mo_inc interface_inc(p,\
    \ ans);\n    rollback_square_decomposition(n, query_inc, interface_inc, [&](int\
    \ l, int r) {\n        int last = INT_MAX;\n        REP3R (i, l, r) {\n      \
    \      if (p[i] < last) {\n                last = p[i];\n                ++ ans;\n\
    \            }\n        }\n    });\n    return ans;\n}\n\nint64_t solve(int n,\
    \ vector<int> p) {\n    int64_t ans = solve1(n, p);\n    reverse(ALL(p));\n  \
    \  return ans + solve1(n, p);\n}\n\n// generated by online-judge-template-generator\
    \ v4.1.0 (https://github.com/kmyk/online-judge-template-generator)\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    constexpr\
    \ char endl = '\\n';\n    int N;\n    cin >> N;\n    vector<int> p(N);\n    REP\
    \ (i, N) {\n        cin >> p[i];\n        -- p[i];\n    }\n    auto ans = solve(N,\
    \ p);\n    cout << ans << endl;\n    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - data_structure/sparse_table.hpp
  - data_structure/segment_tree.hpp
  - monoids/max.hpp
  - old/rollback-square-decomposition.inc.cpp
  isVerificationFile: true
  path: old/rollback-square-decomposition.yukicoder-1031.test.cpp
  requiredBy: []
  timestamp: '2020-04-17 23:46:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: old/rollback-square-decomposition.yukicoder-1031.test.cpp
layout: document
redirect_from:
- /verify/old/rollback-square-decomposition.yukicoder-1031.test.cpp
- /verify/old/rollback-square-decomposition.yukicoder-1031.test.cpp.html
title: old/rollback-square-decomposition.yukicoder-1031.test.cpp
---
