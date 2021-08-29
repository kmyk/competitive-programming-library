---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: monoids/left.hpp
    title: monoids/left.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoids/left_action.hpp\"\n#include <utility>\n#line 3 \"\
    monoids/left.hpp\"\n\ntemplate <class T>\nstruct left_monoid {\n    // typedef\
    \ std::optional<T> value_type;\n    typedef std::pair<bool, T> value_type;\n \
    \   value_type unit() const { return std::make_pair(false, T()); }\n    value_type\
    \ mult(value_type a, value_type b) const { return a.first ? a : b; }\n};\n#line\
    \ 4 \"monoids/left_action.hpp\"\n\n/**\n * @note lazy_propagation_segment_tree<left_monoid<typename\
    \ Monoid::value_type>, Monoid, left_action<Monoid> > is the same to dual_segment_tree<Monoid>\n\
    \ */\ntemplate <class Monoid>\nstruct left_action {\n    typename left_monoid<typename\
    \ Monoid::value_type>::value_type operator () (typename Monoid::value_type f,\
    \ typename left_monoid<typename Monoid::value_type>::value_type x) const {\n \
    \       return x.first ? std::make_pair(true, Monoid().mult(f, x.second)) : x;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include \"../monoids/left.hpp\"\n\n/**\n\
    \ * @note lazy_propagation_segment_tree<left_monoid<typename Monoid::value_type>,\
    \ Monoid, left_action<Monoid> > is the same to dual_segment_tree<Monoid>\n */\n\
    template <class Monoid>\nstruct left_action {\n    typename left_monoid<typename\
    \ Monoid::value_type>::value_type operator () (typename Monoid::value_type f,\
    \ typename left_monoid<typename Monoid::value_type>::value_type x) const {\n \
    \       return x.first ? std::make_pair(true, Monoid().mult(f, x.second)) : x;\n\
    \    }\n};\n"
  dependsOn:
  - monoids/left.hpp
  isVerificationFile: false
  path: monoids/left_action.hpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoids/left_action.hpp
layout: document
redirect_from:
- /library/monoids/left_action.hpp
- /library/monoids/left_action.hpp.html
title: monoids/left_action.hpp
---
