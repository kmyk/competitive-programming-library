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
  bundledCode: "#line 1 \"old/dlopen.inc.cpp\"\nextern \"C\" {\n#if defined(_WIN32)\n\
    void *__libc_dlopen_mode(const char *, int);\nvoid *__libc_dlsym(void *, const\
    \ char *);\n#else\nvoid* __stdcall LoadLibraryA(const char *);\nvoid* __stdcall\
    \ GetProcAddress(void *, const char *);\n#endif\n}\nstruct dynamic_library {\n\
    \    void *handle;\n    dynamic_library() : handle(nullptr) {}\n    dynamic_library(string\
    \ const & path) { handle = nullptr; try_open(path); }\n    void try_open(string\
    \ const & path) {\n        if (not handle) {\n#if defined(_WIN32)\n          \
    \  handle = LoadLibraryA(path.c_str());\n#else\n            int rtld_now = 2;\n\
    \            handle = __libc_dlopen_mode(path.c_str(), rtld_now);\n#endif\n  \
    \      }\n    }\n    void *operator () (string const & symbol) {\n#if defined(_WIN32)\n\
    \        return GetProcAddress(handle, symbol.c_str());\n#else\n        return\
    \ __libc_dlsym(handle, symbol.c_str());\n#endif\n    }\n};\n\ndynamic_library\
    \ libpthread = dynamic_library()\n    .try_open(\"/lib/x86_64-linux-gnu/libpthread.so.0\"\
    ) // atcoder\n    .try_open(\"/usr/lib64/libpthread.so.0\"); // yukicoder\nextern\
    \ \"C\" {\nint pthread_create (pthread_t *__restrict __newthread,\n        const\
    \ pthread_attr_t *__restrict __attr,\n        void *(*__start_routine) (void *),\n\
    \        void *__restrict __arg) {\n    typedef decltype(pthread_create) (*type);\n\
    \    static type ptr = (type)(libpthread(\"pthread_create\"));\n    return ptr(__newthread,\
    \ __attr, __start_routine, __arg);\n}\nvoid pthread_exit (void *__retval) {\n\
    \    typedef decltype(pthread_exit) (*type);\n    static type ptr = (type)(libpthread(\"\
    pthread_exit\"));\n    ptr(__retval);\n}\nint pthread_join (pthread_t __th, void\
    \ **__thread_return) {\n    typedef decltype(pthread_join) (*type);\n    static\
    \ type ptr = (type)(libpthread(\"pthread_join\"));\n    return ptr(__th, __thread_return);\n\
    }\nint pthread_detach (pthread_t __th) {\n    typedef decltype(pthread_detach)\
    \ (*type);\n    static type ptr = (type)(libpthread(\"pthread_detach\"));\n  \
    \  return ptr(__th);\n}\n}\n\n#include <gmp.h>\n#define EXPAND_MACRO_TO_STR_2(a)\
    \ #a\n#define EXPAND_MACRO_TO_STR(a) EXPAND_MACRO_TO_STR_2(a)\ndynamic_library\
    \ libgmp = dynamic_library()\n    .try_open(\"/usr/lib/x86_64-linux-gnu/libgmp.so.10\"\
    ) // atcoder\n    .try_open(\"/usr/lib64/libgmp.so.10\") // yukicoder\n    .try_open(\"\
    mpir.dll\");\n#define D(name) const auto my_##name = (decltype(::name) *)libgmp(EXPAND_MACRO_TO_STR(name))\n\
    D(mpz_init_set_str)\nD(mpz_probab_prime_p)\n#undef D\n"
  code: "extern \"C\" {\n#if defined(_WIN32)\nvoid *__libc_dlopen_mode(const char\
    \ *, int);\nvoid *__libc_dlsym(void *, const char *);\n#else\nvoid* __stdcall\
    \ LoadLibraryA(const char *);\nvoid* __stdcall GetProcAddress(void *, const char\
    \ *);\n#endif\n}\nstruct dynamic_library {\n    void *handle;\n    dynamic_library()\
    \ : handle(nullptr) {}\n    dynamic_library(string const & path) { handle = nullptr;\
    \ try_open(path); }\n    void try_open(string const & path) {\n        if (not\
    \ handle) {\n#if defined(_WIN32)\n            handle = LoadLibraryA(path.c_str());\n\
    #else\n            int rtld_now = 2;\n            handle = __libc_dlopen_mode(path.c_str(),\
    \ rtld_now);\n#endif\n        }\n    }\n    void *operator () (string const &\
    \ symbol) {\n#if defined(_WIN32)\n        return GetProcAddress(handle, symbol.c_str());\n\
    #else\n        return __libc_dlsym(handle, symbol.c_str());\n#endif\n    }\n};\n\
    \ndynamic_library libpthread = dynamic_library()\n    .try_open(\"/lib/x86_64-linux-gnu/libpthread.so.0\"\
    ) // atcoder\n    .try_open(\"/usr/lib64/libpthread.so.0\"); // yukicoder\nextern\
    \ \"C\" {\nint pthread_create (pthread_t *__restrict __newthread,\n        const\
    \ pthread_attr_t *__restrict __attr,\n        void *(*__start_routine) (void *),\n\
    \        void *__restrict __arg) {\n    typedef decltype(pthread_create) (*type);\n\
    \    static type ptr = (type)(libpthread(\"pthread_create\"));\n    return ptr(__newthread,\
    \ __attr, __start_routine, __arg);\n}\nvoid pthread_exit (void *__retval) {\n\
    \    typedef decltype(pthread_exit) (*type);\n    static type ptr = (type)(libpthread(\"\
    pthread_exit\"));\n    ptr(__retval);\n}\nint pthread_join (pthread_t __th, void\
    \ **__thread_return) {\n    typedef decltype(pthread_join) (*type);\n    static\
    \ type ptr = (type)(libpthread(\"pthread_join\"));\n    return ptr(__th, __thread_return);\n\
    }\nint pthread_detach (pthread_t __th) {\n    typedef decltype(pthread_detach)\
    \ (*type);\n    static type ptr = (type)(libpthread(\"pthread_detach\"));\n  \
    \  return ptr(__th);\n}\n}\n\n#include <gmp.h>\n#define EXPAND_MACRO_TO_STR_2(a)\
    \ #a\n#define EXPAND_MACRO_TO_STR(a) EXPAND_MACRO_TO_STR_2(a)\ndynamic_library\
    \ libgmp = dynamic_library()\n    .try_open(\"/usr/lib/x86_64-linux-gnu/libgmp.so.10\"\
    ) // atcoder\n    .try_open(\"/usr/lib64/libgmp.so.10\") // yukicoder\n    .try_open(\"\
    mpir.dll\");\n#define D(name) const auto my_##name = (decltype(::name) *)libgmp(EXPAND_MACRO_TO_STR(name))\n\
    D(mpz_init_set_str)\nD(mpz_probab_prime_p)\n#undef D\n"
  dependsOn: []
  isVerificationFile: false
  path: old/dlopen.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/dlopen.inc.cpp
layout: document
redirect_from:
- /library/old/dlopen.inc.cpp
- /library/old/dlopen.inc.cpp.html
title: old/dlopen.inc.cpp
---
