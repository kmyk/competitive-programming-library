---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/knapsack-problem-branch-and-bound.inc.cpp\"\nll knapsack_problem_branch_and_bound(int\
    \ n, ll max_w, vector<ll> const & a_v, vector<ll> const & a_w) {\n    vector<ll>\
    \ v(n), w(n); {\n        vector<int> xs(n);\n        iota(ALL(xs), 0);\n     \
    \   sort(ALL(xs), [&](int i, int j) {\n            return a_v[i] *(double) a_w[j]\
    \ > a_v[j] *(double) a_w[i];\n        });\n        REP (i, n) {\n            v[i]\
    \ = a_v[xs[i]];\n            w[i] = a_w[xs[i]];\n        }\n    }\n    ll ans\
    \ = 0;\n    function<void (int, ll, ll)> go = [&](int i, ll cur_v, ll cur_w) {\n\
    \        if (max_w < cur_w) return; // not executable\n        if (i == n) {\n\
    \            chmax(ans, cur_v);\n            return; // terminate\n        }\n\
    \        ll lr_v = cur_v; // linear relaxation\n        ll lr_w = cur_w;\n   \
    \     int j = i;\n        for (; j < n and lr_w + w[j] <= max_w; ++ j) { // greedy\n\
    \            lr_w += w[j];\n            lr_v += v[j];\n        }\n        if (lr_w\
    \ == max_w or j == n) {\n            chmax(ans, lr_v);\n            return; //\
    \ accept greedy\n        }\n        double lr_ans = lr_v + v[j] * ((max_w - lr_w)\
    \ /(double) w[j]);\n        if (lr_ans <= ans) return; // bound\n        go(i\
    \ + 1, cur_v + v[i], cur_w + w[i]);\n        go(i + 1, cur_v,        cur_w   \
    \    );\n    };\n    go(0, 0, 0);\n    return ans;\n}\n"
  code: "ll knapsack_problem_branch_and_bound(int n, ll max_w, vector<ll> const &\
    \ a_v, vector<ll> const & a_w) {\n    vector<ll> v(n), w(n); {\n        vector<int>\
    \ xs(n);\n        iota(ALL(xs), 0);\n        sort(ALL(xs), [&](int i, int j) {\n\
    \            return a_v[i] *(double) a_w[j] > a_v[j] *(double) a_w[i];\n     \
    \   });\n        REP (i, n) {\n            v[i] = a_v[xs[i]];\n            w[i]\
    \ = a_w[xs[i]];\n        }\n    }\n    ll ans = 0;\n    function<void (int, ll,\
    \ ll)> go = [&](int i, ll cur_v, ll cur_w) {\n        if (max_w < cur_w) return;\
    \ // not executable\n        if (i == n) {\n            chmax(ans, cur_v);\n \
    \           return; // terminate\n        }\n        ll lr_v = cur_v; // linear\
    \ relaxation\n        ll lr_w = cur_w;\n        int j = i;\n        for (; j <\
    \ n and lr_w + w[j] <= max_w; ++ j) { // greedy\n            lr_w += w[j];\n \
    \           lr_v += v[j];\n        }\n        if (lr_w == max_w or j == n) {\n\
    \            chmax(ans, lr_v);\n            return; // accept greedy\n       \
    \ }\n        double lr_ans = lr_v + v[j] * ((max_w - lr_w) /(double) w[j]);\n\
    \        if (lr_ans <= ans) return; // bound\n        go(i + 1, cur_v + v[i],\
    \ cur_w + w[i]);\n        go(i + 1, cur_v,        cur_w       );\n    };\n   \
    \ go(0, 0, 0);\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/knapsack-problem-branch-and-bound.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/knapsack-problem-branch-and-bound.inc.cpp
layout: document
redirect_from:
- /library/old/knapsack-problem-branch-and-bound.inc.cpp
- /library/old/knapsack-problem-branch-and-bound.inc.cpp.html
title: old/knapsack-problem-branch-and-bound.inc.cpp
---
