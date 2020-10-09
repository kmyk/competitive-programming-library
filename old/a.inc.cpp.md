---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Andrew's Monotone Chain
    links: []
  bundledCode: "#line 1 \"old/a.inc.cpp\"\ntypedef complex<double> point;\ndouble\
    \ cross(point a, point b) { return a.real() * b.imag() - a.imag() * b.real();\
    \ }\nint ccw(point a, point b, point c) { double z = cross(b - a, c - a); return\
    \ z > eps ? 1 : z < - eps ? -1 : 0; }\n\n/**\n * @brief Andrew's Monotone Chain\n\
    \ */\nvector<point> convex_hull(vector<point> ps) {\n    int n = ps.size();\n\
    \    sort(ALL(ps), [&](point a, point b) { return make_pair(a.real(), a.imag())\
    \ < make_pair(b.real(), b.imag()); });\n    vector<point> ch(2 * n);\n    int\
    \ k = 0;\n    for (int i = 0; i < n; ch[k ++] = ps[i ++]) // lower-hull\n    \
    \    while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;\n    for (int\
    \ i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) // upper-hull\n        while\
    \ (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;\n    ch.resize(k -\
    \ 1);\n    return ch;\n}\n\nstruct circle { point p; double r; };\nstruct line\
    \ { point s, t; };\nstruct segment { point s, t; };\nstruct ray { point s, t;\
    \ };\n\n/**\n * @note \u3042\u307E\u308A\u5C0F\u3055\u304F\u3059\u308B\u3068\u8AA4\
    \u5DEE\u3067\u6B7B\u306C\n */\nconst double eps = 1e-6;\ndouble sq(double x) {\
    \ return pow(x, 2); }\n\nstruct point { double y, x; };\npoint operator + (point\
    \ a, point b) { return (point) { a.y + b.y, a.x + b.x }; }\npoint operator - (point\
    \ a, point b) { return (point) { a.y - b.y, a.x - b.x }; }\npoint operator * (point\
    \ a, double b) { return (point) { a.y * b, a.x * b }; }\npoint operator / (point\
    \ a, double b) { return (point) { a.y / b, a.x / b }; }\npoint operator < (point\
    \ a, point b) { return make_pair(a.y, a.x) < make_pair(b.y, b.x); }\ndouble distance(point\
    \ a, point b) { return sqrt(sq(a.y - b.y) + sq(a.x - b.x)); }\ndouble   dot(point\
    \ a, point b) { return a.x * b.x + a.y * b.y; }\ndouble cross(point a, point b)\
    \ { return a.x * b.y - a.y * b.x; }\nint ccw(point a, point b, point c) { double\
    \ z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }\n\n\n\n\n\
    /**\n * @brief segment - segment, inclusive\n */\nbool does_intersect(segment\
    \ const & a, segment const & b){\n    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t,\
    \ b.t) <= 0 and\n           ccw(b.s, b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\n}\n\
    \n/**\n * @brief point and line\n */\nbool does_intersect(point a, line b) { return\
    \ ccw(0, a - b.s, b.t - b.s) == 0; }\nbool does_intersect(line a, point b) { return\
    \ does_intersect(b, a); }\n\n/**\n * @brief line and line\n */\nbool is_parallel(line\
    \ a, line b) { return ccw(0, a.t - a.s, b.t - b.s) == 0; }\nbool is_same(line\
    \ a, line b) { return does_intersect(a.s, b) and does_intersect(a.t, b); }\n/**\n\
    \ * @note false if two lines are the same\n */\nbool does_intersect(line a, line\
    \ b) {\n    return not is_parallel(a, b)\n        and not is_same(a, b);\n}\n\
    point intersection(line a, line b) {\n    assert (does_intersect(a, b));\n   \
    \ double p = cross(a.t - a.s, b.t - b.s);\n    double q = cross(a.t - a.s, a.t\
    \ - b.s);\n    return (q / p) * (b.t - b.s) + b.s;\n}\n\n\n/**\n * @note helper\
    \ for segments and rays\n */\ntemplate <typename T, typename U>\nbool does_intersect_linelikes(T\
    \ const & a, U const & b) {\n    if (not does_intersect(to_line(a), to_line(b)))\
    \ return false;\n    point c = intersection(to_line(a), to_line(b));\n    return\
    \ does_intersect(c, a)\n        and does_intersect(c, b);\n}\n\n\nline to_line(segment\
    \ a) {\n    return { a.s, a.t };\n}\nbool does_intersect(point a, segment b) {\n\
    \    return abs(cross(b.t - b.s, a - b.s)) < eps\n        and dot(b.t - b.s, a\
    \ - b.s) > - eps\n        and dot(b.s - b.t, a - b.t) > - eps;\n}\nbool does_intersect(segment\
    \ a, point b) {\n    return does_intersect(b, a);\n}\nbool is_overwraped(segment\
    \ a, segment b) {\n    return does_intersect(a.s, b)\n        and does_intersect(a.t,\
    \ b);\n}\nbool does_intersect(segment a, segment b) {\n    return does_intersect_linelikes(a,\
    \ b);\n}\npoint intersection(segment a, segment b) {\n    assert (does_intersect(a,\
    \ b));\n    return intersection(to_line(a), to_line(b));\n}\n\n\nline to_line(ray\
    \ a) {\n    return { a.s, a.t };\n}\nbool does_intersect(point a, ray b) {\n \
    \   return abs(cross(b.t - b.s, a - b.s)) < eps\n        and dot(b.t - b.s, a\
    \ - b.s) > - eps;\n}\nbool does_intersect(ray a, point b) {\n    return does_intersect(b,\
    \ a);\n}\nbool is_overwraped(ray a, ray b) {\n    return (does_intersect(a.s,\
    \ b) and does_intersect(a.t, b))\n        or (does_intersect(b.s, a) and does_intersect(b.t,\
    \ a));\n}\nbool does_intersect(ray a, ray b) {\n    return does_intersect_linelikes(a,\
    \ b);\n}\npoint intersection(ray a, ray b) {\n    assert (does_intersect(a, b));\n\
    \    return intersection(to_line(a), to_line(b));\n}\n\n\n\n\n\n\nstruct polygon\
    \ { vector<point> ps; };\nsegment nth_segment(polygon const & a, int i) {\n  \
    \  int j = (i+1) % a.ps.size();\n    return { a.ps[i], a.ps[j] };\n}\nbool does_intersect(ray\
    \ a, segment b) { return does_intersect_linelikes(a, b); }\nbool does_intersect(segment\
    \ a, ray b) { return does_intersect_linelikes(a, b); }\npoint intersection(ray\
    \ a, segment b) { return intersection_linelikes(a, b); }\npoint intersection(segment\
    \ a, ray b) { return intersection_linelikes(a, b); }\ntemplate <typename T>\n\
    vector<point> intersections_polygon_linelike(polygon const & a, T const & b) {\n\
    \    vector<point> result;\n    repeat (i, a.ps.size()) {\n        if (does_intersect(nth_segment(a,\
    \ i), b)) {\n            result.push_back(intersection(nth_segment(a, i), b));\n\
    \        }\n    }\n    return result;\n}\nbool does_intersect(polygon const &\
    \ a, ray const & b) {\n    return not intersections_polygon_linelike(a, b).empty();\n\
    }\nbool does_intersect(polygon const & a, point const & b) {\n    ray c = { b,\
    \ b + point(1, 0) };\n    return intersections_polygon_linelike(a, c).size() %\
    \ 2 == 1;\n}\nbool does_intersect_strict(polygon const & a, point const & b) {\n\
    \    repeat (i, a.ps.size()) {\n        if (does_intersect(nth_segment(a, i),\
    \ b)) {\n            return false; // when the point is on a segment of the polygon\n\
    \        }\n    }\n    return does_intersect(a, b);\n}\nbool does_intersect_strict(polygon\
    \ const & a, segment const & b) { // the boundary is not included\n    vector<point>\
    \ ps = intersections_polygon_linelike(a, b);\n    for (point p : ps) {\n     \
    \   bool ignored = false;\n        if (abs(p - b.s) < eps or abs(p - b.t) < eps)\
    \ {\n            ignored = true;\n        }\n        if (not ignored) {\n    \
    \        for (point q : a.ps) {\n                if (abs(p - q) < eps) {\n   \
    \                 ignored = true; // when the intersection point is one of the\
    \ vertex of the polygon\n                    break;\n                }\n     \
    \       }\n        }\n        if (not ignored) return true;\n    }\n    return\
    \ false;\n}\n"
  code: "typedef complex<double> point;\ndouble cross(point a, point b) { return a.real()\
    \ * b.imag() - a.imag() * b.real(); }\nint ccw(point a, point b, point c) { double\
    \ z = cross(b - a, c - a); return z > eps ? 1 : z < - eps ? -1 : 0; }\n\n/**\n\
    \ * @brief Andrew's Monotone Chain\n */\nvector<point> convex_hull(vector<point>\
    \ ps) {\n    int n = ps.size();\n    sort(ALL(ps), [&](point a, point b) { return\
    \ make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });\n    vector<point>\
    \ ch(2 * n);\n    int k = 0;\n    for (int i = 0; i < n; ch[k ++] = ps[i ++])\
    \ // lower-hull\n        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <=\
    \ 0) -- k;\n    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) //\
    \ upper-hull\n        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)\
    \ -- k;\n    ch.resize(k - 1);\n    return ch;\n}\n\nstruct circle { point p;\
    \ double r; };\nstruct line { point s, t; };\nstruct segment { point s, t; };\n\
    struct ray { point s, t; };\n\n/**\n * @note \u3042\u307E\u308A\u5C0F\u3055\u304F\
    \u3059\u308B\u3068\u8AA4\u5DEE\u3067\u6B7B\u306C\n */\nconst double eps = 1e-6;\n\
    double sq(double x) { return pow(x, 2); }\n\nstruct point { double y, x; };\n\
    point operator + (point a, point b) { return (point) { a.y + b.y, a.x + b.x };\
    \ }\npoint operator - (point a, point b) { return (point) { a.y - b.y, a.x - b.x\
    \ }; }\npoint operator * (point a, double b) { return (point) { a.y * b, a.x *\
    \ b }; }\npoint operator / (point a, double b) { return (point) { a.y / b, a.x\
    \ / b }; }\npoint operator < (point a, point b) { return make_pair(a.y, a.x) <\
    \ make_pair(b.y, b.x); }\ndouble distance(point a, point b) { return sqrt(sq(a.y\
    \ - b.y) + sq(a.x - b.x)); }\ndouble   dot(point a, point b) { return a.x * b.x\
    \ + a.y * b.y; }\ndouble cross(point a, point b) { return a.x * b.y - a.y * b.x;\
    \ }\nint ccw(point a, point b, point c) { double z = cross(b - a, c - a); return\
    \ z > eps ? 1 : z < - eps ? -1 : 0; }\n\n\n\n\n/**\n * @brief segment - segment,\
    \ inclusive\n */\nbool does_intersect(segment const & a, segment const & b){\n\
    \    return ccw(a.s, a.t, b.s) * ccw(a.s, a.t, b.t) <= 0 and\n           ccw(b.s,\
    \ b.t, a.s) * ccw(b.s, b.t, a.t) <= 0;\n}\n\n/**\n * @brief point and line\n */\n\
    bool does_intersect(point a, line b) { return ccw(0, a - b.s, b.t - b.s) == 0;\
    \ }\nbool does_intersect(line a, point b) { return does_intersect(b, a); }\n\n\
    /**\n * @brief line and line\n */\nbool is_parallel(line a, line b) { return ccw(0,\
    \ a.t - a.s, b.t - b.s) == 0; }\nbool is_same(line a, line b) { return does_intersect(a.s,\
    \ b) and does_intersect(a.t, b); }\n/**\n * @note false if two lines are the same\n\
    \ */\nbool does_intersect(line a, line b) {\n    return not is_parallel(a, b)\n\
    \        and not is_same(a, b);\n}\npoint intersection(line a, line b) {\n   \
    \ assert (does_intersect(a, b));\n    double p = cross(a.t - a.s, b.t - b.s);\n\
    \    double q = cross(a.t - a.s, a.t - b.s);\n    return (q / p) * (b.t - b.s)\
    \ + b.s;\n}\n\n\n/**\n * @note helper for segments and rays\n */\ntemplate <typename\
    \ T, typename U>\nbool does_intersect_linelikes(T const & a, U const & b) {\n\
    \    if (not does_intersect(to_line(a), to_line(b))) return false;\n    point\
    \ c = intersection(to_line(a), to_line(b));\n    return does_intersect(c, a)\n\
    \        and does_intersect(c, b);\n}\n\n\nline to_line(segment a) {\n    return\
    \ { a.s, a.t };\n}\nbool does_intersect(point a, segment b) {\n    return abs(cross(b.t\
    \ - b.s, a - b.s)) < eps\n        and dot(b.t - b.s, a - b.s) > - eps\n      \
    \  and dot(b.s - b.t, a - b.t) > - eps;\n}\nbool does_intersect(segment a, point\
    \ b) {\n    return does_intersect(b, a);\n}\nbool is_overwraped(segment a, segment\
    \ b) {\n    return does_intersect(a.s, b)\n        and does_intersect(a.t, b);\n\
    }\nbool does_intersect(segment a, segment b) {\n    return does_intersect_linelikes(a,\
    \ b);\n}\npoint intersection(segment a, segment b) {\n    assert (does_intersect(a,\
    \ b));\n    return intersection(to_line(a), to_line(b));\n}\n\n\nline to_line(ray\
    \ a) {\n    return { a.s, a.t };\n}\nbool does_intersect(point a, ray b) {\n \
    \   return abs(cross(b.t - b.s, a - b.s)) < eps\n        and dot(b.t - b.s, a\
    \ - b.s) > - eps;\n}\nbool does_intersect(ray a, point b) {\n    return does_intersect(b,\
    \ a);\n}\nbool is_overwraped(ray a, ray b) {\n    return (does_intersect(a.s,\
    \ b) and does_intersect(a.t, b))\n        or (does_intersect(b.s, a) and does_intersect(b.t,\
    \ a));\n}\nbool does_intersect(ray a, ray b) {\n    return does_intersect_linelikes(a,\
    \ b);\n}\npoint intersection(ray a, ray b) {\n    assert (does_intersect(a, b));\n\
    \    return intersection(to_line(a), to_line(b));\n}\n\n\n\n\n\n\nstruct polygon\
    \ { vector<point> ps; };\nsegment nth_segment(polygon const & a, int i) {\n  \
    \  int j = (i+1) % a.ps.size();\n    return { a.ps[i], a.ps[j] };\n}\nbool does_intersect(ray\
    \ a, segment b) { return does_intersect_linelikes(a, b); }\nbool does_intersect(segment\
    \ a, ray b) { return does_intersect_linelikes(a, b); }\npoint intersection(ray\
    \ a, segment b) { return intersection_linelikes(a, b); }\npoint intersection(segment\
    \ a, ray b) { return intersection_linelikes(a, b); }\ntemplate <typename T>\n\
    vector<point> intersections_polygon_linelike(polygon const & a, T const & b) {\n\
    \    vector<point> result;\n    repeat (i, a.ps.size()) {\n        if (does_intersect(nth_segment(a,\
    \ i), b)) {\n            result.push_back(intersection(nth_segment(a, i), b));\n\
    \        }\n    }\n    return result;\n}\nbool does_intersect(polygon const &\
    \ a, ray const & b) {\n    return not intersections_polygon_linelike(a, b).empty();\n\
    }\nbool does_intersect(polygon const & a, point const & b) {\n    ray c = { b,\
    \ b + point(1, 0) };\n    return intersections_polygon_linelike(a, c).size() %\
    \ 2 == 1;\n}\nbool does_intersect_strict(polygon const & a, point const & b) {\n\
    \    repeat (i, a.ps.size()) {\n        if (does_intersect(nth_segment(a, i),\
    \ b)) {\n            return false; // when the point is on a segment of the polygon\n\
    \        }\n    }\n    return does_intersect(a, b);\n}\nbool does_intersect_strict(polygon\
    \ const & a, segment const & b) { // the boundary is not included\n    vector<point>\
    \ ps = intersections_polygon_linelike(a, b);\n    for (point p : ps) {\n     \
    \   bool ignored = false;\n        if (abs(p - b.s) < eps or abs(p - b.t) < eps)\
    \ {\n            ignored = true;\n        }\n        if (not ignored) {\n    \
    \        for (point q : a.ps) {\n                if (abs(p - q) < eps) {\n   \
    \                 ignored = true; // when the intersection point is one of the\
    \ vertex of the polygon\n                    break;\n                }\n     \
    \       }\n        }\n        if (not ignored) return true;\n    }\n    return\
    \ false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/a.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/a.inc.cpp
layout: document
redirect_from:
- /library/old/a.inc.cpp
- /library/old/a.inc.cpp.html
title: Andrew's Monotone Chain
---
