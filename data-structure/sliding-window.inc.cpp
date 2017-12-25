/**
 * @brief the sliding window minimum algorithm
 * @note to get maximums, use greater<T>
 * @note verified http://poj.org/problem?id=2823
 * @note verified http://cf16-tournament-round3-open.contest.atcoder.jp/tasks/asaporo_d
 */
template <typename T, class Compare = less<T> >
struct sliding_window {
    deque<pair<int, T> > data;
    function<bool (T const &, T const &)> compare;
    sliding_window(Compare const & a_compare = Compare()) : compare(a_compare) {}
    T front() { return data.front().second; }  // O(1), minimum
    void push_back(int i, T a) { while (not data.empty() and compare(a, data.back().second)) data.pop_back(); data.emplace_back(i, a); }  // O(1) amortized.
    void pop_front(int i) { if (data.front().first == i) data.pop_front(); }
    void push_front(int i, T a) { if (data.empty() or not compare(data.front().second, a)) data.emplace_front(i, a); }
};
