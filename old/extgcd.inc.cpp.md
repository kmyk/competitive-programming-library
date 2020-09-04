---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: extended gcd
  bundledCode: "#line 1 \"old/extgcd.inc.cpp\"\n/**\n * @brief extended gcd\n * @description\
    \ for given a and b, find x, y and gcd(a, b) such that ax + by = 1\n * @note O(log\
    \ n)\n * @see https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466\n\
    \ */\ntuple<ll, ll, ll> extgcd(ll a, ll b) {\n    ll x = 0, y = 1;\n    for (ll\
    \ u = 1, v = 0; a; ) {\n        ll q = b / a;\n        x -= q * u; swap(x, u);\n\
    \        y -= q * v; swap(y, v);\n        b -= q * a; swap(b, a);\n    }\n   \
    \ return make_tuple(x, y, b);\n}\nunittest {\n    random_device device;\n    default_random_engine\
    \ gen(device());\n    REP (iteration, 1000) {\n        ll a = uniform_int_distribution<ll>(1,\
    \ 10000)(gen);\n        ll b = uniform_int_distribution<ll>(1, 10000)(gen);\n\
    \        ll x, y, d; tie(x, y, d) = extgcd(a, b);\n        assert (a * x + b *\
    \ y == d);\n        assert (d == __gcd(a, b));\n    }\n}\n\n/**\n * @note recursive\
    \ version (slow)\n */\npair<int, int> extgcd_recursive(int a, int b) {\n    if\
    \ (b == 0) return { 1, 0 };\n    int na, nb; tie(na, nb) = extgcd(b, a % b);\n\
    \    return { nb, na - a/b * nb };\n}\n\n/**\n * @note x and m must be relatively\
    \ prime\n * @note O(log m)\n */\nll modinv(ll x, int m) {\n    assert (1 <= x\
    \ and x < m);\n    ll y, d; tie(y, ignore, d) = extgcd(x, m);\n    if (d != 1)\
    \ return 0;  // no inverse\n    assert (x * y % m == 1);\n    return (y % m +\
    \ m) % m;\n}\n\n/**\n * @brief chinese remainder theorem\n * @note the unit element\
    \ is (0, 1)\n */\npair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {\n \
    \   ll x1, m1; tie(x1, m1) = eqn1;\n    ll x2, m2; tie(x2, m2) = eqn2;\n    ll\
    \ x = x1 + m1 * (x2 - x1) * modinv(m1 % m2, m2);\n    ll m = m1 * m2;\n    return\
    \ { (x % m + m) % m, m };\n}\n\nll multmod(ll a, ll b, ll m) {\n    a = (a % m\
    \ + m) % m;\n    b = (b % m + m) % m;\n    ll c = 0;\n    REP (i, 63) {\n    \
    \    if (b & (1ll << i)) {\n            c += a;\n            if (c > m) c -= m;\n\
    \        }\n        a *= 2;\n        if (a > m) a -= m;\n    }\n    return c;\n\
    }\n\npair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {\n    ll x1, m1;\
    \ tie(x1, m1) = eqn1;\n    ll x2, m2; tie(x2, m2) = eqn2;\n    if (m1 == 0 or\
    \ m2 == 0) return make_pair(0ll, 0ll);\n    assert (1 <= m1 and 1 <= m2);\n  \
    \  ll m1_inv, d; tie(m1_inv, ignore, d) = extgcd(m1, m2);\n    if ((x1 - x2) %\
    \ d) return make_pair(0ll, 0ll);\n    ll m = m1 * m2 / d;\n    // ll x = x1 +\
    \ (m1 / d) * (x2 - x1) % m * (m1_inv % m) % m;\n    ll x = x1 + multmod(multmod(m1\
    \ / d, x2 - x1, m), m1_inv, m);\n    return make_pair((x % m + m) % m, m);\n}\n\
    \n"
  code: "/**\n * @brief extended gcd\n * @description for given a and b, find x, y\
    \ and gcd(a, b) such that ax + by = 1\n * @note O(log n)\n * @see https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466\n\
    \ */\ntuple<ll, ll, ll> extgcd(ll a, ll b) {\n    ll x = 0, y = 1;\n    for (ll\
    \ u = 1, v = 0; a; ) {\n        ll q = b / a;\n        x -= q * u; swap(x, u);\n\
    \        y -= q * v; swap(y, v);\n        b -= q * a; swap(b, a);\n    }\n   \
    \ return make_tuple(x, y, b);\n}\nunittest {\n    random_device device;\n    default_random_engine\
    \ gen(device());\n    REP (iteration, 1000) {\n        ll a = uniform_int_distribution<ll>(1,\
    \ 10000)(gen);\n        ll b = uniform_int_distribution<ll>(1, 10000)(gen);\n\
    \        ll x, y, d; tie(x, y, d) = extgcd(a, b);\n        assert (a * x + b *\
    \ y == d);\n        assert (d == __gcd(a, b));\n    }\n}\n\n/**\n * @note recursive\
    \ version (slow)\n */\npair<int, int> extgcd_recursive(int a, int b) {\n    if\
    \ (b == 0) return { 1, 0 };\n    int na, nb; tie(na, nb) = extgcd(b, a % b);\n\
    \    return { nb, na - a/b * nb };\n}\n\n/**\n * @note x and m must be relatively\
    \ prime\n * @note O(log m)\n */\nll modinv(ll x, int m) {\n    assert (1 <= x\
    \ and x < m);\n    ll y, d; tie(y, ignore, d) = extgcd(x, m);\n    if (d != 1)\
    \ return 0;  // no inverse\n    assert (x * y % m == 1);\n    return (y % m +\
    \ m) % m;\n}\n\n/**\n * @brief chinese remainder theorem\n * @note the unit element\
    \ is (0, 1)\n */\npair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {\n \
    \   ll x1, m1; tie(x1, m1) = eqn1;\n    ll x2, m2; tie(x2, m2) = eqn2;\n    ll\
    \ x = x1 + m1 * (x2 - x1) * modinv(m1 % m2, m2);\n    ll m = m1 * m2;\n    return\
    \ { (x % m + m) % m, m };\n}\n\nll multmod(ll a, ll b, ll m) {\n    a = (a % m\
    \ + m) % m;\n    b = (b % m + m) % m;\n    ll c = 0;\n    REP (i, 63) {\n    \
    \    if (b & (1ll << i)) {\n            c += a;\n            if (c > m) c -= m;\n\
    \        }\n        a *= 2;\n        if (a > m) a -= m;\n    }\n    return c;\n\
    }\n\npair<ll, ll> crt(pair<ll, ll> eqn1, pair<ll, ll> eqn2) {\n    ll x1, m1;\
    \ tie(x1, m1) = eqn1;\n    ll x2, m2; tie(x2, m2) = eqn2;\n    if (m1 == 0 or\
    \ m2 == 0) return make_pair(0ll, 0ll);\n    assert (1 <= m1 and 1 <= m2);\n  \
    \  ll m1_inv, d; tie(m1_inv, ignore, d) = extgcd(m1, m2);\n    if ((x1 - x2) %\
    \ d) return make_pair(0ll, 0ll);\n    ll m = m1 * m2 / d;\n    // ll x = x1 +\
    \ (m1 / d) * (x2 - x1) % m * (m1_inv % m) % m;\n    ll x = x1 + multmod(multmod(m1\
    \ / d, x2 - x1, m), m1_inv, m);\n    return make_pair((x % m + m) % m, m);\n}\n\
    \n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/extgcd.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/extgcd.inc.cpp
layout: document
redirect_from:
- /library/old/extgcd.inc.cpp
- /library/old/extgcd.inc.cpp.html
title: extended gcd
---
