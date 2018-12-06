/**
 * @brief cumulative sum
 * @see std::partial_sum
 */
template <class T, class F>
vector<T> cumulative_sum(size_t n, F f) {
    vector<T> acc(n + 1);
    REP (i, n) {
        acc[i + 1] = acc[i] + f(i);
    }
    return acc;
}

/**
 * @brief 2D cumulative sum
 */
template <class T, class F>
vector<vector<T> > cumulative_sum(size_t h, size_t w, F f) {
    vector<vector<T> > acc(h + 1, vector<T>(w + 1));
    REP (y, h) {
        REP (x, w) {
            acc[y + 1][x + 1] = acc[y + 1][x] + f(y, x);
            acc[y + 1][x] += acc[y][x];  // in the same loop for speed
        }
        acc[y + 1][w] += acc[y][w];
    }
    return acc;
}


/**
 * @note verified https://beta.atcoder.jp/contests/abc106/submissions/3361728
 */
template <typename T>
struct cumulative_sum_2d {
    int h, w;
    vector<vector<T> > acc;
    bool frozen;
    cumulative_sum_2d(int h_, int w_) :
            h(h_),
            w(w_),
            acc(h + 1, vector<T>(w + 1)),
            frozen(false) {
    }
    void add(int y, int x, T value) {
        assert (not frozen);
        assert (0 <= y and y < h);
        assert (0 <= x and x < w);
        acc[y + 1][x + 1] += value;
    }
    void freeze() {
        assert (not frozen);
        frozen = true;
        REP (y, h) {
            REP (x, w) {
                acc[y + 1][x + 1] += acc[y + 1][x];
                acc[y + 1][x] += acc[y][x];  // in the same loop for speed
            }
            acc[y + 1][w] += acc[y][w];
        }
    }
    T get(int ly, int lx, int ry, int rx) const {  // [l, r)
        assert (frozen);
        assert (0 <= ly and ly <= ry and ry <= h);
        assert (0 <= lx and lx <= rx and rx <= w);
        return acc[ry][rx] - acc[ry][lx] - acc[ly][rx] + acc[ly][lx];
    }
    /**
     * @note call get O((ry - ly) / h * (rx - lx) / w) times
     */
    T get_torus(int ly, int lx, int ry, int rx) const {
        T acc = 0;
        while (ly < 0) { ly += h; ry += h; }
        while (lx < 0) { lx += w; rx += w; }
        for (int bi = ly / h; bi <= (ry - 1) / h; ++ bi) {
            int ly1 = (bi == ly / h ? ly % h : 0);
            int ry1 = (bi == ry / h ? ry % h : h);
            for (int bj = lx / w; bj <= (rx - 1) / w; ++ bj) {
                int lx1 = (bj == lx / w ? lx % w : 0);
                int rx1 = (bj == rx / w ? rx % w : w);
                acc += get(ly1, lx1, ry1, rx1);
            }
        }
        return acc;
    }
};
