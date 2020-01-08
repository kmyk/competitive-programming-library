#pragma once
#include <cstdint>
#include <cstdio>

inline int64_t getint_unlocked() {
    int64_t n = getchar_unlocked() - '0';
    if (n + '0' == '-') return -getint_unlocked();
    for (char c; (c = getchar_unlocked()) >= '0'; ) n = n * 10 + c - '0';
    return n;
}

inline void putint_unlocked(int64_t n) {
    char s[20];
    int i = 0;
    if (n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}
