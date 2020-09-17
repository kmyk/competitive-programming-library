---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoids/trivial.hpp
    title: monoids/trivial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoids/trivial.hpp\"\n\nstruct trivial_monoid {\n    typedef\
    \ struct {} value_type;\n    value_type unit() const { return (value_type) {};\
    \ }\n    value_type mult(value_type a, value_type b) const { return (value_type)\
    \ {}; }\n};\n#line 3 \"monoids/trivial_action.hpp\"\n\n/**\n * @note lazy_propagation_segment_tree<Monoid,\
    \ trivial_monoid, trivial_action<typename Monoid::value_type> > is the same to\
    \ segment_tree<Monoid>\n */\ntemplate <class T>\nstruct trivial_action {\n   \
    \ T operator () (typename trivial_monoid::value_type f, T x) const { return x;\
    \ }\n};\n"
  code: "#pragma once\n#include \"monoids/trivial.hpp\"\n\n/**\n * @note lazy_propagation_segment_tree<Monoid,\
    \ trivial_monoid, trivial_action<typename Monoid::value_type> > is the same to\
    \ segment_tree<Monoid>\n */\ntemplate <class T>\nstruct trivial_action {\n   \
    \ T operator () (typename trivial_monoid::value_type f, T x) const { return x;\
    \ }\n};\n"
  dependsOn:
  - monoids/trivial.hpp
  isVerificationFile: false
  path: monoids/trivial_action.hpp
  requiredBy: []
  timestamp: '2020-01-27 07:18:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/trivial_action.hpp
layout: document
redirect_from:
- /library/monoids/trivial_action.hpp
- /library/monoids/trivial_action.hpp.html
title: monoids/trivial_action.hpp
---
