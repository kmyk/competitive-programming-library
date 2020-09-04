---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/persistent-randomized-binary-search-tree.inc.cpp\"\n\
    template <typename T>\nstruct prbst { // persistent randomized binary search tree\n\
    \    typedef T value_type;\n    value_type v;\n    shared_ptr<prbst> l, r;\n \
    \   size_t m_size;\n    static size_t size(shared_ptr<prbst> const & t) {\n  \
    \      return t ? t->m_size : 0;\n    }\n    static shared_ptr<prbst> merge(shared_ptr<prbst>\
    \ const & a, shared_ptr<prbst> const & b) {\n        if (not a) return b;\n  \
    \      if (not b) return a;\n        if (compare(size(a), size(b))) {\n      \
    \      return make_shared<prbst>(b->v, merge(a, b->l), b->r);\n        } else\
    \ {\n            return make_shared<prbst>(a->v, a->l, merge(a->r, b));\n    \
    \    }\n    }\n    static pair<shared_ptr<prbst>, shared_ptr<prbst> > split(shared_ptr<prbst>\
    \ const & t, size_t i) { // [0, i) [i, n)\n        if (not t) return { shared_ptr<prbst>(),\
    \ shared_ptr<prbst>() };\n        if (i <= size(t->l)) {\n            shared_ptr<prbst>\
    \ l, r; tie(l, r) = split(t->l, i);\n            return { l, make_shared<prbst>(t->v,\
    \ r, t->r) };\n        } else {\n            shared_ptr<prbst> l, r; tie(l, r)\
    \ = split(t->r, i - size(t->l) - 1);\n            return { make_shared<prbst>(t->v,\
    \ t->l, l), r };\n        }\n    }\n    static shared_ptr<prbst> insert(shared_ptr<prbst>\
    \ const & t, size_t i, value_type v) {\n        shared_ptr<prbst> l, r; tie(l,\
    \ r) = split(t, i);\n        shared_ptr<prbst> u = make_shared<prbst>(v);\n  \
    \      return merge(merge(l, u), r);\n    }\n    static pair<shared_ptr<prbst>,\
    \ value_type> erase(shared_ptr<prbst> const & t, size_t i) { // (t \\ t_i, t_i)\n\
    \        shared_ptr<prbst> l, u, r;\n        tie(l, r) = split(t, i+1);\n    \
    \    tie(l, u) = split(l, i);\n        return { merge(l, r), u->v };\n    }\n\
    // private:\n    prbst(value_type v) : v(v), l(), r(), m_size(1) {}\n    prbst(value_type\
    \ v, shared_ptr<prbst> const & l, shared_ptr<prbst> const & r) : v(v), l(l), r(r),\
    \ m_size(1 + size(l) + size(r)) {}\n    static bool compare(size_t a, size_t b)\
    \ {\n        static random_device device;\n        static default_random_engine\
    \ engine(device());\n        bernoulli_distribution dist(b /(double) (a + b));\n\
    \        return dist(engine);\n    }\n};\n"
  code: "template <typename T>\nstruct prbst { // persistent randomized binary search\
    \ tree\n    typedef T value_type;\n    value_type v;\n    shared_ptr<prbst> l,\
    \ r;\n    size_t m_size;\n    static size_t size(shared_ptr<prbst> const & t)\
    \ {\n        return t ? t->m_size : 0;\n    }\n    static shared_ptr<prbst> merge(shared_ptr<prbst>\
    \ const & a, shared_ptr<prbst> const & b) {\n        if (not a) return b;\n  \
    \      if (not b) return a;\n        if (compare(size(a), size(b))) {\n      \
    \      return make_shared<prbst>(b->v, merge(a, b->l), b->r);\n        } else\
    \ {\n            return make_shared<prbst>(a->v, a->l, merge(a->r, b));\n    \
    \    }\n    }\n    static pair<shared_ptr<prbst>, shared_ptr<prbst> > split(shared_ptr<prbst>\
    \ const & t, size_t i) { // [0, i) [i, n)\n        if (not t) return { shared_ptr<prbst>(),\
    \ shared_ptr<prbst>() };\n        if (i <= size(t->l)) {\n            shared_ptr<prbst>\
    \ l, r; tie(l, r) = split(t->l, i);\n            return { l, make_shared<prbst>(t->v,\
    \ r, t->r) };\n        } else {\n            shared_ptr<prbst> l, r; tie(l, r)\
    \ = split(t->r, i - size(t->l) - 1);\n            return { make_shared<prbst>(t->v,\
    \ t->l, l), r };\n        }\n    }\n    static shared_ptr<prbst> insert(shared_ptr<prbst>\
    \ const & t, size_t i, value_type v) {\n        shared_ptr<prbst> l, r; tie(l,\
    \ r) = split(t, i);\n        shared_ptr<prbst> u = make_shared<prbst>(v);\n  \
    \      return merge(merge(l, u), r);\n    }\n    static pair<shared_ptr<prbst>,\
    \ value_type> erase(shared_ptr<prbst> const & t, size_t i) { // (t \\ t_i, t_i)\n\
    \        shared_ptr<prbst> l, u, r;\n        tie(l, r) = split(t, i+1);\n    \
    \    tie(l, u) = split(l, i);\n        return { merge(l, r), u->v };\n    }\n\
    // private:\n    prbst(value_type v) : v(v), l(), r(), m_size(1) {}\n    prbst(value_type\
    \ v, shared_ptr<prbst> const & l, shared_ptr<prbst> const & r) : v(v), l(l), r(r),\
    \ m_size(1 + size(l) + size(r)) {}\n    static bool compare(size_t a, size_t b)\
    \ {\n        static random_device device;\n        static default_random_engine\
    \ engine(device());\n        bernoulli_distribution dist(b /(double) (a + b));\n\
    \        return dist(engine);\n    }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/persistent-randomized-binary-search-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/persistent-randomized-binary-search-tree.inc.cpp
layout: document
redirect_from:
- /library/old/persistent-randomized-binary-search-tree.inc.cpp
- /library/old/persistent-randomized-binary-search-tree.inc.cpp.html
title: old/persistent-randomized-binary-search-tree.inc.cpp
---
