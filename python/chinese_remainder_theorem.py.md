---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\nimport gmpy2\n\ndef chinese_remainder_theorem(eqn):\n\
    \    '''\n        eqn = [ (y_0, n_0), ... ] where\n            x = y_i mod n_i\n\
    \    '''\n    x = 0\n    m = 1\n    for y, n in eqn:\n        d = gmpy2.gcd(m,\
    \ n)\n        x += (m // d) * (y - x) * gmpy2.invert(m // d, n // d)\n       \
    \ m = gmpy2.lcm(m, n)\n    return x % m\n\ndef crt(eqn1, eqn2):\n    x1, m1 =\
    \ eqn1\n    x2, m2 = eqn2\n    d = int(gmpy2.gcd(m1, m2))\n    x = x1 + (m1 //\
    \ d) * (x2 - x1) * int(gmpy2.invert(m1 // d, m2 // d))\n    m = int(gmpy2.lcm(m1,\
    \ m2))\n    return x % m, m\n"
  dependsOn: []
  isVerificationFile: false
  path: python/chinese_remainder_theorem.py
  requiredBy: []
  timestamp: '2018-07-06 01:52:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python/chinese_remainder_theorem.py
layout: document
redirect_from:
- /library/python/chinese_remainder_theorem.py
- /library/python/chinese_remainder_theorem.py.html
title: python/chinese_remainder_theorem.py
---
