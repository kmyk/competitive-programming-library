/**
 * @brief a fully indexable dictionary
 * @note space complexity o(N). 1.5N-bit consumed
 */
class fully_indexable_dictionary {
    static constexpr size_t block_size = 64;
    vector<uint64_t> block;
    vector<int32_t> rank_block;  // a blocked cumulative sum
public:
    size_t size;
    fully_indexable_dictionary() = default;
    template <typename T>
    fully_indexable_dictionary(vector<T> const & bits) {
        size = bits.size();
        size_t block_count = size / block_size + 1;
        block.resize(block_count);
        REP (i, size) if (bits[i]) {
            block[i / block_size] |= (1ull << (i % block_size));
        }
        rank_block.resize(block_count);
        rank_block[0] = 0;
        REP (i, block_count - 1) {
            rank_block[i + 1] = rank_block[i] + __builtin_popcountll(block[i]);
        }
    }
    /**
     * @brief count the number of value in [0, r)
     * @note O(1)
     */
    int rank(bool value, int r) const {
        assert (0 <= r and r <= size);
        uint64_t mask = (1ull << (r % block_size)) - 1;
        int rank_1 = rank_block[r / block_size] + __builtin_popcountll(block[r /block_size] & mask);
        return value ? rank_1 : r - rank_1;
    }
    int rank(bool value, int l, int r) const {
        assert (0 <= l and l <= r and r <= size);
        return rank(value, r) - rank(value, l);
    }
    /**
     * @brief find the index of the k-th occurrence of value
     * @note if there is no such index, returns size
     * @note O(log N)
     */
    int select(bool value, int k) const {
        if (k >= rank(value, size)) return size;
        // binary search: max { i | rank_block[i] <= k }
        int l = 0, r = block.size();  // [l, r)
        while (r - l > 1) {
            int m = (l + r) / 2;
            int rank_block_m = (value ? rank_block[m] : m * block_size - rank_block[m]);
            (rank_block_m <= k ? l : r) = m;
        }
        int block_index = l;
        // binary search: max { i | rank(i) <= k }
        l = block_index * block_size;
        r = min<int>(size, (block_index + 1) * block_size); // [l, r)
        while (r - l > 1) {
            int m = (l + r) / 2;
            (rank(value, m) <= k ? l : r) = m;
        }
        return l;
    }
    /**
     * @brief select(value, k) in [l, size)
     */
    int select(bool value, int k, int l) const {
        assert (0 <= l and l <= size);
        return select(value, k + rank(value, l));
    }
    /**
     * @note O(1)
     */
    bool access(int i) const {
        assert (0 <= i and i <= size);
        return block[i / block_size] & (1ull << (i % block_size));
    }
};

void unittest_fully_indexable_dictionary(int n) {
    random_device device;
    default_random_engine gen(device());
    vector<bool> data(n);
    REP (i, n) data[i] = bernoulli_distribution(0.5)(gen);
    auto rank = [&](bool value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](bool value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    fully_indexable_dictionary fid(data);
    for (int iteration = 1000; iteration --; ) {
        bool value = bernoulli_distribution(0.5)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (fid.rank(value, l, r) == rank(value, l, r));
        assert (fid.select(value, k, l) == select(value, k, l));
        assert (fid.access(l) == data[l]);
    }
}
unittest {
    unittest_fully_indexable_dictionary(1);
    unittest_fully_indexable_dictionary(126);
    unittest_fully_indexable_dictionary(127);
    unittest_fully_indexable_dictionary(128);
    unittest_fully_indexable_dictionary(129);
    unittest_fully_indexable_dictionary(10000);
}
