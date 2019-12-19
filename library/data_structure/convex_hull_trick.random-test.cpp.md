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


# :warning: data_structure/convex_hull_trick.random-test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/convex_hull_trick.random-test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-20 06:12:24 +0900




## Depends on

* :warning: <a href="convex_hull_trick.hpp.html">data_structure/convex_hull_trick.hpp</a>
* :heavy_check_mark: <a href="../utils/macros.hpp.html">utils/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "data_structure/convex_hull_trick.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;


int main() {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 1000) {
        vector<pair<int, int> > lines;
        convex_hull_trick cht;
        REP (i, 100) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
            cht.add_line(a, b);
        }
        REP (i, 10) {
            int x = uniform_int_distribution<int>(- 100, 100)(gen);
            int y = INT_MAX;
            for (auto line : lines) {
                int a, b; tie(a, b) = line;
                y = min(y, a * x + b);
            }
            assert (cht.get_min(x) == y);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/convex_hull_trick.hpp"
#include <cassert>
#include <climits>
#include <cstdint>
#include <map>
#include <set>
#include <utility>


namespace convex_hull_trick_details {
    /**
     * @note y = ax + b
     */
    struct line_t { int64_t a, b; };
    bool operator < (line_t lhs, line_t rhs) {
        return std::make_pair(- lhs.a, lhs.b) < std::make_pair(- rhs.a, rhs.b);
    }

    struct rational_t { int64_t num, den; };
    bool operator < (rational_t lhs, rational_t rhs) {
        if (lhs.num ==   INT64_MAX or rhs.num == - INT64_MAX) return false;
        if (lhs.num == - INT64_MAX or rhs.num ==   INT64_MAX) return true;
        return lhs.num * rhs.den < rhs.num * lhs.den;  // TODO: check overflow
    }
}


/*
 * @sa http://d.hatena.ne.jp/sune2/20140310/1394440369
 * @sa http://techtipshoge.blogspot.jp/2013/06/convex-hull-trickdequepop-back.html
 * @sa http://satanic0258.hatenablog.com/entry/2016/08/16/181331
 * @sa http://wcipeg.com/wiki/Convex_hull_trick
 * @note verified at http://codeforces.com/contest/631/submission/31828502
 */
class convex_hull_trick {
    typedef convex_hull_trick_details::line_t line_t;
    typedef convex_hull_trick_details::rational_t rational_t;
    static rational_t make_rational(int64_t num, int64_t den = 1) {
        if (den < 0) { num *= -1; den *= -1; }
        return { num, den };  // NOTE: no reduction
    }

public:
    convex_hull_trick() {
        lines.insert({ + INT64_MAX, 0 });  // sentinels
        lines.insert({ - INT64_MAX, 0 });
        cross.emplace(make_rational(- INT64_MAX), (line_t) { - INT64_MAX, 0 });
    }
    /**
     * @note O(log n)
     */
    void add_line(int64_t a, int64_t b) {
        auto it = lines.insert({ a, b }).first;
        if (not is_required(*prev(it), { a, b }, *next(it))) {
            lines.erase(it);
            return;
        }
        cross.erase(cross_point(*prev(it), *next(it)));
        {  // remove right lines
            auto ju = prev(it);
            while (ju != lines.begin() and not is_required(*prev(ju), *ju, { a, b })) -- ju;
            cross_erase(ju, prev(it));
            it = lines.erase(++ ju, it);
        }
        {  // remove left lines
            auto ju = next(it);
            while(next(ju) != lines.end() and not is_required({ a, b }, *ju, *next(ju))) ++ ju;
            cross_erase(++ it, ju);
            it = prev(lines.erase(it, ju));
        }
        cross.emplace(cross_point(*prev(it), *it), *it);
        cross.emplace(cross_point(*it, *next(it)), *next(it));
        assert (not empty());
    }
    bool empty() const {
        return lines.size() <= 2;
    }
    /**
     * @note O(log n)
     */
    int64_t get_min(int64_t x) const {
        assert (not empty());
        line_t f = prev(cross.lower_bound(make_rational(x)))->second;
        return f.a * x + f.b;
    }

private:
    std::set<line_t> lines;
    std::map<rational_t, line_t> cross;
    template <typename Iterator>
    void cross_erase(Iterator first, Iterator last) {
        for (; first != last; ++ first) {
            cross.erase(cross_point(*first, *next(first)));
        }
    }
    rational_t cross_point(line_t f1, line_t f2) const {
        if (f1.a ==   INT64_MAX) return make_rational(- INT64_MAX);
        if (f2.a == - INT64_MAX) return make_rational(  INT64_MAX);
        return make_rational(f1.b - f2.b, f2.a - f1.a);
    }
    bool is_required(line_t f1, line_t f2, line_t f3) const {
        if (f1.a == f2.a and f1.b <= f2.b) return false;
        if (f1.a == INT64_MAX or f3.a == - INT64_MAX) return true;
        return (f2.a - f1.a) * (f3.b - f2.b) < (f2.b - f1.b) * (f3.a - f2.a);
#line 2 "data_structure/convex_hull_trick.random-test.cpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
#include <vector>
#line 2 "utils/macros.hpp"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#line 9 "data_structure/convex_hull_trick.random-test.cpp"
using namespace std;


int main() {
    random_device device;
    default_random_engine gen(device());
    REP (iteration, 1000) {
        vector<pair<int, int> > lines;
        convex_hull_trick cht;
        REP (i, 100) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
            cht.add_line(a, b);
        }
        REP (i, 10) {
            int x = uniform_int_distribution<int>(- 100, 100)(gen);
            int y = INT_MAX;
            for (auto line : lines) {
                int a, b; tie(a, b) = line;
                y = min(y, a * x + b);
            }
            assert (cht.get_min(x) == y);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

