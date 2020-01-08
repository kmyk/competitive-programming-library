#pragma once
#include <cstdint>
#include <cstdio>

inline void putint_unlocked(int64_t n) {
    char s[20];
    int i = 0;
    if (n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}
