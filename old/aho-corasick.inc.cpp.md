---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/aho-corasick.inc.cpp\"\nstruct pma_t { // Aho-Corasick\n\
    \    pma_t* next[26];\n    pma_t* fail;\n    int accept;\n};\npma_t *ac_new()\
    \ {\n    pma_t *pma = new pma_t;\n    *pma = {};\n    return pma;\n}\nvoid ac_add_pattern(pma_t\
    \ *pma, string const & pattern) { // O(m)\n    for (char c : pattern) { // make\
    \ trie\n        if (pma->next[c-'a'] == nullptr) {\n            pma->next[c-'a']\
    \ = ac_new();\n        }\n        pma = pma->next[c-'a'];\n    }\n    pma->accept\
    \ += 1;\n}\nvoid ac_construct_links(pma_t *pma) { // O(m)\n    queue<pma_t *>\
    \ que; // make failure link using bfs\n    repeat (c,26) {\n        if (pma->next[c])\
    \ {\n            pma->next[c]->fail = pma;\n            que.push(pma->next[c]);\n\
    \        } else {\n            pma->next[c] = pma;\n        }\n    }\n    while\
    \ (not que.empty()) {\n        pma_t *now = que.front(); que.pop();\n        repeat\
    \ (c,26) {\n            if (now->next[c]){\n                pma_t *nxt = now->fail;\n\
    \                while (not nxt->next[c]) nxt = nxt->fail;\n                now->next[c]->fail\
    \ = nxt->next[c];\n                now->next[c]->accept += nxt->next[c]->accept;\n\
    \                que.push(now->next[c]);\n            }\n        }\n    }\n}\n\
    int ac_match(pma_t *pma, string const & target) { // O(n)\n    int result = 0;\n\
    \    for (char c : target) {\n        while (not pma->next[c-'a']) pma = pma->fail;\n\
    \        pma = pma->next[c-'a'];\n        result += pma->accept;\n    }\n    return\
    \ result;\n}\nvoid ac_delete(pma_t *pma, unordered_set<pma_t *> & deleted) {\n\
    \    deleted.insert(pma);\n    repeat (c,26) if (pma->next[c] and not deleted.count(pma))\
    \ {\n        ac_delete(pma->next[c], deleted);\n    }\n    delete pma;\n}\nvoid\
    \ ac_delete(pma_t *pma) {\n    unordered_set<pma_t *> deleted;\n    ac_delete(pma,\
    \ deleted);\n}\n"
  code: "struct pma_t { // Aho-Corasick\n    pma_t* next[26];\n    pma_t* fail;\n\
    \    int accept;\n};\npma_t *ac_new() {\n    pma_t *pma = new pma_t;\n    *pma\
    \ = {};\n    return pma;\n}\nvoid ac_add_pattern(pma_t *pma, string const & pattern)\
    \ { // O(m)\n    for (char c : pattern) { // make trie\n        if (pma->next[c-'a']\
    \ == nullptr) {\n            pma->next[c-'a'] = ac_new();\n        }\n       \
    \ pma = pma->next[c-'a'];\n    }\n    pma->accept += 1;\n}\nvoid ac_construct_links(pma_t\
    \ *pma) { // O(m)\n    queue<pma_t *> que; // make failure link using bfs\n  \
    \  repeat (c,26) {\n        if (pma->next[c]) {\n            pma->next[c]->fail\
    \ = pma;\n            que.push(pma->next[c]);\n        } else {\n            pma->next[c]\
    \ = pma;\n        }\n    }\n    while (not que.empty()) {\n        pma_t *now\
    \ = que.front(); que.pop();\n        repeat (c,26) {\n            if (now->next[c]){\n\
    \                pma_t *nxt = now->fail;\n                while (not nxt->next[c])\
    \ nxt = nxt->fail;\n                now->next[c]->fail = nxt->next[c];\n     \
    \           now->next[c]->accept += nxt->next[c]->accept;\n                que.push(now->next[c]);\n\
    \            }\n        }\n    }\n}\nint ac_match(pma_t *pma, string const & target)\
    \ { // O(n)\n    int result = 0;\n    for (char c : target) {\n        while (not\
    \ pma->next[c-'a']) pma = pma->fail;\n        pma = pma->next[c-'a'];\n      \
    \  result += pma->accept;\n    }\n    return result;\n}\nvoid ac_delete(pma_t\
    \ *pma, unordered_set<pma_t *> & deleted) {\n    deleted.insert(pma);\n    repeat\
    \ (c,26) if (pma->next[c] and not deleted.count(pma)) {\n        ac_delete(pma->next[c],\
    \ deleted);\n    }\n    delete pma;\n}\nvoid ac_delete(pma_t *pma) {\n    unordered_set<pma_t\
    \ *> deleted;\n    ac_delete(pma, deleted);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/aho-corasick.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/aho-corasick.inc.cpp
layout: document
redirect_from:
- /library/old/aho-corasick.inc.cpp
- /library/old/aho-corasick.inc.cpp.html
title: old/aho-corasick.inc.cpp
---
