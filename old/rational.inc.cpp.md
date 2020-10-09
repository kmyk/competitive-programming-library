---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "old/rational.inc.cpp"

    struct rational { int num, den; };

    rational make_rational(ll num, ll den = 1) { ll k = gcd(num, den); return (rational)
    { int(num / k), int(den / k) }; }

    rational operator + (rational a, rational b) { return make_rational(a.num *(ll)
    b.den + b.num *(ll) a.den, a.den *(ll) b.den); }

    rational operator - (rational a, rational b) { return make_rational(a.num *(ll)
    b.den - b.num *(ll) a.den, a.den *(ll) b.den); }

    rational operator * (rational a, rational b) { return make_rational(a.num *(ll)
    b.num, a.den *(ll) b.den); }

    rational operator / (rational a, rational b) { return make_rational(a.num *(ll)
    b.den, a.den *(ll) b.num); }

    bool operator < (rational a, rational b) { return a.num *(ll) b.den < b.num *(ll)
    a.den; }

    bool operator > (rational a, rational b) { return a.num *(ll) b.den > b.num *(ll)
    a.den; }

    bool operator == (rational a, rational b) { return a.num == b.num and a.den ==
    b.den; }

    bool operator != (rational a, rational b) { return a.num != b.num  or a.den !=
    b.den; }

    ostream & operator << (ostream & out, rational a) { if (a.den == 0) return out
    << "invalid"; return out << a.num << ''/'' << a.den; }

    '
  code: 'struct rational { int num, den; };

    rational make_rational(ll num, ll den = 1) { ll k = gcd(num, den); return (rational)
    { int(num / k), int(den / k) }; }

    rational operator + (rational a, rational b) { return make_rational(a.num *(ll)
    b.den + b.num *(ll) a.den, a.den *(ll) b.den); }

    rational operator - (rational a, rational b) { return make_rational(a.num *(ll)
    b.den - b.num *(ll) a.den, a.den *(ll) b.den); }

    rational operator * (rational a, rational b) { return make_rational(a.num *(ll)
    b.num, a.den *(ll) b.den); }

    rational operator / (rational a, rational b) { return make_rational(a.num *(ll)
    b.den, a.den *(ll) b.num); }

    bool operator < (rational a, rational b) { return a.num *(ll) b.den < b.num *(ll)
    a.den; }

    bool operator > (rational a, rational b) { return a.num *(ll) b.den > b.num *(ll)
    a.den; }

    bool operator == (rational a, rational b) { return a.num == b.num and a.den ==
    b.den; }

    bool operator != (rational a, rational b) { return a.num != b.num  or a.den !=
    b.den; }

    ostream & operator << (ostream & out, rational a) { if (a.den == 0) return out
    << "invalid"; return out << a.num << ''/'' << a.den; }

    '
  dependsOn: []
  isVerificationFile: false
  path: old/rational.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/rational.inc.cpp
layout: document
redirect_from:
- /library/old/rational.inc.cpp
- /library/old/rational.inc.cpp.html
title: old/rational.inc.cpp
---
