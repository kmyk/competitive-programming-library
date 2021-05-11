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
  code: "def modinv(a_f, m):\n    f = np.copy(a_f)\n    assert isinstance(f, np.ndarray)\n\
    \    assert isinstance(m, int)\n    n = a_f.shape[0]\n    g = np.identity(n, dtype=int)\n\
    \    for i in range(n):\n        for j in range(i+1,n):\n            try:\n  \
    \              gmpy2.invert(int(f[j,i]), m)\n                f[i], f[j] = np.copy(f[j]),\
    \ np.copy(f[i])\n                g[i], g[j] = np.copy(g[j]), np.copy(g[i])\n \
    \               break\n            except:\n                pass\n        inv\
    \ = int(gmpy2.invert(int(f[i,i]), m))\n        f[i] = f[i] * inv % m\n       \
    \ g[i] = g[i] * inv % m\n        for j in range(n):\n            if j != i:\n\
    \                p = f[j,i]\n                f[j] = (f[j] - f[i] * p) % m\n  \
    \              g[j] = (g[j] - g[i] * p) % m\n    assert np.array_equal(f, np.identity(n,\
    \ dtype=int))\n    assert np.array_equal(a_f.dot(g) % m, np.identity(n, dtype=int))\n\
    \    assert isinstance(g, np.ndarray)\n    return g\n"
  dependsOn: []
  isVerificationFile: false
  path: python/matrix-modinv.py
  requiredBy: []
  timestamp: '2017-05-27 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python/matrix-modinv.py
layout: document
redirect_from:
- /library/python/matrix-modinv.py
- /library/python/matrix-modinv.py.html
title: python/matrix-modinv.py
---
