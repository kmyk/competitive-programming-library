/**
 * @brief the extended Mo's algorithm
 * @arg stupid is called O(Q) times, each length is O(\sqrt{N})
 * @arg mo si the following:
 *     struct rollback_mo_interface {
 *         void reset(int l);  // called O(N) times
 *         void extend_left( int l, int r);  // called O(Q) times, the sum of length is O(N \sqrt {N})
 *         void extend_right(int l, int r);  // called O(Q) times, the sum of length is O(Q \sqrt {N})
 *         void snapshot();  // called O(Q) times
 *         void rollback();  // called O(Q) times
 *         void query();     // called O(Q) times
 *     };
 * @see http://snuke.hatenablog.com/entry/2016/07/01/000000
 * @see http://codeforces.com/blog/entry/7383?#comment-161520
 */
template <class Func, class RollbackMoInterface>
void rollback_square_decomposition(int n, vector<pair<int, int> > const & range, RollbackMoInterface & mo, Func stupid) {
    int bucket_size = sqrt(n);
    int bucket_count = (n + bucket_size - 1) / bucket_size;
    vector<vector<int> > bucket(bucket_count);
    REP (i, int(range.size())) {
        int l, r; tie(l, r) = range[i];
        if (r - l <= bucket_size) {
            stupid(l, r);
        } else {
            bucket[l / bucket_size].push_back(i);
        }
    }
    REP (b, bucket_count) {
        sort(ALL(bucket[b]), [&](int i, int j) { return range[i].second < range[j].second; });
        int l = (b + 1) * bucket_size;
        mo.reset(l);
        int r = l;
        for (int i : bucket[b]) {
            int l_i, r_i; tie(l_i, r_i) = range[i];
            mo.extend_right(r, r_i);
            mo.snapshot();
            mo.extend_left(l_i, l);
            mo.query();
            mo.rollback();
            r = r_i;
        }
    }
}
