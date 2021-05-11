---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find_tree_with_monoid.hpp
    title: a disjoint set structure with monoid
  - icon: ':heavy_check_mark:'
    path: graph/subtree.hpp
    title: "subtree info / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E\
      \ size \u3068\u304B height \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\u3081\
      \u3066\u304A\u3044\u3066\u304F\u308C\u308B\u3084\u3064"
  - icon: ':heavy_check_mark:'
    path: hack/stack_pivot.hpp
    title: hack/stack_pivot.hpp
  - icon: ':heavy_check_mark:'
    path: monoids/plus.hpp
    title: monoids/plus.hpp
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.hpp
    title: DSU on tree (sack)
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995
  bundledCode: "#line 1 \"utils/dsu_on_tree.aoj.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995\"\
    \n#line 2 \"utils/dsu_on_tree.hpp\"\n#include <functional>\n#include <stack>\n\
    #include <vector>\n#line 2 \"graph/subtree.hpp\"\n#include <algorithm>\n#line\
    \ 4 \"graph/subtree.hpp\"\n\nstruct subtree_info_t {\n    int parent;  // in the\
    \ entire tree\n    int depth;  // in the entire tree\n    int size;  // of the\
    \ subtree\n    int height;  // of the subtree\n};\n\n/**\n * @brief subtree info\
    \ / \u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E size \u3068\u304B height\
    \ \u3068\u304B\u3092\u307E\u3068\u3081\u3066\u6C42\u3081\u3066\u304A\u3044\u3066\
    \u304F\u308C\u308B\u3084\u3064\n * @arg g must be a tree\n * @note O(n) time\n\
    \ * @note O(n) space on heap\n */\nstd::vector<subtree_info_t> prepare_subtree_info(std::vector<std::vector<int>\
    \ > const & g, int root) {\n    int n = g.size();\n    std::vector<subtree_info_t>\
    \ info(n, (subtree_info_t) { -1, -1, -1, -1 });\n    std::vector<int> topological(n);\n\
    \    topological[0] = root;\n    info[root].parent = root;\n    info[root].depth\
    \ = 0;\n    int r = 1;\n    for (int l = 0; l < r; ++ l) {\n        int i = topological[l];\n\
    \        for (int j : g[i]) if (j != info[i].parent) {\n            topological[r\
    \ ++] = j;\n            info[j].parent = i;\n            info[j].depth = info[i].depth\
    \ + 1;\n        }\n    }\n    while ((-- r) >= 0) {\n        int i = topological[r];\n\
    \        info[i].size = 1;\n        info[i].height = 0;\n        for (int j :\
    \ g[i]) if (j != info[i].parent) {\n            info[i].size += info[j].size;\n\
    \            info[i].height = std::max(info[i].height, info[j].height + 1);\n\
    \        }\n    }\n    info[root].parent = -1;\n    return info;\n}\n#line 2 \"\
    utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n\
    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i,\
    \ n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for\
    \ (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 7 \"utils/dsu_on_tree.hpp\"\n\n/**\n * @brief DSU on tree\
    \ (sack)\n * @arg g is a tree\n * @arg root\n * @arg add is a function object\
    \ which takes a index of a vertex\n * @arg sub is a function object which takes\
    \ a index of a vertex\n * @arg callback is a function object which takes a index\
    \ of a vertex\n * @note for each x, add(x) and sub(x) are called O(log n) times\n\
    \ * @note O(n log n) if add, sub, and callback are O(1)\n * @see https://codeforces.com/blog/entry/44351\n\
    \ * @note sub(x) can be implemented as reset(), because sub(x) is called until\
    \ it becomes empty after sub(x) is called once\n */\ntemplate <class Add, class\
    \ Sub, class Callback>\nvoid dsu_on_tree(const std::vector<std::vector<int> >\
    \ & g, int root, Add & add, Sub & sub, Callback & callback) {\n    auto info =\
    \ prepare_subtree_info(g, root);\n    auto subtree_apply = [&](int x, auto & f)\
    \ {\n        std::stack<int> stk;\n        stk.push(x);\n        while (not stk.empty())\
    \ {\n            int y = stk.top();\n            stk.pop();\n            f(y);\n\
    \            for (int z : g[y]) if (z != info[y].parent) {\n                stk.push(z);\n\
    \            }\n        }\n    };\n    std::function<void (int, bool)> go = [&](int\
    \ x, bool keep) {\n        // leaf\n        if (info[x].size == 1) {\n       \
    \     add(x);\n            callback(x);\n            if (not keep) {\n       \
    \         sub(x);\n            }\n            return;\n        }\n        // choose\
    \ the heavy child\n        int z = *max_element(ALL(g[x]), [&](int y1, int y2)\
    \ {\n            int size1 = (y1 == info[x].parent ? -1 : info[y1].size);\n  \
    \          int size2 = (y2 == info[x].parent ? -1 : info[y2].size);\n        \
    \    return size1 < size2;\n        });\n        // go light\n        for (int\
    \ y : g[x]) if (y != info[x].parent) {\n            if (y != z) {\n          \
    \      go(y, false);\n            }\n        }\n        // go heavy\n        go(z,\
    \ true);\n        for (int y : g[x]) if (y != info[x].parent) {\n            if\
    \ (y != z) {\n                subtree_apply(y, add);\n            }\n        }\n\
    \        add(x);\n        callback(x);\n        if (not keep) {\n            subtree_apply(x,\
    \ sub);\n        }\n    };\n    go(root, false);\n}\n#line 3 \"data_structure/union_find_tree_with_monoid.hpp\"\
    \n\n/**\n * @brief a disjoint set structure with monoid\n * @note union-by-size\
    \ + path-compression\n */\ntemplate <class Monoid>\nstruct union_find_tree_with_monoid\
    \ {\n    typedef typename Monoid::value_type value_type;\n    const Monoid mon;\n\
    \    std::vector<int> data;\n    std::vector<value_type> value;\n\n    union_find_tree_with_monoid()\
    \ = default;\n    union_find_tree_with_monoid(std::size_t n, Monoid const & mon_\
    \ = Monoid()) : mon(mon_), data(n, -1), value(n, mon.unit()) {}\n    bool is_root(int\
    \ i) { return data[i] < 0; }\n    int find_root(int i) { return is_root(i) ? i\
    \ : (data[i] = find_root(data[i])); }\n    int tree_size(int i) { return - data[find_root(i)];\
    \ }\n    int unite_trees(int i, int j) {\n        i = find_root(i); j = find_root(j);\n\
    \        if (i != j) {\n            if (tree_size(i) < tree_size(j)) std::swap(i,\
    \ j);\n            data[i] += data[j];\n            data[j] = i;\n           \
    \ value[i] = mon.mult(value[i], value[j]);\n        }\n        return i;\n   \
    \ }\n    bool is_same(int i, int j) { return find_root(i) == find_root(j); }\n\
    \    value_type get_value(int i) { return value[find_root(i)]; }\n    void set_value(int\
    \ i, value_type z) { value[find_root(i)] = z; }\n};\n#line 2 \"monoids/plus.hpp\"\
    \n\ntemplate <class T>\nstruct plus_monoid {\n    typedef T value_type;\n    value_type\
    \ unit() const { return value_type(); }\n    value_type mult(value_type a, value_type\
    \ b) const { return a + b; }\n};\n#line 2 \"hack/stack_pivot.hpp\"\n#include <cstdlib>\n\
    \n/**\n * @note This is a workaround for WSL. We cannot use ulimit -s unlimited\
    \ on the environment.\n * @note To use such techniques, you should take care of\
    \ the alignment of rsp. If not, you'll get SIGSEGV around XMM registers.\n */\n\
    \n#define BEGIN_STACK_PIVOT(STACK_SIZE) \\\n    static volatile char *old_stack;\
    \ \\\n    asm volatile(\"mov %%rsp, %0\" : \"=r\" (old_stack) ); \\\n    char\
    \ *new_stack = ((char *)malloc(STACK_SIZE) + (STACK_SIZE) - 0x10); \\\n    asm\
    \ volatile(\"mov %0, %%rsp\" : : \"r\" (new_stack) );\n\n#define END_STACK_PIVOT()\
    \ \\\n    asm volatile(\"mov %0, %%rsp\" : : \"r\" (old_stack) );\n\n#define STACK_PIVOT_MAIN(moin)\
    \ \\\n    int main() { \\\n        BEGIN_STACK_PIVOT(1 << 28) \\\n        static\
    \ int returncode = moin(); \\\n        END_STACK_PIVOT() \\\n        return returncode;\
    \ \\\n    }\n#line 6 \"utils/dsu_on_tree.aoj.test.cpp\"\n\n#include <iostream>\n\
    #include <unordered_map>\n#include <unordered_set>\n#line 11 \"utils/dsu_on_tree.aoj.test.cpp\"\
    \nusing namespace std;\n\nvector<int> solve(int n, int k, const vector<vector<int>\
    \ > & g, const vector<int> & c, const vector<int> & d) {\n    union_find_tree_with_monoid<plus_monoid<int>\
    \ > uft(k);\n    unordered_set<int> used;\n    int value = 0;\n    auto func =\
    \ [&](int e) {\n        return min(uft.tree_size(e), uft.get_value(e));\n    };\n\
    \n    auto add = [&](int i) {\n        int c_i = uft.find_root(c[i]);\n      \
    \  int d_i = uft.find_root(d[i]);\n        if (c_i == d_i) {\n            value\
    \ -= func(c_i);\n            uft.set_value(c_i, uft.get_value(c_i) + 1);\n   \
    \         value += func(c_i);\n        } else {\n            value -= func(c_i);\n\
    \            value -= func(d_i);\n            uft.unite_trees(c_i, d_i);\n   \
    \         if (not uft.is_root(c_i)) {\n                swap(c_i, d_i);\n     \
    \       }\n            uft.set_value(c_i, uft.get_value(c_i) + 1);\n         \
    \   value += func(c_i);\n        }\n        used.insert(c_i);\n        used.insert(d_i);\n\
    \    };\n    auto reset = [&](int i) {\n        if (used.empty()) return;\n  \
    \      for (int e : used) {\n            uft.data[e] = -1;\n            uft.value[e]\
    \ = 0;\n        }\n        used.clear();\n        value = 0;\n    };\n\n    vector<int>\
    \ answer(n, -1);\n    auto callback = [&](int i) {\n        answer[i] = value;\n\
    \    };\n\n    constexpr int root = 0;\n    dsu_on_tree(g, root, add, reset, callback);\n\
    \    return answer;\n}\n\nint moin() {\n    // input\n    int n, k; cin >> n >>\
    \ k;\n    vector<vector<int> > g(n);\n    REP (i, n - 1) {\n        int u, v;\
    \ cin >> u >> v;\n        -- u;\n        -- v;\n        g[u].push_back(v);\n \
    \       g[v].push_back(u);\n    }\n    vector<int> c(n);\n    vector<int> d(n);\n\
    \    REP (i, n) {\n        cin >> c[i] >> d[i];\n        -- c[i];\n        --\
    \ d[i];\n    }\n\n    // solve\n    auto answer = solve(n, k, g, c, d);\n\n  \
    \  // output\n    REP (i, n) {\n        cout << answer[i] << endl;\n    }\n  \
    \  return 0;\n}\n\nSTACK_PIVOT_MAIN(moin)\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995\"\
    \n#include \"utils/dsu_on_tree.hpp\"\n#include \"data_structure/union_find_tree_with_monoid.hpp\"\
    \n#include \"monoids/plus.hpp\"\n#include \"hack/stack_pivot.hpp\"\n\n#include\
    \ <iostream>\n#include <unordered_map>\n#include <unordered_set>\n#include \"\
    utils/macros.hpp\"\nusing namespace std;\n\nvector<int> solve(int n, int k, const\
    \ vector<vector<int> > & g, const vector<int> & c, const vector<int> & d) {\n\
    \    union_find_tree_with_monoid<plus_monoid<int> > uft(k);\n    unordered_set<int>\
    \ used;\n    int value = 0;\n    auto func = [&](int e) {\n        return min(uft.tree_size(e),\
    \ uft.get_value(e));\n    };\n\n    auto add = [&](int i) {\n        int c_i =\
    \ uft.find_root(c[i]);\n        int d_i = uft.find_root(d[i]);\n        if (c_i\
    \ == d_i) {\n            value -= func(c_i);\n            uft.set_value(c_i, uft.get_value(c_i)\
    \ + 1);\n            value += func(c_i);\n        } else {\n            value\
    \ -= func(c_i);\n            value -= func(d_i);\n            uft.unite_trees(c_i,\
    \ d_i);\n            if (not uft.is_root(c_i)) {\n                swap(c_i, d_i);\n\
    \            }\n            uft.set_value(c_i, uft.get_value(c_i) + 1);\n    \
    \        value += func(c_i);\n        }\n        used.insert(c_i);\n        used.insert(d_i);\n\
    \    };\n    auto reset = [&](int i) {\n        if (used.empty()) return;\n  \
    \      for (int e : used) {\n            uft.data[e] = -1;\n            uft.value[e]\
    \ = 0;\n        }\n        used.clear();\n        value = 0;\n    };\n\n    vector<int>\
    \ answer(n, -1);\n    auto callback = [&](int i) {\n        answer[i] = value;\n\
    \    };\n\n    constexpr int root = 0;\n    dsu_on_tree(g, root, add, reset, callback);\n\
    \    return answer;\n}\n\nint moin() {\n    // input\n    int n, k; cin >> n >>\
    \ k;\n    vector<vector<int> > g(n);\n    REP (i, n - 1) {\n        int u, v;\
    \ cin >> u >> v;\n        -- u;\n        -- v;\n        g[u].push_back(v);\n \
    \       g[v].push_back(u);\n    }\n    vector<int> c(n);\n    vector<int> d(n);\n\
    \    REP (i, n) {\n        cin >> c[i] >> d[i];\n        -- c[i];\n        --\
    \ d[i];\n    }\n\n    // solve\n    auto answer = solve(n, k, g, c, d);\n\n  \
    \  // output\n    REP (i, n) {\n        cout << answer[i] << endl;\n    }\n  \
    \  return 0;\n}\n\nSTACK_PIVOT_MAIN(moin)\n"
  dependsOn:
  - utils/dsu_on_tree.hpp
  - graph/subtree.hpp
  - utils/macros.hpp
  - data_structure/union_find_tree_with_monoid.hpp
  - monoids/plus.hpp
  - hack/stack_pivot.hpp
  isVerificationFile: true
  path: utils/dsu_on_tree.aoj.test.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: utils/dsu_on_tree.aoj.test.cpp
layout: document
redirect_from:
- /verify/utils/dsu_on_tree.aoj.test.cpp
- /verify/utils/dsu_on_tree.aoj.test.cpp.html
title: utils/dsu_on_tree.aoj.test.cpp
---
