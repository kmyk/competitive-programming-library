---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: data_structure/li_chao_tree.segment_add_get_min.test.cpp
    title: data_structure/li_chao_tree.segment_add_get_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: data_structure/li_chao_tree.md
    document_title: Li-Chao tree
    links: []
  bundledCode: "#line 2 \"data_structure/li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 7 \"data_structure/li_chao_tree.hpp\"\n\n/**\n * @brief Li-Chao tree\n * @docs\
    \ data_structure/li_chao_tree.md\n */\nstruct li_chao_tree {\n    int k;\n   \
    \ std::vector<std::pair<int64_t, int64_t> > f;\n    std::vector<int64_t> x;\n\
    \    std::vector<int64_t> y;\n    li_chao_tree() = default;\n    li_chao_tree(const\
    \ std::vector<int64_t> & x_) : x(x_) {\n        assert (std::is_sorted(ALL(x)));\n\
    \        k = 0; while ((1 << k) < x.size()) ++ k;\n        f.resize((1 << k) -\
    \ 1, std::make_pair(0, std::numeric_limits<int64_t>::max()));\n        y.resize(x.size(),\
    \ std::numeric_limits<int64_t>::max());\n    }\n    /**\n     * @note i is a point\
    \ on the original space\n     */\n    int64_t get_min(int64_t i) {\n        i\
    \ = std::lower_bound(ALL(x), i) - x.begin();\n        return get_min_compressed(i);\n\
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
    \ * i + 2, (il + ir) / 2, ir, l, r, a, b);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include \"../utils/macros.hpp\"\n\n/**\n * @brief Li-Chao\
    \ tree\n * @docs data_structure/li_chao_tree.md\n */\nstruct li_chao_tree {\n\
    \    int k;\n    std::vector<std::pair<int64_t, int64_t> > f;\n    std::vector<int64_t>\
    \ x;\n    std::vector<int64_t> y;\n    li_chao_tree() = default;\n    li_chao_tree(const\
    \ std::vector<int64_t> & x_) : x(x_) {\n        assert (std::is_sorted(ALL(x)));\n\
    \        k = 0; while ((1 << k) < x.size()) ++ k;\n        f.resize((1 << k) -\
    \ 1, std::make_pair(0, std::numeric_limits<int64_t>::max()));\n        y.resize(x.size(),\
    \ std::numeric_limits<int64_t>::max());\n    }\n    /**\n     * @note i is a point\
    \ on the original space\n     */\n    int64_t get_min(int64_t i) {\n        i\
    \ = std::lower_bound(ALL(x), i) - x.begin();\n        return get_min_compressed(i);\n\
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
    \ * i + 2, (il + ir) / 2, ir, l, r, a, b);\n        }\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - data_structure/li_chao_tree.segment_add_get_min.test.cpp
documentation_of: data_structure/li_chao_tree.hpp
layout: document
redirect_from:
- /library/data_structure/li_chao_tree.hpp
- /library/data_structure/li_chao_tree.hpp.html
title: Li-Chao tree
---
## 概要

ありえる座標の有限集合 $X \subseteq \mathbb{Z}$ が固定されているとする。
一次関数と区間の対の集合 $F = \emptyset \subseteq \lbrace \lbrack l, r) \mid l, r \in X \wedge l \le r \rbrace \times \lbrace \lambda x. ax + b \mid a, b \in \mathbb{Z} \rbrace$ に対し、次が $O(\log N)$ amortized (一部は $O(\log N)$) で処理可能:

-   $\mathtt{add\unicode{95}segment}(l, r, f)$: $l, r \in X$ でなければならない。$F \gets F \cup \lbrace (f, \lbrack l, r) \rbrace$ と更新する。
-   $\mathtt{get\unicode{95}min}(x)$: $x \in X$ でなければならない。$$\min _ {(f, \lbrack l, r) \in F \wedge x \lbrack l, r))} f(x)$$ を $O(\log N)$ で計算する。
