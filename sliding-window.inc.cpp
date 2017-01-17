// http://poj.org/problem?id=2823
// http://cf16-tournament-round3-open.contest.atcoder.jp/tasks/asaporo_d
template <typename T>
struct sliding_window {
    deque<pair<int, T> > data;
    function<bool (T const &, T const &)> cmp;
    template <typename F>
    sliding_window(F a_lt) : cmp(a_lt) {}
    T front() { return data.front().second; } // smallest
    void push_back(int i, T a) { while (not data.empty() and cmp(a, data.back().second)) data.pop_back(); data.emplace_back(i, a); }
    void pop_front(int i) { if (data.front().first == i) data.pop_front(); }
    void push_front(int i, T a) { if (data.empty() or not cmp(data.front().second, a)) data.emplace_front(i, a); }
};
