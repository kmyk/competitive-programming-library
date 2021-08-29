#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Li-Chao tree
 * @docs data_structure/li_chao_tree.md
 */
struct li_chao_tree {
    int k;
    std::vector<std::pair<int64_t, int64_t> > f;
    std::vector<int64_t> x;
    std::vector<int64_t> y;
    li_chao_tree() = default;
    li_chao_tree(const std::vector<int64_t> & x_) : x(x_) {
        assert (std::is_sorted(ALL(x)));
        k = 0; while ((1 << k) < x.size()) ++ k;
        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<int64_t>::max()));
        y.resize(x.size(), std::numeric_limits<int64_t>::max());
    }
    /**
     * @note i is a point on the original space
     */
    int64_t get_min(int64_t i) {
        i = std::lower_bound(ALL(x), i) - x.begin();
        return get_min_compressed(i);
    }
    int64_t get_min_compressed(int i) {  // 0-based
        assert (0 <= i and i < x.size());
        int64_t z = y[i];
        for (int j = (i + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based
            z = std::min(z, f[j - 1].first * x[i] + f[j - 1].second);
        }
        return z;
    }
    /**
     * @note [l, r) is an interval on the original space
     */
    void add_segment(int64_t l, int64_t r, int64_t a, int64_t b) {
        l = std::lower_bound(ALL(x), l) - x.begin();
        r = std::lower_bound(ALL(x), r) - x.begin();
        add_segment_compressed(l, r, a, b);
    }
    void add_segment_compressed(int64_t l, int64_t r, int64_t a, int64_t b) {
        assert (0 <= l and l <= r and r <= x.size());
        add_segment_compressed(0, 0, 1 << k, l, r, a, b);
    }
    void add_segment_compressed(int i, int il, int ir, int l, int r, int64_t a, int64_t b) {
        if (l <= il and ir <= r) {  // 0-based
            if (i >= (1 << k) - 1) {
                int j = i - (1 << k) + 1;
                y[j] = std::min(y[j], a * x[j] + b);
            } else {
                int64_t xl = x[il];
                int64_t xr = x[ir - 1];  // [xl, xr]
                int64_t yl1 = f[i].first * xl + f[i].second;
                int64_t yr1 = f[i].first * xr + f[i].second;
                int64_t yl2 = a * xl + b;
                int64_t yr2 = a * xr + b;
                if (yl1 <= yl2 and yr1 <= yr2) {
                    // if forall x in [l, r]. f(x) <= g(x), then do nothing
                    // nop
                } else if (yl2 <= yl1 and yr2 <= yr1) {
                    // if forall x in [l, r]. g(x) <= f(x), then replace f with g
                    f[i] = std::make_pair(a, b);
                } else {
                    int64_t xm = x[(il + ir) / 2];
                    int64_t ym1 = f[i].first * xm + f[i].second;
                    int64_t ym2 = a * xm + b;
                    if (yl1 <= yl2 and ym1 <= ym2) {
                        // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m, r] with f
                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (yl2 <= yl1 and ym2 <= ym1) {
                        // if forall x in [l, m]. g(x) <= f(x), then replace f with g and do recursion for [m, r] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (ym1 <= ym2 and yr1 <= yr2) {
                        // if forall x in [m, r]. f(x) <= g(x), then do recursion for [l, m] with f
                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else if (ym2 <= ym1 and yr2 <= yr1) {
                        // if forall x in [m, r]. g(x) <= f(x), then replace f with g and do recursion for [l, m] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else {
                        assert (false);
                    }
                }
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            add_segment_compressed(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
            add_segment_compressed(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
        }
    }
};
