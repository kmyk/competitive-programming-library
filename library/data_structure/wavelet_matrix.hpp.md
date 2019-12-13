---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: a wavelet matrix
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/wavelet_matrix.hpp">View this file on GitHub</a>
    - Last commit date: 2019-06-03 23:38:29 +0900


* find the k-th number in [l, r)
* count the number of values in [value_l, value_r) in range [l, r)
* flexible version of range_frequency, buf a little bit slow


## Depends On
* :warning: <a href="fully_indexable_dictionary.hpp.html">a fully indexable dictionary</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Required By
* :warning: <a href="wavelet_matrix.random-test.cpp.html">data_structure/wavelet_matrix.random-test.cpp</a>


## Code
{% raw %}
```cpp
#pragma once
#include <array>
#include <cassert>
#include <climits>
#include <cstdint>
#include <vector>
#include "data_structure/fully_indexable_dictionary.hpp"
#include "utils/macros.hpp"


/**
 * @brief a wavelet matrix
 * @tparam BITS express the range [0, 2^BITS) of values. You can assume BITS \le \log N, using coordinate compression
 */
template <int BITS>
struct wavelet_matrix {
    static_assert (BITS < CHAR_BIT * sizeof(uint64_t), "");
    std::array<fully_indexable_dictionary, BITS> fid;
    std::array<int, BITS> zero_count;
    wavelet_matrix() = default;
    /**
     * @note O(N BITS)
     */
    template <typename T>
    wavelet_matrix(std::vector<T> data) {
        int size = data.size();
        REP (i, size) {
            assert (0 <= data[i] and data[i] < (1ull << BITS));
        }
        // bit-inversed radix sort
        std::vector<char> bits(size);
        std::vector<T> next(size);
        REP_R (k, BITS) {
            auto low  = next.begin();
            auto high = next.rbegin();
            REP (i, size) {
                bits[i] = bool(data[i] & (1ull << k));
                (bits[i] ? *(high ++) : *(low ++)) = data[i];
            }
            fid[k] = fully_indexable_dictionary(bits);
            zero_count[k] = low - next.begin();
            reverse(next.rbegin(), high);
            data.swap(next);
        }
    }
    /**
     * @note O(BITS)
     * @note even if l = 0, of course the final [l, r) is not always [0, r)
     */
    int rank(uint64_t value, int l, int r) const {
        assert (0 <= value and value < (1ull << BITS));
        assert (0 <= l and l <= r and r <= fid[0].size);
        REP_R (k, BITS) {
            bool p = value & (1ull << k);
            l = fid[k].rank(p, l) + p * zero_count[k];
            r = fid[k].rank(p, r) + p * zero_count[k];
        }
        return r - l;
    }
    int rank(uint64_t value, int r) const {
        return rank(value, 0, r);
    }
    /**
     * @note O(BITS SELECT) when FID's select() is O(SELECT)
     */
    int select(uint64_t value, int k) const {
        assert (0 <= value and value < (1ull << BITS));
        assert (0 <= k);
        // do rank(value, 0, size) with logging
        std::vector<int> l(BITS + 1), r(BITS + 1);
        l[BITS] = 0;
        r[BITS] = fid[0].size;
        REP_R (d, BITS) {
            bool p = value & (1ull << d);
            l[d] = fid[d].rank(p, l[d + 1]) + p * zero_count[d];
            r[d] = fid[d].rank(p, r[d + 1]) + p * zero_count[d];
        }
        if (r[0] - l[0] <= k) return fid[0].size;
        // trace the log inversely
        REP (d, BITS) {
            bool p = value & (1ull << d);
            k = fid[d].select(p, k, l[d + 1]) - l[d + 1];
        }
        return k;
    }
    int select(uint64_t value, int k, int l) const {
        return select(value, k + rank(value, l));
    }
    /**
     * @note O(BITS)
     */
    uint64_t access(int i) const {
        assert (0 <= i and i < fid[0].size);
        uint64_t acc = 0;
        REP_R (k, BITS) {
            bool p = fid[k].access(i);
            acc |= uint64_t(p) << k;
            i = fid[k].rank(p, i) + p * zero_count[k];
        }
        return acc;
    }
    /**
     * @brief find the k-th number in [l, r)
     * @note O(BITS)
     */
    uint64_t quantile(int k, int l, int r) {
        assert (0 <= k);
        assert (0 <= l and l <= r and r <= fid[0].size);
        if (r - l <= k) return 1ull << BITS;
        uint64_t acc = 0;
        REP_R (d, BITS) {
            int lc = fid[d].rank(1, l);
            int rc = fid[d].rank(1, r);
            int zero = (r - l) - (rc - lc);
            bool p = (k >= zero);
            if (p) {
                acc |= 1ull << d;
                l = lc + zero_count[d];
                r = rc + zero_count[d];
                k -= zero;
            } else {
                l -= lc;
                r -= rc;
            }
        }
        return acc;
    }
    /**
     * @brief count the number of values in [value_l, value_r) in range [l, r)
     * @note O(BITS)
     */
    int range_frequency(int l, int r, uint64_t value_l, uint64_t value_r) const {
        assert (0 <= l and l <= r and r <= fid[0].size);
        assert (0 <= value_l and value_l <= value_r and value_r <= (1ull << BITS));
        return range_frequency(BITS - 1, l, r, 0, value_l, value_r);
    }
    int range_frequency(int k, int l, int r, uint64_t v, uint64_t a, uint64_t b) const {
        if (l == r) return 0;
        if (k == -1) return (a <= v and v < b) ? r - l : 0;
        uint64_t nv  =  v |  (1ull << k);
        uint64_t nnv = nv | ((1ull << k) - 1);
        if (nnv < a or b <= v) return 0;
        if (a <= v and nnv < b) return r - l;
        int lc = fid[k].rank(1, l);
        int rc = fid[k].rank(1, r);
        return
            range_frequency(k - 1,             l - lc,             r - rc,  v, a, b) +
            range_frequency(k - 1, lc + zero_count[k], rc + zero_count[k], nv, a, b);
    }
    /**
     * @brief flexible version of range_frequency, buf a little bit slow
     * @note O(K BITS), K is the number of kinds of values in the range
     * @arg void callback(uint64_t value, int count)
     */
    template <typename Func>
    void range_frequency_callback(int l, int r, uint64_t value_l, uint64_t value_r, Func callback) const {
        assert (0 <= l and l <= r and r <= fid[0].size);
        assert (0 <= value_l and value_l <= value_r and value_r <= (1ull << BITS));
        range_frequency_callback(BITS - 1, l, r, 0, value_l, value_r, callback);
    }
    template <typename Func>
    void range_frequency_callback(int k, int l, int r, uint64_t v, uint64_t a, uint64_t b, Func callback) const {
        if (l == r) return;
        if (b <= v) return;
        if (k == -1) {
            if (a <= v) callback(v, r - l);
            return;
        }
        uint64_t nv  = v  | (1ull << k);
        uint64_t nnv = nv | (((1ull << k) - 1));
        if (nnv < a) return;
        int lc = fid[k].rank(1, l);
        int rc = fid[k].rank(1, r);
        range_frequency_callback(k - 1,             l - lc,             r - rc,  v, a, b, callback);
        range_frequency_callback(k - 1, lc + zero_count[k], rc + zero_count[k], nv, a, b, callback);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

