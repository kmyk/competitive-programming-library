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


# :heavy_check_mark: utils/coordinate_compression.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/coordinate_compression.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24+09:00




## Depends on

* :question: <a href="macros.hpp.html">utils/macros.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.rectangle_sum.test.cpp.html">data_structure/wavelet_matrix.rectangle_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <vector>
#include "utils/macros.hpp"

template <class T>
struct coordinate_compression {
    std::vector<T> data;
    coordinate_compression() = default;
    template <class Iterator>
    coordinate_compression(Iterator first, Iterator last) {
        unsafe_insert(first, last);
        unsafe_rebuild();
    }
    template <class Iterator>
    void unsafe_insert(Iterator first, Iterator last) {
        data.insert(data.end(), first, last);
    }
    void unsafe_rebuild() {
        std::sort(ALL(data));
        data.erase(std::unique(ALL(data)), data.end());
    }
    int operator [] (const T & value) {
        return std::lower_bound(ALL(data), value) - data.begin();
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/coordinate_compression.hpp"
#include <algorithm>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 5 "utils/coordinate_compression.hpp"

template <class T>
struct coordinate_compression {
    std::vector<T> data;
    coordinate_compression() = default;
    template <class Iterator>
    coordinate_compression(Iterator first, Iterator last) {
        unsafe_insert(first, last);
        unsafe_rebuild();
    }
    template <class Iterator>
    void unsafe_insert(Iterator first, Iterator last) {
        data.insert(data.end(), first, last);
    }
    void unsafe_rebuild() {
        std::sort(ALL(data));
        data.erase(std::unique(ALL(data)), data.end());
    }
    int operator [] (const T & value) {
        return std::lower_bound(ALL(data), value) - data.begin();
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

