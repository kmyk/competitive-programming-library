---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "fold a rooted tree / \u6728DP"
  bundledCode: "#line 1 \"old/tree-dp.inc.cpp\"\n/**\n * @brief fold a rooted tree\
    \ / \u6728DP\n * @note O(N op) time\n * @note O(N) space, not recursive\n * @note\n\
    \ *     struct tree_operation {\n *         typedef int type;\n *         type\
    \ operator () (int i, vector<pair<int, type> > const & args);\n *     };\n * @note\
    \ interface\u3061\u3087\u3063\u3068\u5FAE\u5999\u3058\u3083\u306A\u3044\uFF1F\
    \ \u3069\u3046\u305B\u4E00\u7DD2\u306Badd()\u5B9F\u88C5\u3059\u308B \u3042\u3068\
    \u8FBA\u306B\u91CD\u307F\u304C\u3042\u308B\u3068\u4FEE\u6B63\u304C\u3064\u3089\
    \u3044\n */\ntemplate <typename TreeOperation>\nvector<typename TreeOperation::type>\
    \ fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op\
    \ = TreeOperation()) {\n    int n = g.size();\n    vector<typename TreeOperation::type>\
    \ data(n);\n    stack<tuple<bool, int, int> > stk;\n    stk.emplace(false, root,\
    \ -1);\n    while (not stk.empty()) {\n        bool state; int x, parent; tie(state,\
    \ x, parent) = stk.top(); stk.pop();\n        if (not state) {\n            stk.emplace(true,\
    \ x, parent);\n            for (int y : g[x]) if (y != parent) {\n           \
    \     stk.emplace(false, y, x);\n            }\n        } else {\n           \
    \ vector<pair<int, typename TreeOperation::type> > args;\n            for (int\
    \ y : g[x]) if (y != parent) {\n                args.emplace_back(y, data[y]);\n\
    \            }\n            data[x] = op(x, args);\n        }\n    };\n    return\
    \ data;\n}\n\n/**\n * @brief rerooting (\u5168\u65B9\u4F4D\u6728DP)\n * @note\
    \ O(N op) time\n * @note O(N) space, not recursive\n * @note\n *     struct tree_operation\
    \ {\n *         typedef int type;\n *         type      add(int i, type data_i,\
    \ int j, type data_j);  // add    a subtree j to   the root i\n *         type\
    \ subtract(int i, type data_i, int j, type data_j);  // remove a subtree j from\
    \ the root i\n *     };\n * @note if add & subtract are slow, you can merge them\n\
    \ * @see https://twitter.com/tmaehara/status/980787099472297985\n */\ntemplate\
    \ <typename TreeOperation>\nvector<typename TreeOperation::type> reroot_folded_rooted_tree(vector<typename\
    \ TreeOperation::type> data, vector<vector<int> > const & g, int root, TreeOperation\
    \ op = TreeOperation()) {\n    stack<pair<int, int> > stk;\n    stk.emplace(root,\
    \ -1);\n    while (not stk.empty()) {\n        int x, parent; tie(x, parent) =\
    \ stk.top(); stk.pop();\n        if (parent != -1) {\n            data[x] = op.add(x,\
    \ data[x], parent, op.subtract(parent, data[parent], x, data[x]));\n        }\n\
    \        for (int y : g[x]) if (y != parent) {\n            stk.emplace(y, x);\n\
    \        }\n    }\n    return data;\n}\n\n// \u6CE8\u610F: \u307E\u3060verify\u3057\
    \u3066\u306A\u3044\nstruct height_tree_operation {\n    typedef pair<int, int>\
    \ type;\n    type operator () (int i, vector<pair<int, type> > const & args) {\n\
    \        type acc = make_pair(INT_MIN, INT_MIN);\n        for (auto arg : args)\
    \ {\n            acc = add(i, acc, arg.first, arg.second);\n        }\n      \
    \  return acc;\n    }\n    type add(int i, type data_i, int j, type data_j) {\
    \  // add a subtree j to the root i\n        array<int, 3> height = {{ data_i.first,\
    \ data_i.second, data_j.first + 1 }};  // NOTE: the length is corrent\n      \
    \  sort(height.rbegin(), height.rend());\n        return make_pair(height[0],\
    \ height[1]);\n    }\n    type subtract(int i, type data_i, int j, type data_j)\
    \ {  // remove a subtree j from the root i\n        if (data_i.first == data_j.first\
    \ + 1) {\n            return make_pair(data_i.second, INT_MIN);  // NOTE: this\
    \ is correct\n        } else {\n            return data_i;\n        }\n    }\n\
    };\n\nstruct heights_tree_operation {\n    typedef multiset<int> type;  // heights\
    \ of subtrees\n    type operator () (int i, vector<pair<int, type> > const & args)\
    \ {\n        type data;\n        for (auto arg : args) {\n            data = add(i,\
    \ data, arg.first, arg.second);\n        }\n        return data;\n    }\n    type\
    \ add(int i, type data_i, int j, type data_j) {  // add a subtree j to the root\
    \ i\n        int height = 1 + accumulate(ALL(data_j), 0, [&](int a, int b) { return\
    \ max(a, b); });\n        data_i.insert(height);\n        return data_i;\n   \
    \ }\n    type subtract(int i, type data_i, int j, type data_j) {  // remove a\
    \ subtree j from the root i\n        int height = 1 + accumulate(ALL(data_j),\
    \ 0, [&](int a, int b) { return max(a, b); });\n        auto it = data_i.find(height);\n\
    \        data_i.erase(it);\n        return data_i;\n    }\n};\nunittest {\n  \
    \  vector<vector<int> > g(9);\n    constexpr int root = 0;\n    g[0].push_back(1);\n\
    \    g[0].push_back(2);\n    ;   g[2].push_back(4);\n    ;   g[2].push_back(5);\n\
    \    ;   g[2].push_back(6);\n    ;   ;   g[6].push_back(8);\n    g[0].push_back(3);\n\
    \    ;   g[3].push_back(7);\n    auto dp1 = fold_rooted_tree(g, root, heights_tree_operation());\n\
    \    auto dp2 = reroot_folded_rooted_tree(dp1, g, root, heights_tree_operation());\n\
    \    assert (dp1[root] == dp2[root]);\n    assert (dp1[2] == multiset<int>({ 1,\
    \ 1, 2 }));\n    assert (dp2[2] == multiset<int>({ 1, 1, 2, 3 }));\n    assert\
    \ (dp1[3] == multiset<int>({ 1 }));\n    assert (dp2[3] == multiset<int>({ 1,\
    \ 4 }));\n}\n\n\n\n// \u7C21\u7565\u5316\u3057\u305F\u3084\u3064 \u672A\u691C\u8A3C\
    \n\n/**\n * @brief fold a rooted tree (\u6728DP)\n * @note O(N op) time\n * @note\
    \ O(N) space on stack\n * @note\n *     struct tree_operation {\n *         typedef\
    \ int type;\n *         type unit(int i);  // get an initial value of root i\n\
    \ *         type add(int i, type data_i, int j, type data_j);  // add a subtree\
    \ j to the root i\n *     };\n * @note you can replace unit() + add() with a single\
    \ function\n */\ntemplate <typename TreeOperation>\nvector<typename TreeOperation::type>\
    \ fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op\
    \ = TreeOperation()) {\n    int n = g.size();\n    vector<typename TreeOperation::type>\
    \ data(n);\n    function<void (int, int)> go = [&](int i, int parent) {\n    \
    \    data[i] = op.unit(i);\n        for (int j : g[i]) if (j != parent) {\n  \
    \          go(j, i);\n            data[i] = op.add(i, data[i], j, data[j]);\n\
    \        }\n    };\n    go(root, -1);\n    return data;\n}\n\n/**\n * @brief rerooting\
    \ (\u5168\u65B9\u4F4D\u6728DP)\n * @note O(N op) time\n * @note O(N) space on\
    \ stack\n * @note\n *     struct tree_operation {\n *         typedef int type;\n\
    \ *         type      add(int i, type data_i, int j, type data_j);  // add   \
    \ a subtree j to   the root i\n *         type subtract(int i, type data_i, int\
    \ j, type data_j);  // remove a subtree j from the root i\n *     };\n * @note\
    \ a commutative group is one of the structures for this\n * @note you can replace\
    \ add() + subtract() with a single function\n * @see https://twitter.com/tmaehara/status/980787099472297985\n\
    \ */\ntemplate <typename TreeOperation>\nvector<typename TreeOperation::type>\
    \ reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int>\
    \ > const & g, int root, TreeOperation op = TreeOperation()) {\n    function<void\
    \ (int, int)> go = [&](int i, int parent) {\n        if (parent != -1) {\n   \
    \         data[i] = op.add(i, data[i], op.subtract(parent, data[parent], i, data[i]));\n\
    \        }\n        for (int j : g[i]) if (j != parent) {\n            go(j, i);\n\
    \        }\n    };\n    go(root, -1);\n    return data;\n}\n\n"
  code: "/**\n * @brief fold a rooted tree / \u6728DP\n * @note O(N op) time\n * @note\
    \ O(N) space, not recursive\n * @note\n *     struct tree_operation {\n *    \
    \     typedef int type;\n *         type operator () (int i, vector<pair<int,\
    \ type> > const & args);\n *     };\n * @note interface\u3061\u3087\u3063\u3068\
    \u5FAE\u5999\u3058\u3083\u306A\u3044\uFF1F \u3069\u3046\u305B\u4E00\u7DD2\u306B\
    add()\u5B9F\u88C5\u3059\u308B \u3042\u3068\u8FBA\u306B\u91CD\u307F\u304C\u3042\
    \u308B\u3068\u4FEE\u6B63\u304C\u3064\u3089\u3044\n */\ntemplate <typename TreeOperation>\n\
    vector<typename TreeOperation::type> fold_rooted_tree(vector<vector<int> > const\
    \ & g, int root, TreeOperation op = TreeOperation()) {\n    int n = g.size();\n\
    \    vector<typename TreeOperation::type> data(n);\n    stack<tuple<bool, int,\
    \ int> > stk;\n    stk.emplace(false, root, -1);\n    while (not stk.empty())\
    \ {\n        bool state; int x, parent; tie(state, x, parent) = stk.top(); stk.pop();\n\
    \        if (not state) {\n            stk.emplace(true, x, parent);\n       \
    \     for (int y : g[x]) if (y != parent) {\n                stk.emplace(false,\
    \ y, x);\n            }\n        } else {\n            vector<pair<int, typename\
    \ TreeOperation::type> > args;\n            for (int y : g[x]) if (y != parent)\
    \ {\n                args.emplace_back(y, data[y]);\n            }\n         \
    \   data[x] = op(x, args);\n        }\n    };\n    return data;\n}\n\n/**\n *\
    \ @brief rerooting (\u5168\u65B9\u4F4D\u6728DP)\n * @note O(N op) time\n * @note\
    \ O(N) space, not recursive\n * @note\n *     struct tree_operation {\n *    \
    \     typedef int type;\n *         type      add(int i, type data_i, int j, type\
    \ data_j);  // add    a subtree j to   the root i\n *         type subtract(int\
    \ i, type data_i, int j, type data_j);  // remove a subtree j from the root i\n\
    \ *     };\n * @note if add & subtract are slow, you can merge them\n * @see https://twitter.com/tmaehara/status/980787099472297985\n\
    \ */\ntemplate <typename TreeOperation>\nvector<typename TreeOperation::type>\
    \ reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int>\
    \ > const & g, int root, TreeOperation op = TreeOperation()) {\n    stack<pair<int,\
    \ int> > stk;\n    stk.emplace(root, -1);\n    while (not stk.empty()) {\n   \
    \     int x, parent; tie(x, parent) = stk.top(); stk.pop();\n        if (parent\
    \ != -1) {\n            data[x] = op.add(x, data[x], parent, op.subtract(parent,\
    \ data[parent], x, data[x]));\n        }\n        for (int y : g[x]) if (y !=\
    \ parent) {\n            stk.emplace(y, x);\n        }\n    }\n    return data;\n\
    }\n\n// \u6CE8\u610F: \u307E\u3060verify\u3057\u3066\u306A\u3044\nstruct height_tree_operation\
    \ {\n    typedef pair<int, int> type;\n    type operator () (int i, vector<pair<int,\
    \ type> > const & args) {\n        type acc = make_pair(INT_MIN, INT_MIN);\n \
    \       for (auto arg : args) {\n            acc = add(i, acc, arg.first, arg.second);\n\
    \        }\n        return acc;\n    }\n    type add(int i, type data_i, int j,\
    \ type data_j) {  // add a subtree j to the root i\n        array<int, 3> height\
    \ = {{ data_i.first, data_i.second, data_j.first + 1 }};  // NOTE: the length\
    \ is corrent\n        sort(height.rbegin(), height.rend());\n        return make_pair(height[0],\
    \ height[1]);\n    }\n    type subtract(int i, type data_i, int j, type data_j)\
    \ {  // remove a subtree j from the root i\n        if (data_i.first == data_j.first\
    \ + 1) {\n            return make_pair(data_i.second, INT_MIN);  // NOTE: this\
    \ is correct\n        } else {\n            return data_i;\n        }\n    }\n\
    };\n\nstruct heights_tree_operation {\n    typedef multiset<int> type;  // heights\
    \ of subtrees\n    type operator () (int i, vector<pair<int, type> > const & args)\
    \ {\n        type data;\n        for (auto arg : args) {\n            data = add(i,\
    \ data, arg.first, arg.second);\n        }\n        return data;\n    }\n    type\
    \ add(int i, type data_i, int j, type data_j) {  // add a subtree j to the root\
    \ i\n        int height = 1 + accumulate(ALL(data_j), 0, [&](int a, int b) { return\
    \ max(a, b); });\n        data_i.insert(height);\n        return data_i;\n   \
    \ }\n    type subtract(int i, type data_i, int j, type data_j) {  // remove a\
    \ subtree j from the root i\n        int height = 1 + accumulate(ALL(data_j),\
    \ 0, [&](int a, int b) { return max(a, b); });\n        auto it = data_i.find(height);\n\
    \        data_i.erase(it);\n        return data_i;\n    }\n};\nunittest {\n  \
    \  vector<vector<int> > g(9);\n    constexpr int root = 0;\n    g[0].push_back(1);\n\
    \    g[0].push_back(2);\n    ;   g[2].push_back(4);\n    ;   g[2].push_back(5);\n\
    \    ;   g[2].push_back(6);\n    ;   ;   g[6].push_back(8);\n    g[0].push_back(3);\n\
    \    ;   g[3].push_back(7);\n    auto dp1 = fold_rooted_tree(g, root, heights_tree_operation());\n\
    \    auto dp2 = reroot_folded_rooted_tree(dp1, g, root, heights_tree_operation());\n\
    \    assert (dp1[root] == dp2[root]);\n    assert (dp1[2] == multiset<int>({ 1,\
    \ 1, 2 }));\n    assert (dp2[2] == multiset<int>({ 1, 1, 2, 3 }));\n    assert\
    \ (dp1[3] == multiset<int>({ 1 }));\n    assert (dp2[3] == multiset<int>({ 1,\
    \ 4 }));\n}\n\n\n\n// \u7C21\u7565\u5316\u3057\u305F\u3084\u3064 \u672A\u691C\u8A3C\
    \n\n/**\n * @brief fold a rooted tree (\u6728DP)\n * @note O(N op) time\n * @note\
    \ O(N) space on stack\n * @note\n *     struct tree_operation {\n *         typedef\
    \ int type;\n *         type unit(int i);  // get an initial value of root i\n\
    \ *         type add(int i, type data_i, int j, type data_j);  // add a subtree\
    \ j to the root i\n *     };\n * @note you can replace unit() + add() with a single\
    \ function\n */\ntemplate <typename TreeOperation>\nvector<typename TreeOperation::type>\
    \ fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op\
    \ = TreeOperation()) {\n    int n = g.size();\n    vector<typename TreeOperation::type>\
    \ data(n);\n    function<void (int, int)> go = [&](int i, int parent) {\n    \
    \    data[i] = op.unit(i);\n        for (int j : g[i]) if (j != parent) {\n  \
    \          go(j, i);\n            data[i] = op.add(i, data[i], j, data[j]);\n\
    \        }\n    };\n    go(root, -1);\n    return data;\n}\n\n/**\n * @brief rerooting\
    \ (\u5168\u65B9\u4F4D\u6728DP)\n * @note O(N op) time\n * @note O(N) space on\
    \ stack\n * @note\n *     struct tree_operation {\n *         typedef int type;\n\
    \ *         type      add(int i, type data_i, int j, type data_j);  // add   \
    \ a subtree j to   the root i\n *         type subtract(int i, type data_i, int\
    \ j, type data_j);  // remove a subtree j from the root i\n *     };\n * @note\
    \ a commutative group is one of the structures for this\n * @note you can replace\
    \ add() + subtract() with a single function\n * @see https://twitter.com/tmaehara/status/980787099472297985\n\
    \ */\ntemplate <typename TreeOperation>\nvector<typename TreeOperation::type>\
    \ reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int>\
    \ > const & g, int root, TreeOperation op = TreeOperation()) {\n    function<void\
    \ (int, int)> go = [&](int i, int parent) {\n        if (parent != -1) {\n   \
    \         data[i] = op.add(i, data[i], op.subtract(parent, data[parent], i, data[i]));\n\
    \        }\n        for (int j : g[i]) if (j != parent) {\n            go(j, i);\n\
    \        }\n    };\n    go(root, -1);\n    return data;\n}\n\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/tree-dp.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/tree-dp.inc.cpp
layout: document
redirect_from:
- /library/old/tree-dp.inc.cpp
- /library/old/tree-dp.inc.cpp.html
title: "fold a rooted tree / \u6728DP"
---
