/**
 * @brief a wavelet matrix
 * @tparam BITS express the range [0, 2^BITS) of values. You can assume BITS \le \log N, using coordinate compression
 */
template <int BITS>
struct wavelet_matrix {
    static_assert (BITS < CHAR_BIT * sizeof(uint64_t), "");
    array<fully_indexable_dictionary, BITS> fid;
    array<int, BITS> zero_count;
    wavelet_matrix() = default;
    /**
     * @note O(N BITS)
     */
    template <typename T>
    wavelet_matrix(vector<T> data) {
        int size = data.size();
        REP (i, size) {
            assert (0 <= data[i] and data[i] < (1ull << BITS));
        }
        // bit-inversed radix sort
        vector<char> bits(size);
        vector<T> next(size);
        REP_R (k, BITS) {
            auto low  = next.begin();
            auto high = next.rbegin();
            REP (i, size) {
                bits[i] = bool(data[i] & (1ull << k));
                (bits[i] ? *(high ++) : *(low ++)) = data[i];
            }
            fid[k] = fully_indexable_dictionary(bits);
            zero_count[k] = low - next.begin();
            reverse(next.rbegin(), high);
            data.swap(next);
        }
    }
    /**
     * @note O(BITS)
     * @note even if l = 0, of course the final [l, r) is not always [0, r)
     */
    int rank(uint64_t value, int l, int r) const {
        assert (0 <= value and value < (1ull << BITS));
        assert (0 <= l and l <= r and r <= fid[0].size);
        REP_R (k, BITS) {
            bool p = value & (1ull << k);
            l = fid[k].rank(p, l) + p * zero_count[k];
            r = fid[k].rank(p, r) + p * zero_count[k];
        }
        return r - l;
    }
    int rank(uint64_t value, int r) const {
        return rank(value, 0, r);
    }
    /**
     * @note O(BITS SELECT) when FID's select() is O(SELECT)
     */
    int select(uint64_t value, int k) const {
        assert (0 <= value and value < (1ull << BITS));
        assert (0 <= k);
        // do rank(value, 0, size) with logging
        vector<int> l(BITS + 1), r(BITS + 1);
        l[BITS] = 0;
        r[BITS] = fid[0].size;
        REP_R (d, BITS) {
            bool p = value & (1ull << d);
            l[d] = fid[d].rank(p, l[d + 1]) + p * zero_count[d];
            r[d] = fid[d].rank(p, r[d + 1]) + p * zero_count[d];
        }
        if (r[0] - l[0] <= k) return fid[0].size;
        // trace the log inversely
        REP (d, BITS) {
            bool p = value & (1ull << d);
            k = fid[d].select(p, k, l[d + 1]) - l[d + 1];
        }
        return k;
    }
    int select(uint64_t value, int k, int l) const {
        return select(value, k + rank(value, l));
    }
    /**
     * @note O(BITS)
     */
    uint64_t access(int i) const {
        assert (0 <= i and i < size);
        uint64_t acc = 0;
        REP_R (k, BITS) {
            bool p = fid[k].access(i);
            acc |= uint64_t(p) << k;
            i = fid[k].rank(p, i) + p * zero_count[k];
        }
        return acc;
    }
    /**
     * @brief find the k-th number in [l, r)
     * @note O(BITS)
     */
    uint64_t quantile(int k, int l, int r) {
        assert (0 <= k);
        assert (0 <= l and l <= r and r <= fid[0].size);
        if (r - l <= k) return 1ull << BITS;
        uint64_t acc = 0;
        REP_R (d, BITS) {
            int lc = fid[d].rank(1, l);
            int rc = fid[d].rank(1, r);
            int zero = (r - l) - (rc - lc);
            bool p = (k >= zero);
            if (p) {
                acc |= 1ull << d;
                l = lc + zero_count[d];
                r = rc + zero_count[d];
                k -= zero;
            } else {
                l -= lc;
                r -= rc;
            }
        }
        return acc;
    }
    /**
     * @brief count the number of values in [value_l, value_r) in range [l, r)
     * @note O(BITS)
     */
    int range_frequency(int l, int r, uint64_t value_l, uint64_t value_r) const {
        assert (0 <= l and l <= r and r <= fid[0].size);
        assert (0 <= value_l and value_l <= value_r and value_r <= (1ull << BITS));
        return range_frequency(BITS - 1, l, r, 0, value_l, value_r);
    }
    int range_frequency(int k, int l, int r, uint64_t v, uint64_t a, uint64_t b) const {
        if (l == r) return 0;
        if (k == -1) return (a <= v and v < b) ? r - l : 0;
        uint64_t nv  =  v |  (1ull << k);
        uint64_t nnv = nv | ((1ull << k) - 1);
        if (nnv < a or b <= v) return 0;
        if (a <= v and nnv < b) return r - l;
        int lc = fid[k].rank(1, l);
        int rc = fid[k].rank(1, r);
        return
            range_frequency(k - 1,             l - lc,             r - rc,  v, a, b) +
            range_frequency(k - 1, lc + zero_count[k], rc + zero_count[k], nv, a, b);
    }
    /**
     * @brief flexible version of range_frequency, buf a little bit slow
     * @note O(K BITS), K is the number of kinds of values in the range
     * @arg void callback(uint64_t value, int count)
     */
    template <typename Func>
    void range_frequency_callback(int l, int r, uint64_t value_l, uint64_t value_r, Func callback) const {
        assert (0 <= l and l <= r and r <= fid[0].size);
        assert (0 <= value_l and value_l <= value_r and value_r <= (1ull << BITS));
        range_frequency_callback(BITS - 1, l, r, 0, value_l, value_r, callback);
    }
    template <typename Func>
    void range_frequency_callback(int k, int l, int r, uint64_t v, uint64_t a, uint64_t b, Func callback) const {
        if (l == r) return;
        if (b <= v) return;
        if (k == -1) {
            if (a <= v) callback(v, r - l);
            return;
        }
        uint64_t nv  = v  | (1ull << k);
        uint64_t nnv = nv | (((1ull << k) - 1));
        if (nnv < a) return;
        int lc = fid[k].rank(1, l);
        int rc = fid[k].rank(1, r);
        range_frequency_callback(k - 1,             l - lc,             r - rc,  v, a, b, callback);
        range_frequency_callback(k - 1, lc + zero_count[k], rc + zero_count[k], nv, a, b, callback);
    }
};

template <int BITS>
void unittest_wavelet_matrix(int n) {
    random_device device;
    default_random_engine gen(device());
    vector<uint64_t> data(n);
    REP (i, n) data[i] = uniform_int_distribution<uint64_t>(0, (1ull << BITS) - 1)(gen);
    auto rank = [&](uint64_t value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](uint64_t value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    auto quantile = [&](int k, int l, int r) {
        vector<uint64_t> range;
        REP3 (i, l, r) range.push_back(data[i]);
        sort(ALL(range));
        return range[k];
    };
    auto range_frequency = [&](int l, int r, uint64_t value_l, uint64_t value_r) {
        int cnt = 0;
        REP3 (i, l, r) cnt += value_l <= data[i] and data[i] < value_r;
        return cnt;
    };
    wavelet_matrix<BITS> wm(data);
    for (int iteration = 1000; iteration --; ) {
        uint64_t value = uniform_int_distribution<uint64_t>(0, (1ull << BITS) - 1)(gen);
        uint64_t another_value = uniform_int_distribution<uint64_t>(value, (1ull << BITS) - 1)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (wm.rank(value, l, r) == rank(value, l, r));
        assert (wm.select(value, k, l) == select(value, k, l));
        assert (wm.access(l) == data[l]);
        assert (wm.quantile(k, l, r) == quantile(k, l, r));
        assert (wm.range_frequency(l, r, value, another_value + 1) == range_frequency(l, r, value, another_value + 1));
        {
            int acc = 0;
            wm.range_frequency_callback(l, r, value, another_value + 1, [&](uint64_t value, int count) {
                acc += count;
            });
            assert (acc == range_frequency(l, r, value, another_value + 1));
        }
    }
}
unittest {
    unittest_wavelet_matrix<3>(10);
    unittest_wavelet_matrix<10>(100);
    unittest_wavelet_matrix<10>(126);
    unittest_wavelet_matrix<10>(127);
    unittest_wavelet_matrix<10>(128);
    unittest_wavelet_matrix<10>(129);
    unittest_wavelet_matrix<63>(10000);
}
