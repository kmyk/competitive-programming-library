#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <type_traits>
#include <vector>
#include "../utils/macros.hpp"

/**
 * @brief Dual Segment Tree / 双対セグメント木 (列挙クエリ, 完全二分木)
 * @note This tree is very similar to the Bentley's original segment tree.
 */
template <class Key>
struct reporting_segment_tree {
    int size;
    std::vector<std::vector<Key> > data;
    reporting_segment_tree() = default;
    explicit reporting_segment_tree(int size_) {
        size = 1; while (size < size_) size *= 2;
        data.resize(2 * size - 1);
    }

    /**
     * @arg key must be unique
     * @note $O(\log n)$
     */
    void add_segment(int l, int r, const Key & key) {
        assert (0 <= l and l <= r and r <= size);
        for (l += size, r += size; l < r; l /= 2, r /= 2) {  // 1-based
            if (l % 2 == 1) data[(l ++) - 1].push_back(key);
            if (r % 2 == 1) data[(-- r) - 1].push_back(key);
        }
    }

    /**
     * @note $O(\log n + k)$
     */
    template <class Callback>
    void list_segments(int i, Callback & callback) {
        static_assert (std::is_invocable_r<void, Callback, const Key &>::value, "");
        assert (0 <= i and i < size);
        for (i += size; i > 0; i /= 2) {  // 1-based
            for (const auto & key : data[i - 1]) {
                callback(key);
            }
        }
    }

    /**
     * @note $O(n + k)$
     * @arg remove can be implemented as undo
     * @arg report is called with all indices in increasing order
     */
    template <class Add, class Remove, class Report>
    void traverse_segments(Add & add, Remove & remove, Report & report) {
        static_assert (std::is_invocable_r<void, Add, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Remove, const Key &>::value, "");
        static_assert (std::is_invocable_r<void, Report, int>::value, "");
        std::function<void (int, int, int)> dfs = [&](int i, int l, int r) {
            for (const auto & key : data[i]) {
                add(key);
            }
            if (i >= size - 1) {
                report(i - size + 1);
            } else {
                dfs(2 * i + 1, l, (l + r) / 2);
                dfs(2 * i + 2, (l + r) / 2, r);
            }
            for (auto it = data[i].rbegin(); it != data[i].rend(); ++ it) {
                remove(*it);
            }
        };
        dfs(0, 0, size);
    }
};
