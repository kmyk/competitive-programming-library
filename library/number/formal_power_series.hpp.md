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


# :heavy_check_mark: number/formal_power_series.hpp
* category: number


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [modulus/mint.hpp](../modulus/mint.hpp.html)
* :heavy_check_mark: [a specialized version of Garner's algorithm](number_theoretic_transformation.hpp.html)
* :heavy_check_mark: [utils/macros.hpp](../utils/macros.hpp.html)


## Verified
* :heavy_check_mark: [number/formal_power_series.exp.test.cpp](../../verify/number/formal_power_series.exp.test.cpp.html)
* :heavy_check_mark: [number/formal_power_series.inv.test.cpp](../../verify/number/formal_power_series.inv.test.cpp.html)
* :heavy_check_mark: [number/formal_power_series.log.test.cpp](../../verify/number/formal_power_series.log.test.cpp.html)


## Code
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <initializer_list>
#include <tuple>
#include <vector>
#include "modulus/mint.hpp"
#include "number/number_theoretic_transformation.hpp"
#include "utils/macros.hpp"

template <class T>
struct formal_power_series {
    std::vector<T> a;

    inline size_t size() const { return a.size(); }
    inline bool empty() const { return a.empty(); }
    inline T at(int i) const { return (i < size() ? a[i] : T(0)); }
    inline const std::vector<T> & data() const { return a; }

    formal_power_series() = default;
    formal_power_series(const std::vector<T> & a_) : a(a_) { shrink(); }
    formal_power_series(const std::initializer_list<T> & init) : a(init) { shrink(); }
    template <class Iterator>
    formal_power_series(Iterator first, Iterator last) : a(first, last) { shrink(); }
    void shrink() { while (not a.empty() and a.back().value == 0) a.pop_back(); }

    inline formal_power_series<T> operator + (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) += other;
    }
    inline formal_power_series<T> operator - (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) -= other;
    }
    inline formal_power_series<T> & operator += (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] += other.a[i];
        return *this;
    }
    inline formal_power_series<T> & operator -= (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] -= other.a[i];
        return *this;
    }
    inline formal_power_series<T> operator * (const formal_power_series<T> & other) const {
        return formal_power_series<T>(ntt_convolution(a, other.a));
    }
    inline formal_power_series<T> operator * (T b) {
        return formal_power_series<T>(a) *= b;
    }
    inline formal_power_series<T> & operator *= (T b) {
        REP (i, size()) a[i] *= b;
        return *this;
    }

    inline formal_power_series<T> integral() const {
        std::vector<T> b(size() + 1);
        REP (i, size()) {
            b[i + 1] = a[i] / (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> differential() const {
        if (empty()) return *this;
        std::vector<T> b(size() - 1);
        REP (i, size() - 1) {
            b[i] = a[i + 1] * (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> modulo_x_to(int k) const {
        return formal_power_series<T>(a.begin(), a.begin() + std::min<int>(size(), k));
    }

    formal_power_series<T> inv(int n) const {
        assert (at(0) != 0);
        formal_power_series<T> res { at(0).inv() };
        for (int i = 1; i < n; i *= 2) {
            res = (res * T(2) - res * res * modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return res.modulo_x_to(n);
    }
    formal_power_series<T> exp(int n) const {
        formal_power_series<T> f{ 1 };
        formal_power_series<T> g{ 1 };
        for (int i = 1; i < n; i *= 2) {
            g = (g * 2 - f * g * g).modulo_x_to(i);
            formal_power_series<T> q = differential().modulo_x_to(i - 1);
            formal_power_series<T> w = (q + g * (f.differential() - f * q)).modulo_x_to(2 * i - 1);
            f = (f + f * (*this - w.integral()).modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return f.modulo_x_to(n);
    }
    inline formal_power_series<T> log(int n) const {
        assert (at(0) == 1);
        return (this->differential() * this->inv(n - 1)).modulo_x_to(n - 1).integral();
    }
    inline formal_power_series<T> pow(int k, int n) const {
        return (this->log(n) * k).exp(n);
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

