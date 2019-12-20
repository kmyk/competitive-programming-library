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


# :warning: utils/ternary-search.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/ternary-search.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-12-07 05:10:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @arg f must be a downward-convex function
 * @retrun argmin f
 * @note f is called (iteration + 1) times
 */
template <class Function>
double golden_section_search(double l, double r, int iteration, Function f) {
    static const double GOLDEN_RATIO = (1 + sqrt(5)) / 2;
    double m1 = l + (r - l) / (GOLDEN_RATIO + 1);
    double m2 = l + (r - l) / GOLDEN_RATIO;  // NOTE: this equals to GOLDEN_RATIO / (GOLDEN_RATIO + 1.0)
    double f1 = f(m1);
    double f2 = f(m2);
    while (iteration --) {
        if (f1 < f2){
            r = m2;
            m2 = m1;
            f2 = f1;
            m1 = l + (r - l) / (GOLDEN_RATIO + 1);
            f1 = f(m1);
        } else {
            l = m1;
            m1 = m2;
            f1 = f2;
            m2 = l + (r - l) / GOLDEN_RATIO;
            f2 = f(m2);
        }
    }
    return (l + r) / 2;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/ternary-search.inc.cpp"
/**
 * @arg f must be a downward-convex function
 * @retrun argmin f
 * @note f is called (iteration + 1) times
 */
template <class Function>
double golden_section_search(double l, double r, int iteration, Function f) {
    static const double GOLDEN_RATIO = (1 + sqrt(5)) / 2;
    double m1 = l + (r - l) / (GOLDEN_RATIO + 1);
    double m2 = l + (r - l) / GOLDEN_RATIO;  // NOTE: this equals to GOLDEN_RATIO / (GOLDEN_RATIO + 1.0)
    double f1 = f(m1);
    double f2 = f(m2);
    while (iteration --) {
        if (f1 < f2){
            r = m2;
            m2 = m1;
            f2 = f1;
            m1 = l + (r - l) / (GOLDEN_RATIO + 1);
            f1 = f(m1);
        } else {
            l = m1;
            m1 = m2;
            f1 = f2;
            m2 = l + (r - l) / GOLDEN_RATIO;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

