---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.hackerrank.com/contests/zalando-codesprint/challenges/give-me-the-order/submissions/code/6004391
  bundledCode: "#line 1 \"old/treap.inc.cpp\"\n#include <random>\n#include <memory>\n\
    \n// https://www.hackerrank.com/contests/zalando-codesprint/challenges/give-me-the-order/submissions/code/6004391\n\
    template <typename T>\nstruct treap {\n    typedef T value_type;\n    typedef\
    \ double key_type;\n    value_type v;\n    key_type k;\n    shared_ptr<treap>\
    \ l, r;\n    size_t m_size;\n    treap(value_type v)\n            : v(v)\n   \
    \         , k(generate())\n            , l()\n            , r()\n            ,\
    \ m_size(1) {\n    }\n    static size_t size(shared_ptr<treap> const & t) {\n\
    \        return t ? t->m_size : 0;\n    }\n    static shared_ptr<treap> merge(shared_ptr<treap>\
    \ const & a, shared_ptr<treap> const & b) { // destructive\n        if (not a)\
    \ return b;\n        if (not b) return a;\n        if (a->k > b->k) {\n      \
    \      a->r = merge(a->r, b);\n            return update(a);\n        } else {\n\
    \            b->l = merge(a, b->l);\n            return update(b);\n        }\n\
    \    }\n    static pair<shared_ptr<treap>, shared_ptr<treap> > split(shared_ptr<treap>\
    \ const & t, size_t i) { // [0, i) [i, n), destructive\n        if (not t) return\
    \ { shared_ptr<treap>(), shared_ptr<treap>() };\n        if (i <= size(t->l))\
    \ {\n            shared_ptr<treap> u; tie(u, t->l) = split(t->l, i);\n       \
    \     return { u, update(t) };\n        } else {\n            shared_ptr<treap>\
    \ u; tie(t->r, u) = split(t->r, i - size(t->l) - 1);\n            return { update(t),\
    \ u };\n        }\n    }\n    static shared_ptr<treap> insert(shared_ptr<treap>\
    \ const & t, size_t i, value_type v) { // destructive\n        shared_ptr<treap>\
    \ l, r; tie(l, r) = split(t, i);\n        shared_ptr<treap> u = make_shared<treap>(v);\n\
    \        return merge(merge(l, u), r);\n    }\n    static pair<shared_ptr<treap>,\
    \ shared_ptr<treap> > erase(shared_ptr<treap> const & t, size_t i) { // (t \\\
    \ t_i, t_i), destructive\n        shared_ptr<treap> l, u, r;\n        tie(l, r)\
    \ = split(t, i + 1);\n        tie(l, u) = split(l, i);\n        return { merge(l,\
    \ r), u };\n    }\nprivate:\n    static shared_ptr<treap> update(shared_ptr<treap>\
    \ const & t) {\n        if (t) {\n            t->m_size = 1 + size(t->l) + size(t->r);\n\
    \        }\n        return t;\n    }\n    static key_type generate() {\n     \
    \   static random_device device;\n        static default_random_engine engine(device());\n\
    \        static uniform_real_distribution<double> dist;\n        return dist(engine);\n\
    \    }\n};\n"
  code: "#include <random>\n#include <memory>\n\n// https://www.hackerrank.com/contests/zalando-codesprint/challenges/give-me-the-order/submissions/code/6004391\n\
    template <typename T>\nstruct treap {\n    typedef T value_type;\n    typedef\
    \ double key_type;\n    value_type v;\n    key_type k;\n    shared_ptr<treap>\
    \ l, r;\n    size_t m_size;\n    treap(value_type v)\n            : v(v)\n   \
    \         , k(generate())\n            , l()\n            , r()\n            ,\
    \ m_size(1) {\n    }\n    static size_t size(shared_ptr<treap> const & t) {\n\
    \        return t ? t->m_size : 0;\n    }\n    static shared_ptr<treap> merge(shared_ptr<treap>\
    \ const & a, shared_ptr<treap> const & b) { // destructive\n        if (not a)\
    \ return b;\n        if (not b) return a;\n        if (a->k > b->k) {\n      \
    \      a->r = merge(a->r, b);\n            return update(a);\n        } else {\n\
    \            b->l = merge(a, b->l);\n            return update(b);\n        }\n\
    \    }\n    static pair<shared_ptr<treap>, shared_ptr<treap> > split(shared_ptr<treap>\
    \ const & t, size_t i) { // [0, i) [i, n), destructive\n        if (not t) return\
    \ { shared_ptr<treap>(), shared_ptr<treap>() };\n        if (i <= size(t->l))\
    \ {\n            shared_ptr<treap> u; tie(u, t->l) = split(t->l, i);\n       \
    \     return { u, update(t) };\n        } else {\n            shared_ptr<treap>\
    \ u; tie(t->r, u) = split(t->r, i - size(t->l) - 1);\n            return { update(t),\
    \ u };\n        }\n    }\n    static shared_ptr<treap> insert(shared_ptr<treap>\
    \ const & t, size_t i, value_type v) { // destructive\n        shared_ptr<treap>\
    \ l, r; tie(l, r) = split(t, i);\n        shared_ptr<treap> u = make_shared<treap>(v);\n\
    \        return merge(merge(l, u), r);\n    }\n    static pair<shared_ptr<treap>,\
    \ shared_ptr<treap> > erase(shared_ptr<treap> const & t, size_t i) { // (t \\\
    \ t_i, t_i), destructive\n        shared_ptr<treap> l, u, r;\n        tie(l, r)\
    \ = split(t, i + 1);\n        tie(l, u) = split(l, i);\n        return { merge(l,\
    \ r), u };\n    }\nprivate:\n    static shared_ptr<treap> update(shared_ptr<treap>\
    \ const & t) {\n        if (t) {\n            t->m_size = 1 + size(t->l) + size(t->r);\n\
    \        }\n        return t;\n    }\n    static key_type generate() {\n     \
    \   static random_device device;\n        static default_random_engine engine(device());\n\
    \        static uniform_real_distribution<double> dist;\n        return dist(engine);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/treap.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/treap.inc.cpp
layout: document
redirect_from:
- /library/old/treap.inc.cpp
- /library/old/treap.inc.cpp.html
title: old/treap.inc.cpp
---
