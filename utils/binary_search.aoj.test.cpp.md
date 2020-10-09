---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/binary_search.hpp
    title: "a binary search / \u4E8C\u5206\u63A2\u7D22"
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
  bundledCode: "#line 1 \"utils/binary_search.aoj.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n#line 2 \"utils/binary_search.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    \n/**\n * @brief a binary search / \u4E8C\u5206\u63A2\u7D22\n * @param[in] p \
    \ a monotone predicate defined on $[l, r)$\n * @return $\\min \\lbrace x \\in\
    \ [l, r) \\mid p(x) \\rbrace$, or r if it doesn't exist\n */\ntemplate <typename\
    \ UnaryPredicate>\nint64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {\n\
    \    assert (l <= r);\n    -- l;\n    while (r - l > 1) {\n        int64_t m =\
    \ l + (r - l) / 2;\n        (p(m) ? r : l) = m;\n    }\n    return r;\n}\n\n/**\n\
    \ * @return $\\max \\lbrace x \\in (l, r] \\mid p(x) \\rbrace$, or l if it doesn't\
    \ exist\n */\ntemplate <typename UnaryPredicate>\nint64_t binsearch_max(int64_t\
    \ l, int64_t r, UnaryPredicate p) {\n    assert (l <= r);\n    ++ r;\n    while\
    \ (r - l > 1) {\n        int64_t m = l + (r - l) / 2;\n        (p(m) ? l : r)\
    \ = m;\n    }\n    return l;\n}\n#line 3 \"utils/binary_search.aoj.test.cpp\"\n\
    \n#line 6 \"utils/binary_search.aoj.test.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i)\
    \ < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n);\
    \ ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n\
    #define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define\
    \ ALL(x) std::begin(x), std::end(x)\n#line 9 \"utils/binary_search.aoj.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int>\
    \ s(n);\n    REP (i, n) {\n        cin >> s[i];\n    }\n\n    int q; cin >> q;\n\
    \    int64_t cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n    \
    \    int l = binsearch(0, n, [&](int i) {\n            return s[i] >= t_i;\n \
    \       });\n        cnt += (l < n and s[l] == t_i);\n\n        int r = binsearch_max(0,\
    \ n, [&](int i) {\n            return s[i] <= t_i;\n        });\n        assert\
    \ ((l < n and s[l] == t_i) == (l <= r));\n    }\n\n    cout << cnt << endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n#include \"utils/binary_search.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    #include <iostream>\n#include <vector>\n#include \"utils/macros.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n    REP (i,\
    \ n) {\n        cin >> s[i];\n    }\n\n    int q; cin >> q;\n    int64_t cnt =\
    \ 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        int l = binsearch(0,\
    \ n, [&](int i) {\n            return s[i] >= t_i;\n        });\n        cnt +=\
    \ (l < n and s[l] == t_i);\n\n        int r = binsearch_max(0, n, [&](int i) {\n\
    \            return s[i] <= t_i;\n        });\n        assert ((l < n and s[l]\
    \ == t_i) == (l <= r));\n    }\n\n    cout << cnt << endl;\n    return 0;\n}\n"
  dependsOn:
  - utils/binary_search.hpp
  - utils/macros.hpp
  isVerificationFile: true
  path: utils/binary_search.aoj.test.cpp
  requiredBy: []
  timestamp: '2019-12-20 06:12:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: utils/binary_search.aoj.test.cpp
layout: document
redirect_from:
- /verify/utils/binary_search.aoj.test.cpp
- /verify/utils/binary_search.aoj.test.cpp.html
title: utils/binary_search.aoj.test.cpp
---
