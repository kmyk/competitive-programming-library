// https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0#.E7.AC.AC2.E7.A8.AE.E3.82.B9.E3.82.BF.E3.83.BC.E3.83.AA.E3.83.B3.E3.82.B0.E6.95.B0
ll second_kind_stirling(ll n, ll k) { // O(nk)
    assert (0 <= n and 0 <= k);
    if (n  < k) return 0;
    if (n == k) return 1;
    if (k == 0) return 0;
    static vector<vector<ll> > memo;
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n + 1);
        repeat_from (i,l,n+1) memo[i].resize(i);
    }
    if (memo[n][k]) return memo[n][k];
    return memo[n][k] = (second_kind_stirling(n-1, k-1) + k * second_kind_stirling(n-1, k) % mod) % mod;
}
