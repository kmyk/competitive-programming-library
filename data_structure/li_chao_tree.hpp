#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

template <class T>
struct li_chao_tree {
    int k;
    std::vector<std::pair<T, T> > f;
    std::vector<T> x;
    std::vector<T> y;
    li_chao_tree() = default;
    li_chao_tree(const std::vector<T> & x_) : x(x_) {
        assert (std::is_sorted(ALL(x)));
        k = 0; while ((1 << k) < x.size()) ++ k;
        f.resize((1 << k) - 1, std::make_pair(0, std::numeric_limits<T>::max()));
        y.resize(x.size(), std::numeric_limits<T>::max());
    }
    T get_min(int i) {  // 0-based
        assert (0 <= i and i < x.size());
        T z = y[i];
        for (int j = (i + (1 << k)) / 2; j > 0; j /= 2) {  // 1-based
            z = std::min(z, f[j - 1].first * x[i] + f[j - 1].second);
        }
        return z;
    }
    void add_segment(int l, int r, T a, T b) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= x.size());
        add_segment(0, 0, 1 << k, l, r, a, b);
    }
    void add_segment(int i, int il, int ir, int l, int r, T a, T b) {
        if (l <= il and ir <= r) {  // 0-based
            if (i >= (1 << k) - 1) {
                int j = i - (1 << k) + 1;
                y[j] = std::min(y[j], a * x[j] + b);
            } else {
                T xl = x[il];
                T xr = x[ir - 1];  // [xl, xr]
                T yl1 = f[i].first * xl + f[i].second;
                T yr1 = f[i].first * xr + f[i].second;
                T yl2 = a * xl + b;
                T yr2 = a * xr + b;
                if (yl1 <= yl2 and yr1 <= yr2) {
                    // if forall x in [l, r]. f(x) <= g(x), then do nothing
                    // nop
                } else if (yl2 <= yl1 and yr2 <= yr1) {
                    // if forall x in [l, r]. g(x) <= f(x), then replace f with g
                    f[i] = std::make_pair(a, b);
                } else {
                    T xm = x[(il + ir) / 2];
                    T ym1 = f[i].first * xm + f[i].second;
                    T ym2 = a * xm + b;
                    if (yl1 <= yl2 and ym1 <= ym2) {
                        // if forall x in [l, m]. f(x) <= g(x), then do recursion for [m, r] with f
                        add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (yl2 <= yl1 and ym2 <= ym1) {
                        // if forall x in [l, m]. g(x) <= f(x), then replace f with g and do recursion for [m, r] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
                    } else if (ym1 <= ym2 and yr1 <= yr2) {
                        // if forall x in [m, r]. f(x) <= g(x), then do recursion for [l, m] with f
                        add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else if (ym2 <= ym1 and yr2 <= yr1) {
                        // if forall x in [m, r]. g(x) <= f(x), then replace f with g and do recursion for [l, m] with g
                        std::swap(a, f[i].first);
                        std::swap(b, f[i].second);
                        add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
                    } else {
                        assert (false);
                    }
                }
            }
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            add_segment(2 * i + 1, il, (il + ir) / 2, l, r, a, b);
            add_segment(2 * i + 2, (il + ir) / 2, ir, l, r, a, b);
        }
    }
};