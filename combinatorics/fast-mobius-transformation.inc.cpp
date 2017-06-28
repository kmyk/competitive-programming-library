/**
 * @brief fast zeta transformation
 * @note for f : 2^n \to R; \zeta f(Y) = \sum\_{X \subseteq Y} f(X)
 * @note O(n2^n)
 * @param T is a commutative semigroup
 */
template <typename T>
vector<T> fast_zeta_transform(vector<T> f) {
    int pow_n = f.size();
    for (int i = 1; i < pow_n; i <<= 1) {
        repeat (s, pow_n) {
            if (s & i) {
                f[s] += f[s ^ i];
            }
        }
    }
    return f;
}

/**
 * @brief fast mobius transformation
 * @note for f : 2^n \to R; \mu f(Y) = \sum\_{X \subseteq Y} (-1)^{\|Y \setminues X\|} f(X)
 * @note O(n2^n)
 * @see http://pekempey.hatenablog.com/entry/2016/10/30/205852
 * @param T is a commutative group
 */
template <typename T>
vector<T> fast_mobius_transform(vector<T> f) {
    int pow_n = f.size();
    for (int i = 1; i < pow_n; i <<= 1) {
        repeat (s, pow_n) {
            if (s & i) {
                f[s] -= f[s ^ i];
            }
        }
    }
    return f;
}
