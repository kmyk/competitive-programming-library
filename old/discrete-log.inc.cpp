uint32_t powmod(uint32_t g, uint32_t x, uint32_t p) {
    uint32_t y = 1;
    for (; x; x >>= 1) {
        if (x & 1) y = (uint64_t)y * g % p;
        g = (uint64_t)g * g % p;
    }
    return y;
}

uint32_t modinv(uint32_t g, uint32_t p) {
    return powmod(g, p - 2, p);  // p must be a prime
}

/**
 * @description find the smallest x >= 0 s.t. g^x = y mod p
 * @note O(sqrt(p))
 * @note meet-in-the-middle; let x = a sqrt(p) + b
 */
uint32_t baby_step_giant_step(uint32_t g, uint32_t y, uint32_t p) {
    uint32_t sqrt_p = sqrt(p);

    unordered_map<uint32_t, int> baby;
    uint32_t gb = 1;
    REP (b, sqrt_p + 3) {
        baby[gb] = b;
        gb = (uint64_t)gb * g % p;
    }

    uint32_t g_sqrt_p_inv = modinv(powmod(g, sqrt_p, p), p);
    uint32_t giant = y;
    REP (a, sqrt_p + 3) {
        if (baby.count(giant)) {
            int b = baby[giant];
            uint32_t x = a * sqrt_p + b;
            return x % p;
        }
        giant = (uint64_t)giant * g_sqrt_p_inv % p;
    }
    return -1;
}

unittest {
    assert (baby_step_giant_step( 3, powmod( 3,  0,  17),  17) ==  0);
    assert (baby_step_giant_step( 3, powmod( 3, 12,  17),  17) == 12);
    assert (baby_step_giant_step(12, powmod(12, 17, 101), 101) == 17);
}
