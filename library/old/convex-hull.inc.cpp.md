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


# :warning: old/convex-hull.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/convex-hull.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00


* see: <a href="http://www.prefield.com/algorithm/geometry/convex_hull.html">http://www.prefield.com/algorithm/geometry/convex_hull.html</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
double dot(complex<double> a, complex<double> b) { return real(a * conj(b)); }
double cross(complex<double> a, complex<double> b) { return imag(conj(a) * b); }
int ccw(complex<double> a, complex<double> b, complex<double> c) {
    b -= a;
    c -= a;
    if (cross(b, c) > 0) return +1;  // counter clockwise
    if (cross(b, c) < 0) return -1;  // clockwise
    if (dot(b, c) < 0)   return +2;  // c--a--b on line
    if (abs(b) < abs(c)) return -2;  // a--b--c on line
    return 0;
}
/**
 * @see http://www.prefield.com/algorithm/geometry/convex_hull.html
 */
vector<complex<double> > convex_hull(vector<complex<double> > ps) {
    int n = ps.size();
    if (n <= 2) return ps;
    int k = 0;
    sort(ps.begin(), ps.end(), [&](complex<double> const a, complex<double> const b) { return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });
    vector<complex<double> > ch(2 * n);
    for (int i = 0; i < n; ch[k ++] = ps[i ++]) {  // lower-hull
        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) {  // upper-hull
        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    }
    ch.resize(k - 1);
    return ch;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/convex-hull.inc.cpp"
double dot(complex<double> a, complex<double> b) { return real(a * conj(b)); }
double cross(complex<double> a, complex<double> b) { return imag(conj(a) * b); }
int ccw(complex<double> a, complex<double> b, complex<double> c) {
    b -= a;
    c -= a;
    if (cross(b, c) > 0) return +1;  // counter clockwise
    if (cross(b, c) < 0) return -1;  // clockwise
    if (dot(b, c) < 0)   return +2;  // c--a--b on line
    if (abs(b) < abs(c)) return -2;  // a--b--c on line
    return 0;
}
/**
 * @see http://www.prefield.com/algorithm/geometry/convex_hull.html
 */
vector<complex<double> > convex_hull(vector<complex<double> > ps) {
    int n = ps.size();
    if (n <= 2) return ps;
    int k = 0;
    sort(ps.begin(), ps.end(), [&](complex<double> const a, complex<double> const b) { return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });
    vector<complex<double> > ch(2 * n);
    for (int i = 0; i < n; ch[k ++] = ps[i ++]) {  // lower-hull
        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) {  // upper-hull
        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    }
    ch.resize(k - 1);
    return ch;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

