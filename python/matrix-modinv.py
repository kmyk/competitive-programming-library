def modinv(a_f, m):
    f = np.copy(a_f)
    assert isinstance(f, np.ndarray)
    assert isinstance(m, int)
    n = a_f.shape[0]
    g = np.identity(n, dtype=int)
    for i in range(n):
        for j in range(i+1,n):
            try:
                gmpy2.invert(int(f[j,i]), m)
                f[i], f[j] = np.copy(f[j]), np.copy(f[i])
                g[i], g[j] = np.copy(g[j]), np.copy(g[i])
                break
            except:
                pass
        inv = int(gmpy2.invert(int(f[i,i]), m))
        f[i] = f[i] * inv % m
        g[i] = g[i] * inv % m
        for j in range(n):
            if j != i:
                p = f[j,i]
                f[j] = (f[j] - f[i] * p) % m
                g[j] = (g[j] - g[i] * p) % m
    assert np.array_equal(f, np.identity(n, dtype=int))
    assert np.array_equal(a_f.dot(g) % m, np.identity(n, dtype=int))
    assert isinstance(g, np.ndarray)
    return g
