from fractions import Fraction
import math
def lcm(a, b):
    return a * b // math.gcd(a, b)

# https://kimiyuki.net/blog/2016/06/08/yuki-356/
def qlcm(p, q):
    a = p.numerator * q.denominator
    b = p.denominator * q.numerator
    c = p.denominator * q.denominator
    return Fraction(lcm(a, b), c)
def qgcd(p, q):
    return p * q / qlcm(p, q)
