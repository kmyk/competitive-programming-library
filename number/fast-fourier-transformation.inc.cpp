/**
 * @note O(N log N)
 */
template <typename T>
void fft_inplace(vector<complex<T> > & f, int dir) {
    int n = f.size();
    assert(n == pow(2, log2(n)));
    R theta = dir * 2 * M_PI / n;
    for (int m = n; m >= 2; m >>= 1) {
        REP (i, m / 2) {
            complex<R> w = polar<R>(1, i * theta);
            for (int j = i; j < n; j += m) {
                int k = j + m / 2;
                complex<R> x = f[j] - f[k];
                f[j] += f[k];
                f[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    REP3 (j, 1, n - 1) {
        for (int k = n >> 1; k > (i ^= k); ) k >>= 1;
        if (j < i) {
            swap(f[i], f[j]);
        }
    }
}
template <typename T>
vector<complex<T> > fft(vector<complex<T> > f) {
    f.resize(pow(2, ceil(log2(f.size()))));
    fft_inplace(f, +1);
    return f;
}
template <typename T>
vector<complex<T> > ifft(vector<complex<T> > f) {
    f.resize(pow(2, ceil(log2(f.size()))));
    fft_inplace(f, -1);
    return f;
}

/**
 * @brief the convolution
 * @note O(N log N)
 * @note (f \ast g)(i) = \sum_{0 \le j \lt i + 1} f(j) g(i - j)
 */
template <typename T, typename R = double>
vector<T> convolution(vector<T> const & a, vector<T> const & b) {
    int m = a.size() + b.size() - 1;
    int n = pow(2, ceil(log2(m)));
    vector<complex<R> > x(n), y(n);
    copy(a.begin(), a.end(), x.begin());
    copy(b.begin(), b.end(), y.begin());
    fft_inplace(x, +1);
    fft_inplace(y, +1);
    vector<complex<R> > z(n);
    REP (i, n) z[i] = x[i] * y[i];
    fft_inplace(z, -1);
    vector<T> c(m);
    REP (i, m) c[i] = is_integral<T>::value ? round(z[i].real() / n) : z[i].real() / n;
    return c;
}
unittest {
    vector<int> f { 1, 2, 3 };
    vector<int> g { 10, 20, 30 };
    vector<int> h = convolution(f, g);
    assert (h[0] == 1 * 10);
    assert (h[1] == 1 * 20 + 2 * 10);
    assert (h[2] == 1 * 30 + 2 * 20 + 3 * 10);
    assert (h[3] ==          2 * 30 + 3 * 20);
    assert (h[4] ==                   3 * 30);
}
