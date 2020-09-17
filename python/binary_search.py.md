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
  code: "#!/usr/bin/env python3\ndef binsearch(l, r, pred): # [l, r)\n    assert l\
    \ < r\n    l -= 1\n    while r - l > 1:\n        m = (l + r) // 2\n        if\
    \ pred(m):\n            r = m\n        else:\n            l = m\n    return r\n\
    \ndef binsearch_float(l, r, pred): # [l, r)\n    assert l < r\n    for _ in range(100):\n\
    \        m = (l + r) / 2\n        if pred(m):\n            r = m\n        else:\n\
    \            l = m\n    return r\n"
  dependsOn: []
  isVerificationFile: false
  path: python/binary_search.py
  requiredBy: []
  timestamp: '2018-07-06 01:52:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python/binary_search.py
layout: document
redirect_from:
- /library/python/binary_search.py
- /library/python/binary_search.py.html
title: python/binary_search.py
---
