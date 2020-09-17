---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoids/product.hpp\"\n#include <utility>\n\ntemplate <class\
    \ Monoid1, class Monoid2>\nstruct product_monoid {\n    typedef std::pair<typename\
    \ Monoid1::value_type, typename Monoid2::value_type> value_type;\n    Monoid1\
    \ mon1;\n    Monoid2 mon2;\n    value_type unit() const {\n        return std::make_pair(mon1.unit(),\
    \ mon2.unit());\n    }\n    value_type mult(value_type a, value_type b) const\
    \ {\n        return std::make_pair(mon1.mult(a.first, b.first), mon2.mult(a.second,\
    \ b.second));\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class Monoid1, class Monoid2>\n\
    struct product_monoid {\n    typedef std::pair<typename Monoid1::value_type, typename\
    \ Monoid2::value_type> value_type;\n    Monoid1 mon1;\n    Monoid2 mon2;\n   \
    \ value_type unit() const {\n        return std::make_pair(mon1.unit(), mon2.unit());\n\
    \    }\n    value_type mult(value_type a, value_type b) const {\n        return\
    \ std::make_pair(mon1.mult(a.first, b.first), mon2.mult(a.second, b.second));\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: monoids/product.hpp
  requiredBy: []
  timestamp: '2020-02-26 11:29:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/product.hpp
layout: document
redirect_from:
- /library/monoids/product.hpp
- /library/monoids/product.hpp.html
title: monoids/product.hpp
---
