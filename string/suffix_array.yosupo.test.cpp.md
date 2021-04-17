---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: "Suffix Array / \u63A5\u5C3E\u8F9E\u914D\u5217 ($O(N (\\log N)^2)$, Manber\
      \ & Myers)"
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"string/suffix_array.yosupo.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/suffixarray\"\n#include <cassert>\n#include <string>\n\
    #include <vector>\n#line 2 \"string/suffix_array.hpp\"\n#include <algorithm>\n\
    #line 5 \"string/suffix_array.hpp\"\n#include <utility>\n#line 2 \"utils/macros.hpp\"\
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
    \    }\n}\n#line 2 \"hack/fastio.hpp\"\n#include <cstdint>\n#include <cstdio>\n\
    #line 5 \"hack/fastio.hpp\"\n#include <type_traits>\n\ntemplate <class Char, std::enable_if_t<std::is_same_v<Char,\
    \ char>, int> = 0>\ninline Char in() { return getchar_unlocked(); }\ntemplate\
    \ <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> =\
    \ 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked(); } while\
    \ (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while (not isspace(c\
    \ = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>\
    \ and not std::is_same_v<Integer, char>, int> = 0>\ninline Integer in() {\n  \
    \  char c; do { c = getchar_unlocked(); } while (isspace(c));\n    if (std::is_signed<Integer>::value\
    \ and c == '-') return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10\
    \ + c - '0'; } while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline void out(char c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n#line 7 \"string/suffix_array.yosupo.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    // input\n    string s = in<string>();\n    int n\
    \ = s.length();\n\n    // solve\n    vector<int> sa, rank;\n    compute_suffix_array(s,\
    \ sa, rank);\n    assert ((int)sa.size() == n + 1);\n    assert (sa[0] == n);\n\
    \n    // output\n    REP (i, n) {\n        out<int>(sa[i + 1]);\n        out<char>(i\
    \ < n - 1 ? ' ' : '\\n');\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ <cassert>\n#include <string>\n#include <vector>\n#include \"string/suffix_array.hpp\"\
    \n#include \"hack/fastio.hpp\"\nusing namespace std;\n\nint main() {\n    // input\n\
    \    string s = in<string>();\n    int n = s.length();\n\n    // solve\n    vector<int>\
    \ sa, rank;\n    compute_suffix_array(s, sa, rank);\n    assert ((int)sa.size()\
    \ == n + 1);\n    assert (sa[0] == n);\n\n    // output\n    REP (i, n) {\n  \
    \      out<int>(sa[i + 1]);\n        out<char>(i < n - 1 ? ' ' : '\\n');\n   \
    \ }\n    return 0;\n}\n"
  dependsOn:
  - string/suffix_array.hpp
  - utils/macros.hpp
  - hack/fastio.hpp
  isVerificationFile: true
  path: string/suffix_array.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-06-13 00:00:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: string/suffix_array.yosupo.test.cpp
layout: document
redirect_from:
- /verify/string/suffix_array.yosupo.test.cpp
- /verify/string/suffix_array.yosupo.test.cpp.html
title: string/suffix_array.yosupo.test.cpp
---
