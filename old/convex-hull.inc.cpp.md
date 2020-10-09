---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://www.prefield.com/algorithm/geometry/convex_hull.html
  bundledCode: "#line 1 \"old/convex-hull.inc.cpp\"\ndouble dot(complex<double> a,\
    \ complex<double> b) { return real(a * conj(b)); }\ndouble cross(complex<double>\
    \ a, complex<double> b) { return imag(conj(a) * b); }\nint ccw(complex<double>\
    \ a, complex<double> b, complex<double> c) {\n    b -= a;\n    c -= a;\n    if\
    \ (cross(b, c) > 0) return +1;  // counter clockwise\n    if (cross(b, c) < 0)\
    \ return -1;  // clockwise\n    if (dot(b, c) < 0)   return +2;  // c--a--b on\
    \ line\n    if (abs(b) < abs(c)) return -2;  // a--b--c on line\n    return 0;\n\
    }\n/**\n * @see http://www.prefield.com/algorithm/geometry/convex_hull.html\n\
    \ */\nvector<complex<double> > convex_hull(vector<complex<double> > ps) {\n  \
    \  int n = ps.size();\n    if (n <= 2) return ps;\n    int k = 0;\n    sort(ps.begin(),\
    \ ps.end(), [&](complex<double> const a, complex<double> const b) { return make_pair(a.real(),\
    \ a.imag()) < make_pair(b.real(), b.imag()); });\n    vector<complex<double> >\
    \ ch(2 * n);\n    for (int i = 0; i < n; ch[k ++] = ps[i ++]) {  // lower-hull\n\
    \        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;\n    }\n\
    \    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) {  // upper-hull\n\
    \        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;\n    }\n\
    \    ch.resize(k - 1);\n    return ch;\n}\n"
  code: "double dot(complex<double> a, complex<double> b) { return real(a * conj(b));\
    \ }\ndouble cross(complex<double> a, complex<double> b) { return imag(conj(a)\
    \ * b); }\nint ccw(complex<double> a, complex<double> b, complex<double> c) {\n\
    \    b -= a;\n    c -= a;\n    if (cross(b, c) > 0) return +1;  // counter clockwise\n\
    \    if (cross(b, c) < 0) return -1;  // clockwise\n    if (dot(b, c) < 0)   return\
    \ +2;  // c--a--b on line\n    if (abs(b) < abs(c)) return -2;  // a--b--c on\
    \ line\n    return 0;\n}\n/**\n * @see http://www.prefield.com/algorithm/geometry/convex_hull.html\n\
    \ */\nvector<complex<double> > convex_hull(vector<complex<double> > ps) {\n  \
    \  int n = ps.size();\n    if (n <= 2) return ps;\n    int k = 0;\n    sort(ps.begin(),\
    \ ps.end(), [&](complex<double> const a, complex<double> const b) { return make_pair(a.real(),\
    \ a.imag()) < make_pair(b.real(), b.imag()); });\n    vector<complex<double> >\
    \ ch(2 * n);\n    for (int i = 0; i < n; ch[k ++] = ps[i ++]) {  // lower-hull\n\
    \        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;\n    }\n\
    \    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) {  // upper-hull\n\
    \        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;\n    }\n\
    \    ch.resize(k - 1);\n    return ch;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/convex-hull.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/convex-hull.inc.cpp
layout: document
redirect_from:
- /library/old/convex-hull.inc.cpp
- /library/old/convex-hull.inc.cpp.html
title: old/convex-hull.inc.cpp
---
