#!/usr/bin/env python3
def binsearch(p, l, r): # (l,r], return the smallest n which p holds
    while l+1 != r:
        m = (l + r) // 2
        if p(m):
            r = m
        else:
            l = m
    return r
