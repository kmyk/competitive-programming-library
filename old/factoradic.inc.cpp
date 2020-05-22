template <class RandomAccessIterator>
uint64_t encode_factoradic(RandomAccessIterator first, RandomAccessIterator last) { // O(N^2)
    static vector<int> fact(1, 1);
    while (fact.size() < n) {
        fact.push_back(fact.size() * fact.back());
    }
    int n = last - first;
    uint64_t y = 0;
    REP (i, n) {
        int xi = *(first + i);
        int rank = count_if(first, first + i, [&](int xj) { return xi < xj; });
        y += rank * fact[i];
    }
    return y;
}
vector<int> decode_factoradic(uint64_t y, int n) { // O(N^2)
    static vector<int> fact(1, 1);
    while (fact.size() < n) {
        fact.push_back(fact.size() * fact.back());
    }
    vector<int> xs(n);
    vector<int> zs(n); iota(zs.begin(), zs.end(), 0);
    REP_R (i, n) {
        auto it = zs.begin() + (i - y / fact[i]);
        xs[i] = *it;
        zs.erase(it);
        y %= fact[i];
    }
    return xs;
}
