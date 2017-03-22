template <typename T, size_t H, size_t W>
using matrix = array<array<T,W>,H>;

template <typename T, size_t A, size_t B, size_t C>
matrix<T,A,C> operator * (matrix<T,A,B> const & a, matrix<T,B,C> const & b) {
    matrix<T,A,C> c = {};
    repeat (y,A) {
        repeat (z,B) {
            repeat (x,C) {
                c[y][x] += a[y][z] * b[z][x];
                c[y][x] %= mod;
            }
        }
    }
    return c;
}
template <typename T, size_t H, size_t W>
array<T,H> operator * (matrix<T,H,W> const & a, array<T,W> const & b) {
    array<T,H> c = {};
    repeat (y,H) {
        repeat (z,W) {
            c[y] += a[y][z] * b[z];
            c[y] %= mod;
        }
    }
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T,H,W> operator + (matrix<T,H,W> const & a, matrix<T,H,W> const & b) {
    matrix<T,H,W> c;
    repeat (y,H) {
        repeat (x,W) {
            c[y][x] = a[y][x] + b[y][x];
            c[y][x] %= mod;
        }
    }
    return c;
}

template <typename T, size_t N>
array<T,N> operator + (array<T,N> const & a, array<T,N> const & b) {
    array<T,N> c;
    repeat (i,N) {
        c[i] = a[i] + b[i];
        c[i] %= mod;
    }
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T,H,W> matrix_zero() { return {}; }
template <typename T, size_t N>
matrix<T,N,N> matrix_unit() { matrix<T,N,N> a = {}; repeat (i,N) a[i][i] = 1; return a; }
