#pragma once
#include <map>
#include <optional>
#include <utility>
#include <vector>

/**
 * @brief set of disjoint intervals
 */
class interval_set {
    std::map<int64_t, int64_t> data;  // the function which from right terminals r_i to left terminals l_i of intervals [l_i, r_i)

public:
    /**
     * @note O(\log q) amortized
     * @note [l_i, r_i)
     */
    void add_interval(int64_t l, int64_t r) {
        assert (l <= r);
        if (l == r) return;
        while (true) {
            auto it = data.lower_bound(l);
            if (it == data.end() or r < it->second) {
                break;
            }
            l = std::min(l, it->second);
            r = std::max(r, it->first);
            data.erase(it);
        }
        data.emplace(r, l);
    }

    /**
     * @note O(\log q)
     */
    void remove_containing_interval(int64_t x) {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second <= x) {
            data.erase(it);
        }
    }

    /**
     * @note O(\log q)
     */
    std::optional<std::pair<int64_t, int64_t> > find_containing_interval(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second <= x) {
            return std::make_optional(std::make_pair(it->second, it->first));
        } else {
            return std::optional<std::pair<int64_t, int64_t> >();
        }
    }

    /**
     * @note O(k \log q)
     * @note [l_i, r_i)
     */
    std::vector<std::pair<int64_t, int64_t> > list_intersecting_interval(int64_t l, int64_t r) const {
        assert (l <= r);
        std::vector<std::pair<int64_t, int64_t> > result;
        while (true) {
            auto it = data.upper_bound(l);
            if (it == data.end() or r <= it->second) {
                break;
            }
            result.emplace_back(it->second, it->first);
            l = it->first;
        }
        return result;
    }

    size_t size() const {
        return data.size();
    }
};
