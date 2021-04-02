---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/convex-hull-trick-with-monotonicity.inc.cpp\"\nclass\
    \ convex_hull_trick_with_monotonicity {\n    typedef pair<ll, ll> line_t;\n  \
    \  deque<line_t> lines;\n    ll inc_x, dec_x;  // only for assertions\npublic:\n\
    \    convex_hull_trick_with_monotonicity() {\n        inc_x = LLONG_MIN;\n   \
    \     dec_x = LLONG_MAX;\n    }\n    void add_line_increasing(ll a, ll b) {\n\
    \        assert (lines.empty() or lines.back().first <= a);  // weakly monotonically\
    \ increasing\n        while (lines.size() >= 2 and not is_required(lines[lines.size()\
    \ - 2], lines.back(), { a, b })) {\n            lines.pop_back();\n        }\n\
    \        lines.emplace_back(a, b);\n    }\n    void add_line_decreasing(ll a,\
    \ ll b) {\n        assert (lines.empty() or a <= lines.front().first);  // weakly\
    \ monotonically decreasing\n        while (lines.size() >= 2 and not is_required({\
    \ a, b }, lines.front(), lines[1])) {\n            lines.pop_front();\n      \
    \  }\n        lines.emplace_front(a, b);\n    }\n    ll get_max_increasing(ll\
    \ x) {\n        assert (inc_x <= x);  // weakly monotonically increasing\n   \
    \     inc_x = x;\n        assert (not lines.empty());\n        while (lines.size()\
    \ >= 2 and get_value(0, x) <= get_value(1, x)) {\n            lines.pop_front();\n\
    \        }\n        return get_value(0, x);\n    }\n    ll get_max_decreasing(ll\
    \ x) {\n        assert (x <= dec_x);  // weakly monotonically decreasing\n   \
    \     dec_x = x;\n        assert (not lines.empty());\n        while (lines.size()\
    \ >= 2 and get_value(-2, x) >= get_value(-1, x)) {\n            lines.pop_back();\n\
    \        }\n        return get_value(-1, x);\n    }\nprivate:\n    bool is_required(line_t\
    \ f1, line_t f2, line_t f3) const {\n        return (f3.first - f1.first) * (f1.second\
    \ - f2.second) < (f2.first - f1.first) * (f1.second - f3.second);\n    }\n   \
    \ ll get_value(int i, ll x) const {\n        if (i < 0) i += lines.size();\n \
    \       ll a, b; tie(a, b) = lines[i];\n        return a * x + b;\n    }\n};\n\
    \nstruct inverted_convex_hull_trick_with_monotonicity {\n    convex_hull_trick_with_monotonicity\
    \ data;\n    void add_line_increasing(ll a, ll b) { data.add_line_decreasing(-\
    \ a, - b); }\n    void add_line_decreasing(ll a, ll b) { data.add_line_increasing(-\
    \ a, - b); }\n    ll get_max_increasing(ll x) { return - data.get_max_increasing(x);\
    \ }\n    ll get_max_decreasing(ll x) { return - data.get_max_decreasing(x); }\n\
    };\n\nunittest() {\n    default_random_engine gen;\n    REP (iteration, 10000)\
    \ {\n        bool inc_f = bernoulli_distribution(0.5)(gen);\n        bool inc_x\
    \ = bernoulli_distribution(0.5)(gen);\n        vector<pair<int, int> > lines;\n\
    \        REP (i, 30) {\n            int a = uniform_int_distribution<int>(- 30,\
    \ 30)(gen);\n            int b = uniform_int_distribution<int>(- 30, 30)(gen);\n\
    \            lines.emplace_back(a, b);\n        }\n        sort(ALL(lines));\n\
    \        if (inc_f) {\n            // nop\n        } else {\n            reverse(ALL(lines));\n\
    \        }\n        convex_hull_trick_with_monotonicity cht;\n        int x =\
    \ uniform_int_distribution<int>(- 100, 100)(gen);\n        REP (i, lines.size())\
    \ {\n            int y = INT_MIN;\n            REP (j, i + 1) {\n            \
    \    int a, b; tie(a, b) = lines[j];\n                chmax(y, a * x + b);\n \
    \           }\n            int a, b; tie(a, b) = lines[i];\n            if (inc_f)\
    \ {\n                cht.add_line_increasing(a, b);\n            } else {\n  \
    \              cht.add_line_decreasing(a, b);\n            }\n            if (inc_x)\
    \ {\n                assert (cht.get_max_increasing(x) == y);\n              \
    \  x += uniform_int_distribution<int>(0, 5)(gen);\n            } else {\n    \
    \            assert (cht.get_max_decreasing(x) == y);\n                x -= uniform_int_distribution<int>(0,\
    \ 5)(gen);\n            }\n        }\n    }\n}\n"
  code: "class convex_hull_trick_with_monotonicity {\n    typedef pair<ll, ll> line_t;\n\
    \    deque<line_t> lines;\n    ll inc_x, dec_x;  // only for assertions\npublic:\n\
    \    convex_hull_trick_with_monotonicity() {\n        inc_x = LLONG_MIN;\n   \
    \     dec_x = LLONG_MAX;\n    }\n    void add_line_increasing(ll a, ll b) {\n\
    \        assert (lines.empty() or lines.back().first <= a);  // weakly monotonically\
    \ increasing\n        while (lines.size() >= 2 and not is_required(lines[lines.size()\
    \ - 2], lines.back(), { a, b })) {\n            lines.pop_back();\n        }\n\
    \        lines.emplace_back(a, b);\n    }\n    void add_line_decreasing(ll a,\
    \ ll b) {\n        assert (lines.empty() or a <= lines.front().first);  // weakly\
    \ monotonically decreasing\n        while (lines.size() >= 2 and not is_required({\
    \ a, b }, lines.front(), lines[1])) {\n            lines.pop_front();\n      \
    \  }\n        lines.emplace_front(a, b);\n    }\n    ll get_max_increasing(ll\
    \ x) {\n        assert (inc_x <= x);  // weakly monotonically increasing\n   \
    \     inc_x = x;\n        assert (not lines.empty());\n        while (lines.size()\
    \ >= 2 and get_value(0, x) <= get_value(1, x)) {\n            lines.pop_front();\n\
    \        }\n        return get_value(0, x);\n    }\n    ll get_max_decreasing(ll\
    \ x) {\n        assert (x <= dec_x);  // weakly monotonically decreasing\n   \
    \     dec_x = x;\n        assert (not lines.empty());\n        while (lines.size()\
    \ >= 2 and get_value(-2, x) >= get_value(-1, x)) {\n            lines.pop_back();\n\
    \        }\n        return get_value(-1, x);\n    }\nprivate:\n    bool is_required(line_t\
    \ f1, line_t f2, line_t f3) const {\n        return (f3.first - f1.first) * (f1.second\
    \ - f2.second) < (f2.first - f1.first) * (f1.second - f3.second);\n    }\n   \
    \ ll get_value(int i, ll x) const {\n        if (i < 0) i += lines.size();\n \
    \       ll a, b; tie(a, b) = lines[i];\n        return a * x + b;\n    }\n};\n\
    \nstruct inverted_convex_hull_trick_with_monotonicity {\n    convex_hull_trick_with_monotonicity\
    \ data;\n    void add_line_increasing(ll a, ll b) { data.add_line_decreasing(-\
    \ a, - b); }\n    void add_line_decreasing(ll a, ll b) { data.add_line_increasing(-\
    \ a, - b); }\n    ll get_max_increasing(ll x) { return - data.get_max_increasing(x);\
    \ }\n    ll get_max_decreasing(ll x) { return - data.get_max_decreasing(x); }\n\
    };\n\nunittest() {\n    default_random_engine gen;\n    REP (iteration, 10000)\
    \ {\n        bool inc_f = bernoulli_distribution(0.5)(gen);\n        bool inc_x\
    \ = bernoulli_distribution(0.5)(gen);\n        vector<pair<int, int> > lines;\n\
    \        REP (i, 30) {\n            int a = uniform_int_distribution<int>(- 30,\
    \ 30)(gen);\n            int b = uniform_int_distribution<int>(- 30, 30)(gen);\n\
    \            lines.emplace_back(a, b);\n        }\n        sort(ALL(lines));\n\
    \        if (inc_f) {\n            // nop\n        } else {\n            reverse(ALL(lines));\n\
    \        }\n        convex_hull_trick_with_monotonicity cht;\n        int x =\
    \ uniform_int_distribution<int>(- 100, 100)(gen);\n        REP (i, lines.size())\
    \ {\n            int y = INT_MIN;\n            REP (j, i + 1) {\n            \
    \    int a, b; tie(a, b) = lines[j];\n                chmax(y, a * x + b);\n \
    \           }\n            int a, b; tie(a, b) = lines[i];\n            if (inc_f)\
    \ {\n                cht.add_line_increasing(a, b);\n            } else {\n  \
    \              cht.add_line_decreasing(a, b);\n            }\n            if (inc_x)\
    \ {\n                assert (cht.get_max_increasing(x) == y);\n              \
    \  x += uniform_int_distribution<int>(0, 5)(gen);\n            } else {\n    \
    \            assert (cht.get_max_decreasing(x) == y);\n                x -= uniform_int_distribution<int>(0,\
    \ 5)(gen);\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/convex-hull-trick-with-monotonicity.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/convex-hull-trick-with-monotonicity.inc.cpp
layout: document
redirect_from:
- /library/old/convex-hull-trick-with-monotonicity.inc.cpp
- /library/old/convex-hull-trick-with-monotonicity.inc.cpp.html
title: old/convex-hull-trick-with-monotonicity.inc.cpp
---
