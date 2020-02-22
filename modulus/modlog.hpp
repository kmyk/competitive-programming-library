#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include "modulus/modinv.hpp"
#include "modulus/modpow.hpp"
#include "utils/macros.hpp"
#include <iostream>

/**
 * @brief discrete log / 離散対数 (the baby-step giant-step, $O(\sqrt{m})$)
 * @description find the smallest $x \ge 0$ s.t. $g^x \equiv y \pmod{m}$
 * @param m is a positive integer
 * @note -1 if not found
 */
inline int modlog(int g, int y, int m) {
    assert (0 <= g and g < m);
    assert (0 <= y and y < m);
    if (m == 1) return 0;
    if (y == 1) return 0;
    if (g == 0 and y == 0) return 1;

    // meet-in-the-middle; let x = a \sqrt{m} + b
    int sqrt_m = sqrt(m) + 100;  // + 100 is required to bruteforce g^b for b < 100; this avoids problems with g != 0 and y = 0
    assert (sqrt_m >= 0);

    // baby-step: list (y, gy, g^2 y, ...) = (g^x, g^{x + 1}, g^{x + 2}, ...)
    std::unordered_map<int, int> table;
    int baby = 1;
    REP (b, sqrt_m) {
        if (baby == y) return b;
        table[(int64_t)baby * y % m] = b;
        baby = (int64_t)baby * g % m;
    }

    // giant-step: list (g^{sqrt(m)}, g^{2 sqrt(m)}, g^{3 sqrt(m)}, ...)
    int giant = 1;
    REP3 (a, 1, sqrt_m + 3) {
        giant = (int64_t)giant * baby % m;
        auto it = table.find(giant);
        if (it != table.end()) {
            int b = it->second;
            int x = (int64_t)a * sqrt_m - b;
            assert (x >= 0);
            return (modpow(g, x, m) == y ? x : -1);
        }
    }
    return -1;
}
