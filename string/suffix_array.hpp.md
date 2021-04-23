---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/longest_common_prefix.hpp
    title: "Longest Common Prefix / \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (\u63A5\
      \u5C3E\u8F9E\u914D\u5217, \u524D\u51E6\u7406 $O(N (\\log N)^2)$ + $O(1)$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: string/longest_common_prefix.yosupo.test.cpp
    title: string/longest_common_prefix.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.yosupo.test.cpp
    title: string/suffix_array.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$,\
      \ Manber & Myers)"
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n#include <algorithm>\n#include\
    \ <string>\n#include <vector>\n#include <utility>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 7 \"string/suffix_array.hpp\"\n\n/**\n * @brief Suffix Array / \u63A5\u5C3E\u8F9E\
    \u914D\u5217 ($O(N (\\log N)^2)$, Manber & Myers)\n * @arg sa[i] is the index\
    \ of i-th smallest substring of s, s[sa[i], N)\n * @arg rank[i] is the rank of\
    \ substring s[i, N)\n * @note \u87FB\u672C\u3088\u308A\n */\nvoid compute_suffix_array(std::string\
    \ const & s, std::vector<int> & sa, std::vector<int> & rank) {\n    int n = s.length();\n\
    \    sa.resize(n + 1);\n    rank.resize(n + 1);\n    REP (i, n + 1) {\n      \
    \  sa[i] = i;\n        rank[i] = i < n ? s[i] : -1;\n    }\n    auto rankf = [&](int\
    \ i) {\n        return i <= n ? rank[i] : -1;\n    };\n    std::vector<int> nxt(n\
    \ + 1);\n    for (int k = 1; k <= n; k <<= 1) {\n        auto cmp = [&](int i,\
    \ int j) {\n            return std::make_pair(rank[i], rankf(i + k)) < std::make_pair(rank[j],\
    \ rankf(j + k));\n        };\n        std::sort(sa.begin(), sa.end(), cmp);\n\
    \        nxt[sa[0]] = 0;\n        REP3 (i, 1, n + 1) {\n            nxt[sa[i]]\
    \ = nxt[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        rank.swap(nxt);\n\
    \    }\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    #include <utility>\n#include \"utils/macros.hpp\"\n\n/**\n * @brief Suffix Array\
    \ / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$, Manber & Myers)\n * @arg\
    \ sa[i] is the index of i-th smallest substring of s, s[sa[i], N)\n * @arg rank[i]\
    \ is the rank of substring s[i, N)\n * @note \u87FB\u672C\u3088\u308A\n */\nvoid\
    \ compute_suffix_array(std::string const & s, std::vector<int> & sa, std::vector<int>\
    \ & rank) {\n    int n = s.length();\n    sa.resize(n + 1);\n    rank.resize(n\
    \ + 1);\n    REP (i, n + 1) {\n        sa[i] = i;\n        rank[i] = i < n ? s[i]\
    \ : -1;\n    }\n    auto rankf = [&](int i) {\n        return i <= n ? rank[i]\
    \ : -1;\n    };\n    std::vector<int> nxt(n + 1);\n    for (int k = 1; k <= n;\
    \ k <<= 1) {\n        auto cmp = [&](int i, int j) {\n            return std::make_pair(rank[i],\
    \ rankf(i + k)) < std::make_pair(rank[j], rankf(j + k));\n        };\n       \
    \ std::sort(sa.begin(), sa.end(), cmp);\n        nxt[sa[0]] = 0;\n        REP3\
    \ (i, 1, n + 1) {\n            nxt[sa[i]] = nxt[sa[i - 1]] + (cmp(sa[i - 1], sa[i])\
    \ ? 1 : 0);\n        }\n        rank.swap(nxt);\n    }\n}\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy:
  - string/longest_common_prefix.hpp
  timestamp: '2020-03-04 13:12:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/suffix_array.yosupo.test.cpp
  - string/longest_common_prefix.yosupo.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
redirect_from:
- /library/string/suffix_array.hpp
- /library/string/suffix_array.hpp.html
title: "Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$, Manber\
  \ & Myers)"
---
