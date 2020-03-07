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


# VerificationStatus.DEFAULT monoids/matrix_template.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/matrix_template.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :warning: <a href="../number/matrix_template.hpp.html">number/matrix_template.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "number/matrix_template.hpp"

template <class T, int N>
struct matrix_monoid {
    typedef matrix<T, N, N> value_type;
    value_type f;
    value_type unit() const {
        return unit_matrix<T, N>();
    }
    value_type mult(const value_type & f, const value_type & g) const {
        return f * g;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "number/matrix_template.hpp"
#include <array>
#include <cstdint>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "number/matrix_template.hpp"

template <typename T, size_t H, size_t W>
using matrix = std::array<std::array<T, W>, H>;

template <typename T, size_t A, size_t B, size_t C>
matrix<T, A, C> operator * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {
    matrix<T, A, C> c = {};
    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];
    return c;
}
template <typename T, size_t H, size_t W>
std::array<T, H> operator * (matrix<T, H, W> const & a, std::array<T, W> const & b) {
    std::array<T, H> c = {};
    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> operator + (matrix<T, H, W> const & a, matrix<T, H, W> const & b) {
    matrix<T, H, W> c;
    REP (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];
    return c;
}

template <typename T, size_t N>
std::array<T, N> operator + (std::array<T, N> const & a, std::array<T, N> const & b) {
    std::array<T, N> c;
    REP (i, N) c[i] = a[i] + b[i];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> zero_matrix() {
    return {};
}

template <typename T, size_t N>
matrix<T, N, N> unit_matrix() {
    matrix<T, N, N> a = {};
    REP (i, N) a[i][i] = 1;
    return a;
}

template <typename T, size_t N>
matrix<T, N, N> powmat(matrix<T, N, N> x, int64_t k) {
    matrix<T, N, N> y = unit_matrix<T, N>();
    for (; k; k >>= 1) {
        if (k & 1) y = y * x;
        x = x * x;
    }
    return y;
}
#line 3 "monoids/matrix_template.hpp"

template <class T, int N>
struct matrix_monoid {
    typedef matrix<T, N, N> value_type;
    value_type f;
    value_type unit() const {
        return unit_matrix<T, N>();
    }
    value_type mult(const value_type & f, const value_type & g) const {
        return f * g;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

