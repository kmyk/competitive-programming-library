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


# VerificationStatus.DEFAULT utils/next_combination.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/next_combination.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-01 19:13:43+09:00


* see: <a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf">http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>

/**
 * @note copied from the reference implementation of N2639
 * @see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf
 */
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator last2) {
    if (first1 == last1 or first2 == last2) {
        return false;
    }
    BidirectionalIterator m1 = last1;
    BidirectionalIterator m2 = last2;
    -- m2;
    while (-- m1 != first1 and not (*m1 < *m2)) {
    }
    bool result = (m1 == first1) and not (*first1 < *m2);
    if (! result ) {
        while (first2 != m2 and not (*m1 < *first2)) {
            ++ first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++ first1;
        ++ first2;
    }
    if (first1 != last1 and first2 != last2) {
        m1 = last1;
        m2 = first2;
        while (m1 != first1 and m2 != last2) {
            std::iter_swap(-- m1, m2);
            ++ m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return not result;
}

template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
    return next_combination(first, middle, middle, last);
}

template <class BidirectionalIterator>
inline bool prev_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
    return next_combination(middle, last, first, middle);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/next_combination.hpp"
#include <algorithm>

/**
 * @note copied from the reference implementation of N2639
 * @see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2639.pdf
 */
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first1, BidirectionalIterator last1, BidirectionalIterator first2, BidirectionalIterator last2) {
    if (first1 == last1 or first2 == last2) {
        return false;
    }
    BidirectionalIterator m1 = last1;
    BidirectionalIterator m2 = last2;
    -- m2;
    while (-- m1 != first1 and not (*m1 < *m2)) {
    }
    bool result = (m1 == first1) and not (*first1 < *m2);
    if (! result ) {
        while (first2 != m2 and not (*m1 < *first2)) {
            ++ first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++ first1;
        ++ first2;
    }
    if (first1 != last1 and first2 != last2) {
        m1 = last1;
        m2 = first2;
        while (m1 != first1 and m2 != last2) {
            std::iter_swap(-- m1, m2);
            ++ m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return not result;
}

template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
    return next_combination(first, middle, middle, last);
}

template <class BidirectionalIterator>
inline bool prev_combination(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last) {
    return next_combination(middle, last, first, middle);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

