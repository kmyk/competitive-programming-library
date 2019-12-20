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


# :warning: Andrew's Monotone Chain <small>(geometry/a.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed7daeb157cd9b31e53896ad3c771a26">geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/a.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2018-03-01 19:03:05+09:00


* segment - segment, inclusive
* point and line
* line and line


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
typedef complex<double> point;
double cross(point a, point b) { return a.real() * b.imag() - a.imag() * b.real(); }
int ccw(point a, point b, point c) { double z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }

/**
 * @brief Andrew's Monotone Chain
 */
vector<point> convex_hull(vector<point> ps) {
    int n = ps.size();
    sort(ALL(ps), [&](point a, point b) { return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });
    vector<point> ch(2 * n);
    int k = 0;
    for (int i = 0; i < n; ch[k ++] = ps[i ++]) // lower-hull
        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) // upper-hull
        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    ch.resize(k - 1);
    return ch;
}

struct circle { point p; double r; };
struct line { point s, t; };
struct segment { point s, t; };
struct ray { point s, t; };

/**
 * @note あまり小さくすると誤差で死ぬ
 */
const double eps = 1e-6;
double sq(double x) { return pow(x, 2); }

struct point { double y, x; };
point operator + (point a, point b) { return (point) { a.y + b.y, a.x + b.x }; }
point operator - (point a, point b) { return (point) { a.y - b.y, a.x - b.x }; }
point operator * (point a, double b) { return (point) { a.y * b, a.x * b }; }
point operator / (point a, double b) { return (point) { a.y / b, a.x / b }; }
point operator < (point a, point b) { return make_pair(a.y, a.x) < make_pair(b.y, b.x); }
double distance(point a, point b) { return sqrt(sq(a.y - b.y) + sq(a.x - b.x)); }
double   dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
int ccw(point a, point b, point c) { double z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }




/**
 * @brief segment - segment, inclusive
 */
bool does_intersect(segment const & a, segment const & b){
    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 and
           ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;
}

/**
 * @brief point and line
 */
bool does_intersect(point a, line b) { return ccw(0, a - b.s, b.t - b.s) == 0; }
bool does_intersect(line a, point b) { return does_intersect(b, a); }

/**
 * @brief line and line
 */
bool is_parallel(line a, line b) { return ccw(0, a.t - a.s, b.t - b.s) == 0; }
bool is_same(line a, line b) { return does_intersect(a.s, b) and does_intersect(a.t, b); }
/**
 * @note false if two lines are the same
 */
bool does_intersect(line a, line b) {
    return not is_parallel(a, b)
        and not is_same(a, b);
}
point intersection(line a, line b) {
    assert (does_intersect(a, b));
    double p = cross(a.t - a.s, b.t - b.s);
    double q = cross(a.t - a.s, a.t - b.s);
    return (q / p) * (b.t - b.s) + b.s;
}


/**
 * @note helper for segments and rays
 */
template <typename T, typename U>
bool does_intersect_linelikes(T const & a, U const & b) {
    if (not does_intersect(to_line(a), to_line(b))) return false;
    point c = intersection(to_line(a), to_line(b));
    return does_intersect(c, a)
        and does_intersect(c, b);
}


line to_line(segment a) {
    return { a.s, a.t };
}
bool does_intersect(point a, segment b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps
        and dot(b.s - b.t, a - b.t) > - eps;
}
bool does_intersect(segment a, point b) {
    return does_intersect(b, a);
}
bool is_overwraped(segment a, segment b) {
    return does_intersect(a.s, b)
        and does_intersect(a.t, b);
}
bool does_intersect(segment a, segment b) {
    return does_intersect_linelikes(a, b);
}
point intersection(segment a, segment b) {
    assert (does_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}


line to_line(ray a) {
    return { a.s, a.t };
}
bool does_intersect(point a, ray b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps;
}
bool does_intersect(ray a, point b) {
    return does_intersect(b, a);
}
bool is_overwraped(ray a, ray b) {
    return (does_intersect(a.s, b) and does_intersect(a.t, b))
        or (does_intersect(b.s, a) and does_intersect(b.t, a));
}
bool does_intersect(ray a, ray b) {
    return does_intersect_linelikes(a, b);
}
point intersection(ray a, ray b) {
    assert (does_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}






struct polygon { vector<point> ps; };
segment nth_segment(polygon const & a, int i) {
    int j = (i+1) % a.ps.size();
    return { a.ps[i], a.ps[j] };
}
bool does_intersect(ray a, segment b) { return does_intersect_linelikes(a, b); }
bool does_intersect(segment a, ray b) { return does_intersect_linelikes(a, b); }
point intersection(ray a, segment b) { return intersection_linelikes(a, b); }
point intersection(segment a, ray b) { return intersection_linelikes(a, b); }
template <typename T>
vector<point> intersections_polygon_linelike(polygon const & a, T const & b) {
    vector<point> result;
    repeat (i, a.ps.size()) {
        if (does_intersect(nth_segment(a, i), b)) {
            result.push_back(intersection(nth_segment(a, i), b));
        }
    }
    return result;
}
bool does_intersect(polygon const & a, ray const & b) {
    return not intersections_polygon_linelike(a, b).empty();
}
bool does_intersect(polygon const & a, point const & b) {
    ray c = { b, b + point(1, 0) };
    return intersections_polygon_linelike(a, c).size() % 2 == 1;
}
bool does_intersect_strict(polygon const & a, point const & b) {
    repeat (i, a.ps.size()) {
        if (does_intersect(nth_segment(a, i), b)) {
            return false; // when the point is on a segment of the polygon
        }
    }
    return does_intersect(a, b);
}
bool does_intersect_strict(polygon const & a, segment const & b) { // the boundary is not included
    vector<point> ps = intersections_polygon_linelike(a, b);
    for (point p : ps) {
        bool ignored = false;
        if (abs(p - b.s) < eps or abs(p - b.t) < eps) {
            ignored = true;
        }
        if (not ignored) {
            for (point q : a.ps) {
                if (abs(p - q) < eps) {
                    ignored = true; // when the intersection point is one of the vertex of the polygon
                    break;
                }
            }
        }
        if (not ignored) return true;
    }
    return false;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "geometry/a.inc.cpp"
typedef complex<double> point;
double cross(point a, point b) { return a.real() * b.imag() - a.imag() * b.real(); }
int ccw(point a, point b, point c) { double z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }

/**
 * @brief Andrew's Monotone Chain
 */
vector<point> convex_hull(vector<point> ps) {
    int n = ps.size();
    sort(ALL(ps), [&](point a, point b) { return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });
    vector<point> ch(2 * n);
    int k = 0;
    for (int i = 0; i < n; ch[k ++] = ps[i ++]) // lower-hull
        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) // upper-hull
        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    ch.resize(k - 1);
    return ch;
}

struct circle { point p; double r; };
struct line { point s, t; };
struct segment { point s, t; };
struct ray { point s, t; };

/**
 * @note あまり小さくすると誤差で死ぬ
 */
const double eps = 1e-6;
double sq(double x) { return pow(x, 2); }

struct point { double y, x; };
point operator + (point a, point b) { return (point) { a.y + b.y, a.x + b.x }; }
point operator - (point a, point b) { return (point) { a.y - b.y, a.x - b.x }; }
point operator * (point a, double b) { return (point) { a.y * b, a.x * b }; }
point operator / (point a, double b) { return (point) { a.y / b, a.x / b }; }
point operator < (point a, point b) { return make_pair(a.y, a.x) < make_pair(b.y, b.x); }
double distance(point a, point b) { return sqrt(sq(a.y - b.y) + sq(a.x - b.x)); }
double   dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
int ccw(point a, point b, point c) { double z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }




/**
 * @brief segment - segment, inclusive
 */
bool does_intersect(segment const & a, segment const & b){
    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 and
           ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;
}

/**
 * @brief point and line
 */
bool does_intersect(point a, line b) { return ccw(0, a - b.s, b.t - b.s) == 0; }
bool does_intersect(line a, point b) { return does_intersect(b, a); }

/**
 * @brief line and line
 */
bool is_parallel(line a, line b) { return ccw(0, a.t - a.s, b.t - b.s) == 0; }
bool is_same(line a, line b) { return does_intersect(a.s, b) and does_intersect(a.t, b); }
/**
 * @note false if two lines are the same
 */
bool does_intersect(line a, line b) {
    return not is_parallel(a, b)
        and not is_same(a, b);
}
point intersection(line a, line b) {
    assert (does_intersect(a, b));
    double p = cross(a.t - a.s, b.t - b.s);
    double q = cross(a.t - a.s, a.t - b.s);
    return (q / p) * (b.t - b.s) + b.s;
}


/**
 * @note helper for segments and rays
 */
template <typename T, typename U>
bool does_intersect_linelikes(T const & a, U const & b) {
    if (not does_intersect(to_line(a), to_line(b))) return false;
    point c = intersection(to_line(a), to_line(b));
    return does_intersect(c, a)
        and does_intersect(c, b);
}


line to_line(segment a) {
    return { a.s, a.t };
}
bool does_intersect(point a, segment b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps
        and dot(b.s - b.t, a - b.t) > - eps;
}
bool does_intersect(segment a, point b) {
    return does_intersect(b, a);
}
bool is_overwraped(segment a, segment b) {
    return does_intersect(a.s, b)
        and does_intersect(a.t, b);
}
bool does_intersect(segment a, segment b) {
    return does_intersect_linelikes(a, b);
}
point intersection(segment a, segment b) {
    assert (does_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}


line to_line(ray a) {
    return { a.s, a.t };
}
bool does_intersect(point a, ray b) {
    return abs(cross(b.t - b.s, a - b.s)) < eps
        and dot(b.t - b.s, a - b.s) > - eps;
}
bool does_intersect(ray a, point b) {
    return does_intersect(b, a);
}
bool is_overwraped(ray a, ray b) {
    return (does_intersect(a.s, b) and does_intersect(a.t, b))
        or (does_intersect(b.s, a) and does_intersect(b.t, a));
}
bool does_intersect(ray a, ray b) {
    return does_intersect_linelikes(a, b);
}
point intersection(ray a, ray b) {
    assert (does_intersect(a, b));
    return intersection(to_line(a), to_line(b));
}






struct polygon { vector<point> ps; };
segment nth_segment(polygon const & a, int i) {
    int j = (i+1) % a.ps.size();
    return { a.ps[i], a.ps[j] };
}
bool does_intersect(ray a, segment b) { return does_intersect_linelikes(a, b); }
bool does_intersect(segment a, ray b) { return does_intersect_linelikes(a, b); }
point intersection(ray a, segment b) { return intersection_linelikes(a, b); }
point intersection(segment a, ray b) { return intersection_linelikes(a, b); }
template <typename T>
vector<point> intersections_polygon_linelike(polygon const & a, T const & b) {
    vector<point> result;
    repeat (i, a.ps.size()) {
        if (does_intersect(nth_segment(a, i), b)) {
            result.push_back(intersection(nth_segment(a, i), b));
        }
    }
    return result;
}
bool does_intersect(polygon const & a, ray const & b) {
    return not intersections_polygon_linelike(a, b).empty();
}
bool does_intersect(polygon const & a, point const & b) {
    ray c = { b, b + point(1, 0) };
    return intersections_polygon_linelike(a, c).size() % 2 == 1;
}
bool does_intersect_strict(polygon const & a, point const & b) {
    repeat (i, a.ps.size()) {
        if (does_intersect(nth_segment(a, i), b)) {
            return false; // when the point is on a segment of the polygon
        }
    }
    return does_intersect(a, b);
}
bool does_intersect_strict(polygon const & a, segment const & b) { // the boundary is not included
    vector<point> ps = intersections_polygon_linelike(a, b);
    for (point p : ps) {
        bool ignored = false;
        if (abs(p - b.s) < eps or abs(p - b.t) < eps) {
            ignored = true;
        }
        if (not ignored) {
            for (point q : a.ps) {
                if (abs(p - q) < eps) {
                    ignored = true; // when the intersection point is one of the vertex of the polygon
                    break;
                }
            }
        }
        if (not ignored) return true;
    }
    return false;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

