---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/trie-tree.inc.cpp\"\ntemplate <typename T>\nstruct trie_t\
    \ {\n    T data;\n    array<shared_ptr<trie_t>, 26> children;\n};\ntemplate <typename\
    \ T>\nshared_ptr<trie_t<T> > trie_insert(shared_ptr<trie_t<T> > original_t, string\
    \ const & s, T data) {\n    if (not original_t) original_t = make_shared<trie_t<T>\
    \ >();\n    auto t = original_t;\n    for (char c : s) {\n        assert (isalpha(c));\n\
    \        int i = toupper(c) - 'A';\n        if (not t->children[i]) t->children[i]\
    \ = make_shared<trie_t<T> >();\n        t = t->children[i];\n    }\n    t->data\
    \ = data;\n    return original_t;\n}\ntemplate <typename T>\nshared_ptr<trie_t<T>\
    \ > trie_find(shared_ptr<trie_t<T> > const & t, string const & s, int i) {\n \
    \   if (t == nullptr) return t;\n    if (i == s.length()) return t;\n    char\
    \ c = s[i];\n    int j = toupper(c) - 'A';\n    return trie_find(t->children[j],\
    \ s, i + 1);\n}\n"
  code: "template <typename T>\nstruct trie_t {\n    T data;\n    array<shared_ptr<trie_t>,\
    \ 26> children;\n};\ntemplate <typename T>\nshared_ptr<trie_t<T> > trie_insert(shared_ptr<trie_t<T>\
    \ > original_t, string const & s, T data) {\n    if (not original_t) original_t\
    \ = make_shared<trie_t<T> >();\n    auto t = original_t;\n    for (char c : s)\
    \ {\n        assert (isalpha(c));\n        int i = toupper(c) - 'A';\n       \
    \ if (not t->children[i]) t->children[i] = make_shared<trie_t<T> >();\n      \
    \  t = t->children[i];\n    }\n    t->data = data;\n    return original_t;\n}\n\
    template <typename T>\nshared_ptr<trie_t<T> > trie_find(shared_ptr<trie_t<T> >\
    \ const & t, string const & s, int i) {\n    if (t == nullptr) return t;\n   \
    \ if (i == s.length()) return t;\n    char c = s[i];\n    int j = toupper(c) -\
    \ 'A';\n    return trie_find(t->children[j], s, i + 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/trie-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/trie-tree.inc.cpp
layout: document
redirect_from:
- /library/old/trie-tree.inc.cpp
- /library/old/trie-tree.inc.cpp.html
title: old/trie-tree.inc.cpp
---
