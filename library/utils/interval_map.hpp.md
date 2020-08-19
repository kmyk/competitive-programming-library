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


# :warning: map from disjoint intervals <small>(utils/interval_map.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2b3583e6e17721c54496bd04e57a0c15">utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/utils/interval_map.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-16 05:36:03+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <map>
#include <optional>
#include <tuple>
#include <vector>

/**
 * @brief map from disjoint intervals
 */
template <class T>
class interval_map {
    std::map<int64_t, std::pair<int64_t, T> > data;  // the function which from right terminals r_i to the pairs (l_i, value) of left terminals l_i of intervals [l_i, r_i)

public:
    /**
     * @note O(\log q) amortized
     * @note [l_i, r_i)
     */
    void update_interval(int64_t l, int64_t r, T value) {
        assert (l <= r);
        if (l == r) return;
        auto it = data.lower_bound(l);
        if (it != data.end() and it->second.first < l) {
            auto r2 = it->first;
            auto [l2, value2] = it->second;
            if (r < r2) {  // included
                if (value2 == value) {
                    return;
                } else {
                    it->second.first = r;
                    data.emplace(l, std::make_pair(l2, value2));
                }
            } else {
                if (value2 == value) {
                    l = l2;
                    data.erase(it);
                } else if (l < r2) {
                    data.erase(it);
                    data.emplace(l, std::make_pair(l2, value2));
                }
            }
        }
        while (true) {
            it = data.upper_bound(l);
            if (it == data.end() or r < it->second.first) {
                break;
            }
            auto r2 = it->first;
            auto [l2, value2] = it->second;
            assert (l <= l2);
            if (r2 <= r) {
                data.erase(it);
            } else {
                if (value2 == value) {
                    r = r2;
                    data.erase(it);
                } else if (l2 < r) {
                    it->second.first = r;
                }
                break;
            }
        }
        data.emplace(r, std::make_pair(l, value));
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
    std::optional<T> find_value(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second.first <= x) {
            return std::make_optional(it->second.second);
        } else {
            return std::optional<T>();
        }
    }

    /**
     * @note O(\log q)
     */
    std::optional<std::tuple<int64_t, int64_t, T> > find_containing_interval(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second.first <= x) {
            return std::make_optional(std::make_tuple(it->second.first, it->first, it->second.second));
        } else {
            return std::optional<std::tuple<int64_t, int64_t, T> >();
        }
    }

    /**
     * @note O(k \log q)
     * @note [l_i, r_i)
     */
    std::vector<std::tuple<int64_t, int64_t, T> > list_intersecting_interval(int64_t l, int64_t r) const {
        assert (l <= r);
        std::vector<std::tuple<int64_t, int64_t, T> > result;
        while (true) {
            auto it = data.upper_bound(l);
            if (it == data.end() or r <= it->second.first) {
                break;
            }
            result.emplace_back(it->second.first, it->first, it->second.second);
            l = it->first;
        }
        return result;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "utils/interval_map.hpp"
#include <map>
#include <optional>
#include <tuple>
#include <vector>

/**
 * @brief map from disjoint intervals
 */
template <class T>
class interval_map {
    std::map<int64_t, std::pair<int64_t, T> > data;  // the function which from right terminals r_i to the pairs (l_i, value) of left terminals l_i of intervals [l_i, r_i)

public:
    /**
     * @note O(\log q) amortized
     * @note [l_i, r_i)
     */
    void update_interval(int64_t l, int64_t r, T value) {
        assert (l <= r);
        if (l == r) return;
        auto it = data.lower_bound(l);
        if (it != data.end() and it->second.first < l) {
            auto r2 = it->first;
            auto [l2, value2] = it->second;
            if (r < r2) {  // included
                if (value2 == value) {
                    return;
                } else {
                    it->second.first = r;
                    data.emplace(l, std::make_pair(l2, value2));
                }
            } else {
                if (value2 == value) {
                    l = l2;
                    data.erase(it);
                } else if (l < r2) {
                    data.erase(it);
                    data.emplace(l, std::make_pair(l2, value2));
                }
            }
        }
        while (true) {
            it = data.upper_bound(l);
            if (it == data.end() or r < it->second.first) {
                break;
            }
            auto r2 = it->first;
            auto [l2, value2] = it->second;
            assert (l <= l2);
            if (r2 <= r) {
                data.erase(it);
            } else {
                if (value2 == value) {
                    r = r2;
                    data.erase(it);
                } else if (l2 < r) {
                    it->second.first = r;
                }
                break;
            }
        }
        data.emplace(r, std::make_pair(l, value));
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
    std::optional<T> find_value(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second.first <= x) {
            return std::make_optional(it->second.second);
        } else {
            return std::optional<T>();
        }
    }

    /**
     * @note O(\log q)
     */
    std::optional<std::tuple<int64_t, int64_t, T> > find_containing_interval(int64_t x) const {
        auto it = data.upper_bound(x);
        if (it != data.end() and it->second.first <= x) {
            return std::make_optional(std::make_tuple(it->second.first, it->first, it->second.second));
        } else {
            return std::optional<std::tuple<int64_t, int64_t, T> >();
        }
    }

    /**
     * @note O(k \log q)
     * @note [l_i, r_i)
     */
    std::vector<std::tuple<int64_t, int64_t, T> > list_intersecting_interval(int64_t l, int64_t r) const {
        assert (l <= r);
        std::vector<std::tuple<int64_t, int64_t, T> > result;
        while (true) {
            auto it = data.upper_bound(l);
            if (it == data.end() or r <= it->second.first) {
                break;
            }
            result.emplace_back(it->second.first, it->first, it->second.second);
            l = it->first;
        }
        return result;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

