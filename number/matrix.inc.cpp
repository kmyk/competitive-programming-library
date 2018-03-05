vector<vector<ll> > operator * (vector<vector<ll> > const & a, vector<vector<ll> > const & b) {
    int n = a.size();
    vector<vector<ll> > c = vectors(n, n, ll());
    REP (y, n) REP (z, n) REP (x, n) c[y][x] = (c[y][x] + a[y][z] * b[z][x] % mod) % mod;
    return c;
}
vector<ll> operator * (vector<vector<ll> > const & a, vector<ll> const & b) {
    int n = a.size();
    vector<ll> c(n);
    REP (y, n) REP (z, n) c[y] = (c[y] + a[y][z] * b[z] % mod) % mod;
    return c;
}
vector<vector<ll> > unit_matrix(int n) {
    vector<vector<ll> > e = vectors(n, n, ll());
    REP (i, n) e[i][i] = 1;
    return e;
}
vector<vector<ll> > zero_matrix(int n) {
    vector<vector<ll> > o = vectors(n, n, ll());
    return o;
}

template <typename T>
T determinant(vector<vector<T> > a) {
    int n = a.size();
    REP (z,n) { // make A upper trianglar
        if (a[z][z] == 0) { // swap rows to avoid zero-division
            int x;
            for (x = z + 1; x < n; ++ x) {
                if (a[x][z] != 0) {
                    a[z].swap(a[x]);
                    break;
                }
            }
            if (x == n) return 0; // A is singular
        }
        REP3 (y, z + 1, n) {
            REP3 (x, z + 1, n) {
                a[y][x] -= a[y][z] * a[z][x] / a[z][z]; // elim
            }
            a[y][z] = 0;
        }
    }
    T acc = 1;
    REP (z, n) acc = acc * a[z][z]; // product of the diagonal elems
    return acc;
}

template <typename T>
vector<T> gaussian_elimination(vector<vector<T> > f, vector<T> x) {
    int n = x.size();
    REP (y, n) {
        int pivot = y;
        while (pivot < n and abs(f[pivot][y]) < eps) ++ pivot;
        assert (pivot < n);
        swap(f[y], f[pivot]);
        x[y] /= f[y][y];
        REP3 (x, y + 1, n) f[y][x] /= f[y][y];
        f[y][y] = 1;
        REP (ny, n) if (ny != y) {
            x[ny] -= f[ny][y] * x[y];
            REP3 (x, y + 1, n) f[ny][x] -= f[ny][y] * f[y][x];
            f[ny][y] = 0;
        }
    }
    return x;
}

constexpr double eps = 1e-8;
template <typename T>
vector<vector<T> > inverse_matrix(vector<vector<T> > f) {
    int n = f.size();
    vector<vector<T> > g = unit_matrix<T>(n);
    REP (y, n) {
        int pivot = y;
        while (pivot < n and abs(f[pivot][y]) < eps) ++ pivot;
        assert (pivot < n);
        swap(f[y], f[pivot]);
        REP (x, n) g[y][x] /= f[y][y];
        REP3 (x, y + 1, n) f[y][x] /= f[y][y];
        f[y][y] = 1;
        REP (ny, n) if (ny != y) {
            REP (x, n) g[ny][x] -= f[ny][y] * g[y][x];
            REP3 (x, y + 1, n) f[ny][x] -= f[ny][y] * f[y][x];
            f[ny][y] = 0;
        }
    }
    return g;
}
unittest {
    vector<vector<double> > f { { 1, 2 }, { 3, 4 } };
    auto g = f * inverse_matrix(f);
    assert (abs(g[0][0] - 1) < eps);
    assert (abs(g[0][1]    ) < eps);
    assert (abs(g[1][0]    ) < eps);
    assert (abs(g[1][1] - 1) < eps);
}

template <typename T>
vector<vector<T> > powmat(vector<vector<T> > x, ll y) {
    int n = x.size();
    auto z = unit_matrix(n);
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x;
        x = x * x;
    }
    return z;
}

template <typename T>
vector<vector<T> > concat_matrix_vector(vector<vector<T> > const & f, vector<T> const & x) {
    int h = f.size();
    int w = f.fornt().size();
    vector<vector<T> > fx(h);
    REP (y, h) {
        fx[y].resize(w + 1);
        copy(whole(f[y]), fx[y].begin());
        fx[y][w] = x[y];
    }
    return fx;
}
