---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.aoj2674.test.cpp
    title: data_structure/wavelet_matrix.aoj2674.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
    title: data_structure/wavelet_matrix.range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.rectangle_sum.test.cpp
    title: data_structure/wavelet_matrix.rectangle_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: data_structure/fully_indexable_dictionary.md
    document_title: "Fully Indexable Dictionary / \u5B8C\u5099\u8F9E\u66F8"
    links: []
  bundledCode: "#line 2 \"data_structure/fully_indexable_dictionary.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <vector>\n#line\
    \ 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++\
    \ (i))\n#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define\
    \ REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m,\
    \ n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n#line 7 \"data_structure/fully_indexable_dictionary.hpp\"\n\n/**\n\
    \ * @brief Fully Indexable Dictionary / \u5B8C\u5099\u8F9E\u66F8\n * @docs data_structure/fully_indexable_dictionary.md\n\
    \ * @note space complexity $o(N)$. $1.5N$-bit consumed\n */\nclass fully_indexable_dictionary\
    \ {\n    static constexpr std::size_t block_size = 64;\n    std::vector<uint64_t>\
    \ block;\n    std::vector<int32_t> rank_block;  // a blocked cumulative sum\n\
    public:\n    std::size_t size;\n    fully_indexable_dictionary() = default;\n\
    \    template <typename T>\n    fully_indexable_dictionary(const std::vector<T>\
    \ & bits) {\n        size = bits.size();\n        std::size_t block_count = size\
    \ / block_size + 1;\n        block.resize(block_count);\n        REP (i, size)\
    \ if (bits[i]) {\n            block[i / block_size] |= (1ull << (i % block_size));\n\
    \        }\n        rank_block.resize(block_count);\n        rank_block[0] = 0;\n\
    \        REP (i, block_count - 1) {\n            rank_block[i + 1] = rank_block[i]\
    \ + __builtin_popcountll(block[i]);\n        }\n    }\n\n    /**\n     * @brief\
    \ count the number of value in $[0, r)$\n     * @note $O(1)$\n     */\n    int\
    \ rank(bool value, int r) const {\n        assert (0 <= r and r <= size);\n  \
    \      uint64_t mask = (1ull << (r % block_size)) - 1;\n        int rank_1 = rank_block[r\
    \ / block_size] + __builtin_popcountll(block[r /block_size] & mask);\n       \
    \ return value ? rank_1 : r - rank_1;\n    }\n    int rank(bool value, int l,\
    \ int r) const {\n        assert (0 <= l and l <= r and r <= size);\n        return\
    \ rank(value, r) - rank(value, l);\n    }\n\n    /**\n     * @brief find the index\
    \ of the $k$-th occurrence of value\n     * @note if there is no such index, returns\
    \ size\n     * @note $O(\\log N)$\n     */\n    int select(bool value, int k)\
    \ const {\n        if (k >= rank(value, size)) return size;\n        // binary\
    \ search: max { i | rank_block[i] <= k }\n        int l = 0, r = block.size();\
    \  // [l, r)\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            int rank_block_m = (value ? rank_block[m] : m * block_size - rank_block[m]);\n\
    \            (rank_block_m <= k ? l : r) = m;\n        }\n        int block_index\
    \ = l;\n        // binary search: max { i | rank(i) <= k }\n        l = block_index\
    \ * block_size;\n        r = std::min<int>(size, (block_index + 1) * block_size);\
    \  // [l, r)\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            (rank(value, m) <= k ? l : r) = m;\n        }\n        return l;\n\
    \    }\n    /**\n     * @brief select(value, k) in [l, size)\n     */\n    int\
    \ select(bool value, int k, int l) const {\n        assert (0 <= l and l <= size);\n\
    \        return select(value, k + rank(value, l));\n    }\n\n    /**\n     * @brief\
    \ get the $i$-th element\n     * @note $O(1)$\n     */\n    bool access(int i)\
    \ const {\n        assert (0 <= i and i < size);\n        return block[i / block_size]\
    \ & (1ull << (i % block_size));\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n\
    #include <vector>\n#include \"utils/macros.hpp\"\n\n/**\n * @brief Fully Indexable\
    \ Dictionary / \u5B8C\u5099\u8F9E\u66F8\n * @docs data_structure/fully_indexable_dictionary.md\n\
    \ * @note space complexity $o(N)$. $1.5N$-bit consumed\n */\nclass fully_indexable_dictionary\
    \ {\n    static constexpr std::size_t block_size = 64;\n    std::vector<uint64_t>\
    \ block;\n    std::vector<int32_t> rank_block;  // a blocked cumulative sum\n\
    public:\n    std::size_t size;\n    fully_indexable_dictionary() = default;\n\
    \    template <typename T>\n    fully_indexable_dictionary(const std::vector<T>\
    \ & bits) {\n        size = bits.size();\n        std::size_t block_count = size\
    \ / block_size + 1;\n        block.resize(block_count);\n        REP (i, size)\
    \ if (bits[i]) {\n            block[i / block_size] |= (1ull << (i % block_size));\n\
    \        }\n        rank_block.resize(block_count);\n        rank_block[0] = 0;\n\
    \        REP (i, block_count - 1) {\n            rank_block[i + 1] = rank_block[i]\
    \ + __builtin_popcountll(block[i]);\n        }\n    }\n\n    /**\n     * @brief\
    \ count the number of value in $[0, r)$\n     * @note $O(1)$\n     */\n    int\
    \ rank(bool value, int r) const {\n        assert (0 <= r and r <= size);\n  \
    \      uint64_t mask = (1ull << (r % block_size)) - 1;\n        int rank_1 = rank_block[r\
    \ / block_size] + __builtin_popcountll(block[r /block_size] & mask);\n       \
    \ return value ? rank_1 : r - rank_1;\n    }\n    int rank(bool value, int l,\
    \ int r) const {\n        assert (0 <= l and l <= r and r <= size);\n        return\
    \ rank(value, r) - rank(value, l);\n    }\n\n    /**\n     * @brief find the index\
    \ of the $k$-th occurrence of value\n     * @note if there is no such index, returns\
    \ size\n     * @note $O(\\log N)$\n     */\n    int select(bool value, int k)\
    \ const {\n        if (k >= rank(value, size)) return size;\n        // binary\
    \ search: max { i | rank_block[i] <= k }\n        int l = 0, r = block.size();\
    \  // [l, r)\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            int rank_block_m = (value ? rank_block[m] : m * block_size - rank_block[m]);\n\
    \            (rank_block_m <= k ? l : r) = m;\n        }\n        int block_index\
    \ = l;\n        // binary search: max { i | rank(i) <= k }\n        l = block_index\
    \ * block_size;\n        r = std::min<int>(size, (block_index + 1) * block_size);\
    \  // [l, r)\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            (rank(value, m) <= k ? l : r) = m;\n        }\n        return l;\n\
    \    }\n    /**\n     * @brief select(value, k) in [l, size)\n     */\n    int\
    \ select(bool value, int k, int l) const {\n        assert (0 <= l and l <= size);\n\
    \        return select(value, k + rank(value, l));\n    }\n\n    /**\n     * @brief\
    \ get the $i$-th element\n     * @note $O(1)$\n     */\n    bool access(int i)\
    \ const {\n        assert (0 <= i and i < size);\n        return block[i / block_size]\
    \ & (1ull << (i % block_size));\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/fully_indexable_dictionary.hpp
  requiredBy:
  - data_structure/wavelet_matrix.hpp
  timestamp: '2020-02-28 15:08:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/wavelet_matrix.aoj2674.test.cpp
  - data_structure/wavelet_matrix.range_kth_smallest.test.cpp
  - data_structure/wavelet_matrix.rectangle_sum.test.cpp
documentation_of: data_structure/fully_indexable_dictionary.hpp
layout: document
redirect_from:
- /library/data_structure/fully_indexable_dictionary.hpp
- /library/data_structure/fully_indexable_dictionary.hpp.html
title: "Fully Indexable Dictionary / \u5B8C\u5099\u8F9E\u66F8"
---
## 概要

長さ $N$ の bit 列 $b = (b_0, b_1, \dots, b _ {n - 1}) \in 2^N$ に対し、次が $O(1)$ で処理可能:

-   $\mathtt{rank}(l, r)$: 区間 $\lbrack l, r)$ 中の値 $1$ の出現回数 $$\unicode{35} \lbrace i \in \lbrack l, r) \mid a_i = 1 \rbrace$$ を計算する。
-   $\mathtt{select}(k)$: 位置 $l$ 以降で $k \ge 0$ 番目に出現する値 $1$ の位置 $i$ (つまり $i \ge l$ かつ $a_i = 1$ かつ $$\unicode{35} \lbrace j \in \lbrack l, i) \mid a_j = 1 \rbrace = k$$ を満たす $i$) を計算する。
    -   ただし今回の実装では妥協の結果 $O(\log N)$ になっている
-   $\mathtt{access}(i)$: 値 $b_i$ を計算する。
