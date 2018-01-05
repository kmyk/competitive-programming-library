template <int32_t MOD>
int32_t fact(int n) {
    static vector<int32_t> memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() *(int64_t) memo.size() % MOD);
    }
    return memo[n];
}
template <int32_t PRIME>
int32_t inv_fact(int n) {
    static vector<int32_t> memo(1, 1);
    while (n >= memo.size()) {
        memo.push_back(memo.back() *(int64_t) modinv(memo.size(), PRIME) % PRIME);
    }
    return memo[n];
}

unittest {
    constexpr int32_t mod = 1e9 + 7;
    assert (fact<mod>(0) == 1);
    assert (fact<mod>(1) == 1);
    assert (fact<mod>(2) == 2);
    assert (fact<mod>(3) == 6);
    assert (fact<mod>(4) == 24);
    assert (fact<mod>(5) == 120);
}
