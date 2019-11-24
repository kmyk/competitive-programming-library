#pragma once
#include <cassert>
#include <stack>

template <class Monoid>
struct sliding_window_aggregation {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    std::stack<value_type> front, back;
    std::stack<value_type> sum_front;
    value_type sum_back;
    sliding_window_aggregation(const Monoid & mon_ = Monoid()) : mon(mon_) {
        sum_front.push(mon.unit());
        sum_back = mon.unit();
    }
    /**
     * @note O(1)
     */
    void push(value_type x) {
        back.push(x);
        sum_back = mon.append(sum_back, x);
    }
    /**
     * @note amortized O(1)
     */
    void pop() {
        if (front.empty()) {
            while (not back.empty()) {
                front.push(back.top());
                sum_front.push(mon.append(front.top(), sum_front.top()));
                back.pop();
            }
            sum_back = mon.unit();
        }
        assert (not front.empty());
        front.pop();
        sum_front.pop();
    }
    /**
     * @brief get sum of elements in the queue
     * @note O(1)
     */
    value_type accumulate() const {
        return mon.append(sum_front.top(), sum_back);
    }
    bool empty() const {
        return front.empty() and back.empty();
    }
    size_t size() const {
        return front.size() + back.size();
    }
};
