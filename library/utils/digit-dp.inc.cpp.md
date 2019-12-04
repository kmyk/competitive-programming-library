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


# :warning: utils/digit-dp.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
```cpp
// http://yukicoder.me/problems/no/260
// strmodin(s, a, b, m)[i][j] = the number of digits t in mod m  for  t \le s, i = t \bmod \prod a and t contains digits j \subset b
vector<vector<ll> > strmodin(string const & s, int a, vector<int> const & b, ll m) {
    int pow_b = 1 << b.size();
    array<int,10> table = {};
    repeat (d,10) {
        auto it = whole(find, b, d);
        if (it != b.end()) table[d] |= 1 << (it - b.begin());
    }
    auto cur = vectors(a, pow_b, ll());
    auto prv = vectors(a, pow_b, ll());
    int bound_i = 0, bound_j = 0;
    for (char c : s) {
        c -= '0';
        cur.swap(prv);
        repeat (d, c) cur[(bound_i * 10 + d) % a][bound_j | table[d]] += 1;
        bound_i = (bound_i * 10 + c) % a;
        bound_j |= table[c];
        repeat (i,a) repeat (j,pow_b) {
            repeat (d,10) {
                ll & it = cur[(i * 10 + d) % a][j | table[d]];
                it = (it + prv[i][j]) % m;
            }
            prv[i][j] = 0;
        }
    }
    cur[bound_i][bound_j] += 1;
    cur[bound_i][bound_j] %= m;
    return cur;
}

```

[Back to top page](../../index.html)

