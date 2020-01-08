/**
 * @sa https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/
 */

// for a set z, list y \subseteq z, ascending order
for (int y = 0; ; y = (y - z) & z) {
    ...
    if (y == z) break;
}

// for a set z, list y \subseteq z, descending order
for (int y = z; ; y = (y - 1) & z) {
    ...
    if (y == 0) break;
}

// for a set x and an ordinal n, list y s.t. x \subseteq y \subseteq n
or (int y = x; y < (1 << n); y = (y + 1) | x) {
    ...
}

// for an ordinal n and integer k, list x \subseteq n s.t. \|x\| = k
for (int x = (1 << k) - 1; x < (1 << n); ) {
    ...
    int t = x | (x - 1);
    x = (t + 1) | (((~ t & - ~ t) - 1) >> (__builtin_ctz(x) + 1));
}
