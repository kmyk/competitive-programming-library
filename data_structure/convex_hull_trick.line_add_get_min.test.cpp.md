---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/convex_hull_trick.hpp
    title: "Convex Hull Trick (\u975E\u5358\u8ABF, online)"
  - icon: ':question:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"data_structure/convex_hull_trick.line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 2 \"data_structure/convex_hull_trick.hpp\"\n#include <cassert>\n#include <climits>\n\
    #include <cstdint>\n#include <map>\n#include <set>\n#include <utility>\n\n\nnamespace\
    \ convex_hull_trick_details {\n    /**\n     * @note y = ax + b\n     */\n   \
    \ struct line_t { int64_t a, b; };\n    bool operator < (line_t lhs, line_t rhs)\
    \ {\n        return std::make_pair(- lhs.a, lhs.b) < std::make_pair(- rhs.a, rhs.b);\n\
    \    }\n\n    struct rational_t { int64_t num, den; };\n    bool operator < (rational_t\
    \ lhs, rational_t rhs) {\n        if (lhs.num ==   INT64_MAX or rhs.num == - INT64_MAX)\
    \ return false;\n        if (lhs.num == - INT64_MAX or rhs.num ==   INT64_MAX)\
    \ return true;\n        return (__int128_t)lhs.num * rhs.den < (__int128_t)rhs.num\
    \ * lhs.den;\n    }\n}\n\n\n/*\n * @brief Convex Hull Trick (\u975E\u5358\u8ABF\
    , online)\n * @docs data_structure/convex_hull_trick.md\n */\nclass convex_hull_trick\
    \ {\n    typedef convex_hull_trick_details::line_t line_t;\n    typedef convex_hull_trick_details::rational_t\
    \ rational_t;\n    static rational_t make_rational(int64_t num, int64_t den =\
    \ 1) {\n        if (den < 0) { num *= -1; den *= -1; }\n        return { num,\
    \ den };  // NOTE: no reduction\n    }\n\npublic:\n    convex_hull_trick() {\n\
    \        lines.insert({ + INT64_MAX, 0 });  // sentinels\n        lines.insert({\
    \ - INT64_MAX, 0 });\n        cross.emplace(make_rational(- INT64_MAX), (line_t)\
    \ { - INT64_MAX, 0 });\n    }\n    /**\n     * @note O(log n)\n     */\n    void\
    \ add_line(int64_t a, int64_t b) {\n        auto it = lines.insert({ a, b }).first;\n\
    \        if (not is_required(*prev(it), { a, b }, *next(it))) {\n            lines.erase(it);\n\
    \            return;\n        }\n        cross.erase(cross_point(*prev(it), *next(it)));\n\
    \        {  // remove right lines\n            auto ju = prev(it);\n         \
    \   while (ju != lines.begin() and not is_required(*prev(ju), *ju, { a, b }))\
    \ -- ju;\n            cross_erase(ju, prev(it));\n            it = lines.erase(++\
    \ ju, it);\n        }\n        {  // remove left lines\n            auto ju =\
    \ next(it);\n            while(next(ju) != lines.end() and not is_required({ a,\
    \ b }, *ju, *next(ju))) ++ ju;\n            cross_erase(++ it, ju);\n        \
    \    it = prev(lines.erase(it, ju));\n        }\n        cross.emplace(cross_point(*prev(it),\
    \ *it), *it);\n        cross.emplace(cross_point(*it, *next(it)), *next(it));\n\
    \        assert (not empty());\n    }\n    bool empty() const {\n        return\
    \ lines.size() <= 2;\n    }\n    /**\n     * @note O(log n)\n     */\n    int64_t\
    \ get_min(int64_t x) const {\n        assert (not empty());\n        line_t f\
    \ = prev(cross.lower_bound(make_rational(x)))->second;\n        return f.a * x\
    \ + f.b;\n    }\n\nprivate:\n    std::set<line_t> lines;\n    std::map<rational_t,\
    \ line_t> cross;\n    template <typename Iterator>\n    void cross_erase(Iterator\
    \ first, Iterator last) {\n        for (; first != last; ++ first) {\n       \
    \     cross.erase(cross_point(*first, *next(first)));\n        }\n    }\n    rational_t\
    \ cross_point(line_t f1, line_t f2) const {\n        if (f1.a ==   INT64_MAX)\
    \ return make_rational(- INT64_MAX);\n        if (f2.a == - INT64_MAX) return\
    \ make_rational(  INT64_MAX);\n        return make_rational(f1.b - f2.b, f2.a\
    \ - f1.a);\n    }\n    bool is_required(line_t f1, line_t f2, line_t f3) const\
    \ {\n        if (f1.a == f2.a and f1.b <= f2.b) return false;\n        if (f1.a\
    \ == INT64_MAX or f3.a == - INT64_MAX) return true;\n        return (__int128_t)(f2.a\
    \ - f1.a) * (f3.b - f2.b) < (__int128_t)(f2.b - f1.b) * (f3.a - f2.a);\n    }\n\
    };\n\nstruct inverted_convex_hull_trick {\n    convex_hull_trick data;\n    void\
    \ add_line(int64_t a, int64_t b) { data.add_line(- a, - b); }\n    int64_t get_max(int64_t\
    \ x) { return - data.get_min(x); }\n};\n#line 2 \"utils/macros.hpp\"\n#define\
    \ REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for\
    \ (int i = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n)\
    \ - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 4 \"\
    data_structure/convex_hull_trick.line_add_get_min.test.cpp\"\n#include <cstdio>\n\
    \nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n    convex_hull_trick\
    \ cht;\n    REP (i, n) {\n        int64_t a, b; scanf(\"%lld%lld\", &a, &b);\n\
    \        cht.add_line(a, b);\n    }\n    while (q --) {\n        int t; scanf(\"\
    %d\", &t);\n        if (t == 0) {\n            int64_t a, b; scanf(\"%lld%lld\"\
    , &a, &b);\n            cht.add_line(a, b);\n        } else if (t == 1) {\n  \
    \          int64_t p; scanf(\"%lld\", &p);\n            printf(\"%lld\\n\", cht.get_min(p));\n\
    \        } else {\n            assert (false);\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../data_structure/convex_hull_trick.hpp\"\n#include \"../utils/macros.hpp\"\
    \n#include <cstdio>\n\nint main() {\n    int n, q; scanf(\"%d%d\", &n, &q);\n\
    \    convex_hull_trick cht;\n    REP (i, n) {\n        int64_t a, b; scanf(\"\
    %lld%lld\", &a, &b);\n        cht.add_line(a, b);\n    }\n    while (q --) {\n\
    \        int t; scanf(\"%d\", &t);\n        if (t == 0) {\n            int64_t\
    \ a, b; scanf(\"%lld%lld\", &a, &b);\n            cht.add_line(a, b);\n      \
    \  } else if (t == 1) {\n            int64_t p; scanf(\"%lld\", &p);\n       \
    \     printf(\"%lld\\n\", cht.get_min(p));\n        } else {\n            assert\
    \ (false);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - data_structure/convex_hull_trick.hpp
  - utils/macros.hpp
  isVerificationFile: true
  path: data_structure/convex_hull_trick.line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/convex_hull_trick.line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/data_structure/convex_hull_trick.line_add_get_min.test.cpp
- /verify/data_structure/convex_hull_trick.line_add_get_min.test.cpp.html
title: data_structure/convex_hull_trick.line_add_get_min.test.cpp
---
