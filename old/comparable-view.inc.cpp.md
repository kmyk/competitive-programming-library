---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: compare substrings of a string with O(1) using suffix arrays
  bundledCode: "#line 1 \"old/comparable-view.inc.cpp\"\n/**\n * @brief compare substrings\
    \ of a string with O(1) using suffix arrays\n * @note O(1)\n */\nint string_view_strcmp(int\
    \ l1, int r1, int l2, int r2, vector<int> const & rank, sparse_table<min_semilattice>\
    \ const & lcp) {\n    int rank_l, rank_r; tie(rank_l, rank_r) = minmax({ rank[l1],\
    \ rank[l2] });\n    int k = lcp.range_concat(rank_l, rank_r);\n    if (min(r1\
    \ - l1, r2 - l2) <= k) {\n        return (r1 - l1) - (r2 - l2);\n    } else {\n\
    \        return rank[l1] - rank[l2];\n    }\n}\n\nunittest {\n    default_random_engine\
    \ gen;\n    REP (iteration, 100) {\n        int length = uniform_int_distribution<int>(10,\
    \ 100)(gen);\n        string s;\n        REP (i, length) {\n            s += uniform_int_distribution<char>('A',\
    \ 'Z')(gen);\n        }\n        vector<int> sa, rank;\n        suffix_array(s,\
    \ sa, rank);\n        vector<int> lcp_ = longest_common_prefix_array(s, sa, rank);\n\
    \        sparse_table<min_semilattice> lcp = sparse_table<min_semilattice>(lcp_);\n\
    \        REP (iteration, 100) {\n            int l1 = uniform_int_distribution<int>(0,\
    \ length / 2)(gen);\n            int r1 = uniform_int_distribution<int>(l1, length)(gen);\n\
    \            int l2 = uniform_int_distribution<int>(0, length / 2)(gen);\n   \
    \         int r2 = uniform_int_distribution<int>(l2, length)(gen);\n         \
    \   auto sub1 = s.substr(l1, r1 - l1);\n            auto sub2 = s.substr(l2, r2\
    \ - l2);\n            assert ((string_view_strcmp(l1, r1, l2, r2, rank, lcp) <\
    \ 0) == (sub1 < sub2));\n        }\n    }\n}\n\n/**\n * @brief as a class\n */\n\
    class comparable_string_view_factory {\npublic:\n    class comparable_string_view\
    \ {\n    public:\n        const comparable_string_view_factory *factory;\n   \
    \     const int l, r;\n    private:\n        friend class comparable_string_view_factory;\n\
    \        comparable_string_view(const comparable_string_view_factory *factory_,\
    \ int l_, int r_)\n                : factory(factory_), l(l_), r(r_) {\n     \
    \   }\n    public:\n        inline bool empty() const { return r == 0; }\n   \
    \     inline size_t size() const { return r - l; }\n        inline char operator\
    \ [] (size_t i) const {\n            assert (0 <= i and i < size());\n       \
    \     return factory->s[l + i];\n        }\n        inline bool operator < (comparable_string_view\
    \ const & other) const {\n            assert (this->factory == other.factory);\n\
    \            return this->factory->strcmp(this->l, this->r, other.l, other.r)\
    \ < 0;\n        }\n        inline bool operator == (comparable_string_view const\
    \ & other) const {\n            assert (this->factory == other.factory);\n   \
    \         return this->factory->strcmp(this->l, this->r, other.l, other.r) ==\
    \ 0;\n        }\n        inline bool operator != (comparable_string_view const\
    \ & other) const {\n            assert (this->factory == other.factory);\n   \
    \         return this->factory->strcmp(this->l, this->r, other.l, other.r) !=\
    \ 0;\n        }\n    };\nprivate:\n    string s;\n    vector<int> sa, rank;\n\
    \    sparse_table<min_semilattice> lcp;\npublic:\n    comparable_string_view_factory()\
    \ = default;\n    comparable_string_view_factory(string const & s_)\n        \
    \    : s(s_) {\n        suffix_array(s, sa, rank);\n        vector<int> lcp_ =\
    \ longest_common_prefix_array(s, sa, rank);\n        lcp = sparse_table<min_semilattice>(lcp_);\n\
    \    }\n    comparable_string_view make_view(int l, int r) const {\n        assert\
    \ (0 <= l and l <= r and r <= s.length());\n        return comparable_string_view(this,\
    \ l, r);\n    }\nprivate:\n    int strcmp(int l1, int r1, int l2, int r2) const\
    \ {\n        int rank_l, rank_r; tie(rank_l, rank_r) = minmax({ rank[l1], rank[l2]\
    \ });\n        int k = lcp.range_concat(rank_l, rank_r);\n        if (min(r1 -\
    \ l1, r2 - l2) <= k) {\n            return (r1 - l1) - (r2 - l2);\n        } else\
    \ {\n            return rank[l1] - rank[l2];\n        }\n    }\n};\ntypedef comparable_string_view_factory::comparable_string_view\
    \ comparable_string_view;\n\nunittest {\n    default_random_engine gen;\n    REP\
    \ (iteration, 100) {\n        int length = uniform_int_distribution<int>(10, 100)(gen);\n\
    \        string s;\n        REP (i, length) {\n            s += uniform_int_distribution<char>('A',\
    \ 'Z')(gen);\n        }\n        comparable_string_view_factory factory(s);\n\
    \        REP (iteration, 100) {\n            int l1 = uniform_int_distribution<int>(0,\
    \ length / 2)(gen);\n            int r1 = uniform_int_distribution<int>(l1, length)(gen);\n\
    \            int l2 = uniform_int_distribution<int>(0, length / 2)(gen);\n   \
    \         int r2 = uniform_int_distribution<int>(l2, length)(gen);\n         \
    \   auto view1 = factory.make_view(l1, r1);\n            auto view2 = factory.make_view(l2,\
    \ r2);\n            auto sub1 = s.substr(l1, r1 - l1);\n            auto sub2\
    \ = s.substr(l2, r2 - l2);\n            assert ((view1 < view2) == (sub1 < sub2));\n\
    \        }\n    }\n}\n"
  code: "/**\n * @brief compare substrings of a string with O(1) using suffix arrays\n\
    \ * @note O(1)\n */\nint string_view_strcmp(int l1, int r1, int l2, int r2, vector<int>\
    \ const & rank, sparse_table<min_semilattice> const & lcp) {\n    int rank_l,\
    \ rank_r; tie(rank_l, rank_r) = minmax({ rank[l1], rank[l2] });\n    int k = lcp.range_concat(rank_l,\
    \ rank_r);\n    if (min(r1 - l1, r2 - l2) <= k) {\n        return (r1 - l1) -\
    \ (r2 - l2);\n    } else {\n        return rank[l1] - rank[l2];\n    }\n}\n\n\
    unittest {\n    default_random_engine gen;\n    REP (iteration, 100) {\n     \
    \   int length = uniform_int_distribution<int>(10, 100)(gen);\n        string\
    \ s;\n        REP (i, length) {\n            s += uniform_int_distribution<char>('A',\
    \ 'Z')(gen);\n        }\n        vector<int> sa, rank;\n        suffix_array(s,\
    \ sa, rank);\n        vector<int> lcp_ = longest_common_prefix_array(s, sa, rank);\n\
    \        sparse_table<min_semilattice> lcp = sparse_table<min_semilattice>(lcp_);\n\
    \        REP (iteration, 100) {\n            int l1 = uniform_int_distribution<int>(0,\
    \ length / 2)(gen);\n            int r1 = uniform_int_distribution<int>(l1, length)(gen);\n\
    \            int l2 = uniform_int_distribution<int>(0, length / 2)(gen);\n   \
    \         int r2 = uniform_int_distribution<int>(l2, length)(gen);\n         \
    \   auto sub1 = s.substr(l1, r1 - l1);\n            auto sub2 = s.substr(l2, r2\
    \ - l2);\n            assert ((string_view_strcmp(l1, r1, l2, r2, rank, lcp) <\
    \ 0) == (sub1 < sub2));\n        }\n    }\n}\n\n/**\n * @brief as a class\n */\n\
    class comparable_string_view_factory {\npublic:\n    class comparable_string_view\
    \ {\n    public:\n        const comparable_string_view_factory *factory;\n   \
    \     const int l, r;\n    private:\n        friend class comparable_string_view_factory;\n\
    \        comparable_string_view(const comparable_string_view_factory *factory_,\
    \ int l_, int r_)\n                : factory(factory_), l(l_), r(r_) {\n     \
    \   }\n    public:\n        inline bool empty() const { return r == 0; }\n   \
    \     inline size_t size() const { return r - l; }\n        inline char operator\
    \ [] (size_t i) const {\n            assert (0 <= i and i < size());\n       \
    \     return factory->s[l + i];\n        }\n        inline bool operator < (comparable_string_view\
    \ const & other) const {\n            assert (this->factory == other.factory);\n\
    \            return this->factory->strcmp(this->l, this->r, other.l, other.r)\
    \ < 0;\n        }\n        inline bool operator == (comparable_string_view const\
    \ & other) const {\n            assert (this->factory == other.factory);\n   \
    \         return this->factory->strcmp(this->l, this->r, other.l, other.r) ==\
    \ 0;\n        }\n        inline bool operator != (comparable_string_view const\
    \ & other) const {\n            assert (this->factory == other.factory);\n   \
    \         return this->factory->strcmp(this->l, this->r, other.l, other.r) !=\
    \ 0;\n        }\n    };\nprivate:\n    string s;\n    vector<int> sa, rank;\n\
    \    sparse_table<min_semilattice> lcp;\npublic:\n    comparable_string_view_factory()\
    \ = default;\n    comparable_string_view_factory(string const & s_)\n        \
    \    : s(s_) {\n        suffix_array(s, sa, rank);\n        vector<int> lcp_ =\
    \ longest_common_prefix_array(s, sa, rank);\n        lcp = sparse_table<min_semilattice>(lcp_);\n\
    \    }\n    comparable_string_view make_view(int l, int r) const {\n        assert\
    \ (0 <= l and l <= r and r <= s.length());\n        return comparable_string_view(this,\
    \ l, r);\n    }\nprivate:\n    int strcmp(int l1, int r1, int l2, int r2) const\
    \ {\n        int rank_l, rank_r; tie(rank_l, rank_r) = minmax({ rank[l1], rank[l2]\
    \ });\n        int k = lcp.range_concat(rank_l, rank_r);\n        if (min(r1 -\
    \ l1, r2 - l2) <= k) {\n            return (r1 - l1) - (r2 - l2);\n        } else\
    \ {\n            return rank[l1] - rank[l2];\n        }\n    }\n};\ntypedef comparable_string_view_factory::comparable_string_view\
    \ comparable_string_view;\n\nunittest {\n    default_random_engine gen;\n    REP\
    \ (iteration, 100) {\n        int length = uniform_int_distribution<int>(10, 100)(gen);\n\
    \        string s;\n        REP (i, length) {\n            s += uniform_int_distribution<char>('A',\
    \ 'Z')(gen);\n        }\n        comparable_string_view_factory factory(s);\n\
    \        REP (iteration, 100) {\n            int l1 = uniform_int_distribution<int>(0,\
    \ length / 2)(gen);\n            int r1 = uniform_int_distribution<int>(l1, length)(gen);\n\
    \            int l2 = uniform_int_distribution<int>(0, length / 2)(gen);\n   \
    \         int r2 = uniform_int_distribution<int>(l2, length)(gen);\n         \
    \   auto view1 = factory.make_view(l1, r1);\n            auto view2 = factory.make_view(l2,\
    \ r2);\n            auto sub1 = s.substr(l1, r1 - l1);\n            auto sub2\
    \ = s.substr(l2, r2 - l2);\n            assert ((view1 < view2) == (sub1 < sub2));\n\
    \        }\n    }\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/comparable-view.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/comparable-view.inc.cpp
layout: document
redirect_from:
- /library/old/comparable-view.inc.cpp
- /library/old/comparable-view.inc.cpp.html
title: compare substrings of a string with O(1) using suffix arrays
---
