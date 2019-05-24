/**
 * @brief a rolling hash
 * @note 4 primes for modulo and and random bases
 * @see http://hos.ac/blog/#blog0003
 */
struct rolling_hash {
    static constexpr int size = 4;
    static const int32_t prime[size];
    static int32_t base[size];
    static struct base_initializer_t {
        base_initializer_t() {
            random_device device;
            default_random_engine gen(device());
            REP (i, size) {
                base[i] = uniform_int_distribution<int32_t>(256, prime[i] - 1)(gen);
            }
        }
    } base_initializer;
public:
    array<int32_t, size> data;
    rolling_hash() : data({}) {}
    rolling_hash(char c) {
        REP (i, size) data[i] = c;
    }
    rolling_hash(const string & s) : data({}) {
        for (char c : s) push_back(c);
    }
    void push_back(char c) {
        REP (i, size) {
            data[i] = (data[i] *(int64_t) base[i] + c) % prime[i];
        }
    }
    rolling_hash & operator += (rolling_hash const & other) {
        REP (i, size) {
            data[i] += other.data[i];
            if (data[i] >= prime[i]) data[i] -= prime[i];
        }
        return *this;
    }
    rolling_hash operator + (rolling_hash const & other) const {
        return rolling_hash(*this) += other;
    }
    rolling_hash & operator -= (rolling_hash const & other) {
        REP (i, size) {
            data[i] -= other.data[i];
            if (data[i] < 0) data[i] += prime[i];
        }
        return *this;
    }
    /**
     * @note O(size)
     */
    rolling_hash & operator <<= (array<int32_t, size> const & pow_base) {
        REP (i, size) {
            data[i] = data[i] *(int64_t) pow_base[i] % prime[i];
        }
        return *this;
    }
    /**
     * @note O(size log width)
     */
    rolling_hash & operator <<= (int width) {
        array<int32_t, size> pow_base;
        REP (i, size) {
            pow_base[i] = powmod(base[i], width, prime[i]);
        }
        return *this << pow_base;
    }
    rolling_hash operator << (int width) const {
        return rolling_hash(*this) <<= width;
    }
    bool operator == (rolling_hash const & other) const {
        return data == other.data;
    }
    bool operator != (rolling_hash const & other) const {
        return not (*this == other);
    }
    friend ostream & operator << (ostream & out, rolling_hash const & that) {
        char buffer[8 * size + 1];
        REP (i, size) {
            sprintf(buffer + 8 * i, "%08x", that.data[i]);
        }
        return out << buffer;
    }
};
const int32_t rolling_hash::prime[size] = { 1000000027, 1000000033, 1000000087, 1000000093 };
int32_t rolling_hash::base[size];
rolling_hash::base_initializer_t rolling_hash::base_initializer;

struct rolling_hash_cumulative_sum {
    rolling_hash_cumulative_sum() = default;
    int size;
    vector<rolling_hash> data;
    vector<array<int32_t, rolling_hash::size> > pow_base;
    rolling_hash_cumulative_sum(string const & s) {
        size = s.length();
        data.resize(size + 1);
        data[0] = rolling_hash();
        REP (i, size) {
            data[i + 1] = data[i];
            data[i + 1].push_back(s[i]);
        }
        pow_base.resize(size + 1);
        fill(ALL(pow_base[0]), 1);
        REP (i, size) {
            REP (j, rolling_hash::size) {
                pow_base[i + 1][j] = pow_base[i][j] *(int64_t) rolling_hash::base[j] % rolling_hash::prime[j];
            }
        }
    }
    rolling_hash get_initial_segment(int r) {
        assert (0 <= r and r <= size);
        return data[r];
    }
    /**
     * @note O(rolling_hash::size)
     */
    rolling_hash get_range(int l, int r) {
        assert (0 <= l and l <= r and r <= size);
        return rolling_hash(data[r]) -= (rolling_hash(data[l]) <<= pow_base[r - l]);
    }
};

/**
 * @brief an adaptor to a segment tree
 * @note slow
 * @note you should use something like cumulative sum
 */
struct rolling_hash_monoid {
    typedef struct { int length; rolling_hash hash; } underlying_type;
    static underlying_type from_char(char c) {
        return { 1, rolling_hash(c) };
    }
    underlying_type unit() const {
        return { 0, rolling_hash() };
    }
    underlying_type append(underlying_type a, underlying_type const & b) const {
        if (a.length == 0) return b;
        if (b.length == 0) return a;
        return { a.length + b.length, (a.hash <<= b.length) += b.hash };
    }
};

constexpr uint64_t prime = 1000000000000037;  // if you didn't shift
constexpr uint64_t prime = 1000000007;
constexpr uint64_t base = 10007;
uint64_t rolling_hash_push(uint64_t hash, int c) {
    return (hash * base + c) % prime;
}
uint64_t rolling_hash_shift(uint64_t hash, int k) {
    uint64_t e = base;
    for (; k; k >>= 1) {
        if (k & 1) hash = hash * e % prime;
        e = e * e % prime;
    }
    return hash;
}
vector<uint64_t> rolling_hash_prepare(const vector<int> & s) {
    vector<uint64_t> hash(s.size() + 1);
    REP (i, s.size()) {
        hash[i + 1] = rolling_hash_push(hash[i], s[i]);
    }
    return hash;
}
uint64_t rolling_hash_range(const vector<uint64_t> & hash, int l, int r) {
    return (hash[r] - rolling_hash_shift(hash[l], r - l) + prime) % prime;
}
uint64_t rolling_hash(const vector<int> & s) {
    uint64_t hash = 0;
    for (int c : s) {
        hash = rolling_hash_push(hash, c);
    }
    return hash;
}
