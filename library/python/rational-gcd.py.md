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


# :warning: python/rational-gcd.py

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#23eeeb4347bdd26bfc6b7ee9a3b755dd">python</a>
* <a href="{{ site.github.repository_url }}/blob/master/python/rational-gcd.py">View this file on GitHub</a>
    - Last commit date: 2016-12-10 07:34:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

