---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://beta.atcoder.jp/contests/yahoo-procon2018-final/submissions/2126707
  bundledCode: "#line 1 \"old/range-union-find-tree.inc.cpp\"\n/**\n * @note \u8A08\
    \u7B97\u91CF\u306F\u78BA\u304B\u306B\u843D\u3061\u308B\u306E\u3060\u3051\u3069\
    \u3053\u308C\u3092\u4F7F\u3063\u3066\u901F\u304F\u306A\u308B\u30B1\u30FC\u30B9\
    \u306F\u5143\u3005\u5168\u90E8\u9023\u7D50\u3057\u3066\u3066\u81EA\u660E\u306A\
    \u6C17\u304C\u3059\u308B\n * @note thank to https://beta.atcoder.jp/contests/yahoo-procon2018-final/submissions/2126707\n\
    \ */\nstruct range_union_find_tree {\n    vector<union_find_tree> data;\n    range_union_find_tree()\
    \ = default;\n    explicit range_union_find_tree(size_t n) {\n        int log_n\
    \ = 32 - __builtin_clz(n);\n        data.resize(log_n, union_find_tree(n));\n\
    \    }\n    /**\n     * @description unite (l1 + k)-th tree and (l2 + k)-th tree\
    \ for each k in [0, len)\n     * @note O(1)\n     */\n    void range_unite_trees(int\
    \ l1, int l2, int len) {\n        int n = data.front().data.size();\n        assert\
    \ (0 <= l1 and l1 + len <= n);\n        assert (0 <= l2 and l2 + len <= n);\n\
    \        assert (len >= 1);\n        int k = 31 - __builtin_clz(len);  // log2\n\
    \        data[k].unite_trees(l1, l2);\n        data[k].unite_trees(l1 + len -\
    \ (1 << k), l2 + len - (1 << k));\n    }\n    /**\n     * @description collapse\
    \ range-queries and get result\n     * @note O(N \\log N)\n     */\n    union_find_tree\
    \ const & update() {\n        int n = data.front().data.size();\n        int log_n\
    \ = data.size();\n        REP_R (k, log_n - 1) {\n            REP (i, n - (1 <<\
    \ k)) {\n                int root = data[k + 1].find_root(i);\n              \
    \  data[k].unite_trees(i, root);\n                data[k].unite_trees(i + (1 <<\
    \ k), root + (1 << k));\n            }\n        }\n        return data[0];\n \
    \   }\n};\n"
  code: "/**\n * @note \u8A08\u7B97\u91CF\u306F\u78BA\u304B\u306B\u843D\u3061\u308B\
    \u306E\u3060\u3051\u3069\u3053\u308C\u3092\u4F7F\u3063\u3066\u901F\u304F\u306A\
    \u308B\u30B1\u30FC\u30B9\u306F\u5143\u3005\u5168\u90E8\u9023\u7D50\u3057\u3066\
    \u3066\u81EA\u660E\u306A\u6C17\u304C\u3059\u308B\n * @note thank to https://beta.atcoder.jp/contests/yahoo-procon2018-final/submissions/2126707\n\
    \ */\nstruct range_union_find_tree {\n    vector<union_find_tree> data;\n    range_union_find_tree()\
    \ = default;\n    explicit range_union_find_tree(size_t n) {\n        int log_n\
    \ = 32 - __builtin_clz(n);\n        data.resize(log_n, union_find_tree(n));\n\
    \    }\n    /**\n     * @description unite (l1 + k)-th tree and (l2 + k)-th tree\
    \ for each k in [0, len)\n     * @note O(1)\n     */\n    void range_unite_trees(int\
    \ l1, int l2, int len) {\n        int n = data.front().data.size();\n        assert\
    \ (0 <= l1 and l1 + len <= n);\n        assert (0 <= l2 and l2 + len <= n);\n\
    \        assert (len >= 1);\n        int k = 31 - __builtin_clz(len);  // log2\n\
    \        data[k].unite_trees(l1, l2);\n        data[k].unite_trees(l1 + len -\
    \ (1 << k), l2 + len - (1 << k));\n    }\n    /**\n     * @description collapse\
    \ range-queries and get result\n     * @note O(N \\log N)\n     */\n    union_find_tree\
    \ const & update() {\n        int n = data.front().data.size();\n        int log_n\
    \ = data.size();\n        REP_R (k, log_n - 1) {\n            REP (i, n - (1 <<\
    \ k)) {\n                int root = data[k + 1].find_root(i);\n              \
    \  data[k].unite_trees(i, root);\n                data[k].unite_trees(i + (1 <<\
    \ k), root + (1 << k));\n            }\n        }\n        return data[0];\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/range-union-find-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/range-union-find-tree.inc.cpp
layout: document
redirect_from:
- /library/old/range-union-find-tree.inc.cpp
- /library/old/range-union-find-tree.inc.cpp.html
title: old/range-union-find-tree.inc.cpp
---
