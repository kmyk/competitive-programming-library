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


# :warning: number/rational.inc.cpp
<a href="../../index.html">Back to top page</a>

* category: number
* <a href="{{ site.github.repository_url }}/blob/master/number/rational.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-07-06 01:52:56 +0900




## Code
{% raw %}
```cpp
struct rational { int num, den; };
rational make_rational(ll num, ll den = 1) { ll k = gcd(num, den); return (rational) { int(num / k), int(den / k) }; }
rational operator + (rational a, rational b) { return make_rational(a.num *(ll) b.den + b.num *(ll) a.den, a.den *(ll) b.den); }
rational operator - (rational a, rational b) { return make_rational(a.num *(ll) b.den - b.num *(ll) a.den, a.den *(ll) b.den); }
rational operator * (rational a, rational b) { return make_rational(a.num *(ll) b.num, a.den *(ll) b.den); }
rational operator / (rational a, rational b) { return make_rational(a.num *(ll) b.den, a.den *(ll) b.num); }
bool operator < (rational a, rational b) { return a.num *(ll) b.den < b.num *(ll) a.den; }
bool operator > (rational a, rational b) { return a.num *(ll) b.den > b.num *(ll) a.den; }
bool operator == (rational a, rational b) { return a.num == b.num and a.den == b.den; }
bool operator != (rational a, rational b) { return a.num != b.num  or a.den != b.den; }
ostream & operator << (ostream & out, rational a) { if (a.den == 0) return out << "invalid"; return out << a.num << '/' << a.den; }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

