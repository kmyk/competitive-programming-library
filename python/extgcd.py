def extgcd(a, b):
    if b == 0:
        return 1, 0
    else:
        na, nb = extgcd(b, a % b)
        return nb, na - a//b * nb
def modinv(a, n):
    return extgcd(a, n)[0] % n
