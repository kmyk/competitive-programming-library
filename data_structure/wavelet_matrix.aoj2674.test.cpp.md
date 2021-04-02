---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fully_indexable_dictionary.hpp
    title: "Fully Indexable Dictionary / \u5B8C\u5099\u8F9E\u66F8"
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: Wavelet Matrix
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674
  bundledCode: "#line 1 \"data_structure/wavelet_matrix.aoj2674.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674\"\n\
    #line 2 \"data_structure/wavelet_matrix.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <climits>\n#include <cstdint>\n#include <vector>\n#line 2 \"data_structure/fully_indexable_dictionary.hpp\"\
    \n#include <algorithm>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int\
    \ i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i)\
    \ < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 7 \"data_structure/fully_indexable_dictionary.hpp\"\
    \n\n/**\n * @brief Fully Indexable Dictionary / \u5B8C\u5099\u8F9E\u66F8\n * @docs\
    \ data_structure/fully_indexable_dictionary.md\n * @note space complexity $o(N)$.\
    \ $1.5N$-bit consumed\n */\nclass fully_indexable_dictionary {\n    static constexpr\
    \ std::size_t block_size = 64;\n    std::vector<uint64_t> block;\n    std::vector<int32_t>\
    \ rank_block;  // a blocked cumulative sum\npublic:\n    std::size_t size;\n \
    \   fully_indexable_dictionary() = default;\n    template <typename T>\n    fully_indexable_dictionary(const\
    \ std::vector<T> & bits) {\n        size = bits.size();\n        std::size_t block_count\
    \ = size / block_size + 1;\n        block.resize(block_count);\n        REP (i,\
    \ size) if (bits[i]) {\n            block[i / block_size] |= (1ull << (i % block_size));\n\
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
    \ & (1ull << (i % block_size));\n    }\n};\n#line 9 \"data_structure/wavelet_matrix.hpp\"\
    \n\n\n/**\n * @brief Wavelet Matrix\n * @docs data_structure/wavelet_matrix.md\n\
    \ * @tparam BITS express the range [0, 2^BITS) of values. You can assume BITS\
    \ \\le \\log N, using coordinate compression\n * @see https://www.slideshare.net/pfi/ss-15916040\n\
    \ */\ntemplate <int BITS>\nstruct wavelet_matrix {\n    static_assert (BITS <\
    \ CHAR_BIT * sizeof(uint64_t), \"\");\n    std::array<fully_indexable_dictionary,\
    \ BITS> fid;\n    std::array<int, BITS> zero_count;\n\n    wavelet_matrix() =\
    \ default;\n    /**\n     * @note O(N BITS)\n     */\n    template <typename T>\n\
    \    wavelet_matrix(std::vector<T> data) {\n        int size = data.size();\n\
    \        REP (i, size) {\n            assert (0 <= data[i] and data[i] < (1ull\
    \ << BITS));\n        }\n        // bit-inversed radix sort\n        std::vector<char>\
    \ bits(size);\n        std::vector<T> next(size);\n        REP_R (k, BITS) {\n\
    \            auto low  = next.begin();\n            auto high = next.rbegin();\n\
    \            REP (i, size) {\n                bits[i] = bool(data[i] & (1ull <<\
    \ k));\n                (bits[i] ? *(high ++) : *(low ++)) = data[i];\n      \
    \      }\n            fid[k] = fully_indexable_dictionary(bits);\n           \
    \ zero_count[k] = low - next.begin();\n            reverse(next.rbegin(), high);\n\
    \            data.swap(next);\n        }\n    }\n\n    /**\n     * @brief count\
    \ the occurrences of value in [l, r)\n     * @note O(BITS)\n     * @note even\
    \ if l = 0, of course the final [l, r) is not always [0, r)\n     */\n    int\
    \ rank(uint64_t value, int l, int r) const {\n        assert (0 <= value and value\
    \ < (1ull << BITS));\n        assert (0 <= l and l <= r and r <= fid[0].size);\n\
    \        REP_R (k, BITS) {\n            bool p = value & (1ull << k);\n      \
    \      l = fid[k].rank(p, l) + p * zero_count[k];\n            r = fid[k].rank(p,\
    \ r) + p * zero_count[k];\n        }\n        return r - l;\n    }\n    int rank(uint64_t\
    \ value, int r) const {\n        return rank(value, 0, r);\n    }\n\n    /**\n\
    \     * @brief find the index of the k-th occurence of value\n     * @note O(BITS\
    \ SELECT) when FID's select() is O(SELECT)\n     */\n    int select(uint64_t value,\
    \ int k) const {\n        assert (0 <= value and value < (1ull << BITS));\n  \
    \      assert (0 <= k);\n        // do rank(value, 0, size) with logging\n   \
    \     std::vector<int> l(BITS + 1), r(BITS + 1);\n        l[BITS] = 0;\n     \
    \   r[BITS] = fid[0].size;\n        REP_R (d, BITS) {\n            bool p = value\
    \ & (1ull << d);\n            l[d] = fid[d].rank(p, l[d + 1]) + p * zero_count[d];\n\
    \            r[d] = fid[d].rank(p, r[d + 1]) + p * zero_count[d];\n        }\n\
    \        if (r[0] - l[0] <= k) return fid[0].size;\n        // trace the log inversely\n\
    \        REP (d, BITS) {\n            bool p = value & (1ull << d);\n        \
    \    k = fid[d].select(p, k, l[d + 1]) - l[d + 1];\n        }\n        return\
    \ k;\n    }\n    /**\n     * @brief find the index of the k-th occurence of value\
    \ in [l, n)\n     */\n    int select(uint64_t value, int k, int l) const {\n \
    \       return select(value, k + rank(value, l));\n    }\n\n    /**\n     * @brief\
    \ returns the i-th element\n     * @note O(BITS)\n     */\n    uint64_t access(int\
    \ i) const {\n        assert (0 <= i and i < fid[0].size);\n        uint64_t acc\
    \ = 0;\n        REP_R (k, BITS) {\n            bool p = fid[k].access(i);\n  \
    \          acc |= uint64_t(p) << k;\n            i = fid[k].rank(p, i) + p * zero_count[k];\n\
    \        }\n        return acc;\n    }\n\n    /**\n     * @brief find the k-th\
    \ number in [l, r)\n     * @note O(BITS)\n     */\n    uint64_t quantile(int k,\
    \ int l, int r) {\n        assert (0 <= k);\n        assert (0 <= l and l <= r\
    \ and r <= fid[0].size);\n        if (r - l <= k) return 1ull << BITS;\n     \
    \   uint64_t acc = 0;\n        REP_R (d, BITS) {\n            int lc = fid[d].rank(1,\
    \ l);\n            int rc = fid[d].rank(1, r);\n            int zero = (r - l)\
    \ - (rc - lc);\n            bool p = (k >= zero);\n            if (p) {\n    \
    \            acc |= 1ull << d;\n                l = lc + zero_count[d];\n    \
    \            r = rc + zero_count[d];\n                k -= zero;\n           \
    \ } else {\n                l -= lc;\n                r -= rc;\n            }\n\
    \        }\n        return acc;\n    }\n\n    /**\n     * @brief count the number\
    \ of values in [value_l, value_r) in range [l, r)\n     * @note O(BITS)\n    \
    \ */\n    int range_frequency(int l, int r, uint64_t value_l, uint64_t value_r)\
    \ const {\n        assert (0 <= l and l <= r and r <= fid[0].size);\n        assert\
    \ (0 <= value_l and value_l <= value_r and value_r <= (1ull << BITS));\n     \
    \   return range_frequency(BITS - 1, l, r, 0, value_l, value_r);\n    }\n    int\
    \ range_frequency(int k, int l, int r, uint64_t v, uint64_t a, uint64_t b) const\
    \ {\n        if (l == r) return 0;\n        if (k == -1) return (a <= v and v\
    \ < b) ? r - l : 0;\n        uint64_t nv  =  v |  (1ull << k);\n        uint64_t\
    \ nnv = nv | ((1ull << k) - 1);\n        if (nnv < a or b <= v) return 0;\n  \
    \      if (a <= v and nnv < b) return r - l;\n        int lc = fid[k].rank(1,\
    \ l);\n        int rc = fid[k].rank(1, r);\n        return\n            range_frequency(k\
    \ - 1,             l - lc,             r - rc,  v, a, b) +\n            range_frequency(k\
    \ - 1, lc + zero_count[k], rc + zero_count[k], nv, a, b);\n    }\n\n    /**\n\
    \     * @brief flexible version of range_frequency, buf a little bit slow\n  \
    \   * @note O(K BITS), K is the number of kinds of values in the range\n     *\
    \ @arg void callback(uint64_t value, int count)\n     */\n    template <typename\
    \ Func>\n    void range_frequency_callback(int l, int r, uint64_t value_l, uint64_t\
    \ value_r, Func callback) const {\n        assert (0 <= l and l <= r and r <=\
    \ fid[0].size);\n        assert (0 <= value_l and value_l <= value_r and value_r\
    \ <= (1ull << BITS));\n        range_frequency_callback(BITS - 1, l, r, 0, value_l,\
    \ value_r, callback);\n    }\n    template <typename Func>\n    void range_frequency_callback(int\
    \ k, int l, int r, uint64_t v, uint64_t a, uint64_t b, Func callback) const {\n\
    \        if (l == r) return;\n        if (b <= v) return;\n        if (k == -1)\
    \ {\n            if (a <= v) callback(v, r - l);\n            return;\n      \
    \  }\n        uint64_t nv  = v  | (1ull << k);\n        uint64_t nnv = nv | (((1ull\
    \ << k) - 1));\n        if (nnv < a) return;\n        int lc = fid[k].rank(1,\
    \ l);\n        int rc = fid[k].rank(1, r);\n        range_frequency_callback(k\
    \ - 1,             l - lc,             r - rc,  v, a, b, callback);\n        range_frequency_callback(k\
    \ - 1, lc + zero_count[k], rc + zero_count[k], nv, a, b, callback);\n    }\n};\n\
    #line 4 \"data_structure/wavelet_matrix.aoj2674.test.cpp\"\n#include <cstdio>\n\
    #include <numeric>\nusing namespace std;\n\nint main() {\n    constexpr int BITS\
    \ = 30;\n    constexpr int MIN_X = -1e8;\n    constexpr int MAX_X = 1e8;\n\n \
    \   // read a sequence\n    int d; scanf(\"%d\", &d);\n    vector<int> x(d);\n\
    \    REP (i, d) {\n        scanf(\"%d\", &x[i]);\n        x[i] -= MIN_X;\n   \
    \ }\n\n    // construct a wavelet matrix\n    wavelet_matrix<BITS> wm(x);\n\n\
    \    // answer to queries\n    int q; scanf(\"%d\", &q);\n    while (q --) {\n\
    \        int l, r, e; scanf(\"%d%d%d\", &l, &r, &e);\n        -- l;\n        int\
    \ a = min(x[l], x[r - 1]);\n        int b = max(x[l], x[r - 1]);\n        int\
    \ cnt = 0;\n        cnt += wm.range_frequency(l, r, 0, max(0, a - e));\n     \
    \   cnt += wm.range_frequency(l, r, min(MAX_X - MIN_X + 1, b + e + 1), MAX_X -\
    \ MIN_X + 1);\n        printf(\"%d\\n\", cnt);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674\"\
    \n#include \"data_structure/wavelet_matrix.hpp\"\n#include \"utils/macros.hpp\"\
    \n#include <cstdio>\n#include <numeric>\nusing namespace std;\n\nint main() {\n\
    \    constexpr int BITS = 30;\n    constexpr int MIN_X = -1e8;\n    constexpr\
    \ int MAX_X = 1e8;\n\n    // read a sequence\n    int d; scanf(\"%d\", &d);\n\
    \    vector<int> x(d);\n    REP (i, d) {\n        scanf(\"%d\", &x[i]);\n    \
    \    x[i] -= MIN_X;\n    }\n\n    // construct a wavelet matrix\n    wavelet_matrix<BITS>\
    \ wm(x);\n\n    // answer to queries\n    int q; scanf(\"%d\", &q);\n    while\
    \ (q --) {\n        int l, r, e; scanf(\"%d%d%d\", &l, &r, &e);\n        -- l;\n\
    \        int a = min(x[l], x[r - 1]);\n        int b = max(x[l], x[r - 1]);\n\
    \        int cnt = 0;\n        cnt += wm.range_frequency(l, r, 0, max(0, a - e));\n\
    \        cnt += wm.range_frequency(l, r, min(MAX_X - MIN_X + 1, b + e + 1), MAX_X\
    \ - MIN_X + 1);\n        printf(\"%d\\n\", cnt);\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/wavelet_matrix.hpp
  - data_structure/fully_indexable_dictionary.hpp
  - utils/macros.hpp
  isVerificationFile: true
  path: data_structure/wavelet_matrix.aoj2674.test.cpp
  requiredBy: []
  timestamp: '2020-02-28 15:08:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/wavelet_matrix.aoj2674.test.cpp
layout: document
redirect_from:
- /verify/data_structure/wavelet_matrix.aoj2674.test.cpp
- /verify/data_structure/wavelet_matrix.aoj2674.test.cpp.html
title: data_structure/wavelet_matrix.aoj2674.test.cpp
---
