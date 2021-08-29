#pragma once
#include <cassert>
#include <vector>
#include "../modulus/mint.hpp"
#include "../modulus/factorial.hpp"
#include "../modulus/number_theoretic_transformation_with_garner.hpp"

/**
 * @brief the Stirling number of the second kind (for given $N$, compute $S(N, \ast)$ in $O(N \log N)$)
 * @see https://min-25.hatenablog.com/entry/2015/04/07/160154
 */
template <int MOD>
std::vector<mint<MOD> > stirling_number_of_the_second_kind_convolution(int n) {
    assert (0 <= n);
    std::vector<mint<MOD> > a(n + 1);
    std::vector<mint<MOD> > b(n + 1);
    REP (i, n + 1) {
        a[i] = mint<MOD>(i).pow(n) * inv_fact<MOD>(i);
        b[i] = (i % 2 == 0 ? 1 : -1) * inv_fact<MOD>(i);
    }
    auto c = ntt_convolution(a, b);
    c.resize(n + 1);
    return c;
}
