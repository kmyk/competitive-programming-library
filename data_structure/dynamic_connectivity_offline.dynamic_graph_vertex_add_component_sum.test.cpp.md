---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#line 2 \"data_structure/dynamic_connectivity_offline.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <optional>\n#include <tuple>\n#include\
    \ <vector>\n#line 4 \"data_structure/union_find_tree_foldable_undoable.hpp\"\n\
    #include <utility>\n#line 6 \"data_structure/union_find_tree_foldable_undoable.hpp\"\
    \n\n/**\n * @brief Union-Find Tree (foldable with commutative monoids, undoable)\n\
    \ * @note $O(\\log N)$\n * @note union-by-size (without path-compression)\n */\n\
    template <class CommutativeMonoid>\nclass union_find_tree_foldable_undoable {\n\
    \    typedef typename CommutativeMonoid::value_type value_type;\n    const CommutativeMonoid\
    \ mon;\n    std::vector<int> data;\n    std::vector<value_type> value;\n    std::vector<std::tuple<int,\
    \ int, value_type> > history;\n\npublic:\n    union_find_tree_foldable_undoable()\
    \ = default;\n    union_find_tree_foldable_undoable(std::size_t size, const CommutativeMonoid\
    \ & mon_ = CommutativeMonoid())\n            : mon(mon_), data(size, -1), value(size,\
    \ mon.unit()) {\n    }\n    template <class InputIterator>\n    union_find_tree_foldable_undoable(InputIterator\
    \ first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())\n\
    \            : mon(mon_), data(std::distance(first, last), -1), value(first, last)\
    \ {\n    }\n\n    bool is_root(int i) { return data[i] < 0; }\n    int find_root(int\
    \ i) { while (not is_root(i)) i = data[i]; return i; }\n    int get_size(int i)\
    \ { return - data[find_root(i)]; }\n    void unite_trees(int i, int j) {\n   \
    \     i = find_root(i);\n        j = find_root(j);\n        if (get_size(i) <\
    \ get_size(j)) std::swap(i, j);\n        history.emplace_back(-1, 0, mon.unit());\n\
    \        if (i != j) {\n            history.emplace_back(i, data[i], value[i]);\n\
    \            history.emplace_back(j, data[j], value[j]);\n            data[i]\
    \ += data[j];\n            data[j] = i;\n            value[i] = mon.mult(value[i],\
    \ value[j]);\n        }\n    }\n    bool is_connected(int i, int j) { return find_root(i)\
    \ == find_root(j); }\n\n    void tree_set(int i, value_type x) {\n        i =\
    \ find_root(i);\n        history.emplace_back(-1, 0, mon.unit());\n        history.emplace_back(i,\
    \ data[i], value[i]);\n        value[i] = x;\n    }\n    value_type tree_get(int\
    \ i) {\n        return value[find_root(i)];\n    }\n    /**\n     * @note for\
    \ unite_trees() and tree_set()\n     */\n    void undo() {\n        while (true)\
    \ {\n            assert (not history.empty());\n            auto [i, data_i, value_i]\
    \ = history.back();\n            history.pop_back();\n            if (i == -1)\
    \ break;\n            value[i] = value_i;\n            data[i] = data_i;\n   \
    \     }\n    }\n};\n#line 4 \"data_structure/reporting_segment_tree.hpp\"\n#include\
    \ <functional>\n#include <type_traits>\n#line 2 \"utils/macros.hpp\"\n#define\
    \ REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for\
    \ (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 8 \"\
    data_structure/reporting_segment_tree.hpp\"\n\n/**\n * @brief Dual Segment Tree\
    \ / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5217\u6319\u30AF\u30A8\
    \u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)\n * @note This tree is very similar to\
    \ the Bentley's original segment tree.\n */\ntemplate <class Key>\nstruct reporting_segment_tree\
    \ {\n    int size;\n    std::vector<std::vector<Key> > data;\n    reporting_segment_tree()\
    \ = default;\n    explicit reporting_segment_tree(int size_) {\n        size =\
    \ 1; while (size < size_) size *= 2;\n        data.resize(2 * size - 1);\n   \
    \ }\n\n    /**\n     * @arg key must be unique\n     * @note $O(\\log n)$\n  \
    \   */\n    void add_segment(int l, int r, const Key & key) {\n        assert\
    \ (0 <= l and l <= r and r <= size);\n        for (l += size, r += size; l < r;\
    \ l /= 2, r /= 2) {  // 1-based\n            if (l % 2 == 1) data[(l ++) - 1].push_back(key);\n\
    \            if (r % 2 == 1) data[(-- r) - 1].push_back(key);\n        }\n   \
    \ }\n\n    /**\n     * @note $O(\\log n + k)$\n     */\n    template <class Callback>\n\
    \    void list_segments(int i, Callback & callback) {\n        static_assert (std::is_invocable_r<void,\
    \ Callback, const Key &>::value, \"\");\n        assert (0 <= i and i < size);\n\
    \        for (i += size; i > 0; i /= 2) {  // 1-based\n            for (const\
    \ auto & key : data[i - 1]) {\n                callback(key);\n            }\n\
    \        }\n    }\n\n    /**\n     * @note $O(n + k)$\n     * @arg remove can\
    \ be implemented as undo\n     * @arg report is called with all indices in increasing\
    \ order\n     */\n    template <class Add, class Remove, class Report>\n    void\
    \ traverse_segments(Add & add, Remove & remove, Report & report) {\n        static_assert\
    \ (std::is_invocable_r<void, Add, const Key &>::value, \"\");\n        static_assert\
    \ (std::is_invocable_r<void, Remove, const Key &>::value, \"\");\n        static_assert\
    \ (std::is_invocable_r<void, Report, int>::value, \"\");\n        std::function<void\
    \ (int, int, int)> dfs = [&](int i, int l, int r) {\n            for (const auto\
    \ & key : data[i]) {\n                add(key);\n            }\n            if\
    \ (i >= size - 1) {\n                report(i - size + 1);\n            } else\
    \ {\n                dfs(2 * i + 1, l, (l + r) / 2);\n                dfs(2 *\
    \ i + 2, (l + r) / 2, r);\n            }\n            for (auto it = data[i].rbegin();\
    \ it != data[i].rend(); ++ it) {\n                remove(*it);\n            }\n\
    \        };\n        dfs(0, 0, size);\n    }\n};\n#line 11 \"data_structure/dynamic_connectivity_offline.hpp\"\
    \n\n/**\n * @brief Dynamic Connectivity (offline, commutative monoids)\n * @docs\
    \ data_structure/dynamic_connectivity_offline.md\n */\ntemplate <class CommutativeMonoid>\n\
    class dynamic_connectivity_offline {\n    typedef typename CommutativeMonoid::value_type\
    \ value_type;\n    enum query_tag {\n        LINK,\n        ADD,\n    };\n   \
    \ struct query_type {\n        query_tag tag;\n        int l, r;\n        int\
    \ a;\n        int64_t b;\n    };\n\n    const CommutativeMonoid mon;\n    int\
    \ size;\n    int time;\n    std::vector<query_type> set_queries;\n    std::vector<std::pair<int,\
    \ int> > get_queries;\n    std::map<std::pair<int, int>, int> current_edges;\n\
    \    std::vector<std::vector<std::pair<int, value_type> > > current_values;\n\n\
    \    void flush_time() {\n        if (not get_queries.empty() and get_queries.back().first\
    \ == time) {\n            ++ time;\n        }\n    }\n\npublic:\n    /**\n   \
    \  * @arg size is the number of vertices\n     */\n    dynamic_connectivity_offline(int\
    \ size_, const CommutativeMonoid & mon_ = CommutativeMonoid())\n            :\
    \ mon(mon_) {\n        size = size_;\n        time = 0;\n        current_values.resize(size);\n\
    \    }\n    void link(int x, int y) {\n        flush_time();\n        auto edge\
    \ = std::minmax({ x, y });\n        assert (not current_edges.count(edge));\n\
    \        current_edges[edge] = time;\n    }\n    void cut(int x, int y) {\n  \
    \      flush_time();\n        auto edge = std::minmax({ x, y });\n        assert\
    \ (current_edges.count(edge));\n        set_queries.emplace_back((query_type)\
    \ {\n            LINK,\n            current_edges[edge],\n            time,\n\
    \            edge.first,\n            edge.second,\n        });\n        current_edges.erase(edge);\n\
    \    }\n    void point_set(int x, value_type value) {\n        flush_time();\n\
    \        while (not current_values[x].empty()) {\n            auto [l, value_]\
    \ = current_values[x].back();\n            current_values[x].pop_back();\n   \
    \         set_queries.emplace_back((query_type) {\n                ADD,\n    \
    \            l,\n                time,\n                x,\n                value_,\n\
    \            });\n        }\n        current_values[x].emplace_back(time, value);\n\
    \    }\n    void point_mult(int x, value_type value) {\n        flush_time();\n\
    \        current_values[x].emplace_back(time, value);\n    }\n    void component_get(int\
    \ x) {\n        get_queries.emplace_back(time, x);\n    }\n\n    /**\n     * @note\
    \ $O(Q \\log Q)$\n     */\n    std::vector<value_type> run() {\n        std::vector<value_type>\
    \ results;\n        auto it = get_queries.begin();\n\n        // close half-open\
    \ queries\n        int current_size = set_queries.size();\n        for (auto [edge,\
    \ l] : current_edges) {\n            set_queries.emplace_back((query_type) {\n\
    \                LINK,\n                l,\n                time + 1,\n      \
    \          edge.first,\n                edge.second,\n            });\n      \
    \  }\n        REP (x, size) {\n            for (auto [l, value] : current_values[x])\
    \ {\n                set_queries.emplace_back((query_type) {\n               \
    \     ADD,\n                    l,\n                    time + 1,\n          \
    \          x,\n                    value,\n                });\n            }\n\
    \        }\n\n        // prepare undoable union-find tree\n        union_find_tree_foldable_undoable<CommutativeMonoid>\
    \ uft(size, mon);\n        auto add = [&](int i) {\n            auto & q = set_queries[i];\n\
    \            if (q.tag == LINK) {\n                uft.unite_trees(q.a, q.b);\n\
    \            } else if (q.tag == ADD) {\n                uft.tree_set(q.a, mon.mult(uft.tree_get(q.a),\
    \ q.b));\n            } else {\n                assert (false);\n            }\n\
    \        };\n        auto remove = [&](int i) {\n            uft.undo();\n   \
    \     };\n        auto report = [&](int t) {\n            for (; it != get_queries.end()\
    \ and it->first == t; ++ it) {\n                int x = it->second;\n        \
    \        results.push_back(uft.tree_get(x));\n            }\n        };\n\n  \
    \      // use segment trees on time-axis for queries\n        reporting_segment_tree<int>\
    \ segtree(time + 1);\n        REP (i, set_queries.size()) {\n            auto\
    \ & q = set_queries[i];\n            segtree.add_segment(q.l, q.r, i);\n     \
    \   }\n        segtree.traverse_segments(add, remove, report);\n\n        // re-open\
    \ closed queries\n        set_queries.resize(current_size);\n\n        assert\
    \ (it == get_queries.end());\n        return results;\n    }\n};\n#line 2 \"monoids/plus.hpp\"\
    \n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return value_type(); }\n    value_type mult(value_type a, value_type\
    \ b) const { return a + b; }\n};\n#line 2 \"hack/fastio.hpp\"\n#include <cstdint>\n\
    #include <cstdio>\n#include <string>\n#line 6 \"hack/fastio.hpp\"\n\ntemplate\
    \ <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\ninline\
    \ Char in() { return getchar_unlocked(); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
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
    \ i] + '0');\n}\n#line 6 \"data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \n\nint main() {\n    int n = in<int>();\n    int q = in<int>();\n\n    dynamic_connectivity_offline<plus_monoid<int64_t>\
    \ > dycon(n);\n    REP (v, n) {\n        int64_t a = in<int64_t>();\n        dycon.point_set(v,\
    \ a);\n    }\n    REP (i, q) {\n        int t = in<int>();\n        if (t == 0)\
    \ {\n            int u = in<int>();\n            int v = in<int>();\n        \
    \    dycon.link(u, v);\n        } else if (t == 1) {\n            int u = in<int>();\n\
    \            int v = in<int>();\n            dycon.cut(u, v);\n        } else\
    \ if (t == 2) {\n            int v = in<int>();\n            int64_t x = in<int64_t>();\n\
    \            dycon.point_mult(v, x);\n        } else if (t == 3) {\n         \
    \   int v = in<int>();\n            dycon.component_get(v);\n        } else {\n\
    \            assert (false);\n        }\n    }\n\n    std::vector<int64_t> answer\
    \ = dycon.run();\n    for (int64_t a : answer) {\n        out<int64_t>(a);\n \
    \       out<char>('\\n');\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"data_structure/dynamic_connectivity_offline.hpp\"\n#include \"monoids/plus.hpp\"\
    \n#include \"hack/fastio.hpp\"\n#include \"utils/macros.hpp\"\n\nint main() {\n\
    \    int n = in<int>();\n    int q = in<int>();\n\n    dynamic_connectivity_offline<plus_monoid<int64_t>\
    \ > dycon(n);\n    REP (v, n) {\n        int64_t a = in<int64_t>();\n        dycon.point_set(v,\
    \ a);\n    }\n    REP (i, q) {\n        int t = in<int>();\n        if (t == 0)\
    \ {\n            int u = in<int>();\n            int v = in<int>();\n        \
    \    dycon.link(u, v);\n        } else if (t == 1) {\n            int u = in<int>();\n\
    \            int v = in<int>();\n            dycon.cut(u, v);\n        } else\
    \ if (t == 2) {\n            int v = in<int>();\n            int64_t x = in<int64_t>();\n\
    \            dycon.point_mult(v, x);\n        } else if (t == 3) {\n         \
    \   int v = in<int>();\n            dycon.component_get(v);\n        } else {\n\
    \            assert (false);\n        }\n    }\n\n    std::vector<int64_t> answer\
    \ = dycon.run();\n    for (int64_t a : answer) {\n        out<int64_t>(a);\n \
    \       out<char>('\\n');\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/dynamic_connectivity_offline.hpp
  - data_structure/union_find_tree_foldable_undoable.hpp
  - data_structure/reporting_segment_tree.hpp
  - utils/macros.hpp
  - monoids/plus.hpp
  - hack/fastio.hpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_connectivity_offline.hpp
    title: Dynamic Connectivity (offline, commutative monoids)
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find_tree_foldable_undoable.hpp
    title: Union-Find Tree (foldable with commutative monoids, undoable)
  - icon: ':heavy_check_mark:'
    path: data_structure/reporting_segment_tree.hpp
    title: "Dual Segment Tree / \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5217\
      \u6319\u30AF\u30A8\u30EA, \u5B8C\u5168\u4E8C\u5206\u6728)"
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  - icon: ':heavy_check_mark:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
  requiredBy: []
  timestamp: '2020-06-13 00:00:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
- /verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp.html
title: data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp
---
