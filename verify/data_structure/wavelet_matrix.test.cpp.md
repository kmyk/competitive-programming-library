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


# :heavy_check_mark: data_structure/wavelet_matrix.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [data_structure/wavelet_matrix.hpp](../../library/data_structure/wavelet_matrix.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
```cpp
#include "data_structure/wavelet_matrix.hpp"

#include <cassert>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

template <int BITS, class RandomEngine>
void unittest(int n, RandomEngine & gen) {
    vector<uint64_t> data(n);
    REP (i, n) data[i] = uniform_int_distribution<uint64_t>(0, (1ull << BITS) - 1)(gen);
    auto rank = [&](uint64_t value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](uint64_t value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    auto quantile = [&](int k, int l, int r) {
        vector<uint64_t> range;
        REP3 (i, l, r) range.push_back(data[i]);
        sort(ALL(range));
        return range[k];
    };
    auto range_frequency = [&](int l, int r, uint64_t value_l, uint64_t value_r) {
        int cnt = 0;
        REP3 (i, l, r) cnt += value_l <= data[i] and data[i] < value_r;
        return cnt;
    };
    wavelet_matrix<BITS> wm(data);
    for (int iteration = 1000; iteration --; ) {
        uint64_t value = uniform_int_distribution<uint64_t>(0, (1ull << BITS) - 1)(gen);
        uint64_t another_value = uniform_int_distribution<uint64_t>(value, (1ull << BITS) - 1)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (wm.rank(value, l, r) == rank(value, l, r));
        assert (wm.select(value, k, l) == select(value, k, l));
        assert (wm.access(l) == data[l]);
        assert (wm.quantile(k, l, r) == quantile(k, l, r));
        assert (wm.range_frequency(l, r, value, another_value + 1) == range_frequency(l, r, value, another_value + 1));
        {
            int acc = 0;
            wm.range_frequency_callback(l, r, value, another_value + 1, [&](uint64_t value, int count) {
                acc += count;
            });
            assert (acc == range_frequency(l, r, value, another_value + 1));
        }
    }
}

int main() {
    random_device device;
    default_random_engine gen(device());
    unittest<3>(10, gen);
    unittest<10>(100, gen);
    unittest<10>(126, gen);
    unittest<10>(127, gen);
    unittest<10>(128, gen);
    unittest<10>(129, gen);
    unittest<63>(10000, gen);
    return 0;
}

```

[Back to top page](../../index.html)

