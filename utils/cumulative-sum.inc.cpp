/**
 * @brief cumulative sum
 * @see std::partial_sum
 */
template <class T, class F>
vector<T> cumulative_sum(size_t n, F f) {
    vector<T> acc(n+1);
    repeat (i,n) {
        acc[i+1] = acc[i] + f(i);
    }
    return acc;
}

/**
 * @brief 2D cumulative sum
 */
template <class T, class F>
vector<vector<T> > cumulative_sum(size_t h, size_t w, F f) {
    vector<vector<T> > acc(h+1, vector<T>(w+1));
    repeat (y,h) {
        repeat (x,w) {
            acc[y+1][x+1] = acc[y+1][x] + f(y, x);
            acc[y+1][x] += acc[y][x]; // in same loop: for speed
        }
        acc[y+1][w] += acc[y][w];
    }
    return acc;
}
