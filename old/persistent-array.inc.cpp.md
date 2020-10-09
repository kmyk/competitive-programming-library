---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "persistent array / \u6C38\u7D9A\u914D\u5217"
    links:
    - http://qiita.com/imos/items/c4c5e19289a79e598b93
    - http://web.mit.edu/andersk/Public/6.851-presentation.pdf
  bundledCode: "#line 1 \"old/persistent-array.inc.cpp\"\n/**\n * @brief persistent\
    \ array / \u6C38\u7D9A\u914D\u5217\n * @see http://qiita.com/imos/items/c4c5e19289a79e598b93\n\
    \ * @see http://web.mit.edu/andersk/Public/6.851-presentation.pdf\n */\ntemplate\
    \ <class T>\nstruct persistent_array { // fully persistent\n    static const int\
    \ SHIFT_SIZE = 3; // log of the branching factor b\n    int size; // the size\
    \ n\n    int shift;\n    array<shared_ptr<persistent_array>, (1 << SHIFT_SIZE)>\
    \ children;\n    shared_ptr<T> leaf;\n    persistent_array(persistent_array const\
    \ &) = default; // O(b)\n    persistent_array() : size(0), shift(-1) {}\n    persistent_array(int\
    \ a_size) : size(a_size), shift(-1) { // O(n \\log_b n + m b \\log_b n) for number\
    \ of update m\n        if (size == 0) return;\n        for (shift = 0; (1 << (shift\
    \ * SHIFT_SIZE)) < size; ++ shift);\n        if (shift == 0) {\n            leaf.reset(new\
    \ T());\n        } else {\n            int child_size = 1 << ((shift - 1) * SHIFT_SIZE);\n\
    \            for (int l = 0; l < size; l += child_size) {\n                int\
    \ r = min(size, l + child_size);\n                children[l / child_size].reset(new\
    \ persistent_array(r - l));\n            }\n        }\n    }\n    T const & get(int\
    \ index) const { // O(log_b n)\n        return const_cast<persistent_array *>(this)->mutable_reference(index);\n\
    \    }\n    T & mutable_reference(int index) { // unsafe, to speed up initialization\n\
    \        if (shift == 0) {\n            assert (index == 0);\n            return\
    \ *leaf;\n        }\n        int l_shift = (shift - 1) * SHIFT_SIZE;\n       \
    \ int index_high = index >> l_shift;\n        int index_low  = index & ((1 <<\
    \ l_shift) - 1);\n        return children[index_high]->mutable_reference(index_low);\n\
    \    }\n    void set(int index, T const & value) { // O(b log_b n), increment\
    \ m\n        if (shift == 0) {\n            assert (index == 0);\n           \
    \ leaf.reset(new T(value));\n            return;\n        }\n        int l_shift\
    \ = (shift - 1) * SHIFT_SIZE;\n        int index_high = index >> l_shift;\n  \
    \      int index_low  = index & ((1 << l_shift) - 1);\n        persistent_array\
    \ *p = new persistent_array();\n        *p = *(children[index_high]);\n      \
    \  children[index_high].reset(p);\n        children[index_high]->set(index_low,\
    \ value);\n    }\n};\ntemplate <typename T>\nstatic ostream & operator << (ostream\
    \ & out, persistent_array<T> const & a) {\n    if (a.shift == 0) {\n        repeat\
    \ (i, 10) out << ' ';\n        persistent_array<T> const *p = &a;\n        out\
    \ << p << ' ' << a.size << ' ' << *a.leaf<< endl;\n    } else {\n        repeat\
    \ (i, 10 - a.shift) out << ' ';\n        persistent_array<T> const *p = &a;\n\
    \        out << p << ' ' << a.size << endl;\n        for (auto it : a.children)\
    \ if (it) out << *it;\n    }\n    return out;\n};\n"
  code: "/**\n * @brief persistent array / \u6C38\u7D9A\u914D\u5217\n * @see http://qiita.com/imos/items/c4c5e19289a79e598b93\n\
    \ * @see http://web.mit.edu/andersk/Public/6.851-presentation.pdf\n */\ntemplate\
    \ <class T>\nstruct persistent_array { // fully persistent\n    static const int\
    \ SHIFT_SIZE = 3; // log of the branching factor b\n    int size; // the size\
    \ n\n    int shift;\n    array<shared_ptr<persistent_array>, (1 << SHIFT_SIZE)>\
    \ children;\n    shared_ptr<T> leaf;\n    persistent_array(persistent_array const\
    \ &) = default; // O(b)\n    persistent_array() : size(0), shift(-1) {}\n    persistent_array(int\
    \ a_size) : size(a_size), shift(-1) { // O(n \\log_b n + m b \\log_b n) for number\
    \ of update m\n        if (size == 0) return;\n        for (shift = 0; (1 << (shift\
    \ * SHIFT_SIZE)) < size; ++ shift);\n        if (shift == 0) {\n            leaf.reset(new\
    \ T());\n        } else {\n            int child_size = 1 << ((shift - 1) * SHIFT_SIZE);\n\
    \            for (int l = 0; l < size; l += child_size) {\n                int\
    \ r = min(size, l + child_size);\n                children[l / child_size].reset(new\
    \ persistent_array(r - l));\n            }\n        }\n    }\n    T const & get(int\
    \ index) const { // O(log_b n)\n        return const_cast<persistent_array *>(this)->mutable_reference(index);\n\
    \    }\n    T & mutable_reference(int index) { // unsafe, to speed up initialization\n\
    \        if (shift == 0) {\n            assert (index == 0);\n            return\
    \ *leaf;\n        }\n        int l_shift = (shift - 1) * SHIFT_SIZE;\n       \
    \ int index_high = index >> l_shift;\n        int index_low  = index & ((1 <<\
    \ l_shift) - 1);\n        return children[index_high]->mutable_reference(index_low);\n\
    \    }\n    void set(int index, T const & value) { // O(b log_b n), increment\
    \ m\n        if (shift == 0) {\n            assert (index == 0);\n           \
    \ leaf.reset(new T(value));\n            return;\n        }\n        int l_shift\
    \ = (shift - 1) * SHIFT_SIZE;\n        int index_high = index >> l_shift;\n  \
    \      int index_low  = index & ((1 << l_shift) - 1);\n        persistent_array\
    \ *p = new persistent_array();\n        *p = *(children[index_high]);\n      \
    \  children[index_high].reset(p);\n        children[index_high]->set(index_low,\
    \ value);\n    }\n};\ntemplate <typename T>\nstatic ostream & operator << (ostream\
    \ & out, persistent_array<T> const & a) {\n    if (a.shift == 0) {\n        repeat\
    \ (i, 10) out << ' ';\n        persistent_array<T> const *p = &a;\n        out\
    \ << p << ' ' << a.size << ' ' << *a.leaf<< endl;\n    } else {\n        repeat\
    \ (i, 10 - a.shift) out << ' ';\n        persistent_array<T> const *p = &a;\n\
    \        out << p << ' ' << a.size << endl;\n        for (auto it : a.children)\
    \ if (it) out << *it;\n    }\n    return out;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/persistent-array.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/persistent-array.inc.cpp
layout: document
redirect_from:
- /library/old/persistent-array.inc.cpp
- /library/old/persistent-array.inc.cpp.html
title: "persistent array / \u6C38\u7D9A\u914D\u5217"
---
