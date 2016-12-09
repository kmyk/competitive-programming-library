#!/usr/bin/env python3
import gmpy2
def chinese_remainder_theorem(eqn):
    x = m = 1
    for a, n in eqn:
        x += m * (a - x) * gmpy2.invert(m, n)
        m *= n
    return x % m
