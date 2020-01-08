/**
 * @note O(N) time, O(N) space
 */
template <typename T>
vector<T> apply_permutation(vector<int> const & sigma, vector<T> const & xs) {
    int n = sigma.size();
    vector<T> ys(n);
    REP (i, n) ys[i] = xs[sigma[i]];
    return ys;
}

unittest {
    vector<char> xs { 'a', 'b', 'c', 'd', 'e' };
    vector<int> sigma { 4, 3, 2, 0, 1 };
    vector<char> ys { 'e', 'd', 'c', 'a', 'b' };
    assert (ys == apply_permutation(sigma, xs));
}
