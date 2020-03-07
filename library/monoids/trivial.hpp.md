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


# VerificationStatus.VERIFIED monoids/trivial.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#315142c884fa9bdd2be3b42923ffe964">monoids</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoids/trivial.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 07:18:51+09:00




## Required by

* :warning: <a href="trivial_action.hpp.html">monoids/trivial_action.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/link_cut_tree.marked_ancestor.test.cpp.html">data_structure/link_cut_tree.marked_ancestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

struct trivial_monoid {
    typedef struct {} value_type;
    value_type unit() const { return (value_type) {}; }
    value_type mult(value_type a, value_type b) const { return (value_type) {}; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoids/trivial.hpp"

struct trivial_monoid {
    typedef struct {} value_type;
    value_type unit() const { return (value_type) {}; }
    value_type mult(value_type a, value_type b) const { return (value_type) {}; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

