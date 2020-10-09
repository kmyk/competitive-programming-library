---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/lowest_common_ancestor.yosupo.test.cpp
    title: graph/lowest_common_ancestor.yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: utils/dsu_on_tree.aoj.test.cpp
    title: utils/dsu_on_tree.aoj.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"hack/stack_pivot.hpp\"\n#include <cstdlib>\n\n/**\n * @note\
    \ This is a workaround for WSL. We cannot use ulimit -s unlimited on the environment.\n\
    \ * @note To use such techniques, you should take care of the alignment of rsp.\
    \ If not, you'll get SIGSEGV around XMM registers.\n */\n\n#define BEGIN_STACK_PIVOT(STACK_SIZE)\
    \ \\\n    static volatile char *old_stack; \\\n    asm volatile(\"mov %%rsp, %0\"\
    \ : \"=r\" (old_stack) ); \\\n    char *new_stack = ((char *)malloc(STACK_SIZE)\
    \ + (STACK_SIZE) - 0x10); \\\n    asm volatile(\"mov %0, %%rsp\" : : \"r\" (new_stack)\
    \ );\n\n#define END_STACK_PIVOT() \\\n    asm volatile(\"mov %0, %%rsp\" : : \"\
    r\" (old_stack) );\n\n#define STACK_PIVOT_MAIN(moin) \\\n    int main() { \\\n\
    \        BEGIN_STACK_PIVOT(1 << 28) \\\n        static int returncode = moin();\
    \ \\\n        END_STACK_PIVOT() \\\n        return returncode; \\\n    }\n"
  code: "#pragma once\n#include <cstdlib>\n\n/**\n * @note This is a workaround for\
    \ WSL. We cannot use ulimit -s unlimited on the environment.\n * @note To use\
    \ such techniques, you should take care of the alignment of rsp. If not, you'll\
    \ get SIGSEGV around XMM registers.\n */\n\n#define BEGIN_STACK_PIVOT(STACK_SIZE)\
    \ \\\n    static volatile char *old_stack; \\\n    asm volatile(\"mov %%rsp, %0\"\
    \ : \"=r\" (old_stack) ); \\\n    char *new_stack = ((char *)malloc(STACK_SIZE)\
    \ + (STACK_SIZE) - 0x10); \\\n    asm volatile(\"mov %0, %%rsp\" : : \"r\" (new_stack)\
    \ );\n\n#define END_STACK_PIVOT() \\\n    asm volatile(\"mov %0, %%rsp\" : : \"\
    r\" (old_stack) );\n\n#define STACK_PIVOT_MAIN(moin) \\\n    int main() { \\\n\
    \        BEGIN_STACK_PIVOT(1 << 28) \\\n        static int returncode = moin();\
    \ \\\n        END_STACK_PIVOT() \\\n        return returncode; \\\n    }\n"
  dependsOn: []
  isVerificationFile: false
  path: hack/stack_pivot.hpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/lowest_common_ancestor.yosupo.test.cpp
  - utils/dsu_on_tree.aoj.test.cpp
documentation_of: hack/stack_pivot.hpp
layout: document
redirect_from:
- /library/hack/stack_pivot.hpp
- /library/hack/stack_pivot.hpp.html
title: hack/stack_pivot.hpp
---
