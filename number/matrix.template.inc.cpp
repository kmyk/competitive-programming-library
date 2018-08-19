template <typename T, size_t H, size_t W>
using matrix = array<array<T, W>, H>;

template <typename T, size_t A, size_t B, size_t C>
matrix<T, A, C> operator * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {
    matrix<T, A, C> c = {};
    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];
    return c;
}
template <typename T, size_t H, size_t W>
array<T, H> operator * (matrix<T, H, W> const & a, array<T, W> const & b) {
    array<T, H> c = {};
    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> operator + (matrix<T, H, W> const & a, matrix<T, H, W> const & b) {
    matrix<T, H, W> c;
    REP (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];
    return c;
}

template <typename T, size_t N>
array<T, N> operator + (array<T, N> const & a, array<T, N> const & b) {
    array<T, N> c;
    REP (i, N) c[i] = a[i] + b[i];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> matrix_zero() {
    return {};
}

template <typename T, size_t N>
matrix<T, N, N> matrix_unit() {
    matrix<T, N, N> a = {};
    REP (i, N) a[i][i] = 1;
    return a;
}

template <typename T, size_t N>
matrix<T, N, N> matrix_pow(matrix<T, N, N> x, ll k) {
    matrix<T, N, N> y = matrix_unit<T, N>();
    for (ll i = 1; i <= k; i <<= 1) {
        if (k & i) y = y * x;
        x = x * x;
    }
    return y;
}
