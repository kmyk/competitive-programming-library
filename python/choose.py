import array
def get_fact(n, mod):
    fact = array.array('l')
    fact.append(1)
    for i in range(n):
        fact.append((i + 1) * fact[-1] % mod)
    return fact
def choose(n, r, mod, fact=None):
    return fact[n] * pow(fact[n - r] * fact[r], mod - 2, mod) % mod
