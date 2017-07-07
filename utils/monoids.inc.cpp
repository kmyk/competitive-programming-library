/**
 * @brief an abelian group
 */
struct plus_t {
    typedef int type;
    int unit() const { return 0; }
    int append(int a, int b) const { return a + b; }
    int invert(int a) const { return - a; }
};
template <int mod>
struct modplus_t {
    typedef int type;
    int unit() const { return 0; }
    int append(int a, int b) const { int c = a + b; return c < mod ? c : c - mod; }
    int invert(int a) const { return a ? mod - a : 0; }
};

/**
 * @brief an commutative monoid
 */
struct max_t {
    typedef int underlying_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return max(a, b); }
};
struct min_t {
    typedef int underlying_type;
    int unit() const { return INT_MAX; }
    int append(int a, int b) const { return min(a, b); }
};

struct linear_endomorphism_t { // f(x) = ax + b
    typedef int underlying_type;
    typedef array<int, 2> type;
    array<int, 2> identity() const {
        return array<int, 2>{{ 1, 0 }};
    }
    array<int, 2> compose(array<int, 2> f, array<int, 2> g) const {
        return array<int, 2>{{ f[0] * g[0], f[0] * g[1] + f[1] }};
    }
    int apply(array<int, 2> f, int x) const {
        return f[0] * x + f[1];
    }
};
template <int mod>
struct mod_linear_endomorphism_t {
    typedef int underlying_type;
    typedef array<int, 2> type;
    array<int, 2> identity() const {
        return array<int, 2>{{ 1, 0 }};
    }
    array<int, 2> compose(array<int, 2> f, array<int, 2> g) const {
        int a = f[0] *(ll) g[0] % mod;
        int b = (f[0] *(ll) g[1] + f[1]) % mod;
        return array<int, 2>{{ a, b }};
    }
    int apply(array<int, 2> f, int x) const {
        return (f[0] *(ll) x + f[1]) % mod;
    }
};

struct plus_endomorphism_t {
    typedef int underlying_type;
    typedef int type;
    type identity() const {
        return 0;
    }
    type compose(type a, type b) const {
        return a + b;
    }
    underlying_type apply(type a, underlying_type b) const {
        return a + b;
    }
};
