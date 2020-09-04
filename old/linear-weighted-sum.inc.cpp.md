---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/linear-weighted-sum.inc.cpp\"\n/**\n * @description\
    \ a structure to compute sum_{i \\in [l, r)} (i - l) a_i\n * @note a_l is ignored\
    \ since i - l = 0\n */\nclass linear_weighted_sum {\n    vector<ll> b;\n    vector<ll>\
    \ c;\npublic:\n    linear_weighted_sum() = default;\n    linear_weighted_sum(vector<ll>\
    \ const & a) {\n        int n = a.size();\n        b.resize(n + 1);\n        c.resize(n\
    \ + 1);\n        REP (i, n) {\n            b[i + 1] = b[i] + a[i];\n         \
    \   c[i + 1] = c[i] + i * a[i];\n        }\n    }\n    ll range_sum(int l, int\
    \ r) const {\n        assert (max(0, l) <= r and r <= b.size() - 1);\n       \
    \ int l1 = max(0, l);\n        return (c[r] - c[l1]) - l * (b[r] - b[l1]);\n \
    \   }\n    ll inversed_range_sum(int l, int r) const {\n        assert (0 <= l\
    \ and l <= min((int)b.size() - 1, r));\n        int r1 = min((int)b.size() - 1,\
    \ r);\n        return r * (b[r1] - b[l]) - (c[r1] - c[l]);\n    }\n};\n\n/**\n\
    \ * @description a monoid to compute sum_{i \\in [l, r)} (i - l) a_i\n */\nstruct\
    \ linear_weighted_plus_monoid {\n    typedef struct {\n        int l, r;\n   \
    \     ll sum, weighted_sum;\n    } value_type;\n    static value_type make(int\
    \ i, ll value) {\n        value_type a;\n        a.l = i;\n        a.r = i + 1;\n\
    \        a.sum = value;\n        a.weighted_sum = 0;\n        return a;\n    }\n\
    \    value_type unit() const {\n        return make(-1, 0);\n    }\n    value_type\
    \ append(value_type a, value_type b) const {\n        if (a.l == -1) return b;\n\
    \        if (b.l == -1) return a;\n        assert (a.r == b.l);\n        value_type\
    \ c;\n        c.l = a.l;\n        c.r = b.r;\n        c.sum = a.sum + b.sum;\n\
    \        c.weighted_sum = a.weighted_sum + b.weighted_sum + (a.r - a.l) * b.sum;\n\
    \        return c;\n    }\n};\n\nunittest {\n    default_random_engine gen;\n\
    \    REP (iteration, 10) {\n        int size = uniform_int_distribution<int>(3,\
    \ 100)(gen);\n        vector<ll> ary(size);\n        segment_tree<linear_weighted_plus_monoid>\
    \ segtree(size);\n        REP (i, size) {\n            int a = uniform_int_distribution<int>(-100,\
    \ 100)(gen);\n            ary[i] = a;\n            segtree.point_set(i, linear_weighted_plus_monoid::make(i,\
    \ a));\n        }\n        linear_weighted_sum lws(ary);\n        REP (iteration,\
    \ 100) {\n            int l = uniform_int_distribution<int>(0, size - 1)(gen);\n\
    \            int r = uniform_int_distribution<int>(l + 1, size)(gen);\n      \
    \      ll acc_l = 0;\n            ll acc_r = 0;\n            REP3 (m, l, r) {\n\
    \                acc_l += (m - l) * ary[m];\n                acc_r += (r - m)\
    \ * ary[m];\n            }\n            auto m = segtree.range_concat(l, r);\n\
    \            assert (acc_l == m.weighted_sum);\n            assert (acc_r == m.sum\
    \ * (m.r - m.l) - m.weighted_sum);\n            assert (acc_l == lws.range_sum(l,\
    \ r));\n            assert (acc_r == lws.inversed_range_sum(l, r));\n        }\n\
    \    }\n}\n"
  code: "/**\n * @description a structure to compute sum_{i \\in [l, r)} (i - l) a_i\n\
    \ * @note a_l is ignored since i - l = 0\n */\nclass linear_weighted_sum {\n \
    \   vector<ll> b;\n    vector<ll> c;\npublic:\n    linear_weighted_sum() = default;\n\
    \    linear_weighted_sum(vector<ll> const & a) {\n        int n = a.size();\n\
    \        b.resize(n + 1);\n        c.resize(n + 1);\n        REP (i, n) {\n  \
    \          b[i + 1] = b[i] + a[i];\n            c[i + 1] = c[i] + i * a[i];\n\
    \        }\n    }\n    ll range_sum(int l, int r) const {\n        assert (max(0,\
    \ l) <= r and r <= b.size() - 1);\n        int l1 = max(0, l);\n        return\
    \ (c[r] - c[l1]) - l * (b[r] - b[l1]);\n    }\n    ll inversed_range_sum(int l,\
    \ int r) const {\n        assert (0 <= l and l <= min((int)b.size() - 1, r));\n\
    \        int r1 = min((int)b.size() - 1, r);\n        return r * (b[r1] - b[l])\
    \ - (c[r1] - c[l]);\n    }\n};\n\n/**\n * @description a monoid to compute sum_{i\
    \ \\in [l, r)} (i - l) a_i\n */\nstruct linear_weighted_plus_monoid {\n    typedef\
    \ struct {\n        int l, r;\n        ll sum, weighted_sum;\n    } value_type;\n\
    \    static value_type make(int i, ll value) {\n        value_type a;\n      \
    \  a.l = i;\n        a.r = i + 1;\n        a.sum = value;\n        a.weighted_sum\
    \ = 0;\n        return a;\n    }\n    value_type unit() const {\n        return\
    \ make(-1, 0);\n    }\n    value_type append(value_type a, value_type b) const\
    \ {\n        if (a.l == -1) return b;\n        if (b.l == -1) return a;\n    \
    \    assert (a.r == b.l);\n        value_type c;\n        c.l = a.l;\n       \
    \ c.r = b.r;\n        c.sum = a.sum + b.sum;\n        c.weighted_sum = a.weighted_sum\
    \ + b.weighted_sum + (a.r - a.l) * b.sum;\n        return c;\n    }\n};\n\nunittest\
    \ {\n    default_random_engine gen;\n    REP (iteration, 10) {\n        int size\
    \ = uniform_int_distribution<int>(3, 100)(gen);\n        vector<ll> ary(size);\n\
    \        segment_tree<linear_weighted_plus_monoid> segtree(size);\n        REP\
    \ (i, size) {\n            int a = uniform_int_distribution<int>(-100, 100)(gen);\n\
    \            ary[i] = a;\n            segtree.point_set(i, linear_weighted_plus_monoid::make(i,\
    \ a));\n        }\n        linear_weighted_sum lws(ary);\n        REP (iteration,\
    \ 100) {\n            int l = uniform_int_distribution<int>(0, size - 1)(gen);\n\
    \            int r = uniform_int_distribution<int>(l + 1, size)(gen);\n      \
    \      ll acc_l = 0;\n            ll acc_r = 0;\n            REP3 (m, l, r) {\n\
    \                acc_l += (m - l) * ary[m];\n                acc_r += (r - m)\
    \ * ary[m];\n            }\n            auto m = segtree.range_concat(l, r);\n\
    \            assert (acc_l == m.weighted_sum);\n            assert (acc_r == m.sum\
    \ * (m.r - m.l) - m.weighted_sum);\n            assert (acc_l == lws.range_sum(l,\
    \ r));\n            assert (acc_r == lws.inversed_range_sum(l, r));\n        }\n\
    \    }\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/linear-weighted-sum.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/linear-weighted-sum.inc.cpp
layout: document
redirect_from:
- /library/old/linear-weighted-sum.inc.cpp
- /library/old/linear-weighted-sum.inc.cpp.html
title: old/linear-weighted-sum.inc.cpp
---
