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


# :warning: data_structure/sliding_window_aggregation.random-test.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/sliding_window_aggregation.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-13 18:43:42 +0900




## Depends On
* :warning: <a href="sliding_window_aggregation.hpp.html">get sum of elements in the queue</a>
* :heavy_check_mark: <a href="../modulus/mint.hpp.html">modulus/mint.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code
{% raw %}
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
{% endraw %}

<a href="../../index.html">Back to top page</a>

