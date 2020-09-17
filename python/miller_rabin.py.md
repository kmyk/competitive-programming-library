---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\ndef is_prime(n, k=20): # miller-rabin primality\
    \ test\n    if n == 2:\n        return True\n    if n == 1 or n % 2 == 0:\n  \
    \      return False\n    d = n - 1\n    while d % 2 == 0:\n        d //= 2\n \
    \   for _ in range(k):\n        a = random.randint(1,n-2)\n        t = d\n   \
    \     y = pow(a,t,n)\n        while t != n-1 and y != 1 and y != n-1:\n      \
    \      y = (y * y) % n\n            t <<= 1\n        if y != n-1 and t & 1 ==\
    \ 0:\n            return False\n    return True\n"
  dependsOn: []
  isVerificationFile: false
  path: python/miller_rabin.py
  requiredBy: []
  timestamp: '2016-11-18 22:19:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python/miller_rabin.py
layout: document
redirect_from:
- /library/python/miller_rabin.py
- /library/python/miller_rabin.py.html
title: python/miller_rabin.py
---
