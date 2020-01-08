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


# :warning: old/point-int.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/point-int.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct point_t { ll y, x; };
point_t operator + (point_t a, point_t b) { return { a.y + b.y, a.x + b.x }; }
point_t operator - (point_t a, point_t b) { return { a.y - b.y, a.x - b.x }; }
point_t operator - (point_t a) { return { - a.y, - a.x }; }
point_t operator * (ll a, point_t b) { return { a * b.y, a * b.x }; }
std::pair<ll,ll> to_pair(point_t a) { return { a.y, a.x }; }
bool operator == (point_t a, point_t b) { return to_pair(a) == to_pair(b); }
bool operator != (point_t a, point_t b) { return to_pair(a) != to_pair(b); }
bool operator <  (point_t a, point_t b) { return to_pair(a) <  to_pair(b); }
bool operator <= (point_t a, point_t b) { return to_pair(a) <= to_pair(b); }
bool operator >= (point_t a, point_t b) { return to_pair(a) >= to_pair(b); }
bool operator >  (point_t a, point_t b) { return to_pair(a) >  to_pair(b); }
ll length_squared(point_t p) { return p.y*p.y + p.x*p.x; }
ll length(point_t p) { return sqrt(length_squared(p)); }
point_t normalized(point_t a) { return (1.0 / length(a)) * a; }
ll   dot(point_t p, point_t q) { return p.x * q.x + p.y * q.y; }
ll cross(point_t p, point_t q) { return p.x * q.y - p.y * q.x; }
int ccw(point_t a, point_t b, point_t c) { ll z = cross(b - a, c - a); return z > 0 ? 1 : z < 0 ? -1 : 0; }
std::istream & operator >> (std::istream & in, point_t & a) { return in >> a.x >> a.y; }
std::ostream & operator << (std::ostream & out, point_t a) { return out << a.x << ' ' << a.y; }

function<bool (point_t)> make_is_on_field(point_t p) { return [=](point_t q) { return 0 <= q.y and q.y < p.y and 0 <= q.x and q.x < p.x; }; }
const point_t directions[4] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/point-int.inc.cpp"
struct point_t { ll y, x; };
point_t operator + (point_t a, point_t b) { return { a.y + b.y, a.x + b.x }; }
point_t operator - (point_t a, point_t b) { return { a.y - b.y, a.x - b.x }; }
point_t operator - (point_t a) { return { - a.y, - a.x }; }
point_t operator * (ll a, point_t b) { return { a * b.y, a * b.x }; }
std::pair<ll,ll> to_pair(point_t a) { return { a.y, a.x }; }
bool operator == (point_t a, point_t b) { return to_pair(a) == to_pair(b); }
bool operator != (point_t a, point_t b) { return to_pair(a) != to_pair(b); }
bool operator <  (point_t a, point_t b) { return to_pair(a) <  to_pair(b); }
bool operator <= (point_t a, point_t b) { return to_pair(a) <= to_pair(b); }
bool operator >= (point_t a, point_t b) { return to_pair(a) >= to_pair(b); }
bool operator >  (point_t a, point_t b) { return to_pair(a) >  to_pair(b); }
ll length_squared(point_t p) { return p.y*p.y + p.x*p.x; }
ll length(point_t p) { return sqrt(length_squared(p)); }
point_t normalized(point_t a) { return (1.0 / length(a)) * a; }
ll   dot(point_t p, point_t q) { return p.x * q.x + p.y * q.y; }
ll cross(point_t p, point_t q) { return p.x * q.y - p.y * q.x; }
int ccw(point_t a, point_t b, point_t c) { ll z = cross(b - a, c - a); return z > 0 ? 1 : z < 0 ? -1 : 0; }
std::istream & operator >> (std::istream & in, point_t & a) { return in >> a.x >> a.y; }
std::ostream & operator << (std::ostream & out, point_t a) { return out << a.x << ' ' << a.y; }

function<bool (point_t)> make_is_on_field(point_t p) { return [=](point_t q) { return 0 <= q.y and q.y < p.y and 0 <= q.x and q.x < p.x; }; }
const point_t directions[4] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

