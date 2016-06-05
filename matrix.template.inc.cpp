template <typename T, size_t H, size_t W>
using matrix = array<array<T,W>,H>;
template <typename T, size_t A, size_t B, size_t C>
matrix<T,A,C> operator * (matrix<T,A,B> const & p, matrix<T,B,C> const & q) {
    matrix<T,A,C> r = {};
    repeat (y,A) {
        repeat (z,B) {
            repeat (x,C) {
                r[y][x] += p[y][z] * q[z][x];
                r[y][x] %= mod;
            }
        }
    }
    return r;
}
template <typename T, size_t A, size_t B>
array<T,A> operator * (matrix<T,A,B> const & p, array<T,B> const & q) {
    array<T,A> r = {};
    repeat (y,A) {
        repeat (z,B) {
            r[y] += p[y][z] * q[z];
            r[y] %= mod;
        }
    }
    return r;
}
template <typename T, size_t H, size_t W>
matrix<T,H,W> matrix_zero() { return {}; }
template <typename T, size_t N>
matrix<T,N,N> matrix_unit() { matrix<T,N,N> a = {}; repeat (i,N) a[i][i] = 1; return a; }
