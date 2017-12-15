pair<int, int> extgcd(int a, int b) {
    if (b == 0) return { 1, 0 };
    int na, nb; tie(na, nb) = extgcd(b, a % b);
    return { nb, na - a/b * nb };
}
/**
 * @note x and n must be relatively prime, O(log n)
 */
int modinv(int x, int n) {
    assert (1 <= x and x < n);
    int y = extgcd(x, n).first % n;
    return y >= 0 ? y : y + n;
}
