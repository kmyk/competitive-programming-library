template <size_t N>
struct modint {
    typedef value_type long long;
    value_type get;
    modint() : get(0) {}
    modint(value_type a) : get((a % N + N) % N) {}
    operator value_type () const { return this->get; }
};

template <size_t N>
modint<N> operator + (modint<N> a, modint<N> b) {
    return (a.get + b.get) % N;
}
template <size_t N>
modint<N> operator * (modint<N> a, modint<N> b) {
    return { a.get * b.get % N };
}
template <size_t N>
modint<N> operator - (modint<N> a) {
    return { (N - a.get) % N };
}
template <size_t N>
modint<N> operator - (modint<N> a, modint<N> b) {
    return { (a.get - b.get + N) % N };
}
template <size_t N>
modint<N> inverse(modint<N> a) {
    return { inv(a.get, N) };
}
template <size_t N>
modint<N> operator / (modint<N> a, modint<N> b) {
    return a * inverse(b);
}

template <size_t N>
bool operator == (modint<N> a, modint<N> b) {
    return a.get == b.get;
}
template <size_t N>
bool operator != (modint<N> a, modint<N> b) {
    return a.get != b.get;
}
template <size_t N>
bool operator < (modint<N> a, modint<N> b) {
    return a.get < b.get;
}
template <size_t N>
bool operator <= (modint<N> a, modint<N> b) {
    return a.get <= b.get;
}
template <size_t N>
bool operator > (modint<N> a, modint<N> b) {
    return a.get > b.get;
}
template <size_t N>
bool operator >= (modint<N> a, modint<N> b) {
    return a.get >= b.get;
}

template <size_t N>
istream & operator >> (istream & in, modint<N> & a) {
    long long n; in >> n;
    if (in) a = n;
    return in;
}
template <size_t N>
ostream & operator << (ostream & out, modint<N> a) {
    return out << a.get;
}
