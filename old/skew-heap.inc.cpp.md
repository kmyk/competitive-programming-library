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
    - http://hos.ac/blog/#blog0001
  bundledCode: "#line 1 \"old/skew-heap.inc.cpp\"\n/**\n * @sa http://hos.ac/blog/#blog0001\n\
    \ */\ntemplate <class T>\nclass skew_heap {\n    struct node_t {\n        node_t\
    \ *left, *right;\n        T value;\n    };\n    static node_t *merge(node_t *a,\
    \ node_t *b) {\n        if (a == nullptr) return b;\n        if (b == nullptr)\
    \ return a;\n        if (a->value > b->value) swap(a, b);\n        a->right =\
    \ merge(a->right, b);\n        swap(a->left, a->right);\n        return a;\n \
    \   }\n    static void release(node_t *node) {\n        if (node == nullptr) return;\n\
    \        release(node->left);\n        release(node->right);\n        delete node;\n\
    \    }\n    node_t *root;\npublic:\n    skew_heap() : root(nullptr) {}\n    ~\
    \ skew_heap() { release(root); }\n    void push(T a) {\n        node_t *node =\
    \ new node_t;\n        node->left = node->right = nullptr;\n        node->value\
    \ = a;\n        root = merge(root, node);\n    }\n    T get_min() {\n        assert\
    \ (root != nullptr);\n        return root->value;\n    }\n    void pop() {\n \
    \       assert (root != nullptr);\n        node_t *node = merge(root->left, root->right);\n\
    \        delete root;\n        root = node;\n    }\n    bool empty() {\n     \
    \   return root == nullptr;\n    }\n    void merge(skew_heap & other) {\n    \
    \    root = skew_heap::merge(root, other.root);\n        other.root = nullptr;\n\
    \    }\n};\n\nunittest {\n    default_random_engine gen;\n    skew_heap<int> skew;\n\
    \    priority_queue<int, vector<int>, greater<int> > que;\n    REP (iteration,\
    \ 100000) {\n        if (que.empty() or bernoulli_distribution(0.5)(gen)) {\n\
    \            int k = uniform_int_distribution<int>(1, 100)(gen);\n           \
    \ skew_heap<int> skew1;\n            while (k --) {\n                int a = uniform_int_distribution<int>()(gen);\n\
    \                skew1.push(a);\n                que.push(a);\n            }\n\
    \            skew.merge(skew1);\n            assert (skew1.empty());\n       \
    \ } else {\n            int a = skew.get_min();\n            int b = que.top();\n\
    \            assert (a == b);\n            skew.pop();\n            que.pop();\n\
    \        }\n    }\n}\n"
  code: "/**\n * @sa http://hos.ac/blog/#blog0001\n */\ntemplate <class T>\nclass\
    \ skew_heap {\n    struct node_t {\n        node_t *left, *right;\n        T value;\n\
    \    };\n    static node_t *merge(node_t *a, node_t *b) {\n        if (a == nullptr)\
    \ return b;\n        if (b == nullptr) return a;\n        if (a->value > b->value)\
    \ swap(a, b);\n        a->right = merge(a->right, b);\n        swap(a->left, a->right);\n\
    \        return a;\n    }\n    static void release(node_t *node) {\n        if\
    \ (node == nullptr) return;\n        release(node->left);\n        release(node->right);\n\
    \        delete node;\n    }\n    node_t *root;\npublic:\n    skew_heap() : root(nullptr)\
    \ {}\n    ~ skew_heap() { release(root); }\n    void push(T a) {\n        node_t\
    \ *node = new node_t;\n        node->left = node->right = nullptr;\n        node->value\
    \ = a;\n        root = merge(root, node);\n    }\n    T get_min() {\n        assert\
    \ (root != nullptr);\n        return root->value;\n    }\n    void pop() {\n \
    \       assert (root != nullptr);\n        node_t *node = merge(root->left, root->right);\n\
    \        delete root;\n        root = node;\n    }\n    bool empty() {\n     \
    \   return root == nullptr;\n    }\n    void merge(skew_heap & other) {\n    \
    \    root = skew_heap::merge(root, other.root);\n        other.root = nullptr;\n\
    \    }\n};\n\nunittest {\n    default_random_engine gen;\n    skew_heap<int> skew;\n\
    \    priority_queue<int, vector<int>, greater<int> > que;\n    REP (iteration,\
    \ 100000) {\n        if (que.empty() or bernoulli_distribution(0.5)(gen)) {\n\
    \            int k = uniform_int_distribution<int>(1, 100)(gen);\n           \
    \ skew_heap<int> skew1;\n            while (k --) {\n                int a = uniform_int_distribution<int>()(gen);\n\
    \                skew1.push(a);\n                que.push(a);\n            }\n\
    \            skew.merge(skew1);\n            assert (skew1.empty());\n       \
    \ } else {\n            int a = skew.get_min();\n            int b = que.top();\n\
    \            assert (a == b);\n            skew.pop();\n            que.pop();\n\
    \        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/skew-heap.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/skew-heap.inc.cpp
layout: document
redirect_from:
- /library/old/skew-heap.inc.cpp
- /library/old/skew-heap.inc.cpp.html
title: old/skew-heap.inc.cpp
---
