#!/usr/bin/env python3
import gmpy2

def chinese_remainder_theorem(eqn):
    '''
        eqn = [ (y_0, n_0), ... ] where
            x = y_i mod n_i
    '''
    x = 0
    m = 1
    for y, n in eqn:
        d = gmpy2.gcd(m, n)
        x += (m // d) * (y - x) * gmpy2.invert(m // d, n // d)
        m = gmpy2.lcm(m, n)
    return x % m

def crt(eqn1, eqn2):
    x1, m1 = eqn1
    x2, m2 = eqn2
    d = int(gmpy2.gcd(m1, m2))
    x = x1 + (m1 // d) * (x2 - x1) * int(gmpy2.invert(m1 // d, m2 // d))
    m = int(gmpy2.lcm(m1, m2))
    return x % m, m
