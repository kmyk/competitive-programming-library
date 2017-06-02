// initial s = (1 << k) - 1;
int next_subset(int & s, int n) {
    int x = s & - s;
    int y = s + x;
    s = ((s & ~y) / x >> 1) | y;
    return s < 1 << n;
}
