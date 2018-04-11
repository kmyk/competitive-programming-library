double dot(complex<double> a, complex<double> b) { return real(a * conj(b)); }
double cross(complex<double> a, complex<double> b) { return imag(conj(a) * b); }
int ccw(complex<double> a, complex<double> b, complex<double> c) {
    b -= a;
    c -= a;
    if (cross(b, c) > 0) return +1;  // counter clockwise
    if (cross(b, c) < 0) return -1;  // clockwise
    if (dot(b, c) < 0)   return +2;  // c--a--b on line
    if (abs(b) < abs(c)) return -2;  // a--b--c on line
    return 0;
}
/**
 * @see http://www.prefield.com/algorithm/geometry/convex_hull.html
 */
vector<complex<double> > convex_hull(vector<complex<double> > ps) {
    int n = ps.size();
    int k = 0;
    sort(ps.begin(), ps.end(), [&](complex<double> const a, complex<double> const b) { return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag()); });
    vector<complex<double> > ch(2 * n);
    for (int i = 0; i < n; ch[k ++] = ps[i ++]) {  // lower-hull
        while (k >= 2 and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k ++] = ps[i --]) {  // upper-hull
        while (k >= t and ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) -- k;
    }
    ch.resize(k - 1);
    return ch;
}
