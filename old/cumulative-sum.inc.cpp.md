---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: cumulative sum
    links:
    - https://beta.atcoder.jp/contests/abc106/submissions/3361728
  bundledCode: "#line 1 \"old/cumulative-sum.inc.cpp\"\n/**\n * @brief cumulative\
    \ sum\n * @see std::partial_sum\n */\ntemplate <class T, class F>\nvector<T> cumulative_sum(size_t\
    \ n, F f) {\n    vector<T> acc(n + 1);\n    REP (i, n) {\n        acc[i + 1] =\
    \ acc[i] + f(i);\n    }\n    return acc;\n}\n\n/**\n * @brief 2D cumulative sum\n\
    \ */\ntemplate <class T, class F>\nvector<vector<T> > cumulative_sum(size_t h,\
    \ size_t w, F f) {\n    vector<vector<T> > acc(h + 1, vector<T>(w + 1));\n   \
    \ REP (y, h) {\n        REP (x, w) {\n            acc[y + 1][x + 1] = acc[y +\
    \ 1][x] + f(y, x);\n            acc[y + 1][x] += acc[y][x];  // in the same loop\
    \ for speed\n        }\n        acc[y + 1][w] += acc[y][w];\n    }\n    return\
    \ acc;\n}\n\n\n/**\n * @note verified https://beta.atcoder.jp/contests/abc106/submissions/3361728\n\
    \ */\ntemplate <typename T>\nstruct cumulative_sum_2d {\n    int h, w;\n    vector<vector<T>\
    \ > acc;\n    bool frozen;\n    cumulative_sum_2d(int h_, int w_) :\n        \
    \    h(h_),\n            w(w_),\n            acc(h + 1, vector<T>(w + 1)),\n \
    \           frozen(false) {\n    }\n    void add(int y, int x, T value) {\n  \
    \      assert (not frozen);\n        assert (0 <= y and y < h);\n        assert\
    \ (0 <= x and x < w);\n        acc[y + 1][x + 1] += value;\n    }\n    void freeze()\
    \ {\n        assert (not frozen);\n        frozen = true;\n        REP (y, h)\
    \ {\n            REP (x, w) {\n                acc[y + 1][x + 1] += acc[y + 1][x];\n\
    \                acc[y + 1][x] += acc[y][x];  // in the same loop for speed\n\
    \            }\n            acc[y + 1][w] += acc[y][w];\n        }\n    }\n  \
    \  T get(int ly, int lx, int ry, int rx) const {  // [l, r)\n        assert (frozen);\n\
    \        assert (0 <= ly and ly <= ry and ry <= h);\n        assert (0 <= lx and\
    \ lx <= rx and rx <= w);\n        return acc[ry][rx] - acc[ry][lx] - acc[ly][rx]\
    \ + acc[ly][lx];\n    }\n    /**\n     * @note call get O((ry - ly) / h * (rx\
    \ - lx) / w) times\n     */\n    T get_torus(int ly, int lx, int ry, int rx) const\
    \ {\n        T acc = 0;\n        while (ly < 0) { ly += h; ry += h; }\n      \
    \  while (lx < 0) { lx += w; rx += w; }\n        for (int bi = ly / h; bi <= (ry\
    \ - 1) / h; ++ bi) {\n            int ly1 = (bi == ly / h ? ly % h : 0);\n   \
    \         int ry1 = (bi == ry / h ? ry % h : h);\n            for (int bj = lx\
    \ / w; bj <= (rx - 1) / w; ++ bj) {\n                int lx1 = (bj == lx / w ?\
    \ lx % w : 0);\n                int rx1 = (bj == rx / w ? rx % w : w);\n     \
    \           acc += get(ly1, lx1, ry1, rx1);\n            }\n        }\n      \
    \  return acc;\n    }\n};\n"
  code: "/**\n * @brief cumulative sum\n * @see std::partial_sum\n */\ntemplate <class\
    \ T, class F>\nvector<T> cumulative_sum(size_t n, F f) {\n    vector<T> acc(n\
    \ + 1);\n    REP (i, n) {\n        acc[i + 1] = acc[i] + f(i);\n    }\n    return\
    \ acc;\n}\n\n/**\n * @brief 2D cumulative sum\n */\ntemplate <class T, class F>\n\
    vector<vector<T> > cumulative_sum(size_t h, size_t w, F f) {\n    vector<vector<T>\
    \ > acc(h + 1, vector<T>(w + 1));\n    REP (y, h) {\n        REP (x, w) {\n  \
    \          acc[y + 1][x + 1] = acc[y + 1][x] + f(y, x);\n            acc[y + 1][x]\
    \ += acc[y][x];  // in the same loop for speed\n        }\n        acc[y + 1][w]\
    \ += acc[y][w];\n    }\n    return acc;\n}\n\n\n/**\n * @note verified https://beta.atcoder.jp/contests/abc106/submissions/3361728\n\
    \ */\ntemplate <typename T>\nstruct cumulative_sum_2d {\n    int h, w;\n    vector<vector<T>\
    \ > acc;\n    bool frozen;\n    cumulative_sum_2d(int h_, int w_) :\n        \
    \    h(h_),\n            w(w_),\n            acc(h + 1, vector<T>(w + 1)),\n \
    \           frozen(false) {\n    }\n    void add(int y, int x, T value) {\n  \
    \      assert (not frozen);\n        assert (0 <= y and y < h);\n        assert\
    \ (0 <= x and x < w);\n        acc[y + 1][x + 1] += value;\n    }\n    void freeze()\
    \ {\n        assert (not frozen);\n        frozen = true;\n        REP (y, h)\
    \ {\n            REP (x, w) {\n                acc[y + 1][x + 1] += acc[y + 1][x];\n\
    \                acc[y + 1][x] += acc[y][x];  // in the same loop for speed\n\
    \            }\n            acc[y + 1][w] += acc[y][w];\n        }\n    }\n  \
    \  T get(int ly, int lx, int ry, int rx) const {  // [l, r)\n        assert (frozen);\n\
    \        assert (0 <= ly and ly <= ry and ry <= h);\n        assert (0 <= lx and\
    \ lx <= rx and rx <= w);\n        return acc[ry][rx] - acc[ry][lx] - acc[ly][rx]\
    \ + acc[ly][lx];\n    }\n    /**\n     * @note call get O((ry - ly) / h * (rx\
    \ - lx) / w) times\n     */\n    T get_torus(int ly, int lx, int ry, int rx) const\
    \ {\n        T acc = 0;\n        while (ly < 0) { ly += h; ry += h; }\n      \
    \  while (lx < 0) { lx += w; rx += w; }\n        for (int bi = ly / h; bi <= (ry\
    \ - 1) / h; ++ bi) {\n            int ly1 = (bi == ly / h ? ly % h : 0);\n   \
    \         int ry1 = (bi == ry / h ? ry % h : h);\n            for (int bj = lx\
    \ / w; bj <= (rx - 1) / w; ++ bj) {\n                int lx1 = (bj == lx / w ?\
    \ lx % w : 0);\n                int rx1 = (bj == rx / w ? rx % w : w);\n     \
    \           acc += get(ly1, lx1, ry1, rx1);\n            }\n        }\n      \
    \  return acc;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/cumulative-sum.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/cumulative-sum.inc.cpp
layout: document
redirect_from:
- /library/old/cumulative-sum.inc.cpp
- /library/old/cumulative-sum.inc.cpp.html
title: cumulative sum
---
