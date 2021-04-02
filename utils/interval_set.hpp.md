---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: set of disjoint intervals
    links: []
  bundledCode: "#line 2 \"utils/interval_set.hpp\"\n#include <map>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief set of disjoint intervals\n\
    \ */\nclass interval_set {\n    std::map<int64_t, int64_t> data;  // the function\
    \ which from right terminals r_i to left terminals l_i of intervals [l_i, r_i)\n\
    \npublic:\n    /**\n     * @note O(\\log q) amortized\n     * @note [l_i, r_i)\n\
    \     */\n    void add_interval(int64_t l, int64_t r) {\n        assert (l <=\
    \ r);\n        if (l == r) return;\n        while (true) {\n            auto it\
    \ = data.lower_bound(l);\n            if (it == data.end() or r < it->second)\
    \ {\n                break;\n            }\n            l = std::min(l, it->second);\n\
    \            r = std::max(r, it->first);\n            data.erase(it);\n      \
    \  }\n        data.emplace(r, l);\n    }\n\n    /**\n     * @note O(\\log q)\n\
    \     */\n    void remove_containing_interval(int64_t x) {\n        auto it =\
    \ data.upper_bound(x);\n        if (it != data.end() and it->second <= x) {\n\
    \            data.erase(it);\n        }\n    }\n\n    /**\n     * @note O(\\log\
    \ q)\n     */\n    std::optional<std::pair<int64_t, int64_t> > find_containing_interval(int64_t\
    \ x) const {\n        auto it = data.upper_bound(x);\n        if (it != data.end()\
    \ and it->second <= x) {\n            return std::make_optional(std::make_pair(it->second,\
    \ it->first));\n        } else {\n            return std::optional<std::pair<int64_t,\
    \ int64_t> >();\n        }\n    }\n\n    /**\n     * @note O(k \\log q)\n    \
    \ * @note [l_i, r_i)\n     */\n    std::vector<std::pair<int64_t, int64_t> > list_intersecting_interval(int64_t\
    \ l, int64_t r) const {\n        assert (l <= r);\n        std::vector<std::pair<int64_t,\
    \ int64_t> > result;\n        while (true) {\n            auto it = data.upper_bound(l);\n\
    \            if (it == data.end() or r <= it->second) {\n                break;\n\
    \            }\n            result.emplace_back(it->second, it->first);\n    \
    \        l = it->first;\n        }\n        return result;\n    }\n\n    size_t\
    \ size() const {\n        return data.size();\n    }\n};\n"
  code: "#pragma once\n#include <map>\n#include <optional>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief set of disjoint intervals\n */\nclass interval_set\
    \ {\n    std::map<int64_t, int64_t> data;  // the function which from right terminals\
    \ r_i to left terminals l_i of intervals [l_i, r_i)\n\npublic:\n    /**\n    \
    \ * @note O(\\log q) amortized\n     * @note [l_i, r_i)\n     */\n    void add_interval(int64_t\
    \ l, int64_t r) {\n        assert (l <= r);\n        if (l == r) return;\n   \
    \     while (true) {\n            auto it = data.lower_bound(l);\n           \
    \ if (it == data.end() or r < it->second) {\n                break;\n        \
    \    }\n            l = std::min(l, it->second);\n            r = std::max(r,\
    \ it->first);\n            data.erase(it);\n        }\n        data.emplace(r,\
    \ l);\n    }\n\n    /**\n     * @note O(\\log q)\n     */\n    void remove_containing_interval(int64_t\
    \ x) {\n        auto it = data.upper_bound(x);\n        if (it != data.end() and\
    \ it->second <= x) {\n            data.erase(it);\n        }\n    }\n\n    /**\n\
    \     * @note O(\\log q)\n     */\n    std::optional<std::pair<int64_t, int64_t>\
    \ > find_containing_interval(int64_t x) const {\n        auto it = data.upper_bound(x);\n\
    \        if (it != data.end() and it->second <= x) {\n            return std::make_optional(std::make_pair(it->second,\
    \ it->first));\n        } else {\n            return std::optional<std::pair<int64_t,\
    \ int64_t> >();\n        }\n    }\n\n    /**\n     * @note O(k \\log q)\n    \
    \ * @note [l_i, r_i)\n     */\n    std::vector<std::pair<int64_t, int64_t> > list_intersecting_interval(int64_t\
    \ l, int64_t r) const {\n        assert (l <= r);\n        std::vector<std::pair<int64_t,\
    \ int64_t> > result;\n        while (true) {\n            auto it = data.upper_bound(l);\n\
    \            if (it == data.end() or r <= it->second) {\n                break;\n\
    \            }\n            result.emplace_back(it->second, it->first);\n    \
    \        l = it->first;\n        }\n        return result;\n    }\n\n    size_t\
    \ size() const {\n        return data.size();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/interval_set.hpp
  requiredBy: []
  timestamp: '2020-08-16 05:36:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/interval_set.hpp
layout: document
redirect_from:
- /library/utils/interval_set.hpp
- /library/utils/interval_set.hpp.html
title: set of disjoint intervals
---
