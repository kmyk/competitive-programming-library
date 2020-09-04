---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: a structure to make a midpoint for given two points
  bundledCode: "#line 1 \"old/midpoint.inc.cpp\"\n/**\n * @brief a structure to make\
    \ a midpoint for given two points\n */\nclass midpoint {\n    vector<bool> data;\n\
    \    midpoint(vector<bool> const & data_) : data(data_) {}\npublic:\n    midpoint()\
    \ : data({ false, true }) {}\n    static midpoint min() { return midpoint(vector<bool>());\
    \ }\n    static midpoint max() { return midpoint(vector<bool>(1, true)); }\n \
    \   /**\n     * @brief for given $a$ and $c$, make $b$ s.t. $a < b < c$\n    \
    \ */\n    midpoint between(midpoint const & other) const {\n        auto const\
    \ & a = this->data;\n        auto const & b = other.data;\n        vector<bool>\
    \ c(::max(a.size(), b.size()) + 1);\n        bool is_carried = false;\n      \
    \  REP_R (i, ::max(a.size(), b.size())) {\n            bool a_i = (i < a.size()\
    \ and a[i]);\n            bool b_i = (i < b.size() and b[i]);\n            c[i\
    \ + 1]   = a_i ^ b_i ^ is_carried;\n            is_carried = a_i + b_i + is_carried\
    \ >= 2;\n        }\n        c[0] = is_carried;\n        while (not c.empty() and\
    \ not c.back()) {\n            c.pop_back();\n        }\n        return midpoint(c);\n\
    \    }\n    bool operator < (midpoint const & other) const {\n        return this->data\
    \ < other.data;\n    }\n};\n"
  code: "/**\n * @brief a structure to make a midpoint for given two points\n */\n\
    class midpoint {\n    vector<bool> data;\n    midpoint(vector<bool> const & data_)\
    \ : data(data_) {}\npublic:\n    midpoint() : data({ false, true }) {}\n    static\
    \ midpoint min() { return midpoint(vector<bool>()); }\n    static midpoint max()\
    \ { return midpoint(vector<bool>(1, true)); }\n    /**\n     * @brief for given\
    \ $a$ and $c$, make $b$ s.t. $a < b < c$\n     */\n    midpoint between(midpoint\
    \ const & other) const {\n        auto const & a = this->data;\n        auto const\
    \ & b = other.data;\n        vector<bool> c(::max(a.size(), b.size()) + 1);\n\
    \        bool is_carried = false;\n        REP_R (i, ::max(a.size(), b.size()))\
    \ {\n            bool a_i = (i < a.size() and a[i]);\n            bool b_i = (i\
    \ < b.size() and b[i]);\n            c[i + 1]   = a_i ^ b_i ^ is_carried;\n  \
    \          is_carried = a_i + b_i + is_carried >= 2;\n        }\n        c[0]\
    \ = is_carried;\n        while (not c.empty() and not c.back()) {\n          \
    \  c.pop_back();\n        }\n        return midpoint(c);\n    }\n    bool operator\
    \ < (midpoint const & other) const {\n        return this->data < other.data;\n\
    \    }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/midpoint.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/midpoint.inc.cpp
layout: document
redirect_from:
- /library/old/midpoint.inc.cpp
- /library/old/midpoint.inc.cpp.html
title: a structure to make a midpoint for given two points
---
