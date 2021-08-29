---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table (idempotent monoid)
  - icon: ':heavy_check_mark:'
    path: monoids/min.hpp
    title: monoids/min.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: "Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$, Manber\
      \ & Myers)"
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: string/longest_common_prefix.yosupo.test.cpp
    title: string/longest_common_prefix.yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Longest Common Prefix / \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
      \ (\u63A5\u5C3E\u8F9E\u914D\u5217, \u524D\u51E6\u7406 $O(N (\\log N)^2)$ + $O(1)$)"
    links: []
  bundledCode: "#line 2 \"string/longest_common_prefix.hpp\"\n#include <algorithm>\n\
    #include <string>\n#include <vector>\n#line 5 \"string/suffix_array.hpp\"\n#include\
    \ <utility>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 7 \"string/suffix_array.hpp\"\n\n/**\n\
    \ * @brief Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$,\
    \ Manber & Myers)\n * @arg sa[i] is the index of i-th smallest substring of s,\
    \ s[sa[i], N)\n * @arg rank[i] is the rank of substring s[i, N)\n * @note \u87FB\
    \u672C\u3088\u308A\n */\nvoid compute_suffix_array(std::string const & s, std::vector<int>\
    \ & sa, std::vector<int> & rank) {\n    int n = s.length();\n    sa.resize(n +\
    \ 1);\n    rank.resize(n + 1);\n    REP (i, n + 1) {\n        sa[i] = i;\n   \
    \     rank[i] = i < n ? s[i] : -1;\n    }\n    auto rankf = [&](int i) {\n   \
    \     return i <= n ? rank[i] : -1;\n    };\n    std::vector<int> nxt(n + 1);\n\
    \    for (int k = 1; k <= n; k <<= 1) {\n        auto cmp = [&](int i, int j)\
    \ {\n            return std::make_pair(rank[i], rankf(i + k)) < std::make_pair(rank[j],\
    \ rankf(j + k));\n        };\n        std::sort(sa.begin(), sa.end(), cmp);\n\
    \        nxt[sa[0]] = 0;\n        REP3 (i, 1, n + 1) {\n            nxt[sa[i]]\
    \ = nxt[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        rank.swap(nxt);\n\
    \    }\n}\n#line 2 \"data_structure/sparse_table.hpp\"\n#include <cassert>\n#line\
    \ 5 \"data_structure/sparse_table.hpp\"\n\n/**\n * @brief Sparse Table (idempotent\
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
    \ table[k][r - (1ll << k)]);\n    }\n};\n#line 3 \"monoids/min.hpp\"\n#include\
    \ <limits>\n\ntemplate <class T>\nstruct min_monoid {\n    typedef T value_type;\n\
    \    value_type unit() const { return std::numeric_limits<T>::max(); }\n    value_type\
    \ mult(value_type a, value_type b) const { return std::min(a, b); }\n};\n#line\
    \ 8 \"string/longest_common_prefix.hpp\"\n\n/**\n * @brief Longest Common Prefix\
    \ / \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (\u63A5\u5C3E\u8F9E\u914D\u5217\
    , \u524D\u51E6\u7406 $O(N (\\log N)^2)$ + $O(1)$)\n */\nclass longest_common_prefix\
    \ {\n    std::vector<int> rank;\n    sparse_table<min_monoid<int> > table;\n\n\
    \    void initialize(const std::string & s, const std::vector<int> & sa) {\n \
    \       int n = s.length();\n        std::vector<int> lcp(n, -1);  // lcp[i] is\
    \ the length of the common prefix between i-th and (i+1)-th substring of s\n \
    \       int h = 0;\n        lcp[0] = 0;\n        REP (i, n) {\n            int\
    \ j = sa[rank[i] - 1];\n            if (h > 0) -- h;\n            while (j + h\
    \ < n and i + h < n and s[j + h] == s[i + h]) ++ h;\n            lcp[rank[i] -\
    \ 1] = h;\n        }\n        table = sparse_table<min_monoid<int> >(ALL(lcp));\n\
    \    }\n\npublic:\n    longest_common_prefix(const std::string & s) {\n      \
    \  std::vector<int> sa;\n        compute_suffix_array(s, sa, rank);\n        initialize(s,\
    \ sa);\n    }\n    longest_common_prefix(const std::string & s, const std::vector<int>\
    \ & sa, const std::vector<int> & rank_)\n            : rank(rank_) {\n       \
    \ initialize(s, sa);\n    }\n\n    int get(int i, int j) const {\n        int\
    \ l = rank[i];\n        int r = rank[j];\n        if (l > r) std::swap(l, r);\n\
    \        int n = rank.size() - 1;\n        return std::min(n, table.range_get(l,\
    \ r));\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    #include \"../string/suffix_array.hpp\"\n#include \"../data_structure/sparse_table.hpp\"\
    \n#include \"../monoids/min.hpp\"\n\n/**\n * @brief Longest Common Prefix / \u6700\
    \u9577\u5171\u901A\u63A5\u982D\u8F9E (\u63A5\u5C3E\u8F9E\u914D\u5217, \u524D\u51E6\
    \u7406 $O(N (\\log N)^2)$ + $O(1)$)\n */\nclass longest_common_prefix {\n    std::vector<int>\
    \ rank;\n    sparse_table<min_monoid<int> > table;\n\n    void initialize(const\
    \ std::string & s, const std::vector<int> & sa) {\n        int n = s.length();\n\
    \        std::vector<int> lcp(n, -1);  // lcp[i] is the length of the common prefix\
    \ between i-th and (i+1)-th substring of s\n        int h = 0;\n        lcp[0]\
    \ = 0;\n        REP (i, n) {\n            int j = sa[rank[i] - 1];\n         \
    \   if (h > 0) -- h;\n            while (j + h < n and i + h < n and s[j + h]\
    \ == s[i + h]) ++ h;\n            lcp[rank[i] - 1] = h;\n        }\n        table\
    \ = sparse_table<min_monoid<int> >(ALL(lcp));\n    }\n\npublic:\n    longest_common_prefix(const\
    \ std::string & s) {\n        std::vector<int> sa;\n        compute_suffix_array(s,\
    \ sa, rank);\n        initialize(s, sa);\n    }\n    longest_common_prefix(const\
    \ std::string & s, const std::vector<int> & sa, const std::vector<int> & rank_)\n\
    \            : rank(rank_) {\n        initialize(s, sa);\n    }\n\n    int get(int\
    \ i, int j) const {\n        int l = rank[i];\n        int r = rank[j];\n    \
    \    if (l > r) std::swap(l, r);\n        int n = rank.size() - 1;\n        return\
    \ std::min(n, table.range_get(l, r));\n    }\n};\n"
  dependsOn:
  - string/suffix_array.hpp
  - utils/macros.hpp
  - data_structure/sparse_table.hpp
  - monoids/min.hpp
  isVerificationFile: false
  path: string/longest_common_prefix.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/longest_common_prefix.yosupo.test.cpp
documentation_of: string/longest_common_prefix.hpp
layout: document
redirect_from:
- /library/string/longest_common_prefix.hpp
- /library/string/longest_common_prefix.hpp.html
title: "Longest Common Prefix / \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (\u63A5\
  \u5C3E\u8F9E\u914D\u5217, \u524D\u51E6\u7406 $O(N (\\log N)^2)$ + $O(1)$)"
---
