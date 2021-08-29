#pragma once
#include <cassert>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Karatsuba method ($O(n^{\log_2 3})$)
 */
template <class CommutativeRing>
std::vector<CommutativeRing> karatsuba_convolution(const std::vector<CommutativeRing> & x, const std::vector<CommutativeRing> & y) {
    int n = x.size();
    int m = y.size();
    if ((int64_t)n * m <= 100) {
        std::vector<CommutativeRing> z(n + m - 1);
        REP (i, n) REP (j, m) {
            z[i + j] += x[i] * y[j];
        }
        return z;
    }
    int half = (std::max(n, m) + 1) / 2;

    std::vector<CommutativeRing> x0(x.begin(), x.begin() + std::min(n, half));
    std::vector<CommutativeRing> y0(y.begin(), y.begin() + std::min(m, half));
    std::vector<CommutativeRing> z0 = karatsuba_convolution(x0, y0);

    std::vector<CommutativeRing> x1(x.begin() + std::min(n, half), x.end());
    std::vector<CommutativeRing> y1(y.begin() + std::min(m, half), y.end());
    std::vector<CommutativeRing> z2 = karatsuba_convolution(x1, y1);

    assert (x1.size() <= x0.size());
    std::vector<CommutativeRing> dx = x0;
    REP (i, x1.size()) dx[i] -= x1[i];
    assert (y1.size() <= y0.size());
    std::vector<CommutativeRing> dy = y0;
    REP (i, y1.size()) dy[i] -= y1[i];
    std::vector<CommutativeRing> dz = karatsuba_convolution(dx, dy);

    std::vector<CommutativeRing> z(n + m - 1);
    REP (i, z0.size()) {
        z[i] += z0[i];
        if (half + i < (int)z.size()) z[half + i] += z0[i];
    }
    REP (i, dz.size()) {
        if (half + i < (int)z.size()) z[half + i] -= dz[i];
    }
    REP (i, z2.size()) {
        z[half + i] += z2[i];
        if (2 * half + i < (int)z.size()) z[2 * half + i] += z2[i];
    }
    return z;
}
