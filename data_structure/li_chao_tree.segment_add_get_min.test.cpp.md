---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/li_chao_tree.hpp
    title: Li-Chao tree
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"data_structure/li_chao_tree.segment_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line\
    \ 2 \"data_structure/li_chao_tree.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 7 \"\
    data_structure/li_chao_tree.hpp\"\n\n/**\n * @brief Li-Chao tree\n * @docs data_structure/li_chao_tree.md\n\
    \ */\nstruct li_chao_tree {\n    int k;\n    std::vector<std::pair<int64_t, int64_t>\
    \ > f;\n    std::vector<int64_t> x;\n    std::vector<int64_t> y;\n    li_chao_tree()\
    \ = default;\n    li_chao_tree(const std::vector<int64_t> & x_) : x(x_) {\n  \
    \      assert (std::is_sorted(ALL(x)));\n        k = 0; while ((1 << k) < x.size())\
    \ ++ k;\n        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<int64_t>::max()));\n\
    \        y.resize(x.size(), std::numeric_limits<int64_t>::max());\n    }\n   \
    \ /**\n     * @note i is a point on the original space\n     */\n    int64_t get_min(int64_t\
    \ i) {\n        i = std::lower_bound(ALL(x), i) - x.begin();\n        return get_min_compressed(i);\n\
    \    }\n    int64_t get_min_compressed(int i) {  // 0-based\n        assert (0\
    \ <= i and i < x.size());\n        int64_t z = y[i];\n        for (int j = (i\
    \ + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based\n            z = std::min(z, f[j\
    \ - 1].first * x[i] + f[j - 1].second);\n        }\n        return z;\n    }\n\
    \    /**\n     * @note [l, r) is an interval on the original space\n     */\n\
    \    void add_segment(int64_t l, int64_t r, int64_t a, int64_t b) {\n        l\
    \ = std::lower_bound(ALL(x), l) - x.begin();\n        r = std::lower_bound(ALL(x),\
    \ r) - x.begin();\n        add_segment_compressed(l, r, a, b);\n    }\n    void\
    \ add_segment_compressed(int64_t l, int64_t r, int64_t a, int64_t b) {\n     \
    \   assert (0 <= l and l <= r and r <= x.size());\n        add_segment_compressed(0,\
    \ 0, 1 << k, l, r, a, b);\n    }\n    void add_segment_compressed(int i, int il,\
    \ int ir, int l, int r, int64_t a, int64_t b) {\n        if (l <= il and ir <=\
    \ r) {  // 0-based\n            if (i >= (1 << k) - 1) {\n                int\
    \ j = i - (1 << k) + 1;\n                y[j] = std::min(y[j], a * x[j] + b);\n\
    \            } else {\n                int64_t xl = x[il];\n                int64_t\
    \ xr = x[ir - 1];  // [xl, xr]\n                int64_t yl1 = f[i].first * xl\
    \ + f[i].second;\n                int64_t yr1 = f[i].first * xr + f[i].second;\n\
    \                int64_t yl2 = a * xl + b;\n                int64_t yr2 = a *\
    \ xr + b;\n                if (yl1 <= yl2 and yr1 <= yr2) {\n                \
    \    // if forall x in [l, r]. f(x) <= g(x), then do nothing\n               \
    \     // nop\n                } else if (yl2 <= yl1 and yr2 <= yr1) {\n      \
    \              // if forall x in [l, r]. g(x) <= f(x), then replace f with g\n\
    \                    f[i] = std::make_pair(a, b);\n                } else {\n\
    \                    int64_t xm = x[(il + ir) / 2];\n                    int64_t\
    \ ym1 = f[i].first * xm + f[i].second;\n                    int64_t ym2 = a *\
    \ xm + b;\n                    if (yl1 <= yl2 and ym1 <= ym2) {\n            \
    \            // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m,\
    \ r] with f\n                        add_segment_compressed(2 * i + 2, (il + ir)\
    \ / 2, ir, l, r, a, b);\n                    } else if (yl2 <= yl1 and ym2 <=\
    \ ym1) {\n                        // if forall x in [l, m]. g(x) <= f(x), then\
    \ replace f with g and do recursion for [m, r] with g\n                      \
    \  std::swap(a, f[i].first);\n                        std::swap(b, f[i].second);\n\
    \                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir,\
    \ l, r, a, b);\n                    } else if (ym1 <= ym2 and yr1 <= yr2) {\n\
    \                        // if forall x in [m, r]. f(x) <= g(x), then do recursion\
    \ for [l, m] with f\n                        add_segment_compressed(2 * i + 1,\
    \ il, (il + ir) / 2, l, r, a, b);\n                    } else if (ym2 <= ym1 and\
    \ yr2 <= yr1) {\n                        // if forall x in [m, r]. g(x) <= f(x),\
    \ then replace f with g and do recursion for [l, m] with g\n                 \
    \       std::swap(a, f[i].first);\n                        std::swap(b, f[i].second);\n\
    \                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2,\
    \ l, r, a, b);\n                    } else {\n                        assert (false);\n\
    \                    }\n                }\n            }\n        } else if (ir\
    \ <= l or r <= il) {\n            // nop\n        } else {\n            add_segment_compressed(2\
    \ * i + 1, il, (il + ir) / 2, l, r, a, b);\n            add_segment_compressed(2\
    \ * i + 2, (il + ir) / 2, ir, l, r, a, b);\n        }\n    }\n};\n#line 4 \"data_structure/li_chao_tree.segment_add_get_min.test.cpp\"\
    \n#include <cstdio>\n#include <tuple>\n#line 7 \"data_structure/li_chao_tree.segment_add_get_min.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    // input\n    int n, q; scanf(\"%d%d\"\
    , &n, &q);\n    vector<int64_t> xs;\n    vector<tuple<int64_t, int64_t, int64_t,\
    \ int64_t> > segments;\n    REP (i, n) {\n        int64_t l, r, a, b; scanf(\"\
    %lld%lld%lld%lld\", &l, &r, &a, &b);\n        xs.push_back(l);\n        xs.push_back(r);\n\
    \        segments.emplace_back(l, r, a, b);\n    }\n    vector<tuple<int, int64_t,\
    \ int64_t, int64_t, int64_t, int64_t> > queries;\n    REP (j, q) {\n        int\
    \ t; scanf(\"%d\", &t);\n        if (t == 0) {\n            int64_t l, r, a, b;\
    \ scanf(\"%lld%lld%lld%lld\", &l, &r, &a, &b);\n            xs.push_back(l);\n\
    \            xs.push_back(r);\n            queries.emplace_back(t, l, r, a, b,\
    \ -1);\n        } else if (t == 1) {\n            int64_t p; scanf(\"%lld\", &p);\n\
    \            xs.push_back(p);\n            queries.emplace_back(t, -1, -1, -1,\
    \ -1, p);\n        } else {\n            assert (false);\n        }\n    }\n\n\
    \    // construct\n    sort(ALL(xs));\n    xs.erase(unique(ALL(xs)), xs.end());\n\
    \    li_chao_tree lichao(xs);\n\n    // output\n    for (auto [l, r, a, b] : segments)\
    \ {\n        lichao.add_segment(l, r, a, b);\n    }\n    for (auto [t, l, r, a,\
    \ b, p] : queries) {\n        if (t == 0) {\n            lichao.add_segment(l,\
    \ r, a, b);\n        } else if (t == 1) {\n            int64_t q = lichao.get_min(p);\n\
    \            if (q == INT64_MAX) {\n                printf(\"INFINITY\\n\");\n\
    \            } else {\n                printf(\"%lld\\n\", q);\n            }\n\
    \        } else {\n            assert (false);\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"../data_structure/li_chao_tree.hpp\"\n#include \"../utils/macros.hpp\"\
    \n#include <cstdio>\n#include <tuple>\n#include <vector>\nusing namespace std;\n\
    \nint main() {\n    // input\n    int n, q; scanf(\"%d%d\", &n, &q);\n    vector<int64_t>\
    \ xs;\n    vector<tuple<int64_t, int64_t, int64_t, int64_t> > segments;\n    REP\
    \ (i, n) {\n        int64_t l, r, a, b; scanf(\"%lld%lld%lld%lld\", &l, &r, &a,\
    \ &b);\n        xs.push_back(l);\n        xs.push_back(r);\n        segments.emplace_back(l,\
    \ r, a, b);\n    }\n    vector<tuple<int, int64_t, int64_t, int64_t, int64_t,\
    \ int64_t> > queries;\n    REP (j, q) {\n        int t; scanf(\"%d\", &t);\n \
    \       if (t == 0) {\n            int64_t l, r, a, b; scanf(\"%lld%lld%lld%lld\"\
    , &l, &r, &a, &b);\n            xs.push_back(l);\n            xs.push_back(r);\n\
    \            queries.emplace_back(t, l, r, a, b, -1);\n        } else if (t ==\
    \ 1) {\n            int64_t p; scanf(\"%lld\", &p);\n            xs.push_back(p);\n\
    \            queries.emplace_back(t, -1, -1, -1, -1, p);\n        } else {\n \
    \           assert (false);\n        }\n    }\n\n    // construct\n    sort(ALL(xs));\n\
    \    xs.erase(unique(ALL(xs)), xs.end());\n    li_chao_tree lichao(xs);\n\n  \
    \  // output\n    for (auto [l, r, a, b] : segments) {\n        lichao.add_segment(l,\
    \ r, a, b);\n    }\n    for (auto [t, l, r, a, b, p] : queries) {\n        if\
    \ (t == 0) {\n            lichao.add_segment(l, r, a, b);\n        } else if (t\
    \ == 1) {\n            int64_t q = lichao.get_min(p);\n            if (q == INT64_MAX)\
    \ {\n                printf(\"INFINITY\\n\");\n            } else {\n        \
    \        printf(\"%lld\\n\", q);\n            }\n        } else {\n          \
    \  assert (false);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/li_chao_tree.hpp
  - utils/macros.hpp
  isVerificationFile: true
  path: data_structure/li_chao_tree.segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data_structure/li_chao_tree.segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/data_structure/li_chao_tree.segment_add_get_min.test.cpp
- /verify/data_structure/li_chao_tree.segment_add_get_min.test.cpp.html
title: data_structure/li_chao_tree.segment_add_get_min.test.cpp
---
