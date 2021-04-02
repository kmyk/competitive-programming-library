---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find_tree.hpp
    title: Union-Find Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"data_structure/union_find_tree.yosupo.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"data_structure/union_find_tree.hpp\"\
    \n#include <vector>\n\n/**\n * @brief Union-Find Tree\n * @docs data_structure/union_find_tree.md\n\
    \ * @note union-by-size + path-compression\n */\nstruct union_find_tree {\n  \
    \  std::vector<int> data;\n    union_find_tree() = default;\n    explicit union_find_tree(std::size_t\
    \ n) : data(n, -1) {}\n    bool is_root(int i) { return data[i] < 0; }\n    int\
    \ find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }\n\
    \    int tree_size(int i) { return - data[find_root(i)]; }\n    int unite_trees(int\
    \ i, int j) {\n        i = find_root(i); j = find_root(j);\n        if (i != j)\
    \ {\n            if (tree_size(i) < tree_size(j)) std::swap(i, j);\n         \
    \   data[i] += data[j];\n            data[j] = i;\n        }\n        return i;\n\
    \    }\n    bool is_same(int i, int j) { return find_root(i) == find_root(j);\
    \ }\n};\n#line 3 \"data_structure/union_find_tree.yosupo.test.cpp\"\n#include\
    \ <cstdio>\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n    union_find_tree\
    \ uft(n);\n    while (q --) {\n        int t, u, v; scanf(\"%d%d%d\", &t, &u,\
    \ &v);\n        if (t == 0) {\n            uft.unite_trees(u, v);\n        } else\
    \ if (t == 1) {\n            bool answer = uft.is_same(u, v);\n            printf(\"\
    %d\\n\", (int)answer);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    data_structure/union_find_tree.hpp\"\n#include <cstdio>\n\nint main() {\n    int\
    \ n, q; scanf(\"%d%d\", &n, &q);\n    union_find_tree uft(n);\n    while (q --)\
    \ {\n        int t, u, v; scanf(\"%d%d%d\", &t, &u, &v);\n        if (t == 0)\
    \ {\n            uft.unite_trees(u, v);\n        } else if (t == 1) {\n      \
    \      bool answer = uft.is_same(u, v);\n            printf(\"%d\\n\", (int)answer);\n\
    \        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/union_find_tree.hpp
  isVerificationFile: true
  path: data_structure/union_find_tree.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-02-28 14:33:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/union_find_tree.yosupo.test.cpp
layout: document
redirect_from:
- /verify/data_structure/union_find_tree.yosupo.test.cpp
- /verify/data_structure/union_find_tree.yosupo.test.cpp.html
title: data_structure/union_find_tree.yosupo.test.cpp
---
