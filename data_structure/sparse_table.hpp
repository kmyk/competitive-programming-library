#pragma once
#include <cassert>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief sparse table on a semilattice
 * @note a semilattice is a commutative idempotent semigroup
 * @note for convenience, it requires the unit
 * @note O(N log N) space
 */
template <class Semilattice>
struct sparse_table {
    typedef typename Semilattice::underlying_type underlying_type;
    std::vector<std::vector<underlying_type> > table;
    Semilattice lat;
    sparse_table() = default;
    /**
     * @note O(N \log N) time
     */
    sparse_table(std::vector<underlying_type> const & data, Semilattice const & a_lat = Semilattice())
            : lat(a_lat) {
        int n = data.size();
        int log_n = 32 - __builtin_clz(n);
        table.resize(log_n, std::vector<underlying_type>(n));
        table[0] = data;
        REP (k, log_n - 1) {
            REP (i, n) {
                table[k + 1][i] = i + (1ll << k) < n ?
                    lat.append(table[k][i], table[k][i + (1ll << k)]) :
                    table[k][i];
            }
        }
    }
    /**
     * @note O(1)
     */
    underlying_type range_concat(int l, int r) const {
        if (l == r) return lat.unit();  // if there is no unit, remove this line
        assert (0 <= l and l < r and r <= table[0].size());
        int k = 31 - __builtin_clz(r - l);  // log2
        return lat.append(table[k][l], table[k][r - (1ll << k)]);
    }
};


#include <algorithm>
#include <climits>
#include "number/gcd.hpp"

struct max_semilattice {
    typedef int underlying_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return std::max(a, b); }
};
struct min_semilattice {
    typedef int underlying_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return std::min(a, b); }
};
struct gcd_semilattice {
    typedef int underlying_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return gcd(a, b); }
};
