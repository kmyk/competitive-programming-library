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
        if (k < 0) return -1;
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
    wavelet_matrix<BITS> wm(data);
    for (int iteration = 1000; iteration --; ) {
        uint64_t value = uniform_int_distribution<uint64_t>(0, (1ull << BITS) - 1)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (wm.rank(value, l, r) == rank(value, l, r));
        assert (wm.select(value, k, l) == select(value, k, l));
        assert (wm.access(l) == data[l]);
        assert (wm.quantile(k, l, r) == quantile(k, l, r));
    }
}
unittest {
    unittest_wavelet_matrix<10>(100);
    unittest_wavelet_matrix<10>(126);
    unittest_wavelet_matrix<10>(127);
    unittest_wavelet_matrix<10>(128);
    unittest_wavelet_matrix<10>(129);
    unittest_wavelet_matrix<63>(10000);
}
