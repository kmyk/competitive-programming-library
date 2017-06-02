template <typename T>
void fft_inplace(vector<complex<T> > & f, int dir) {
    int n = f.size();
    assert (n == pow(2,log2(n)));
    if (n == 1) return;
    vector<complex<T> > a(n/2), b(n/2);
    repeat (i,n/2) {
        a[i] = f[2*i];
        b[i] = f[2*i+1];
    }
    fft_inplace(a, dir);
    fft_inplace(b, dir);
    const complex<T> zeta = polar<T>(1, dir*2*M_PI/n);
    complex<T> pow_zeta = 1;
    repeat (i,n) {
        f[i] = a[i % (n/2)] + pow_zeta * b[i % (n/2)];
        pow_zeta *= zeta;
    }
}
template <typename T>
vector<complex<T> > fft(vector<complex<T> > f) {
    f.resize(pow(2,ceil(log2(f.size()))));
    fft_inplace(f, +1);
    return f;
}
template <typename T>
vector<complex<T> > ifft(vector<complex<T> > f) {
    f.resize(pow(2,ceil(log2(f.size()))));
    fft_inplace(f, -1);
    return f;
}
template <typename T, typename R = double>
vector<T> convolution(vector<T> const & a, vector<T> const & b) {
    int m = a.size() + b.size() - 1;
    int n = pow(2,ceil(log2(m)));
    vector<complex<R> > x(n), y(n);
    copy(a.begin(), a.end(), x.begin());
    copy(b.begin(), b.end(), y.begin());
    fft_inplace(x, +1);
    fft_inplace(y, +1);
    vector<complex<R> > z(n);
    repeat (i, n) z[i] = x[i] * y[i];
    fft_inplace(z, -1);
    vector<T> c(m);
    repeat (i, m) c[i] = round(z[i].real() / n);
    return c;
}
