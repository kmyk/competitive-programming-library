#pragma once
#include <cassert>
#include <cstddef>
#include <deque>
#include "../utils/macros.hpp"

/**
 * @brief Sliding Window Aggregation / 含まれる要素の総和が $O(1)$ で取れる queue (可換とは限らない monoid が乗る)
 */
template <class Monoid>
struct sliding_window_aggregation {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    std::deque<value_type> data;
    int front;
    value_type back;
    sliding_window_aggregation(const Monoid & mon_ = Monoid()) : mon(mon_) {
        front = 0;
        back = mon.unit();
    }
    /**
     * @note O(1)
     */
    void push(value_type x) {
        data.push_back(x);
        back = mon.mult(back, x);
    }
    /**
     * @note amortized O(1)
     */
    void pop() {
        assert (not data.empty());
        data.pop_front();
        if (front) {
            -- front;
        } else {
            REP_R (i, (int)data.size() - 1) {
                data[i] = mon.mult(data[i], data[i + 1]);
            }
            front = data.size();
            back = mon.unit();
        }
    }
    /**
     * @brief get sum of elements in the queue
     * @note O(1)
     */
    value_type accumulate() const {
        return front ? mon.mult(data.front(), back) : back;
    }
    bool empty() const {
        return data.empty();
    }
    std::size_t size() const {
        return data.size();
    }
};
