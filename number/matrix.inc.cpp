vector<vector<ll> > operator * (vector<vector<ll> > const & a, vector<vector<ll> > const & b) {
    int n = a.size();
    vector<vector<ll> > c = vectors(n, n, ll());
    repeat (y,n) repeat (z,n) repeat (x,n) c[y][x] = (c[y][x] + a[y][z] * b[z][x] % mod) % mod;
    return c;
}
vector<ll> operator * (vector<vector<ll> > const & a, vector<ll> const & b) {
    int n = a.size();
    vector<ll> c(n);
    repeat (y,n) repeat (z,n) c[y] = (c[y] + a[y][z] * b[z] % mod) % mod;
    return c;
}
vector<vector<ll> > unit_matrix(int n) {
    vector<vector<ll> > e = vectors(n, n, ll());
    repeat (i,n) e[i][i] = 1;
    return e;
}
vector<vector<ll> > zero_matrix(int n) {
    vector<vector<ll> > o = vectors(n, n, ll());
    return o;
}

template <typename T>
T determinant(vector<vector<T> > a) {
    int n = a.size();
    repeat (z,n) { // make A upper trianglar
        if (a[z][z] == 0) { // swap rows to avoid zero-division
            int x;
            for (x = z+1; x < n; ++ x) {
                if (a[x][z] != 0) {
                    a[z].swap(a[x]);
                    break;
                }
            }
            if (x == n) return 0; // A is singular
        }
        repeat_from (y,z+1,n) {
            repeat_from (x,z+1,n) {
                a[y][x] -= a[y][z] * a[z][x] / a[z][z]; // elim
            }
            a[y][z] = 0;
        }
    }
    T acc = 1;
    repeat (z,n) acc = acc * a[z][z]; // product of the diagonal elems
    return acc;
}

template <typename T>
vector<T> gaussian_elimination(vector<vector<T> > f, vector<T> x) {
    int n = x.size();
    repeat (y,n) {
        int pivot = y;
        while (pivot < n and abs(f[pivot][y]) < eps) ++ pivot;
        assert (pivot < n);
        swap(f[y], f[pivot]);
        x[y] /= f[y][y];
        repeat_from (x,y+1,n) f[y][x] /= f[y][y];
        f[y][y] = 1;
        repeat (ny,n) if (ny != y) {
            x[ny] -= f[ny][y] * x[y];
            repeat_from (x,y+1,n) f[ny][x] -= f[ny][y] * f[y][x];
            f[ny][y] = 0;
        }
    }
    return x;
}
