// http://poj.org/problem?id=2823
template <typename T>
struct sliding_window {
    deque<pair<T,int> > data;
    function<bool (T const &, T const &)> cmp;
    template <typename F>
    sliding_window(F a_lt) : cmp(a_lt) {}
    T front() { return data.front().first; } // smallest
    void push_back(T a, int i) { while (not data.empty() and cmp(a, data.back().first)) data.pop_back(); data.emplace_back(a, i); }
    void pop_front(int i) { if (data.front().second == i) data.pop_front(); }
    void push_front(T a, int i) { if (data.empty() or not cmp(data.front().first, a) data.emplace_front(a, i); }
};
