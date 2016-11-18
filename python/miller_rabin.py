#!/usr/bin/env python3

def is_prime(n, k=20): # miller-rabin primality test
    if n == 2:
        return True
    if n == 1 or n % 2 == 0:
        return False
    d = n - 1
    while d % 2 == 0:
        d //= 2
    for _ in range(k):
        a = random.randint(1,n-2)
        t = d
        y = pow(a,t,n)
        while t != n-1 and y != 1 and y != n-1:
            y = (y * y) % n
            t <<= 1
        if y != n-1 and t & 1 == 0:
            return False
    return True
