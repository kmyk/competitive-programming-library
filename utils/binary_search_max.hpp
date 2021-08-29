#pragma once
#include <cassert>
#include <cstdint>

/**
 * @return $\max \lbrace x \in (l, r] \mid p(x) \rbrace$, or l if it doesn't exist
 */
template <typename UnaryPredicate>
int64_t binsearch_max(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    ++ r;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;
        (p(m) ? l : r) = m;
    }
    return l;
}
