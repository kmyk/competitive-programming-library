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


# :warning: old/palindrome.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/palindrome.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00


* see: <a href="http://snuke.hatenablog.com/entry/2014/12/02/235837">http://snuke.hatenablog.com/entry/2014/12/02/235837</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @return radiuses of odd palindromes
 * @note O(N)
 * @sa http://snuke.hatenablog.com/entry/2014/12/02/235837
 */
template <class RandomAccessIterator>
vector<int> manacher(RandomAccessIterator first, RandomAccessIterator last) {
    int n = distance(first, last);
    vector<int> r(n);
    int i = 0, j = 0;
    while (i < n) {
        while (i - j >= 0 and i + j < n and first[i - j] == first[i + j]) {
            ++ j;
        }
        r[i] = j;
        int k = 1;
        while (i - k >= 0 and i + k < n and k + r[i - k] < j) {
            r[i + k] = r[i - k];
            ++ k;
        }
        i += k;
        j -= k;
    }
    return r;
}

vector<int> odd_palindrome_length(string const & s) {
    int n = s.length();
    vector<int> r = manacher(ALL(s));
    vector<int> l(n);
    REP (i, n) l[i - r[i] + 1] = 2 * r[i] - 1;
    REP (i, n-1) chmax(l[i + 1], l[i] - 2);
    return l;
}
/**
 * @note s must not contain '\xff'
 */
vector<int> even_palindrome_length(string const & s) {
    int n = s.length();
    string t(2 * n + 1, '\xff');
    REP (i, n) t[2 * i + 1] = s[i];
    vector<int> r = manacher(ALL(t));
    vector<int> l(n);
    REP (i, n) if (r[2 * i + 2] >= 3) {
        l[i - r[2 * i + 2] / 2 + 1] = r[2 * i + 2] - 1;
    }
    REP (i, n-1) chmax(l[i + 1], l[i] - 2);
    return l;
}

unittest {
    string x = "abaaababa";
    vector<int> y = { 1, 2, 1, 4, 1, 2, 3, 2, 1 };
    assert (manacher(ALL(x)) == y);
}

struct prepared_manacher {
    vector<int> odd;
    vector<int> even;
    prepared_manacher(string const & s) {
        int n = s.length();
        string t(2 * n + 1, '\xff');
        REP (i, n) t[2 * i + 1] = s[i];
        odd = manacher(ALL(s));
        even = manacher(ALL(t));
    }

    /**
     * @return wheter s[l, r) is a palindrome or not
     */
    bool operator () (int l, int r) const {
        assert (0 <= l and l <= r and r <= odd.size());
        if ((r - l) % 2 == 0) {
            l *= 2;
            r *= 2;
            int m = (l + r) / 2;
            return r - m <= even[m];
        } else {
            int m = (l + r) / 2;
            return r - m <= odd[m];
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/palindrome.inc.cpp"
/**
 * @return radiuses of odd palindromes
 * @note O(N)
 * @sa http://snuke.hatenablog.com/entry/2014/12/02/235837
 */
template <class RandomAccessIterator>
vector<int> manacher(RandomAccessIterator first, RandomAccessIterator last) {
    int n = distance(first, last);
    vector<int> r(n);
    int i = 0, j = 0;
    while (i < n) {
        while (i - j >= 0 and i + j < n and first[i - j] == first[i + j]) {
            ++ j;
        }
        r[i] = j;
        int k = 1;
        while (i - k >= 0 and i + k < n and k + r[i - k] < j) {
            r[i + k] = r[i - k];
            ++ k;
        }
        i += k;
        j -= k;
    }
    return r;
}

vector<int> odd_palindrome_length(string const & s) {
    int n = s.length();
    vector<int> r = manacher(ALL(s));
    vector<int> l(n);
    REP (i, n) l[i - r[i] + 1] = 2 * r[i] - 1;
    REP (i, n-1) chmax(l[i + 1], l[i] - 2);
    return l;
}
/**
 * @note s must not contain '\xff'
 */
vector<int> even_palindrome_length(string const & s) {
    int n = s.length();
    string t(2 * n + 1, '\xff');
    REP (i, n) t[2 * i + 1] = s[i];
    vector<int> r = manacher(ALL(t));
    vector<int> l(n);
    REP (i, n) if (r[2 * i + 2] >= 3) {
        l[i - r[2 * i + 2] / 2 + 1] = r[2 * i + 2] - 1;
    }
    REP (i, n-1) chmax(l[i + 1], l[i] - 2);
    return l;
}

unittest {
    string x = "abaaababa";
    vector<int> y = { 1, 2, 1, 4, 1, 2, 3, 2, 1 };
    assert (manacher(ALL(x)) == y);
}

struct prepared_manacher {
    vector<int> odd;
    vector<int> even;
    prepared_manacher(string const & s) {
        int n = s.length();
        string t(2 * n + 1, '\xff');
        REP (i, n) t[2 * i + 1] = s[i];
        odd = manacher(ALL(s));
        even = manacher(ALL(t));
    }

    /**
     * @return wheter s[l, r) is a palindrome or not
     */
    bool operator () (int l, int r) const {
        assert (0 <= l and l <= r and r <= odd.size());
        if ((r - l) % 2 == 0) {
            l *= 2;
            r *= 2;
            int m = (l + r) / 2;
            return r - m <= even[m];
        } else {
            int m = (l + r) / 2;
            return r - m <= odd[m];
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

