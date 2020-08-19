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


# :warning: set of disjoint intervals <small>(utils/interval_set.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/interval_set.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-16 05:36:03+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <map>
#include <optional>
#include <utility>
#include <vector>

/**
 * @brief set of disjoint intervals
 */
class interval_set {
    std::map<int64_t, int64_t> data;  // the function which from right terminals r_i to left terminals l_i of intervals [l_i, r_i)

public:
    /**
     * @note O(\log q) amortized
     * @note [l_i, r_i)
     */
    void add_interval(int64_t l, int64_t r) {
        assert (l <= r);
        if (l == r) return;
        while (true) {
            auto it = data.lower_bound(l);
            if (it == data.end() or r < it->second) {
                break;
            }
            l = std::min(l, it->second);
            r = std::max(r, it->first);
            data.erase(it);
        }
        data.emplace(r, l);
    }

    /**
     * @note O(\log q)
     */
    void remove_containing_interval(int64_t x) {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second <= x) {
            data.erase(it);
        }
    }

    /**
     * @note O(\log q)
     */
    std::optional<std::pair<int64_t, int64_t> > find_containing_interval(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second <= x) {
            return std::make_optional(std::make_pair(it->second, it->first));
        } else {
            return std::optional<std::pair<int64_t, int64_t> >();
        }
    }

    /**
     * @note O(k \log q)
     * @note [l_i, r_i)
     */
    std::vector<std::pair<int64_t, int64_t> > list_intersecting_interval(int64_t l, int64_t r) const {
        assert (l <= r);
        std::vector<std::pair<int64_t, int64_t> > result;
        while (true) {
            auto it = data.upper_bound(l);
            if (it == data.end() or r <= it->second) {
                break;
            }
            result.emplace_back(it->second, it->first);
            l = it->first;
        }
        return result;
    }

    size_t size() const {
        return data.size();
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/interval_set.hpp"
#include <map>
#include <optional>
#include <utility>
#include <vector>

/**
 * @brief set of disjoint intervals
 */
class interval_set {
    std::map<int64_t, int64_t> data;  // the function which from right terminals r_i to left terminals l_i of intervals [l_i, r_i)

public:
    /**
     * @note O(\log q) amortized
     * @note [l_i, r_i)
     */
    void add_interval(int64_t l, int64_t r) {
        assert (l <= r);
        if (l == r) return;
        while (true) {
            auto it = data.lower_bound(l);
            if (it == data.end() or r < it->second) {
                break;
            }
            l = std::min(l, it->second);
            r = std::max(r, it->first);
            data.erase(it);
        }
        data.emplace(r, l);
    }

    /**
     * @note O(\log q)
     */
    void remove_containing_interval(int64_t x) {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second <= x) {
            data.erase(it);
        }
    }

    /**
     * @note O(\log q)
     */
    std::optional<std::pair<int64_t, int64_t> > find_containing_interval(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second <= x) {
            return std::make_optional(std::make_pair(it->second, it->first));
        } else {
            return std::optional<std::pair<int64_t, int64_t> >();
        }
    }

    /**
     * @note O(k \log q)
     * @note [l_i, r_i)
     */
    std::vector<std::pair<int64_t, int64_t> > list_intersecting_interval(int64_t l, int64_t r) const {
        assert (l <= r);
        std::vector<std::pair<int64_t, int64_t> > result;
        while (true) {
            auto it = data.upper_bound(l);
            if (it == data.end() or r <= it->second) {
                break;
            }
            result.emplace_back(it->second, it->first);
            l = it->first;
        }
        return result;
    }

    size_t size() const {
        return data.size();
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

