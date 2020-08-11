---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: python/matrix-modinv.py

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#23eeeb4347bdd26bfc6b7ee9a3b755dd">python</a>
* <a href="{{ site.github.repository_url }}/blob/master/python/matrix-modinv.py">View this file on GitHub</a>
    - Last commit date: 2017-05-27 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

