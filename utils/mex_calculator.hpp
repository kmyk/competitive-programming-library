#pragma once
#include <cassert>

class mex_calculator {
    uint64_t used;
public:
    mex_calculator()
            : used(0) {
    }
    void put(int x) {
        assert (0 <= x and x < 64 - 1);
        used |= 1ull << x;
    }
    int get() const {
        return __builtin_ctzll(~ used);
    }
    void clear() {
        used = 0;
    }
};
