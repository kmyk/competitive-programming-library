<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: number/matrix.inc.cpp
* category: number


[Back to top page](../../index.html)



## Code
```cpp
template <typename T>
vector<vector<T> > operator * (vector<vector<T> > const & a, vector<vector<T> > const & b) {
    int n = a.size();
    vector<vector<T> > c = vectors(n, n, T());
    REP (y, n) REP (z, n) REP (x, n) c[y][x] += a[y][z] * b[z][x];
    return c;
}
template <typename T>
vector<T> operator * (vector<vector<T> > const & a, vector<T> const & b) {
    int n = a.size();
    vector<T> c(n);
    REP (y, n) REP (z, n) c[y] += a[y][z] * b[z];
    return c;
}
template <typename T>
vector<vector<T> > unit_matrix(int n) {
    vector<vector<T> > e = vectors(n, n, T());
    REP (i, n) e[i][i] = 1;
    return e;
}
template <typename T>
vector<vector<T> > zero_matrix(int n) {
    vector<vector<T> > o = vectors(n, n, T());
    return o;
}

template <typename T>
T determinant(vector<vector<T> > a) {
    int n = a.size();
    REP (z, n) { // make A upper trianglar
        if (a[z][z] == 0) { // swap rows to avoid zero-division
            int x = z + 1;
            for (; x < n; ++ x) {
                if (a[x][z] != 0) {
                    a[z].swap(a[x]);
                    break;
                }
            }
            if (x == n) return 0; // A is singular
        }
        REP3 (y, z + 1, n) {
            T k = a[y][z] / a[z][z];
            REP3 (x, z + 1, n) {
                a[y][x] -= k * a[z][x]; // elim
            }
            a[y][z] = 0;
        }
    }
    T acc = 1;
    REP (z, n) acc *= a[z][z]; // product of the diagonal elems
    return acc;
}

template <class T>
vector<vector<T> > small_matrix(vector<vector<T> > const & a) {
    int n = a.size();
    assert (n >= 1);
    auto b = a;
    b.resize(n - 1);
    REP (y, n - 1) {
        b[y].resize(n - 1);
    }
    return b;
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
    auto z = unit_matrix<T>(n);
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

```

[Back to top page](../../index.html)

