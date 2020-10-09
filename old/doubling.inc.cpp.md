---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: the doubling technique
    links: []
  bundledCode: "#line 1 \"old/doubling.inc.cpp\"\n/**\n * @brief the doubling technique\n\
    \ */\nstruct doubling_table {\n    vector<vector<int> > table;\n    doubling_table()\
    \ = default;\n    /**\n     * @note O(N log K)\n     */\n    doubling_table(vector<int>\
    \ const & next, int size = -1) {\n        int n = next.size();\n        {\n  \
    \          auto it = minmax_element(ALL(next));\n            assert (0 <= *(it.first)\
    \ and *(it.second) <= n);\n        }\n        if (size == -1) {\n            size\
    \ = max<int>(1, ceil(log2(n)));\n        }\n        table.resize(size);\n    \
    \    table[0] = next;\n        REP (k, size - 1) {\n            table[k + 1].resize(n,\
    \ n);\n            REP (i, n) if (table[k][i] != n) {\n                table[k\
    \ + 1][i] = table[k][table[k][i]];\n            }\n        }\n    }\n    /**\n\
    \     * @note O(log K)\n     */\n    int get(int i, int count) {\n        assert\
    \ (count < (1 << table.size()));\n        int n = table[0].size();\n        if\
    \ (i == n) return n;\n        assert (0 <= i and i < n);\n        REP_R (k, table.size())\
    \ if (count & (1 << k)) {\n            i = table[k][i];\n            if (i ==\
    \ n) return n;\n        }\n        return i;\n    }\n};\n\nunittest {\n    vector<int>\
    \ step { 1, 3, 3, 4, 5, 6, 8, 8, 9, 10 };\n    doubling_table steps(step);\n \
    \   assert (steps.get(6, 2) == step[step[6]]);\n    assert (steps.get(3, 5) ==\
    \ step[step[step[step[step[3]]]]]);\n}\n"
  code: "/**\n * @brief the doubling technique\n */\nstruct doubling_table {\n   \
    \ vector<vector<int> > table;\n    doubling_table() = default;\n    /**\n    \
    \ * @note O(N log K)\n     */\n    doubling_table(vector<int> const & next, int\
    \ size = -1) {\n        int n = next.size();\n        {\n            auto it =\
    \ minmax_element(ALL(next));\n            assert (0 <= *(it.first) and *(it.second)\
    \ <= n);\n        }\n        if (size == -1) {\n            size = max<int>(1,\
    \ ceil(log2(n)));\n        }\n        table.resize(size);\n        table[0] =\
    \ next;\n        REP (k, size - 1) {\n            table[k + 1].resize(n, n);\n\
    \            REP (i, n) if (table[k][i] != n) {\n                table[k + 1][i]\
    \ = table[k][table[k][i]];\n            }\n        }\n    }\n    /**\n     * @note\
    \ O(log K)\n     */\n    int get(int i, int count) {\n        assert (count <\
    \ (1 << table.size()));\n        int n = table[0].size();\n        if (i == n)\
    \ return n;\n        assert (0 <= i and i < n);\n        REP_R (k, table.size())\
    \ if (count & (1 << k)) {\n            i = table[k][i];\n            if (i ==\
    \ n) return n;\n        }\n        return i;\n    }\n};\n\nunittest {\n    vector<int>\
    \ step { 1, 3, 3, 4, 5, 6, 8, 8, 9, 10 };\n    doubling_table steps(step);\n \
    \   assert (steps.get(6, 2) == step[step[6]]);\n    assert (steps.get(3, 5) ==\
    \ step[step[step[step[step[3]]]]]);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/doubling.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/doubling.inc.cpp
layout: document
redirect_from:
- /library/old/doubling.inc.cpp
- /library/old/doubling.inc.cpp.html
title: the doubling technique
---
