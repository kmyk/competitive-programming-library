template <typename T>
T gcd(T a, T b) {
    if (b < a) swap(a,b);
    while (a) {
        T c = a;
        a = b % c;
        b = c;
    }
    return b;
}
template <typename T>
T lcm(T a, T b) {
    return (a * b) / gcd(a,b);
}
