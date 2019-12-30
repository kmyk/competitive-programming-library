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

struct prepared_modlog {
    static constexpr double RATE = 0.5;
    const int g;
    const int m;
    int sqrt_m;
    std::unordered_map<int, int> giant;

    prepared_modlog(int g_, int m_)
            : g(g_), m(m_) {
        assert (0 <= g and g < m);
        if (g == 0 or g == 1) return;
        sqrt_m = pow(m, RATE) + 3;  // as a real

        // giant-step
        int g_sqrt_m = modpow(g, sqrt_m, m);
        int ga = 1;
        REP (a, sqrt_m + 3) {
            ga = (int64_t)ga * g_sqrt_m % m;
            if (not giant.count(ga)) {
                giant[ga] = a + 1;
            }
        }
    }

    int operator () (int y) const {
        assert (0 <= y and y < m);
        if (m == 1) return 0;
        if (y == 1) return 0;
        if (g == 0 and y == 0) return 1;

        // baby-step
        int baby = y;
        int min_x = INT_MAX;
        REP (b, sqrt_m) {
            auto it = giant.find(baby);
            if (it != giant.end()) {
                int a = it->second;
                int x = (int64_t)a * sqrt_m - b;
                assert (x >= 0);
                if (modpow(g, x, m) == y) {
                    min_x = std::min(min_x, x);
                }
            }
            baby = (int64_t)baby * g % m;
        }
        if (min_x == INT_MAX) return -1;
        return min_x;
    }
};

/**
 * @brief the baby-step giant-step
 * @description find the smallest $x \ge 0$ s.t. $g^x \equiv y \pmod{m}$
 * @param m is a positive integer
 * @note $O(\sqrt{m})$
 * @note meet-in-the-middle; let $x = a \sqrt{m} + b$
 * @note -1 if not found
 */
inline int modlog(int g, int y, int m) {
    return prepared_modlog(g, m)(y);
}
