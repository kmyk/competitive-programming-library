vector<vector<ll> > operator * (vector<vector<ll> > const & p, vector<vector<ll> > const & q) {
    int n = p.size();
    vector<vector<ll> > r(n, vector<ll>(n));
    repeat (y,n) {
        repeat (z,n) {
            repeat (x,n) {
                r[y][x] += p[y][z] * q[z][x] % mod;
                r[y][x] %= mod;
            }
        }
    }
    return r;
}
vector<ll> operator * (vector<vector<ll> > const & p, vector<ll> const & q) {
    int n = p.size();
    vector<ll> r(n);
    repeat (y,n) {
        repeat (z,n) {
            r[y] += p[y][z] * q[z] % mod;
            r[y] %= mod;
        }
    }
    return r;
}
vector<vector<ll> > unit_matrix(int n) {
    vector<vector<ll> > e(n, vector<ll>(n));
    repeat (i,n) e[i][i] = 1;
    return e;
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
