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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def extgcd(a, b):\n    if b == 0:\n        return 1, 0\n    else:\n     \
    \   na, nb = extgcd(b, a % b)\n        return nb, na - a//b * nb\ndef modinv(a,\
    \ n):\n    return extgcd(a, n)[0] % n\n"
  dependsOn: []
  isVerificationFile: false
  path: python/extgcd.py
  requiredBy: []
  timestamp: '2017-01-17 21:58:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python/extgcd.py
layout: document
redirect_from:
- /library/python/extgcd.py
- /library/python/extgcd.py.html
title: python/extgcd.py
---
