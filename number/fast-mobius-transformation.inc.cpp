/**
 * @brief (upward) fast zeta transformation
 * @note for f : 2^n \to R; \zeta f(X) = \sum\_{X \subseteq Y} f(Y)
 * @note not verified
 */
template <typename T>
vector<T> upward_fast_zeta_transform(vector<T> f) {
    int pow_n = f.size();
    for (int i = 1; i < pow_n; i <<= 1) {
        REP (s, pow_n) {
            if (not (s & i)) {
                f[s] += f[s ^ i];
            }
        }
    }
    return f;
}

/**
 * @brief (downward) fast zeta transformation
 * @note for f : 2^n \to R; \zeta f(Y) = \sum\_{X \subseteq Y} f(X)
 * @note O(n 2^n)
 * @param T is a commutative semigroup
 */
template <typename T>
vector<T> downward_fast_zeta_transform(vector<T> f) {
    int pow_n = f.size();
    for (int i = 1; i < pow_n; i <<= 1) {
        REP (s, pow_n) {
            if (s & i) {
                f[s] += f[s ^ i];
            }
        }
    }
    return f;
}

/**
 * @brief (upward) fast mobius transformation
 * @note for f : 2^n \to R; \mu f(X) = \sum\_{X \subseteq Y} (-1)^{\|Y \setminues X\|} f(Y)
 * @note not verified
 */
template <typename T>
vector<T> upward_fast_mobius_transform(vector<T> f) {
    int pow_n = f.size();
    for (int i = 1; i < pow_n; i <<= 1) {
        REP (s, pow_n) {
            if (not (s & i)) {
                f[s] -= f[s ^ i];
            }
        }
    }
    return f;
}

/**
 * @brief (downward) fast mobius transformation
 * @note for f : 2^n \to R; \mu f(Y) = \sum\_{X \subseteq Y} (-1)^{\|Y \setminues X\|} f(X)
 * @note O(n 2^n)
 * @note related to inclusion-exclusion principle
 * @note inverse of (downward) fast zeta transformation
 * @see http://pekempey.hatenablog.com/entry/2016/10/30/205852
 * @param T is a commutative group
 */
template <typename T>
vector<T> downward_fast_mobius_transform(vector<T> f) {
    int pow_n = f.size();
    for (int i = 1; i < pow_n; i <<= 1) {
        REP (s, pow_n) {
            if (s & i) {
                f[s] -= f[s ^ i];
            }
        }
    }
    return f;
}
