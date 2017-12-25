/**
 * @note if arguments are negative, the result may be negative
 */
template <typename T>
T gcd(T a, T b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

unittest {
    assert (gcd(0, 0) == 0);
    assert (gcd(42, 0) == 42);
    assert (gcd(0, 42) == 42);
    assert (gcd(3, -12) == 3);
    assert (gcd(-3, 12) == -3);
    assert (gcd(7, -12) == -1);
    assert (gcd(-7, 12) == 1);
    assert (gcd(-9, -12) == -3);
    assert (gcd(-1, -1) == -1);
}
