---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://sigma425.hatenablog.com/entry/2015/12/25/224053
  bundledCode: "#line 1 \"old/dominator-tree.inc.cpp\"\n// http://sigma425.hatenablog.com/entry/2015/12/25/224053\n\
    vector<int> dominator_tree(vector<vector<int> > const & g, int root_g) { // G\
    \ is a digraph which any vertex can be reached from the root\n    int n = g.size();\n\
    \    vector<vector<int> > invert_g(n);\n    repeat (i,n) for (int j : g[i]) invert_g[j].push_back(i);\n\
    \    // 1. make dfs tree\n    vector<int> to_rank(n, -1); // index on original\
    \ digraph G -> index on dfs-tree T\n    vector<int> from_rank(n);\n    vector<int>\
    \ parent(n, -1); // on dfs-tree T, indexed on G\n    { // init\n        int next_rank\
    \ = 0;\n        function<void (int)> dfs = [&](int i) {\n            to_rank[i]\
    \ = next_rank;\n            from_rank[next_rank] = i;\n            ++ next_rank;\n\
    \            for (int j : g[i]) if (to_rank[j] == -1) {\n                parent[j]\
    \ = i;\n                dfs(j);\n            }\n        };\n        dfs(root_g);\n\
    \    }\n    // x. check connectivity\n    repeat (i,n) assert (to_rank[i] != -1);\
    \ // or disconnected graph\n    // 2. compute sdom\n    vector<int> sdom(n);\n\
    \    repeat (i,n) sdom[i] = to_rank[i];\n    vector<int> foo(n, -1); // vertex,\
    \ used in 3.\n    // 2.1. union-find tree\n    vector<int> root(n); whole(iota,\
    \ root, 0);\n    vector<int> min_sdom_index(n); whole(iota, min_sdom_index, 0);\
    \ // data on union-find tree\n    function<int (int)> find = [&](int i) {\n  \
    \      if (root[i] == i) return i;\n        int j = find(root[i]);\n        if\
    \ (sdom[min_sdom_index[root[i]]] < sdom[min_sdom_index[i]]) {\n            min_sdom_index[i]\
    \ = min_sdom_index[root[i]];\n        }\n        return root[i] = j;\n    };\n\
    \    auto link = [&](int i, int j) {\n        assert (root[j] == j);\n       \
    \ root[j] = i;\n    };\n    vector<vector<int> > bucket(n);\n    for (int rank_i\
    \ = n-1; rank_i >= 1; -- rank_i) {\n        // 2.2. compute sdom\n        int\
    \ i = from_rank[rank_i];\n        for (int j : invert_g[i]) {\n            //\
    \ int rank_j = to_rank[j];\n            // if (rank_j < rank_i) { // up\n    \
    \        //     setmin(sdom[i], rank_j);\n            // }\n            find(j);\n\
    \            setmin(sdom[i], sdom[min_sdom_index[j]]);\n        }\n        //\
    \ 2.3. compute foo\n        bucket[from_rank[sdom[i]]].push_back(i);\n       \
    \ for (int j : bucket[parent[i]]) {\n            find(j);\n            foo[j]\
    \ = min_sdom_index[j];\n        }\n        bucket[parent[i]] = vector<int>();\
    \ // clear\n        // 2.4. link\n        link(parent[i], i);\n    }\n    // 3.\
    \ compute idom\n    vector<int> idom(n);\n    repeat_from (rank_i,1,n) {\n   \
    \     int i = from_rank[rank_i];\n        int j = foo[i];\n        idom[i] = (sdom[i]\
    \ == sdom[j] ? sdom : idom)[j];\n    }\n    vector<int> result(n);\n    repeat\
    \ (i,n) if (i != root_g) {\n        result[i] = from_rank[idom[i]];\n    }\n \
    \   result[root_g] = -1;\n    return result;\n}\n"
  code: "// http://sigma425.hatenablog.com/entry/2015/12/25/224053\nvector<int> dominator_tree(vector<vector<int>\
    \ > const & g, int root_g) { // G is a digraph which any vertex can be reached\
    \ from the root\n    int n = g.size();\n    vector<vector<int> > invert_g(n);\n\
    \    repeat (i,n) for (int j : g[i]) invert_g[j].push_back(i);\n    // 1. make\
    \ dfs tree\n    vector<int> to_rank(n, -1); // index on original digraph G ->\
    \ index on dfs-tree T\n    vector<int> from_rank(n);\n    vector<int> parent(n,\
    \ -1); // on dfs-tree T, indexed on G\n    { // init\n        int next_rank =\
    \ 0;\n        function<void (int)> dfs = [&](int i) {\n            to_rank[i]\
    \ = next_rank;\n            from_rank[next_rank] = i;\n            ++ next_rank;\n\
    \            for (int j : g[i]) if (to_rank[j] == -1) {\n                parent[j]\
    \ = i;\n                dfs(j);\n            }\n        };\n        dfs(root_g);\n\
    \    }\n    // x. check connectivity\n    repeat (i,n) assert (to_rank[i] != -1);\
    \ // or disconnected graph\n    // 2. compute sdom\n    vector<int> sdom(n);\n\
    \    repeat (i,n) sdom[i] = to_rank[i];\n    vector<int> foo(n, -1); // vertex,\
    \ used in 3.\n    // 2.1. union-find tree\n    vector<int> root(n); whole(iota,\
    \ root, 0);\n    vector<int> min_sdom_index(n); whole(iota, min_sdom_index, 0);\
    \ // data on union-find tree\n    function<int (int)> find = [&](int i) {\n  \
    \      if (root[i] == i) return i;\n        int j = find(root[i]);\n        if\
    \ (sdom[min_sdom_index[root[i]]] < sdom[min_sdom_index[i]]) {\n            min_sdom_index[i]\
    \ = min_sdom_index[root[i]];\n        }\n        return root[i] = j;\n    };\n\
    \    auto link = [&](int i, int j) {\n        assert (root[j] == j);\n       \
    \ root[j] = i;\n    };\n    vector<vector<int> > bucket(n);\n    for (int rank_i\
    \ = n-1; rank_i >= 1; -- rank_i) {\n        // 2.2. compute sdom\n        int\
    \ i = from_rank[rank_i];\n        for (int j : invert_g[i]) {\n            //\
    \ int rank_j = to_rank[j];\n            // if (rank_j < rank_i) { // up\n    \
    \        //     setmin(sdom[i], rank_j);\n            // }\n            find(j);\n\
    \            setmin(sdom[i], sdom[min_sdom_index[j]]);\n        }\n        //\
    \ 2.3. compute foo\n        bucket[from_rank[sdom[i]]].push_back(i);\n       \
    \ for (int j : bucket[parent[i]]) {\n            find(j);\n            foo[j]\
    \ = min_sdom_index[j];\n        }\n        bucket[parent[i]] = vector<int>();\
    \ // clear\n        // 2.4. link\n        link(parent[i], i);\n    }\n    // 3.\
    \ compute idom\n    vector<int> idom(n);\n    repeat_from (rank_i,1,n) {\n   \
    \     int i = from_rank[rank_i];\n        int j = foo[i];\n        idom[i] = (sdom[i]\
    \ == sdom[j] ? sdom : idom)[j];\n    }\n    vector<int> result(n);\n    repeat\
    \ (i,n) if (i != root_g) {\n        result[i] = from_rank[idom[i]];\n    }\n \
    \   result[root_g] = -1;\n    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/dominator-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/dominator-tree.inc.cpp
layout: document
redirect_from:
- /library/old/dominator-tree.inc.cpp
- /library/old/dominator-tree.inc.cpp.html
title: old/dominator-tree.inc.cpp
---
