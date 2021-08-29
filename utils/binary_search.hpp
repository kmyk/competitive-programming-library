#pragma once
#include <cassert>
#include <cstdint>

/**
 * @brief a binary search / 二分探索
 * @param[in] p  a monotone predicate defined on $[l, r)$
 * @return $\min \lbrace x \in [l, r) \mid p(x) \rbrace$, or r if it doesn't exist
 */
template <typename UnaryPredicate>
int64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    -- l;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;
        (p(m) ? r : l) = m;
    }
    return r;
}
