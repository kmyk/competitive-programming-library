#!/usr/bin/env python3
def binsearch(l, r, pred): # [l, r)
    assert l < r
    l -= 1
    while r - l > 1:
        m = (l + r) // 2
        if pred(m):
            r = m
        else:
            l = m
    return r

def binsearch_float(l, r, pred): # [l, r)
    assert l < r
    for _ in range(100):
        m = (l + r) / 2
        if pred(m):
            r = m
        else:
            l = m
    return r
