#pragma once
#include <cstdint>
#include <vector>
#include "../data_structure/binary_indexed_tree.hpp"
#include "../utils/macros.hpp"
#include "../monoids/plus.hpp"

int64_t inversion_number(const std::vector<int> &a) {
    int n = a.size();
    binary_indexed_tree<plus_monoid<int64_t>> bit(n + 1);
    int64_t cnt = 0;
    REP (i, n) {
        cnt += i - bit.initial_range_get(a[i] + 1);
        bit.point_mult(a[i], 1);
    }
    return cnt;
}
