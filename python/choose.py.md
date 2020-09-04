---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import array\ndef get_fact(n, mod):\n    fact = array.array('l')\n    fact.append(1)\n\
    \    for i in range(n):\n        fact.append((i + 1) * fact[-1] % mod)\n    return\
    \ fact\ndef choose(n, r, mod, fact=None):\n    return fact[n] * pow(fact[n - r]\
    \ * fact[r], mod - 2, mod) % mod\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python/choose.py
  requiredBy: []
  timestamp: '2017-10-28 21:00:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python/choose.py
layout: document
redirect_from:
- /library/python/choose.py
- /library/python/choose.py.html
title: python/choose.py
---
