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


# :heavy_check_mark: graph/tree_decomposition.aoj_2405.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/graph/tree_decomposition.aoj_2405.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-22 23:03:03+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/tree_decomposition.hpp.html">木分解 (木幅 $t \le 2$) <small>(graph/tree_decomposition.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/mint.hpp.html">quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$ <small>(modulus/mint.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/modulus/modinv.hpp.html">modulus/modinv.hpp</a>
* :heavy_check_mark: <a href="../../library/modulus/modpow.hpp.html">modulus/modpow.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405"
#include <cstdio>
#include "graph/tree_decomposition.hpp"
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
using namespace std;


constexpr int MOD = 1000003;
mint<MOD> solve(int n, int m, vector<vector<int> > & g) {
    // add the implicitly given edges to g
    REP (x, n) {
        g[x].push_back((x + 1) % n);
        g[(x + 1) % n].push_back(x);
    }
    REP (x, n) {
        sort(ALL(g[x]));
        g[x].erase(unique(ALL(g[x])), g[x].end());
    }

    // get a tree decomposition
    auto [parent, bags_] = get_tree_decomposition(g);
    auto nice = get_nice_tree_decomposition(parent, bags_);

    // dp on a nice tree decomposition
    vector<set<int> > bags(nice.size());
    auto index = [&](int a, int x) {
        assert (bags[a].count(x));
        return distance(bags[a].begin(), bags[a].find(x));
    };
    auto translate = [&](int a, int s, int b) {
        int t = 0;
        for (int x : bags[a]) {
            if (bags[b].count(x) and (s & (1 << index(a, x)))) {
                t |= 1 << index(b, x);
            }
        }
        return t;
    };
    vector<vector<mint<MOD> > > dp(nice.size());
    REP (a, nice.size()) {
        auto [tag, x, b] = nice[a];

        if (tag == LEAF) {
            bags[a].insert(x);
            dp[a].resize(1 << bags[a].size());
            dp[a][0] += 1;

        } else if (tag == INTRODUCE) {
            bags[a] = bags[b];
            bags[a].insert(x);
            assert (bags[a].size() <= 3);
            dp[a].resize(1 << bags[a].size());
            REP (t, dp[b].size()) {
                int s = translate(b, t, a);
                dp[a][s] += dp[b][t];
            }

        } else if (tag == FORGET) {
            assert (bags[b].count(x));
            bags[a] = bags[b];
            bags[a].erase(x);
            dp[a].resize(1 << bags[a].size());
            REP (t, dp[b].size()) {
                int s = translate(b, t, a);
                if (t & (1 << index(b, x))) {
                    dp[a][s] += dp[b][t];
                } else {
                    for (int y : g[x]) {
                        if (bags[a].count(y) and not (s & (1 << index(a, y)))) {
                            int u = s | (1 << index(a, y));
                            dp[a][u] += dp[b][t];
                        }
                    }
                }
            }

        } else if (tag == JOIN) {
            assert (bags[x] == bags[b]);
            bags[a] = bags[b];
            dp[a].resize(1 << bags[a].size());
            REP (s, dp[a].size()) {
                REP (t, dp[a].size()) if ((s & t) == 0) {
                    dp[a][s | t] += dp[x][s] * dp[b][t];
                }
            }

        }
    }
    return dp.back().back();
}

int main() {
    while (true) {
        int n, m; scanf("%d%d", &n, &m);
        if (n == 0 and m == 0) break;
        vector<vector<int> > g(n);
        REP (i, m) {
            int a, b; scanf("%d%d", &a, &b);
            -- a;
            -- b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        mint<MOD> cnt = solve(n, m, g);
        printf("%d\n", cnt.value);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/tree_decomposition.aoj_2405.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405"
#include <cstdio>
#line 2 "graph/tree_decomposition.hpp"
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdint>
#include <functional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 14 "graph/tree_decomposition.hpp"

/**
 * @brief 木分解 (木幅 $t \le 2$)
 * @docs graph/tree_decomposition.md
 * @note $O(N)$ ?
 * @see https://ei1333.hateblo.jp/entry/2020/02/12/150319
 * @arg g is a simple connected graph $G = (V, E)$ whose treewidth $t \le 2$
 * @return a decomposed tree $T = (I, F)$ as a triple of (the root, the list of children $c : I \to \mathcal{P} \to I$, what vertices are contained $X : I \to \mathcal{P}(V)$)
 */
inline std::pair<std::vector<int>, std::vector<std::vector<int> > > get_tree_decomposition(const std::vector<std::vector<int> > & g) {
    int n = g.size();

    // prepare the info about g
    std::vector<int> used(n, -1);
    std::vector<int> degree(n);
    std::unordered_set<int64_t> edges;
    auto pack = [&](int x, int y) {
        if (x > y) std::swap(x, y);
        return ((int64_t)x << 32) | y;
    };
    REP (x, n) {
        degree[x] = g[x].size();
        for (int y : g[x]) if (x < y) {
            edges.insert(pack(x, y));
        }
    }

    // prepare the info about t
    std::vector<int> parent;
    std::vector<int> antecedent;
    std::function<int (int)> find_root = [&](int a) {
        // union-find tree with only path-compression
        return (antecedent[a] == -1 ? a : antecedent[a] = find_root(antecedent[a]));
    };
    std::vector<std::vector<int> > bags;

    // construct the tree with a stack
    std::stack<int> stk;
    REP (x, n) {
        if (g[x].size() <= 2) {
            stk.push(x);
        }
    }
    while (not stk.empty()) {
        int x = stk.top();
        stk.pop();
        if (degree[x] == 0) continue;
        used[x] = bags.size();
        parent.push_back(-1);
        antecedent.push_back(-1);
        bags.emplace_back();
        auto & bag = bags.back();

        // make the new bag
        bag.push_back(x);
        for (int y : g[x]) {
            if (used[y] == -1) {
                // add a vertex y into the new bag
                bag.push_back(y);

            } else if (used[y] >= 0) {
                // connect a bag used[y] as a child
                int root = find_root(used[y]);
                if (root == used[x]) {
                    // nop

                } else if (bags[used[y]].size() == 2) {
                    // the sub-bag is removing a vertex
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[used[y]][1] == x);
                    bag.push_back(y);

                } else if (bags[used[y]].size() == 3) {
                    // the sub-bag is removing an edge
                    if (parent[root] == -1) {
                        parent[root] = antecedent[root] = used[x];
                    }
                    assert (bags[root][1] == x or bags[root][2] == x);
                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);
                    used[bags[root][0]] = used[x];
                } else {
                    assert (false);
                }

            } else {
                // nop
            }
        }
        std::sort(bag.begin() + 1, bag.end());
        bag.erase(std::unique(bag.begin() + 1, bag.end()), bag.end());
        assert (bag.size() == degree[x] + 1);

        // remove and add edges
        auto decr = [&](int y) {
            -- degree[y];
            if (degree[y] == 2) {
                stk.push(y);
            }
        };
        if (degree[x] == 1) {
            decr(bag[1]);
        } if (degree[x] == 2) {
            if (not edges.insert(pack(bag[1], bag[2])).second) {
                decr(bag[1]);
                decr(bag[2]);
            }
        }
        degree[x] = 0;
    }

    if (std::count(ALL(degree), 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int> >());
    assert (std::count(ALL(parent), -1) == 1);
    return std::make_pair(parent, bags);
}

enum nice_tree_decomposition_tag {
    LEAF,
    INTRODUCE,
    FORGET,
    JOIN,
};

/**
 * @note $O(t N)$
 */
inline std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const std::vector<std::vector<int> > & bags) {
    assert (not parent.empty());
    assert (parent.back() == -1);  // assume that vertices are topologically sorted and reversed
    int n = parent.size();
    std::vector<std::vector<int> > children(n);
    std::vector<int> node(n, -1);
    std::vector<std::tuple<nice_tree_decomposition_tag, int, int> > nice;
    REP (a, n) {
        assert (not bags[a].empty());
        if (children[a].empty()) {
            for (int x : bags[a]) {
                if (x == bags[a].front()) {
                    nice.emplace_back(LEAF, x, -1);
                } else {
                    nice.emplace_back(INTRODUCE, x, nice.size() - 1);
                }
            }
            node[a] = nice.size() - 1;
        } else {
            for (int b : children[a]) {
                for (int y : bags[b]) {
                    if (not count(ALL(bags[a]), y)) {
                        nice.emplace_back(FORGET, y, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                for (int x : bags[a]) {
                    if (not count(ALL(bags[b]), x)) {
                        nice.emplace_back(INTRODUCE, x, node[b]);
                        node[b] = nice.size() - 1;
                    }
                }
                if (b == children[a].front()) {
                    std::swap(node[a], node[b]);
                } else {
                    nice.emplace_back(JOIN, node[a], node[b]);
                    node[a] = nice.size() - 1;
                }
            }
        }
        if (parent[a] != -1) {
            children[parent[a]].push_back(a);
        }
    };
    for (int x : bags.back()) {
        nice.emplace_back(FORGET, x, node.back());
        node.back() = nice.size() - 1;
    }
    return nice;
}
#line 2 "modulus/mint.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#line 2 "modulus/modpow.hpp"
#include <cassert>

inline constexpr int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {
    assert (0 <= x and x < MOD);
    uint_fast64_t y = 1;
    for (; k; k >>= 1) {
        if (k & 1) (y *= x) %= MOD;
        (x *= x) %= MOD;
    }
    assert (0 <= y and y < MOD);
    return y;
}
#line 2 "modulus/modinv.hpp"
#include <algorithm>
#include <cassert>

inline int32_t modinv_nocheck(int32_t value, int32_t MOD) {
    assert (0 <= value and value < MOD);
    if (value == 0) return -1;
    int64_t a = value, b = MOD;
    int64_t x = 0, y = 1;
    for (int64_t u = 1, v = 0; a; ) {
        int64_t q = b / a;
        x -= q * u; std::swap(x, u);
        y -= q * v; std::swap(y, v);
        b -= q * a; std::swap(b, a);
    }
    if (not (value * x + MOD * y == b and b == 1)) return -1;
    if (x < 0) x += MOD;
    assert (0 <= x and x < MOD);
    return x;
}

inline int32_t modinv(int32_t x, int32_t MOD) {
    int32_t y = modinv_nocheck(x, MOD);
    assert (y != -1);
    return y;
}
#line 7 "modulus/mint.hpp"


/**
 * @brief quotient ring / 剰余環 $\mathbb{Z}/n\mathbb{Z}$
 */
template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline constexpr mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline constexpr mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline constexpr mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline constexpr mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline constexpr mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline constexpr mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline constexpr mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline constexpr mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline constexpr mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline constexpr mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline constexpr bool operator == (mint<MOD> other) const { return value == other.value; }
    inline constexpr bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
#line 6 "graph/tree_decomposition.aoj_2405.test.cpp"
using namespace std;


constexpr int MOD = 1000003;
mint<MOD> solve(int n, int m, vector<vector<int> > & g) {
    // add the implicitly given edges to g
    REP (x, n) {
        g[x].push_back((x + 1) % n);
        g[(x + 1) % n].push_back(x);
    }
    REP (x, n) {
        sort(ALL(g[x]));
        g[x].erase(unique(ALL(g[x])), g[x].end());
    }

    // get a tree decomposition
    auto [parent, bags_] = get_tree_decomposition(g);
    auto nice = get_nice_tree_decomposition(parent, bags_);

    // dp on a nice tree decomposition
    vector<set<int> > bags(nice.size());
    auto index = [&](int a, int x) {
        assert (bags[a].count(x));
        return distance(bags[a].begin(), bags[a].find(x));
    };
    auto translate = [&](int a, int s, int b) {
        int t = 0;
        for (int x : bags[a]) {
            if (bags[b].count(x) and (s & (1 << index(a, x)))) {
                t |= 1 << index(b, x);
            }
        }
        return t;
    };
    vector<vector<mint<MOD> > > dp(nice.size());
    REP (a, nice.size()) {
        auto [tag, x, b] = nice[a];

        if (tag == LEAF) {
            bags[a].insert(x);
            dp[a].resize(1 << bags[a].size());
            dp[a][0] += 1;

        } else if (tag == INTRODUCE) {
            bags[a] = bags[b];
            bags[a].insert(x);
            assert (bags[a].size() <= 3);
            dp[a].resize(1 << bags[a].size());
            REP (t, dp[b].size()) {
                int s = translate(b, t, a);
                dp[a][s] += dp[b][t];
            }

        } else if (tag == FORGET) {
            assert (bags[b].count(x));
            bags[a] = bags[b];
            bags[a].erase(x);
            dp[a].resize(1 << bags[a].size());
            REP (t, dp[b].size()) {
                int s = translate(b, t, a);
                if (t & (1 << index(b, x))) {
                    dp[a][s] += dp[b][t];
                } else {
                    for (int y : g[x]) {
                        if (bags[a].count(y) and not (s & (1 << index(a, y)))) {
                            int u = s | (1 << index(a, y));
                            dp[a][u] += dp[b][t];
                        }
                    }
                }
            }

        } else if (tag == JOIN) {
            assert (bags[x] == bags[b]);
            bags[a] = bags[b];
            dp[a].resize(1 << bags[a].size());
            REP (s, dp[a].size()) {
                REP (t, dp[a].size()) if ((s & t) == 0) {
                    dp[a][s | t] += dp[x][s] * dp[b][t];
                }
            }

        }
    }
    return dp.back().back();
}

int main() {
    while (true) {
        int n, m; scanf("%d%d", &n, &m);
        if (n == 0 and m == 0) break;
        vector<vector<int> > g(n);
        REP (i, m) {
            int a, b; scanf("%d%d", &a, &b);
            -- a;
            -- b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        mint<MOD> cnt = solve(n, m, g);
        printf("%d\n", cnt.value);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

