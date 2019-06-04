#include "utils/binary_search.hpp"

#include <cassert>
#include <initializer_list>
#include "utils/macros.hpp"

int main() {
    // binsearch()
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return true;   }) == l);
            assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return false;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch(l, r, [&](int n) { assert (l <= n and n < r); return n >= i; }) == i);
            }
        }
    }

    // binsearch_max
    for (int l : { 0, 1, 2, 3 }) {
        for (int r : { 8, 9, 10, 11 }) {
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return false; }) == l);
            assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return true;  }) == r);
            REP3 (i, l, r + 1) {
                assert (binsearch_max(l, r, [&](int n) { assert (l < n and n <= r); return n <= i; }) == i);
            }
        }
    }
    return 0;
}
