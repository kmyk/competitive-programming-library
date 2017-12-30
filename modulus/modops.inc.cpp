inline int modadd<int mod>(int a, int b) {
    int c = a + b;
    return c < mod ? c : c - mod;
}
inline int modsub<int mod>(int a, int b) {
    int c = a - b;
    return c >= 0 ? c : c + mod;
}
inline int modmul<int mod>(int a, int b) {
    return a *(ll) b % mod;
}
