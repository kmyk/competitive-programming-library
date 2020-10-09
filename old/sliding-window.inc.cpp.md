---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: the sliding window minimum algorithm
    links:
    - http://cf16-tournament-round3-open.contest.atcoder.jp/tasks/asaporo_d
    - http://poj.org/problem?id=2823
  bundledCode: "#line 1 \"old/sliding-window.inc.cpp\"\n/**\n * @brief the sliding\
    \ window minimum algorithm\n * @note to get maximums, use greater<T>\n * @note\
    \ verified http://poj.org/problem?id=2823\n * @note verified http://cf16-tournament-round3-open.contest.atcoder.jp/tasks/asaporo_d\n\
    \ */\ntemplate <typename T, class Compare = less<T> >\nclass sliding_window {\n\
    \    deque<pair<int, T> > data;\n    Compare compare;\npublic:\n    sliding_window(Compare\
    \ const & a_compare = Compare())\n        : compare(a_compare) {}\n    T front()\
    \ {  // O(1), minimum\n        return data.front().second;\n    }\n    void push_back(int\
    \ i, T a) {  // O(1) amortized.\n        while (not data.empty() and compare(a,\
    \ data.back().second)) {\n            data.pop_back();\n        }\n        data.emplace_back(i,\
    \ a);\n    }\n    void pop_front(int i) {\n        if (data.front().first == i)\
    \ {\n            data.pop_front();\n        }\n    }\n    void push_front(int\
    \ i, T a) {\n        if (data.empty() or not compare(data.front().second, a))\
    \ {\n            data.emplace_front(i, a);\n        }\n    }\n};\n"
  code: "/**\n * @brief the sliding window minimum algorithm\n * @note to get maximums,\
    \ use greater<T>\n * @note verified http://poj.org/problem?id=2823\n * @note verified\
    \ http://cf16-tournament-round3-open.contest.atcoder.jp/tasks/asaporo_d\n */\n\
    template <typename T, class Compare = less<T> >\nclass sliding_window {\n    deque<pair<int,\
    \ T> > data;\n    Compare compare;\npublic:\n    sliding_window(Compare const\
    \ & a_compare = Compare())\n        : compare(a_compare) {}\n    T front() { \
    \ // O(1), minimum\n        return data.front().second;\n    }\n    void push_back(int\
    \ i, T a) {  // O(1) amortized.\n        while (not data.empty() and compare(a,\
    \ data.back().second)) {\n            data.pop_back();\n        }\n        data.emplace_back(i,\
    \ a);\n    }\n    void pop_front(int i) {\n        if (data.front().first == i)\
    \ {\n            data.pop_front();\n        }\n    }\n    void push_front(int\
    \ i, T a) {\n        if (data.empty() or not compare(data.front().second, a))\
    \ {\n            data.emplace_front(i, a);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/sliding-window.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/sliding-window.inc.cpp
layout: document
redirect_from:
- /library/old/sliding-window.inc.cpp
- /library/old/sliding-window.inc.cpp.html
title: the sliding window minimum algorithm
---
