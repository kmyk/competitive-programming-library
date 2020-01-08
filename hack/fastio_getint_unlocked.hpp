#pragma once
#include <cstdint>
#include <cstdio>

inline int64_t getint_unlocked() {
    int64_t n = getchar_unlocked() - '0';
    if (n + '0' == '-') return -getint_unlocked();
    for (char c; (c = getchar_unlocked()) >= '0'; ) n = n * 10 + c - '0';
    return n;
}
