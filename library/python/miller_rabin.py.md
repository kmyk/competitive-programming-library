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


# :warning: python/miller_rabin.py

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#23eeeb4347bdd26bfc6b7ee9a3b755dd">python</a>
* <a href="{{ site.github.repository_url }}/blob/master/python/miller_rabin.py">View this file on GitHub</a>
    - Last commit date: 2016-11-18 22:19:02+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

