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


# :warning: data_structure/segment-tree-2d.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment-tree-2d.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-09 01:50:43 +0900




## Code

{% raw %}
```cpp
/**
 * @note O(h * w) space
 */
template <class CommutativeMonoid>
struct segment_tree_2d {
    typedef typename CommutativeMonoid::value_type value_type;
    int h1, w1;
    int h, w;
    vector<value_type> data;
    CommutativeMonoid mon;
    segment_tree_2d() = default;
    segment_tree_2d(int h_, int w_, value_type initial_value = CommutativeMonoid().unit(), CommutativeMonoid const & mon_ = CommutativeMonoid())
            : h1(h_), w1(w_), mon(mon_) {
        h = pow(2, ceil(log2(h_)));
        w = pow(2, ceil(log2(w_)));
        data.resize((2 * h - 1) * (2 * w - 1), mon.unit());
        REP_R (y, h) REP_R (x, w) {
            if (y < h - 1) {
                at(y, x) = mon.append(
                    at(2 * y + 1, x),
                    at(2 * y + 2, x));
            } else if (x < w - 1) {
                at(y, x) = mon.append(
                    at(y, 2 * x + 1),
                    at(y, 2 * x + 2));
            } else if (y < h - 1 + h_ and x < w - 1 + w_) {
                at(y, x) = initial_value;
            }
        }
    }
    inline value_type & at(int y, int x) {
        return data[y * (2 * w - 1) + x];
    }
    inline value_type const & at(int y, int x) const {
        return data[y * (2 * w - 1) + x];
    }
    /**
     * @note O(log h * log w)
     */
    void point_set(int y, int x, value_type value) {
        assert (0 <= y and y < h1 and 0 <= x and x < w1);
        for (int i = y + h; i > 0; i /= 2) {  // 1-based
            for (int j = x + w; j > 0; j /= 2) {  // 1-based
                if (i >= h and j >= w) {
                    at(i - 1, j - 1) = value;
                } else if (j >= w) {
                    at(i - 1, j - 1) = mon.append(
                        at(2 * i - 1, j - 1),
                        at(2 * i,     j - 1));
                } else {
                    at(i - 1, j - 1) = mon.append(
                        at(i - 1, 2 * j - 1),
                        at(i - 1, 2 * j));
                }
            }
        }
    }
    /**
     * @note O(log h * log w)
     */
    value_type area_concat(int ly, int lx, int ry, int rx) const {
        assert (0 <= ly and ly <= ry and ry <= h1);
        assert (0 <= lx and lx <= rx and rx <= w1);
        return area_concat(0, 0, 0, 0, h, w, false, ly, lx, ry, rx);
    }
    value_type area_concat(int i, int j, int ily, int jlx, int iry, int jrx, bool p, int ly, int lx, int ry, int rx) const {
        if (iry <= ly or ry <= ily or jrx <= lx or rx <= jlx) {
            return mon.unit();
        } else if (ly <= ily and iry <= ry and lx <= jlx and jrx <= rx) {
            return at(i, j);
        } else if ((ly <= ily and iry <= ry) or (p and not (lx <= jlx and jrx <= rx))) {
            return mon.append(
                area_concat(i, 2 * j + 1, ily, jlx, iry, (jlx + jrx) / 2, not p, ly, lx, ry, rx),
                area_concat(i, 2 * j + 2, ily, (jlx + jrx) / 2, iry, jrx, not p, ly, lx, ry, rx));
        } else {
            return mon.append(
                area_concat(2 * i + 1, j, ily, jlx, (ily + iry) / 2, jrx, not p, ly, lx, ry, rx),
                area_concat(2 * i + 2, j, (ily + iry) / 2, jlx, iry, jrx, not p, ly, lx, ry, rx));
        }
    }
    /**
     * @note call area_concat O((ry - ly) / h * (rx - lx) / w) times
     */
    value_type area_concat_torus(int ly, int lx, int ry, int rx) const {
        value_type acc = mon.unit();
        while (ly < 0) { ly += h1; ry += h1; }
        while (lx < 0) { lx += w1; rx += w1; }
        for (int bi = ly / h1; bi <= (ry - 1) / h1; ++ bi) {
            int ly1 = (bi == ly / h1 ? ly % h1 : 0);
            int ry1 = (bi == ry / h1 ? ry % h1 : h1);
            for (int bj = lx / w1; bj <= (rx - 1) / w1; ++ bj) {
                int lx1 = (bj == lx / w1 ? lx % w1 : 0);
                int rx1 = (bj == rx / w1 ? rx % w1 : w1);
                acc = mon.append(acc, area_concat(ly1, lx1, ry1, rx1));
            }
        }
        return acc;
    }
};

struct max_monoid {
    typedef int value_type;
    int unit() const { return INT_MIN; }
    int append(int a, int b) const { return max(a, b); }
};

struct plus_monoid {
    typedef int value_type;
    int unit() const { return 0; }
    int append(int a, int b) const { return a + b; }
};

unittest {
    default_random_engine gen;
    REP (iteration, 100) {
        int h = uniform_int_distribution<int>(1, 30)(gen);
        int w = uniform_int_distribution<int>(1, 30)(gen);
        vector<vector<int> > a(h, vector<int>(w));
        segment_tree_2d<plus_monoid> segtree(h, w);
        REP (y, h) REP (x, w) {
            a[y][x] = uniform_int_distribution<int>(-10, 10)(gen);
            segtree.point_set(y, x, a[y][x]);
        }
        REP (y, h) REP (x, w) {
            assert (a[y][x] == segtree.area_concat(y, x, y + 1, x + 1));
        }
        REP (iteration, 100) {
            int ly = uniform_int_distribution<int>(0, h - 1)(gen);
            int lx = uniform_int_distribution<int>(0, w - 1)(gen);
            int ry = uniform_int_distribution<int>(ly + 1, h)(gen);
            int rx = uniform_int_distribution<int>(lx + 1, w)(gen);
            int acc = 0;
            REP3 (y, ly, ry) {
                REP3 (x, lx, rx) {
                    acc += a[y][x];
                }
            }
            assert (acc == segtree.area_concat(ly, lx, ry, rx));
        }
        REP (iteration, 10) {
            int ly = uniform_int_distribution<int>(- 100, 50)(gen);
            int lx = uniform_int_distribution<int>(- 100, 50)(gen);
            int ry = uniform_int_distribution<int>(ly, 100)(gen);
            int rx = uniform_int_distribution<int>(lx, 100)(gen);
            int acc = 0;
            REP3 (y, ly, ry) {
                REP3 (x, lx, rx) {
                    acc += a[(y % h + h) % h][(x % w + w) % w];
                }
            }
            assert (acc == segtree.area_concat_torus(ly, lx, ry, rx));
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

