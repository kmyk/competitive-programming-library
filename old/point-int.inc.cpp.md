---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "old/point-int.inc.cpp"

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

    int ccw(point_t a, point_t b, point_t c) { ll z = cross(b - a, c - a); return
    z > 0 ? 1 : z < 0 ? -1 : 0; }

    std::istream & operator >> (std::istream & in, point_t & a) { return in >> a.x
    >> a.y; }

    std::ostream & operator << (std::ostream & out, point_t a) { return out << a.x
    << '' '' << a.y; }


    function<bool (point_t)> make_is_on_field(point_t p) { return [=](point_t q) {
    return 0 <= q.y and q.y < p.y and 0 <= q.x and q.x < p.x; }; }

    const point_t directions[4] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

    '
  code: 'struct point_t { ll y, x; };

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

    int ccw(point_t a, point_t b, point_t c) { ll z = cross(b - a, c - a); return
    z > 0 ? 1 : z < 0 ? -1 : 0; }

    std::istream & operator >> (std::istream & in, point_t & a) { return in >> a.x
    >> a.y; }

    std::ostream & operator << (std::ostream & out, point_t a) { return out << a.x
    << '' '' << a.y; }


    function<bool (point_t)> make_is_on_field(point_t p) { return [=](point_t q) {
    return 0 <= q.y and q.y < p.y and 0 <= q.x and q.x < p.x; }; }

    const point_t directions[4] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

    '
  dependsOn: []
  isVerificationFile: false
  path: old/point-int.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/point-int.inc.cpp
layout: document
redirect_from:
- /library/old/point-int.inc.cpp
- /library/old/point-int.inc.cpp.html
title: old/point-int.inc.cpp
---
