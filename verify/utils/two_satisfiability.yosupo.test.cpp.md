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


# :heavy_check_mark: utils/two_satisfiability.yosupo.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/two_satisfiability.yosupo.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 00:00:25+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/strongly_connected_components.hpp.html">strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解 <small>(graph/strongly_connected_components.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/graph/transpose_graph.hpp.html">graph/transpose_graph.hpp</a>
* :heavy_check_mark: <a href="../../library/hack/fastio.hpp.html">hack/fastio.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/macros.hpp.html">utils/macros.hpp</a>
* :heavy_check_mark: <a href="../../library/utils/two_satisfiability.hpp.html">2-SAT ($O(N)$) <small>(utils/two_satisfiability.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <cassert>
#include <vector>
#include <utility>
#include "utils/macros.hpp"
#include "hack/fastio.hpp"
#include "utils/two_satisfiability.hpp"
using namespace std;

int main() {
    // read the header of DIMACS format
    char const_p = in<char>();
    assert (const_p == 'p');
    string const_cnf = in<string>();
    assert (const_cnf == "cnf");

    // input
    int n = in<int>();
    int m = in<int>();
    vector<pair<int, int> > cnf;
    REP (i, m) {
        int a = in<int>();
        int b = in<int>();
        cnf.emplace_back(a, b);

        int const_zero = in<int>();
        assert (const_zero == 0);
    }

    // solve
    vector<bool> model = compute_two_satisfiability(n, cnf);

    // output
    if (model.empty()) {
        out<string>("s UNSATISFIABLE\n");
    } else {
        out<string>("s SATISFIABLE\n");
        out<char>('v');
        REP (i, n) {
            out<char>(' ');
            out<int>((model[i] ? 1 : -1) * (i + 1));
        }
        out<string>(" 0 \n");
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "utils/two_satisfiability.yosupo.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <cassert>
#include <vector>
#include <utility>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 2 "hack/fastio.hpp"
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline Char in() { return getchar_unlocked(); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline std::string in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    std::string s;
    do { s.push_back(c); } while (not isspace(c = getchar_unlocked()));
    return s;
}
template <class Integer, std::enable_if_t<std::is_integral_v<Integer> and not std::is_same_v<Integer, char>, int> = 0>
inline Integer in() {
    char c; do { c = getchar_unlocked(); } while (isspace(c));
    if (std::is_signed<Integer>::value and c == '-') return -in<Integer>();
    Integer n = 0;
    do { n = n * 10 + c - '0'; } while (not isspace(c = getchar_unlocked()));
    return n;
}

template <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>
inline void out(char c) { putchar_unlocked(c); }
template <class String, std::enable_if_t<std::is_same_v<String, std::string>, int> = 0>
inline void out(const std::string & s) { for (char c : s) putchar_unlocked(c); }
template <class Integer, std::enable_if_t<std::is_integral_v<Integer>, int> = 0>
inline void out(Integer n) {
    char s[20];
    int i = 0;
    if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *= -1; }
    do { s[i ++] = n % 10; n /= 10; } while (n);
    while (i) putchar_unlocked(s[-- i] + '0');
}
#line 2 "graph/strongly_connected_components.hpp"
#include <functional>
#line 4 "graph/transpose_graph.hpp"

/**
 * @param g is an adjacent list of a digraph
 * @note $O(V + E)$
 * @see https://en.wikipedia.org/wiki/Transpose_graph
 */
std::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int> > const & g) {
    int n = g.size();
    std::vector<std::vector<int> > h(n);
    REP (i, n) {
        for (int j : g[i]) {
            h[j].push_back(i);
        }
    }
    return h;
}
#line 7 "graph/strongly_connected_components.hpp"

/**
 * @brief strongly connected components decomposition, Kosaraju's algorithm / 強連結成分分解
 * @return the pair (the number k of components, the function from vertices of g to components)
 * @param g is an adjacent list of a digraph
 * @param g_rev is the transpose graph of g
 * @note $O(V + E)$
 */
std::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev) {
    int n = g.size();
    std::vector<int> acc(n); {
        std::vector<bool> used(n);
        std::function<void (int)> dfs = [&](int i) {
            used[i] = true;
            for (int j : g[i]) if (not used[j]) dfs(j);
            acc.push_back(i);
        };
        REP (i,n) if (not used[i]) dfs(i);
        reverse(ALL(acc));
    }
    int size = 0;
    std::vector<int> component_of(n); {
        std::vector<bool> used(n);
        std::function<void (int)> rdfs = [&](int i) {
            used[i] = true;
            component_of[i] = size;
            for (int j : g_rev[i]) if (not used[j]) rdfs(j);
        };
        for (int i : acc) if (not used[i]) {
            rdfs(i);
            ++ size;
        }
    }
    return { size, move(component_of) };
}

std::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const std::vector<std::vector<int> > & g) {
    return decompose_to_strongly_connected_components(g, make_transpose_graph(g));
}
#line 6 "utils/two_satisfiability.hpp"

/**
 * @brief 2-SAT ($O(N)$)
 * @param n is the number of variables
 * @param cnf is a proposition in a conjunctive normal form. Each literal is expressed as number $x$ s.t. $1 \le \vert x \vert \le n$
 * @return a vector with the length $n$ if SAT. It's empty if UNSAT.
 */
std::vector<bool> compute_two_satisfiability(int n, const std::vector<std::pair<int, int> > & cnf) {
    // make digraph
    std::vector<std::vector<int> > g(2 * n);
    auto index = [&](int x) {
        assert (x != 0 and abs(x) <= n);
        return x > 0 ? x - 1 : n - x - 1;
    };
    for (auto it : cnf) {
        int x, y; std::tie(x, y) = it;  // x or y
        g[index(- x)].push_back(index(y));  // not x implies y
        g[index(- y)].push_back(index(x));  // not y implies x
    }

    // do SCC
    std::vector<int> component = decompose_to_strongly_connected_components(g).second;
    std::vector<bool> valuation(n);
    REP3 (x, 1, n + 1) {
        if (component[index(x)] == component[index(- x)]) {  // x iff not x
            return std::vector<bool>();  // unsat
        }
        valuation[x - 1] = component[index(x)] > component[index(- x)];  // use components which indices are large
    }
    return valuation;
}
#line 8 "utils/two_satisfiability.yosupo.test.cpp"
using namespace std;

int main() {
    // read the header of DIMACS format
    char const_p = in<char>();
    assert (const_p == 'p');
    string const_cnf = in<string>();
    assert (const_cnf == "cnf");

    // input
    int n = in<int>();
    int m = in<int>();
    vector<pair<int, int> > cnf;
    REP (i, m) {
        int a = in<int>();
        int b = in<int>();
        cnf.emplace_back(a, b);

        int const_zero = in<int>();
        assert (const_zero == 0);
    }

    // solve
    vector<bool> model = compute_two_satisfiability(n, cnf);

    // output
    if (model.empty()) {
        out<string>("s UNSATISFIABLE\n");
    } else {
        out<string>("s SATISFIABLE\n");
        out<char>('v');
        REP (i, n) {
            out<char>(' ');
            out<int>((model[i] ? 1 : -1) * (i + 1));
        }
        out<string>(" 0 \n");
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

