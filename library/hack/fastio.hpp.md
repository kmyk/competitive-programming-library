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


# :heavy_check_mark: hack/fastio.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d78b6f30225cdc811adfe8d4e7c9fd34">hack</a>
* <a href="{{ site.github.repository_url }}/blob/master/hack/fastio.hpp">View this file on GitHub</a>
    - Last commit date: 2020-02-26 19:41:19+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp.html">data_structure/dynamic_connectivity_offline.dynamic_graph_vertex_add_component_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp.html">data_structure/euler_tour_subtree_query.vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.dynamic_tree_vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_add_path_sum.test.cpp.html">data_structure/link_cut_tree.vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.vertex_set_path_composite.test.cpp.html">data_structure/link_cut_tree.vertex_set_path_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_F.test.cpp.html">data_structure/segment_tree_beats.DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_G.test.cpp.html">data_structure/segment_tree_beats.DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_H.test.cpp.html">data_structure/segment_tree_beats.DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.DSL_2_I.test.cpp.html">data_structure/segment_tree_beats.DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree_beats.yosupo.test.cpp.html">data_structure/segment_tree_beats.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/wavelet_matrix.range_kth_smallest.test.cpp.html">data_structure/wavelet_matrix.range_kth_smallest.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/hack/fastio.yosupo.test.cpp.html">hack/fastio.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation.yosupo.test.cpp.html">modulus/number_theoretic_transformation.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp.html">modulus/number_theoretic_transformation_with_garner.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp.html">modulus/stirling_number_of_the_second_kind_convolution.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/longest_common_prefix.yosupo.test.cpp.html">string/longest_common_prefix.yosupo.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/string/suffix_array.yosupo.test.cpp.html">string/suffix_array.yosupo.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline Char in() { return getchar_unlocked(); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline std::string in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    std::string s;
    do { s.push_back(c); } while (not isspace(c = getchar_unlocked()));
    return s;
}
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline Integer in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    if (std::is_signed<Integer>::value and c == '-') return -in<Integer>();
    Integer n = 0;
    do { n = n * 10 + c - '0'; } while (not isspace(c = getchar_unlocked()));
    return n;
}

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline void out(char c) { putchar_unlocked(c); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline void out(const std::string & s) { for (char c : s) putchar_unlocked(c); }
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline void out(Integer n) {
    char s[20];
    int i = 0;
    if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "hack/fastio.hpp"
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline Char in() { return getchar_unlocked(); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline std::string in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    std::string s;
    do { s.push_back(c); } while (not isspace(c = getchar_unlocked()));
    return s;
}
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline Integer in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    if (std::is_signed<Integer>::value and c == '-') return -in<Integer>();
    Integer n = 0;
    do { n = n * 10 + c - '0'; } while (not isspace(c = getchar_unlocked()));
    return n;
}

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline void out(char c) { putchar_unlocked(c); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline void out(const std::string & s) { for (char c : s) putchar_unlocked(c); }
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline void out(Integer n) {
    char s[20];
    int i = 0;
    if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

