---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: map from disjoint intervals
  bundledCode: "#line 2 \"utils/interval_map.hpp\"\n#include <map>\n#include <optional>\n\
    #include <tuple>\n#include <vector>\n\n/**\n * @brief map from disjoint intervals\n\
    \ */\ntemplate <class T>\nclass interval_map {\n    std::map<int64_t, std::pair<int64_t,\
    \ T> > data;  // the function which from right terminals r_i to the pairs (l_i,\
    \ value) of left terminals l_i of intervals [l_i, r_i)\n\npublic:\n    /**\n \
    \    * @note O(\\log q) amortized\n     * @note [l_i, r_i)\n     */\n    void\
    \ update_interval(int64_t l, int64_t r, T value) {\n        assert (l <= r);\n\
    \        if (l == r) return;\n        auto it = data.lower_bound(l);\n       \
    \ if (it != data.end() and it->second.first < l) {\n            auto r2 = it->first;\n\
    \            auto [l2, value2] = it->second;\n            if (r < r2) {  // included\n\
    \                if (value2 == value) {\n                    return;\n       \
    \         } else {\n                    it->second.first = r;\n              \
    \      data.emplace(l, std::make_pair(l2, value2));\n                }\n     \
    \       } else {\n                if (value2 == value) {\n                   \
    \ l = l2;\n                    data.erase(it);\n                } else if (l <\
    \ r2) {\n                    data.erase(it);\n                    data.emplace(l,\
    \ std::make_pair(l2, value2));\n                }\n            }\n        }\n\
    \        while (true) {\n            it = data.upper_bound(l);\n            if\
    \ (it == data.end() or r < it->second.first) {\n                break;\n     \
    \       }\n            auto r2 = it->first;\n            auto [l2, value2] = it->second;\n\
    \            assert (l <= l2);\n            if (r2 <= r) {\n                data.erase(it);\n\
    \            } else {\n                if (value2 == value) {\n              \
    \      r = r2;\n                    data.erase(it);\n                } else if\
    \ (l2 < r) {\n                    it->second.first = r;\n                }\n \
    \               break;\n            }\n        }\n        data.emplace(r, std::make_pair(l,\
    \ value));\n    }\n\n    /**\n     * @note O(\\log q)\n     */\n    void remove_containing_interval(int64_t\
    \ x) {\n        auto it = data.upper_bound(x);\n        if (it != data.end() and\
    \ it->second <= x) {\n            data.erase(it);\n        }\n    }\n\n    /**\n\
    \     * @note O(\\log q)\n     */\n    std::optional<T> find_value(int64_t x)\
    \ const {\n        auto it = data.upper_bound(x);\n        if (it != data.end()\
    \ and it->second.first <= x) {\n            return std::make_optional(it->second.second);\n\
    \        } else {\n            return std::optional<T>();\n        }\n    }\n\n\
    \    /**\n     * @note O(\\log q)\n     */\n    std::optional<std::tuple<int64_t,\
    \ int64_t, T> > find_containing_interval(int64_t x) const {\n        auto it =\
    \ data.upper_bound(x);\n        if (it != data.end() and it->second.first <= x)\
    \ {\n            return std::make_optional(std::make_tuple(it->second.first, it->first,\
    \ it->second.second));\n        } else {\n            return std::optional<std::tuple<int64_t,\
    \ int64_t, T> >();\n        }\n    }\n\n    /**\n     * @note O(k \\log q)\n \
    \    * @note [l_i, r_i)\n     */\n    std::vector<std::tuple<int64_t, int64_t,\
    \ T> > list_intersecting_interval(int64_t l, int64_t r) const {\n        assert\
    \ (l <= r);\n        std::vector<std::tuple<int64_t, int64_t, T> > result;\n \
    \       while (true) {\n            auto it = data.upper_bound(l);\n         \
    \   if (it == data.end() or r <= it->second.first) {\n                break;\n\
    \            }\n            result.emplace_back(it->second.first, it->first, it->second.second);\n\
    \            l = it->first;\n        }\n        return result;\n    }\n};\n"
  code: "#pragma once\n#include <map>\n#include <optional>\n#include <tuple>\n#include\
    \ <vector>\n\n/**\n * @brief map from disjoint intervals\n */\ntemplate <class\
    \ T>\nclass interval_map {\n    std::map<int64_t, std::pair<int64_t, T> > data;\
    \  // the function which from right terminals r_i to the pairs (l_i, value) of\
    \ left terminals l_i of intervals [l_i, r_i)\n\npublic:\n    /**\n     * @note\
    \ O(\\log q) amortized\n     * @note [l_i, r_i)\n     */\n    void update_interval(int64_t\
    \ l, int64_t r, T value) {\n        assert (l <= r);\n        if (l == r) return;\n\
    \        auto it = data.lower_bound(l);\n        if (it != data.end() and it->second.first\
    \ < l) {\n            auto r2 = it->first;\n            auto [l2, value2] = it->second;\n\
    \            if (r < r2) {  // included\n                if (value2 == value)\
    \ {\n                    return;\n                } else {\n                 \
    \   it->second.first = r;\n                    data.emplace(l, std::make_pair(l2,\
    \ value2));\n                }\n            } else {\n                if (value2\
    \ == value) {\n                    l = l2;\n                    data.erase(it);\n\
    \                } else if (l < r2) {\n                    data.erase(it);\n \
    \                   data.emplace(l, std::make_pair(l2, value2));\n           \
    \     }\n            }\n        }\n        while (true) {\n            it = data.upper_bound(l);\n\
    \            if (it == data.end() or r < it->second.first) {\n               \
    \ break;\n            }\n            auto r2 = it->first;\n            auto [l2,\
    \ value2] = it->second;\n            assert (l <= l2);\n            if (r2 <=\
    \ r) {\n                data.erase(it);\n            } else {\n              \
    \  if (value2 == value) {\n                    r = r2;\n                    data.erase(it);\n\
    \                } else if (l2 < r) {\n                    it->second.first =\
    \ r;\n                }\n                break;\n            }\n        }\n  \
    \      data.emplace(r, std::make_pair(l, value));\n    }\n\n    /**\n     * @note\
    \ O(\\log q)\n     */\n    void remove_containing_interval(int64_t x) {\n    \
    \    auto it = data.upper_bound(x);\n        if (it != data.end() and it->second\
    \ <= x) {\n            data.erase(it);\n        }\n    }\n\n    /**\n     * @note\
    \ O(\\log q)\n     */\n    std::optional<T> find_value(int64_t x) const {\n  \
    \      auto it = data.upper_bound(x);\n        if (it != data.end() and it->second.first\
    \ <= x) {\n            return std::make_optional(it->second.second);\n       \
    \ } else {\n            return std::optional<T>();\n        }\n    }\n\n    /**\n\
    \     * @note O(\\log q)\n     */\n    std::optional<std::tuple<int64_t, int64_t,\
    \ T> > find_containing_interval(int64_t x) const {\n        auto it = data.upper_bound(x);\n\
    \        if (it != data.end() and it->second.first <= x) {\n            return\
    \ std::make_optional(std::make_tuple(it->second.first, it->first, it->second.second));\n\
    \        } else {\n            return std::optional<std::tuple<int64_t, int64_t,\
    \ T> >();\n        }\n    }\n\n    /**\n     * @note O(k \\log q)\n     * @note\
    \ [l_i, r_i)\n     */\n    std::vector<std::tuple<int64_t, int64_t, T> > list_intersecting_interval(int64_t\
    \ l, int64_t r) const {\n        assert (l <= r);\n        std::vector<std::tuple<int64_t,\
    \ int64_t, T> > result;\n        while (true) {\n            auto it = data.upper_bound(l);\n\
    \            if (it == data.end() or r <= it->second.first) {\n              \
    \  break;\n            }\n            result.emplace_back(it->second.first, it->first,\
    \ it->second.second);\n            l = it->first;\n        }\n        return result;\n\
    \    }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: utils/interval_map.hpp
  requiredBy: []
  timestamp: '2020-08-16 05:36:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: utils/interval_map.hpp
layout: document
redirect_from:
- /library/utils/interval_map.hpp
- /library/utils/interval_map.hpp.html
title: map from disjoint intervals
---
