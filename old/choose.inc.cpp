double choose(int n, int r) {
    double acc = 1;
    REP (i, r) {
        acc *= n - i;
        acc /= i + 1;
    }
    return acc;
}
