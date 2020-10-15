---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.yosupo.test.cpp
    title: data_structure/sliding_window_aggregation.yosupo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Sliding Window Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\
      \u306E\u7DCF\u548C\u304C $O(1)$ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\
      \u3068\u306F\u9650\u3089\u306A\u3044 monoid \u304C\u4E57\u308B)"
    links: []
  bundledCode: "#line 2 \"data_structure/sliding_window_aggregation.hpp\"\n#include\
    \ <cassert>\n#include <cstddef>\n#include <deque>\n#line 2 \"utils/macros.hpp\"\
    \n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line\
    \ 6 \"data_structure/sliding_window_aggregation.hpp\"\n\n/**\n * @brief Sliding\
    \ Window Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u7DCF\u548C\u304C\
    \ $O(1)$ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\u3068\u306F\u9650\u3089\u306A\
    \u3044 monoid \u304C\u4E57\u308B)\n */\ntemplate <class Monoid>\nstruct sliding_window_aggregation\
    \ {\n    typedef typename Monoid::value_type value_type;\n    Monoid mon;\n  \
    \  std::deque<value_type> data;\n    int front;\n    value_type back;\n    sliding_window_aggregation(const\
    \ Monoid & mon_ = Monoid()) : mon(mon_) {\n        front = 0;\n        back =\
    \ mon.unit();\n    }\n    /**\n     * @note O(1)\n     */\n    void push(value_type\
    \ x) {\n        data.push_back(x);\n        back = mon.mult(back, x);\n    }\n\
    \    /**\n     * @note amortized O(1)\n     */\n    void pop() {\n        assert\
    \ (not data.empty());\n        data.pop_front();\n        if (front) {\n     \
    \       -- front;\n        } else {\n            REP_R (i, (int)data.size() -\
    \ 1) {\n                data[i] = mon.mult(data[i], data[i + 1]);\n          \
    \  }\n            front = data.size();\n            back = mon.unit();\n     \
    \   }\n    }\n    /**\n     * @brief get sum of elements in the queue\n     *\
    \ @note O(1)\n     */\n    value_type accumulate() const {\n        return front\
    \ ? mon.mult(data.front(), back) : back;\n    }\n    bool empty() const {\n  \
    \      return data.empty();\n    }\n    std::size_t size() const {\n        return\
    \ data.size();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstddef>\n#include <deque>\n\
    #include \"utils/macros.hpp\"\n\n/**\n * @brief Sliding Window Aggregation / \u542B\
    \u307E\u308C\u308B\u8981\u7D20\u306E\u7DCF\u548C\u304C $O(1)$ \u3067\u53D6\u308C\
    \u308B queue (\u53EF\u63DB\u3068\u306F\u9650\u3089\u306A\u3044 monoid \u304C\u4E57\
    \u308B)\n */\ntemplate <class Monoid>\nstruct sliding_window_aggregation {\n \
    \   typedef typename Monoid::value_type value_type;\n    Monoid mon;\n    std::deque<value_type>\
    \ data;\n    int front;\n    value_type back;\n    sliding_window_aggregation(const\
    \ Monoid & mon_ = Monoid()) : mon(mon_) {\n        front = 0;\n        back =\
    \ mon.unit();\n    }\n    /**\n     * @note O(1)\n     */\n    void push(value_type\
    \ x) {\n        data.push_back(x);\n        back = mon.mult(back, x);\n    }\n\
    \    /**\n     * @note amortized O(1)\n     */\n    void pop() {\n        assert\
    \ (not data.empty());\n        data.pop_front();\n        if (front) {\n     \
    \       -- front;\n        } else {\n            REP_R (i, (int)data.size() -\
    \ 1) {\n                data[i] = mon.mult(data[i], data[i + 1]);\n          \
    \  }\n            front = data.size();\n            back = mon.unit();\n     \
    \   }\n    }\n    /**\n     * @brief get sum of elements in the queue\n     *\
    \ @note O(1)\n     */\n    value_type accumulate() const {\n        return front\
    \ ? mon.mult(data.front(), back) : back;\n    }\n    bool empty() const {\n  \
    \      return data.empty();\n    }\n    std::size_t size() const {\n        return\
    \ data.size();\n    }\n};\n"
  dependsOn:
  - utils/macros.hpp
  isVerificationFile: false
  path: data_structure/sliding_window_aggregation.hpp
  requiredBy: []
  timestamp: '2020-01-08 19:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/sliding_window_aggregation.yosupo.test.cpp
documentation_of: data_structure/sliding_window_aggregation.hpp
layout: document
redirect_from:
- /library/data_structure/sliding_window_aggregation.hpp
- /library/data_structure/sliding_window_aggregation.hpp.html
title: "Sliding Window Aggregation / \u542B\u307E\u308C\u308B\u8981\u7D20\u306E\u7DCF\
  \u548C\u304C $O(1)$ \u3067\u53D6\u308C\u308B queue (\u53EF\u63DB\u3068\u306F\u9650\
  \u3089\u306A\u3044 monoid \u304C\u4E57\u308B)"
---
