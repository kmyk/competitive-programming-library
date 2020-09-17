---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://snuke.hatenablog.com/entry/2014/12/02/235837
  bundledCode: "#line 1 \"old/palindrome.inc.cpp\"\n/**\n * @return radiuses of odd\
    \ palindromes\n * @note O(N)\n * @sa http://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    \ */\ntemplate <class RandomAccessIterator>\nvector<int> manacher(RandomAccessIterator\
    \ first, RandomAccessIterator last) {\n    int n = distance(first, last);\n  \
    \  vector<int> r(n);\n    int i = 0, j = 0;\n    while (i < n) {\n        while\
    \ (i - j >= 0 and i + j < n and first[i - j] == first[i + j]) {\n            ++\
    \ j;\n        }\n        r[i] = j;\n        int k = 1;\n        while (i - k >=\
    \ 0 and i + k < n and k + r[i - k] < j) {\n            r[i + k] = r[i - k];\n\
    \            ++ k;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ r;\n}\n\nvector<int> odd_palindrome_length(string const & s) {\n    int n =\
    \ s.length();\n    vector<int> r = manacher(ALL(s));\n    vector<int> l(n);\n\
    \    REP (i, n) l[i - r[i] + 1] = 2 * r[i] - 1;\n    REP (i, n-1) chmax(l[i +\
    \ 1], l[i] - 2);\n    return l;\n}\n/**\n * @note s must not contain '\\xff'\n\
    \ */\nvector<int> even_palindrome_length(string const & s) {\n    int n = s.length();\n\
    \    string t(2 * n + 1, '\\xff');\n    REP (i, n) t[2 * i + 1] = s[i];\n    vector<int>\
    \ r = manacher(ALL(t));\n    vector<int> l(n);\n    REP (i, n) if (r[2 * i + 2]\
    \ >= 3) {\n        l[i - r[2 * i + 2] / 2 + 1] = r[2 * i + 2] - 1;\n    }\n  \
    \  REP (i, n-1) chmax(l[i + 1], l[i] - 2);\n    return l;\n}\n\nunittest {\n \
    \   string x = \"abaaababa\";\n    vector<int> y = { 1, 2, 1, 4, 1, 2, 3, 2, 1\
    \ };\n    assert (manacher(ALL(x)) == y);\n}\n\nstruct prepared_manacher {\n \
    \   vector<int> odd;\n    vector<int> even;\n    prepared_manacher(string const\
    \ & s) {\n        int n = s.length();\n        string t(2 * n + 1, '\\xff');\n\
    \        REP (i, n) t[2 * i + 1] = s[i];\n        odd = manacher(ALL(s));\n  \
    \      even = manacher(ALL(t));\n    }\n\n    /**\n     * @return wheter s[l,\
    \ r) is a palindrome or not\n     */\n    bool operator () (int l, int r) const\
    \ {\n        assert (0 <= l and l <= r and r <= odd.size());\n        if ((r -\
    \ l) % 2 == 0) {\n            l *= 2;\n            r *= 2;\n            int m\
    \ = (l + r) / 2;\n            return r - m <= even[m];\n        } else {\n   \
    \         int m = (l + r) / 2;\n            return r - m <= odd[m];\n        }\n\
    \    }\n};\n"
  code: "/**\n * @return radiuses of odd palindromes\n * @note O(N)\n * @sa http://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    \ */\ntemplate <class RandomAccessIterator>\nvector<int> manacher(RandomAccessIterator\
    \ first, RandomAccessIterator last) {\n    int n = distance(first, last);\n  \
    \  vector<int> r(n);\n    int i = 0, j = 0;\n    while (i < n) {\n        while\
    \ (i - j >= 0 and i + j < n and first[i - j] == first[i + j]) {\n            ++\
    \ j;\n        }\n        r[i] = j;\n        int k = 1;\n        while (i - k >=\
    \ 0 and i + k < n and k + r[i - k] < j) {\n            r[i + k] = r[i - k];\n\
    \            ++ k;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ r;\n}\n\nvector<int> odd_palindrome_length(string const & s) {\n    int n =\
    \ s.length();\n    vector<int> r = manacher(ALL(s));\n    vector<int> l(n);\n\
    \    REP (i, n) l[i - r[i] + 1] = 2 * r[i] - 1;\n    REP (i, n-1) chmax(l[i +\
    \ 1], l[i] - 2);\n    return l;\n}\n/**\n * @note s must not contain '\\xff'\n\
    \ */\nvector<int> even_palindrome_length(string const & s) {\n    int n = s.length();\n\
    \    string t(2 * n + 1, '\\xff');\n    REP (i, n) t[2 * i + 1] = s[i];\n    vector<int>\
    \ r = manacher(ALL(t));\n    vector<int> l(n);\n    REP (i, n) if (r[2 * i + 2]\
    \ >= 3) {\n        l[i - r[2 * i + 2] / 2 + 1] = r[2 * i + 2] - 1;\n    }\n  \
    \  REP (i, n-1) chmax(l[i + 1], l[i] - 2);\n    return l;\n}\n\nunittest {\n \
    \   string x = \"abaaababa\";\n    vector<int> y = { 1, 2, 1, 4, 1, 2, 3, 2, 1\
    \ };\n    assert (manacher(ALL(x)) == y);\n}\n\nstruct prepared_manacher {\n \
    \   vector<int> odd;\n    vector<int> even;\n    prepared_manacher(string const\
    \ & s) {\n        int n = s.length();\n        string t(2 * n + 1, '\\xff');\n\
    \        REP (i, n) t[2 * i + 1] = s[i];\n        odd = manacher(ALL(s));\n  \
    \      even = manacher(ALL(t));\n    }\n\n    /**\n     * @return wheter s[l,\
    \ r) is a palindrome or not\n     */\n    bool operator () (int l, int r) const\
    \ {\n        assert (0 <= l and l <= r and r <= odd.size());\n        if ((r -\
    \ l) % 2 == 0) {\n            l *= 2;\n            r *= 2;\n            int m\
    \ = (l + r) / 2;\n            return r - m <= even[m];\n        } else {\n   \
    \         int m = (l + r) / 2;\n            return r - m <= odd[m];\n        }\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/palindrome.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/palindrome.inc.cpp
layout: document
redirect_from:
- /library/old/palindrome.inc.cpp
- /library/old/palindrome.inc.cpp.html
title: old/palindrome.inc.cpp
---
