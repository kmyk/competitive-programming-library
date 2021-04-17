---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://kimiyuki.net/blog/2016/06/08/yuki-356/
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from fractions import Fraction\nimport math\ndef lcm(a, b):\n    return a\
    \ * b // math.gcd(a, b)\n\n# https://kimiyuki.net/blog/2016/06/08/yuki-356/\n\
    def qlcm(p, q):\n    a = p.numerator * q.denominator\n    b = p.denominator *\
    \ q.numerator\n    c = p.denominator * q.denominator\n    return Fraction(lcm(a,\
    \ b), c)\ndef qgcd(p, q):\n    return p * q / qlcm(p, q)\n"
  dependsOn: []
  isVerificationFile: false
  path: python/rational-gcd.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python/rational-gcd.py
layout: document
redirect_from:
- /library/python/rational-gcd.py
- /library/python/rational-gcd.py.html
title: python/rational-gcd.py
---
