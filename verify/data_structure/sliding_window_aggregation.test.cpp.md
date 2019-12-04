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


# :heavy_check_mark: data_structure/sliding_window_aggregation.test.cpp


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [data_structure/sliding_window_aggregation.hpp](../../library/data_structure/sliding_window_aggregation.hpp.html)
* :heavy_check_mark: [modulus/mint.hpp](../../library/modulus/mint.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../../library/utils/macros.hpp.html)


## Code
```cpp
#include "data_structure/sliding_window_aggregation.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <random>
#include <vector>
#include "utils/macros.hpp"
#include "modulus/mint.hpp"
using namespace std;

constexpr int MOD = 1e9 + 7;
struct linear_function_monoid {
    typedef pair<mint<MOD>, mint<MOD> > value_type;
    value_type unit() const { return make_pair(1, 0); }
    value_type append(value_type f, value_type g) const { return make_pair(f.first * g.first, f.first * g.second + f.second); }
};

int main() {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 10000) {
        deque<typename linear_function_monoid::value_type> deq;
        sliding_window_aggregation<linear_function_monoid> swag;
        REP (i, 1000) {
            if (not deq.empty() and bernoulli_distribution()(gen) < 0.3) {
                deq.pop_front();
                swag.pop();
            } else {
                mint<MOD> a = uniform_int_distribution<int>(0, MOD - 1)(gen);
                mint<MOD> b = uniform_int_distribution<int>(0, MOD - 1)(gen);
                deq.emplace_back(a, b);
                swag.push(make_pair(a, b));
            }
            assert (accumulate(ALL(deq), linear_function_monoid().unit(), [&](typename linear_function_monoid::value_type f, typename linear_function_monoid::value_type g) {
                return linear_function_monoid().append(f, g);
            }) == swag.accumulate());
        }
    }
    return 0;
}

```

[Back to top page](../../index.html)
