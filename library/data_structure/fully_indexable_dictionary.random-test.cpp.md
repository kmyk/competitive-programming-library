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


# :warning: data_structure/fully_indexable_dictionary.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/fully_indexable_dictionary.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :heavy_check_mark: <a href="fully_indexable_dictionary.hpp.html">a fully indexable dictionary <small>(data_structure/fully_indexable_dictionary.hpp)</small></a>
* :warning: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "data_structure/fully_indexable_dictionary.hpp"

#include <cassert>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

template <class RandomEngine>
void unittest(int n, RandomEngine & gen) {
    vector<bool> data(n);
    REP (i, n) {
        data[i] = bernoulli_distribution(0.5)(gen);
    }
    auto rank = [&](bool value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](bool value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    fully_indexable_dictionary fid(data);
    for (int iteration = 1000; iteration --; ) {
        bool value = bernoulli_distribution(0.5)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (fid.rank(value, l, r) == rank(value, l, r));
        assert (fid.select(value, k, l) == select(value, k, l));
        assert (fid.access(l) == data[l]);
    }
}

int main() {
    random_device device;
    default_random_engine gen(device());
    unittest(1, gen);
    unittest(126, gen);
    unittest(127, gen);
    unittest(128, gen);
    unittest(129, gen);
    unittest(10000, gen);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/fully_indexable_dictionary.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 7 "data_structure/fully_indexable_dictionary.hpp"

/**
 * @brief a fully indexable dictionary
 * @note space complexity $o(N)$. $1.5N$-bit consumed
 */
class fully_indexable_dictionary {
    static constexpr std::size_t block_size = 64;
    std::vector<uint64_t> block;
    std::vector<int32_t> rank_block;  // a blocked cumulative sum
public:
    std::size_t size;
    fully_indexable_dictionary() = default;
    template <typename T>
    fully_indexable_dictionary(const std::vector<T> & bits) {
        size = bits.size();
        std::size_t block_count = size / block_size + 1;
        block.resize(block_count);
        REP (i, size) if (bits[i]) {
            block[i / block_size] |= (1ull << (i % block_size));
        }
        rank_block.resize(block_count);
        rank_block[0] = 0;
        REP (i, block_count - 1) {
            rank_block[i + 1] = rank_block[i] + __builtin_popcountll(block[i]);
        }
    }

    /**
     * @brief count the number of value in $[0, r)$
     * @note $O(1)$
     */
    int rank(bool value, int r) const {
        assert (0 <= r and r <= size);
        uint64_t mask = (1ull << (r % block_size)) - 1;
        int rank_1 = rank_block[r / block_size] + __builtin_popcountll(block[r /block_size] & mask);
        return value ? rank_1 : r - rank_1;
    }
    int rank(bool value, int l, int r) const {
        assert (0 <= l and l <= r and r <= size);
        return rank(value, r) - rank(value, l);
    }

    /**
     * @brief find the index of the $k$-th occurrence of value
     * @note if there is no such index, returns size
     * @note $O(\log N)$
     */
    int select(bool value, int k) const {
        if (k >= rank(value, size)) return size;
        // binary search: max { i | rank_block[i] <= k }
        int l = 0, r = block.size();  // [l, r)
        while (r - l > 1) {
            int m = (l + r) / 2;
            int rank_block_m = (value ? rank_block[m] : m * block_size - rank_block[m]);
            (rank_block_m <= k ? l : r) = m;
        }
        int block_index = l;
        // binary search: max { i | rank(i) <= k }
        l = block_index * block_size;
        r = std::min<int>(size, (block_index + 1) * block_size);  // [l, r)
        while (r - l > 1) {
            int m = (l + r) / 2;
            (rank(value, m) <= k ? l : r) = m;
        }
        return l;
    }
    /**
     * @brief select(value, k) in [l, size)
     */
    int select(bool value, int k, int l) const {
        assert (0 <= l and l <= size);
        return select(value, k + rank(value, l));
    }

    /**
     * @brief get the $i$-th element
     * @note $O(1)$
     */
    bool access(int i) const {
        assert (0 <= i and i < size);
        return block[i / block_size] & (1ull << (i % block_size));
    }
};
#line 2 "data_structure/fully_indexable_dictionary.random-test.cpp"

#include <cassert>
#include <random>
#include <vector>
#line 7 "data_structure/fully_indexable_dictionary.random-test.cpp"
using namespace std;

template <class RandomEngine>
void unittest(int n, RandomEngine & gen) {
    vector<bool> data(n);
    REP (i, n) {
        data[i] = bernoulli_distribution(0.5)(gen);
    }
    auto rank = [&](bool value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](bool value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    fully_indexable_dictionary fid(data);
    for (int iteration = 1000; iteration --; ) {
        bool value = bernoulli_distribution(0.5)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (fid.rank(value, l, r) == rank(value, l, r));
        assert (fid.select(value, k, l) == select(value, k, l));
        assert (fid.access(l) == data[l]);
    }
}

int main() {
    random_device device;
    default_random_engine gen(device());
    unittest(1, gen);
    unittest(126, gen);
    unittest(127, gen);
    unittest(128, gen);
    unittest(129, gen);
    unittest(10000, gen);
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

