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
  bundledCode: "#line 1 \"old/segment-tree-2d.inc.cpp\"\n/**\n * @note O(h * w) space\n\
    \ */\ntemplate <class CommutativeMonoid>\nstruct segment_tree_2d {\n    typedef\
    \ typename CommutativeMonoid::value_type value_type;\n    int h1, w1;\n    int\
    \ h, w;\n    vector<value_type> data;\n    CommutativeMonoid mon;\n    segment_tree_2d()\
    \ = default;\n    segment_tree_2d(int h_, int w_, value_type initial_value = CommutativeMonoid().unit(),\
    \ CommutativeMonoid const & mon_ = CommutativeMonoid())\n            : h1(h_),\
    \ w1(w_), mon(mon_) {\n        h = pow(2, ceil(log2(h_)));\n        w = pow(2,\
    \ ceil(log2(w_)));\n        data.resize((2 * h - 1) * (2 * w - 1), mon.unit());\n\
    \        REP_R (y, h) REP_R (x, w) {\n            if (y < h - 1) {\n         \
    \       at(y, x) = mon.append(\n                    at(2 * y + 1, x),\n      \
    \              at(2 * y + 2, x));\n            } else if (x < w - 1) {\n     \
    \           at(y, x) = mon.append(\n                    at(y, 2 * x + 1),\n  \
    \                  at(y, 2 * x + 2));\n            } else if (y < h - 1 + h_ and\
    \ x < w - 1 + w_) {\n                at(y, x) = initial_value;\n            }\n\
    \        }\n    }\n    inline value_type & at(int y, int x) {\n        return\
    \ data[y * (2 * w - 1) + x];\n    }\n    inline value_type const & at(int y, int\
    \ x) const {\n        return data[y * (2 * w - 1) + x];\n    }\n    /**\n    \
    \ * @note O(log h * log w)\n     */\n    void point_set(int y, int x, value_type\
    \ value) {\n        assert (0 <= y and y < h1 and 0 <= x and x < w1);\n      \
    \  for (int i = y + h; i > 0; i /= 2) {  // 1-based\n            for (int j =\
    \ x + w; j > 0; j /= 2) {  // 1-based\n                if (i >= h and j >= w)\
    \ {\n                    at(i - 1, j - 1) = value;\n                } else if\
    \ (j >= w) {\n                    at(i - 1, j - 1) = mon.append(\n           \
    \             at(2 * i - 1, j - 1),\n                        at(2 * i,     j -\
    \ 1));\n                } else {\n                    at(i - 1, j - 1) = mon.append(\n\
    \                        at(i - 1, 2 * j - 1),\n                        at(i -\
    \ 1, 2 * j));\n                }\n            }\n        }\n    }\n    /**\n \
    \    * @note O(log h * log w)\n     */\n    value_type area_concat(int ly, int\
    \ lx, int ry, int rx) const {\n        assert (0 <= ly and ly <= ry and ry <=\
    \ h1);\n        assert (0 <= lx and lx <= rx and rx <= w1);\n        return area_concat(0,\
    \ 0, 0, 0, h, w, false, ly, lx, ry, rx);\n    }\n    value_type area_concat(int\
    \ i, int j, int ily, int jlx, int iry, int jrx, bool p, int ly, int lx, int ry,\
    \ int rx) const {\n        if (iry <= ly or ry <= ily or jrx <= lx or rx <= jlx)\
    \ {\n            return mon.unit();\n        } else if (ly <= ily and iry <= ry\
    \ and lx <= jlx and jrx <= rx) {\n            return at(i, j);\n        } else\
    \ if ((ly <= ily and iry <= ry) or (p and not (lx <= jlx and jrx <= rx))) {\n\
    \            return mon.append(\n                area_concat(i, 2 * j + 1, ily,\
    \ jlx, iry, (jlx + jrx) / 2, not p, ly, lx, ry, rx),\n                area_concat(i,\
    \ 2 * j + 2, ily, (jlx + jrx) / 2, iry, jrx, not p, ly, lx, ry, rx));\n      \
    \  } else {\n            return mon.append(\n                area_concat(2 * i\
    \ + 1, j, ily, jlx, (ily + iry) / 2, jrx, not p, ly, lx, ry, rx),\n          \
    \      area_concat(2 * i + 2, j, (ily + iry) / 2, jlx, iry, jrx, not p, ly, lx,\
    \ ry, rx));\n        }\n    }\n    /**\n     * @note call area_concat O((ry -\
    \ ly) / h * (rx - lx) / w) times\n     */\n    value_type area_concat_torus(int\
    \ ly, int lx, int ry, int rx) const {\n        value_type acc = mon.unit();\n\
    \        while (ly < 0) { ly += h1; ry += h1; }\n        while (lx < 0) { lx +=\
    \ w1; rx += w1; }\n        for (int bi = ly / h1; bi <= (ry - 1) / h1; ++ bi)\
    \ {\n            int ly1 = (bi == ly / h1 ? ly % h1 : 0);\n            int ry1\
    \ = (bi == ry / h1 ? ry % h1 : h1);\n            for (int bj = lx / w1; bj <=\
    \ (rx - 1) / w1; ++ bj) {\n                int lx1 = (bj == lx / w1 ? lx % w1\
    \ : 0);\n                int rx1 = (bj == rx / w1 ? rx % w1 : w1);\n         \
    \       acc = mon.append(acc, area_concat(ly1, lx1, ry1, rx1));\n            }\n\
    \        }\n        return acc;\n    }\n};\n\nstruct max_monoid {\n    typedef\
    \ int value_type;\n    int unit() const { return INT_MIN; }\n    int append(int\
    \ a, int b) const { return max(a, b); }\n};\n\nstruct plus_monoid {\n    typedef\
    \ int value_type;\n    int unit() const { return 0; }\n    int append(int a, int\
    \ b) const { return a + b; }\n};\n\nunittest {\n    default_random_engine gen;\n\
    \    REP (iteration, 100) {\n        int h = uniform_int_distribution<int>(1,\
    \ 30)(gen);\n        int w = uniform_int_distribution<int>(1, 30)(gen);\n    \
    \    vector<vector<int> > a(h, vector<int>(w));\n        segment_tree_2d<plus_monoid>\
    \ segtree(h, w);\n        REP (y, h) REP (x, w) {\n            a[y][x] = uniform_int_distribution<int>(-10,\
    \ 10)(gen);\n            segtree.point_set(y, x, a[y][x]);\n        }\n      \
    \  REP (y, h) REP (x, w) {\n            assert (a[y][x] == segtree.area_concat(y,\
    \ x, y + 1, x + 1));\n        }\n        REP (iteration, 100) {\n            int\
    \ ly = uniform_int_distribution<int>(0, h - 1)(gen);\n            int lx = uniform_int_distribution<int>(0,\
    \ w - 1)(gen);\n            int ry = uniform_int_distribution<int>(ly + 1, h)(gen);\n\
    \            int rx = uniform_int_distribution<int>(lx + 1, w)(gen);\n       \
    \     int acc = 0;\n            REP3 (y, ly, ry) {\n                REP3 (x, lx,\
    \ rx) {\n                    acc += a[y][x];\n                }\n            }\n\
    \            assert (acc == segtree.area_concat(ly, lx, ry, rx));\n        }\n\
    \        REP (iteration, 10) {\n            int ly = uniform_int_distribution<int>(-\
    \ 100, 50)(gen);\n            int lx = uniform_int_distribution<int>(- 100, 50)(gen);\n\
    \            int ry = uniform_int_distribution<int>(ly, 100)(gen);\n         \
    \   int rx = uniform_int_distribution<int>(lx, 100)(gen);\n            int acc\
    \ = 0;\n            REP3 (y, ly, ry) {\n                REP3 (x, lx, rx) {\n \
    \                   acc += a[(y % h + h) % h][(x % w + w) % w];\n            \
    \    }\n            }\n            assert (acc == segtree.area_concat_torus(ly,\
    \ lx, ry, rx));\n        }\n    }\n}\n"
  code: "/**\n * @note O(h * w) space\n */\ntemplate <class CommutativeMonoid>\nstruct\
    \ segment_tree_2d {\n    typedef typename CommutativeMonoid::value_type value_type;\n\
    \    int h1, w1;\n    int h, w;\n    vector<value_type> data;\n    CommutativeMonoid\
    \ mon;\n    segment_tree_2d() = default;\n    segment_tree_2d(int h_, int w_,\
    \ value_type initial_value = CommutativeMonoid().unit(), CommutativeMonoid const\
    \ & mon_ = CommutativeMonoid())\n            : h1(h_), w1(w_), mon(mon_) {\n \
    \       h = pow(2, ceil(log2(h_)));\n        w = pow(2, ceil(log2(w_)));\n   \
    \     data.resize((2 * h - 1) * (2 * w - 1), mon.unit());\n        REP_R (y, h)\
    \ REP_R (x, w) {\n            if (y < h - 1) {\n                at(y, x) = mon.append(\n\
    \                    at(2 * y + 1, x),\n                    at(2 * y + 2, x));\n\
    \            } else if (x < w - 1) {\n                at(y, x) = mon.append(\n\
    \                    at(y, 2 * x + 1),\n                    at(y, 2 * x + 2));\n\
    \            } else if (y < h - 1 + h_ and x < w - 1 + w_) {\n               \
    \ at(y, x) = initial_value;\n            }\n        }\n    }\n    inline value_type\
    \ & at(int y, int x) {\n        return data[y * (2 * w - 1) + x];\n    }\n   \
    \ inline value_type const & at(int y, int x) const {\n        return data[y *\
    \ (2 * w - 1) + x];\n    }\n    /**\n     * @note O(log h * log w)\n     */\n\
    \    void point_set(int y, int x, value_type value) {\n        assert (0 <= y\
    \ and y < h1 and 0 <= x and x < w1);\n        for (int i = y + h; i > 0; i /=\
    \ 2) {  // 1-based\n            for (int j = x + w; j > 0; j /= 2) {  // 1-based\n\
    \                if (i >= h and j >= w) {\n                    at(i - 1, j - 1)\
    \ = value;\n                } else if (j >= w) {\n                    at(i - 1,\
    \ j - 1) = mon.append(\n                        at(2 * i - 1, j - 1),\n      \
    \                  at(2 * i,     j - 1));\n                } else {\n        \
    \            at(i - 1, j - 1) = mon.append(\n                        at(i - 1,\
    \ 2 * j - 1),\n                        at(i - 1, 2 * j));\n                }\n\
    \            }\n        }\n    }\n    /**\n     * @note O(log h * log w)\n   \
    \  */\n    value_type area_concat(int ly, int lx, int ry, int rx) const {\n  \
    \      assert (0 <= ly and ly <= ry and ry <= h1);\n        assert (0 <= lx and\
    \ lx <= rx and rx <= w1);\n        return area_concat(0, 0, 0, 0, h, w, false,\
    \ ly, lx, ry, rx);\n    }\n    value_type area_concat(int i, int j, int ily, int\
    \ jlx, int iry, int jrx, bool p, int ly, int lx, int ry, int rx) const {\n   \
    \     if (iry <= ly or ry <= ily or jrx <= lx or rx <= jlx) {\n            return\
    \ mon.unit();\n        } else if (ly <= ily and iry <= ry and lx <= jlx and jrx\
    \ <= rx) {\n            return at(i, j);\n        } else if ((ly <= ily and iry\
    \ <= ry) or (p and not (lx <= jlx and jrx <= rx))) {\n            return mon.append(\n\
    \                area_concat(i, 2 * j + 1, ily, jlx, iry, (jlx + jrx) / 2, not\
    \ p, ly, lx, ry, rx),\n                area_concat(i, 2 * j + 2, ily, (jlx + jrx)\
    \ / 2, iry, jrx, not p, ly, lx, ry, rx));\n        } else {\n            return\
    \ mon.append(\n                area_concat(2 * i + 1, j, ily, jlx, (ily + iry)\
    \ / 2, jrx, not p, ly, lx, ry, rx),\n                area_concat(2 * i + 2, j,\
    \ (ily + iry) / 2, jlx, iry, jrx, not p, ly, lx, ry, rx));\n        }\n    }\n\
    \    /**\n     * @note call area_concat O((ry - ly) / h * (rx - lx) / w) times\n\
    \     */\n    value_type area_concat_torus(int ly, int lx, int ry, int rx) const\
    \ {\n        value_type acc = mon.unit();\n        while (ly < 0) { ly += h1;\
    \ ry += h1; }\n        while (lx < 0) { lx += w1; rx += w1; }\n        for (int\
    \ bi = ly / h1; bi <= (ry - 1) / h1; ++ bi) {\n            int ly1 = (bi == ly\
    \ / h1 ? ly % h1 : 0);\n            int ry1 = (bi == ry / h1 ? ry % h1 : h1);\n\
    \            for (int bj = lx / w1; bj <= (rx - 1) / w1; ++ bj) {\n          \
    \      int lx1 = (bj == lx / w1 ? lx % w1 : 0);\n                int rx1 = (bj\
    \ == rx / w1 ? rx % w1 : w1);\n                acc = mon.append(acc, area_concat(ly1,\
    \ lx1, ry1, rx1));\n            }\n        }\n        return acc;\n    }\n};\n\
    \nstruct max_monoid {\n    typedef int value_type;\n    int unit() const { return\
    \ INT_MIN; }\n    int append(int a, int b) const { return max(a, b); }\n};\n\n\
    struct plus_monoid {\n    typedef int value_type;\n    int unit() const { return\
    \ 0; }\n    int append(int a, int b) const { return a + b; }\n};\n\nunittest {\n\
    \    default_random_engine gen;\n    REP (iteration, 100) {\n        int h = uniform_int_distribution<int>(1,\
    \ 30)(gen);\n        int w = uniform_int_distribution<int>(1, 30)(gen);\n    \
    \    vector<vector<int> > a(h, vector<int>(w));\n        segment_tree_2d<plus_monoid>\
    \ segtree(h, w);\n        REP (y, h) REP (x, w) {\n            a[y][x] = uniform_int_distribution<int>(-10,\
    \ 10)(gen);\n            segtree.point_set(y, x, a[y][x]);\n        }\n      \
    \  REP (y, h) REP (x, w) {\n            assert (a[y][x] == segtree.area_concat(y,\
    \ x, y + 1, x + 1));\n        }\n        REP (iteration, 100) {\n            int\
    \ ly = uniform_int_distribution<int>(0, h - 1)(gen);\n            int lx = uniform_int_distribution<int>(0,\
    \ w - 1)(gen);\n            int ry = uniform_int_distribution<int>(ly + 1, h)(gen);\n\
    \            int rx = uniform_int_distribution<int>(lx + 1, w)(gen);\n       \
    \     int acc = 0;\n            REP3 (y, ly, ry) {\n                REP3 (x, lx,\
    \ rx) {\n                    acc += a[y][x];\n                }\n            }\n\
    \            assert (acc == segtree.area_concat(ly, lx, ry, rx));\n        }\n\
    \        REP (iteration, 10) {\n            int ly = uniform_int_distribution<int>(-\
    \ 100, 50)(gen);\n            int lx = uniform_int_distribution<int>(- 100, 50)(gen);\n\
    \            int ry = uniform_int_distribution<int>(ly, 100)(gen);\n         \
    \   int rx = uniform_int_distribution<int>(lx, 100)(gen);\n            int acc\
    \ = 0;\n            REP3 (y, ly, ry) {\n                REP3 (x, lx, rx) {\n \
    \                   acc += a[(y % h + h) % h][(x % w + w) % w];\n            \
    \    }\n            }\n            assert (acc == segtree.area_concat_torus(ly,\
    \ lx, ry, rx));\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/segment-tree-2d.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/segment-tree-2d.inc.cpp
layout: document
redirect_from:
- /library/old/segment-tree-2d.inc.cpp
- /library/old/segment-tree-2d.inc.cpp.html
title: old/segment-tree-2d.inc.cpp
---
