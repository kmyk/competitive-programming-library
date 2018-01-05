/**
 * @brief a rolling hash
 * @note 4 primes for modulo and and random bases
 * @see http://hos.ac/blog/#blog0003
 */
class rolling_hash {
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
    /**
     * @note O(size log width)
     */
    rolling_hash & operator <<= (int width) {
        REP (i, size) {
            data[i] = data[i] *(int64_t) powmod(base[i], width, prime[i]) % prime[i];
        }
        return *this;
    }
    rolling_hash operator << (int width) const {
        return rolling_hash(*this) <<= width;
    }
    bool operator == (rolling_hash const & other) const {
        return equal(ALL(data), other.data.begin());
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
