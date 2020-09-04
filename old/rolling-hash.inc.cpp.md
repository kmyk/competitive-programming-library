---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: a rolling hash
  bundledCode: "#line 1 \"old/rolling-hash.inc.cpp\"\n/**\n * @brief a rolling hash\n\
    \ * @note 4 primes for modulo and and random bases\n * @see http://hos.ac/blog/#blog0003\n\
    \ */\nstruct rolling_hash {\n    static constexpr int size = 4;\n    static const\
    \ int32_t prime[size];\n    static int32_t base[size];\n    static struct base_initializer_t\
    \ {\n        base_initializer_t() {\n            random_device device;\n     \
    \       default_random_engine gen(device());\n            REP (i, size) {\n  \
    \              base[i] = uniform_int_distribution<int32_t>(256, prime[i] - 1)(gen);\n\
    \            }\n        }\n    } base_initializer;\npublic:\n    array<int32_t,\
    \ size> data;\n    rolling_hash() : data({}) {}\n    rolling_hash(char c) {\n\
    \        REP (i, size) data[i] = c;\n    }\n    rolling_hash(const string & s)\
    \ : data({}) {\n        for (char c : s) push_back(c);\n    }\n    void push_back(char\
    \ c) {\n        REP (i, size) {\n            data[i] = (data[i] *(int64_t) base[i]\
    \ + c) % prime[i];\n        }\n    }\n    rolling_hash & operator += (rolling_hash\
    \ const & other) {\n        REP (i, size) {\n            data[i] += other.data[i];\n\
    \            if (data[i] >= prime[i]) data[i] -= prime[i];\n        }\n      \
    \  return *this;\n    }\n    rolling_hash operator + (rolling_hash const & other)\
    \ const {\n        return rolling_hash(*this) += other;\n    }\n    rolling_hash\
    \ & operator -= (rolling_hash const & other) {\n        REP (i, size) {\n    \
    \        data[i] -= other.data[i];\n            if (data[i] < 0) data[i] += prime[i];\n\
    \        }\n        return *this;\n    }\n    /**\n     * @note O(size)\n    \
    \ */\n    rolling_hash & operator <<= (array<int32_t, size> const & pow_base)\
    \ {\n        REP (i, size) {\n            data[i] = data[i] *(int64_t) pow_base[i]\
    \ % prime[i];\n        }\n        return *this;\n    }\n    /**\n     * @note\
    \ O(size log width)\n     */\n    rolling_hash & operator <<= (int width) {\n\
    \        array<int32_t, size> pow_base;\n        REP (i, size) {\n           \
    \ pow_base[i] = powmod(base[i], width, prime[i]);\n        }\n        return *this\
    \ << pow_base;\n    }\n    rolling_hash operator << (int width) const {\n    \
    \    return rolling_hash(*this) <<= width;\n    }\n    bool operator == (rolling_hash\
    \ const & other) const {\n        return data == other.data;\n    }\n    bool\
    \ operator != (rolling_hash const & other) const {\n        return not (*this\
    \ == other);\n    }\n    friend ostream & operator << (ostream & out, rolling_hash\
    \ const & that) {\n        char buffer[8 * size + 1];\n        REP (i, size) {\n\
    \            sprintf(buffer + 8 * i, \"%08x\", that.data[i]);\n        }\n   \
    \     return out << buffer;\n    }\n};\nconst int32_t rolling_hash::prime[size]\
    \ = { 1000000027, 1000000033, 1000000087, 1000000093 };\nint32_t rolling_hash::base[size];\n\
    rolling_hash::base_initializer_t rolling_hash::base_initializer;\n\nstruct rolling_hash_cumulative_sum\
    \ {\n    rolling_hash_cumulative_sum() = default;\n    int size;\n    vector<rolling_hash>\
    \ data;\n    vector<array<int32_t, rolling_hash::size> > pow_base;\n    rolling_hash_cumulative_sum(string\
    \ const & s) {\n        size = s.length();\n        data.resize(size + 1);\n \
    \       data[0] = rolling_hash();\n        REP (i, size) {\n            data[i\
    \ + 1] = data[i];\n            data[i + 1].push_back(s[i]);\n        }\n     \
    \   pow_base.resize(size + 1);\n        fill(ALL(pow_base[0]), 1);\n        REP\
    \ (i, size) {\n            REP (j, rolling_hash::size) {\n                pow_base[i\
    \ + 1][j] = pow_base[i][j] *(int64_t) rolling_hash::base[j] % rolling_hash::prime[j];\n\
    \            }\n        }\n    }\n    rolling_hash get_initial_segment(int r)\
    \ {\n        assert (0 <= r and r <= size);\n        return data[r];\n    }\n\
    \    /**\n     * @note O(rolling_hash::size)\n     */\n    rolling_hash get_range(int\
    \ l, int r) {\n        assert (0 <= l and l <= r and r <= size);\n        return\
    \ rolling_hash(data[r]) -= (rolling_hash(data[l]) <<= pow_base[r - l]);\n    }\n\
    };\n\n/**\n * @brief an adaptor to a segment tree\n * @note slow\n * @note you\
    \ should use something like cumulative sum\n */\nstruct rolling_hash_monoid {\n\
    \    typedef struct { int length; rolling_hash hash; } value_type;\n    static\
    \ value_type from_char(char c) {\n        return { 1, rolling_hash(c) };\n   \
    \ }\n    value_type unit() const {\n        return { 0, rolling_hash() };\n  \
    \  }\n    value_type append(value_type a, value_type const & b) const {\n    \
    \    if (a.length == 0) return b;\n        if (b.length == 0) return a;\n    \
    \    return { a.length + b.length, (a.hash <<= b.length) += b.hash };\n    }\n\
    };\n\nconstexpr uint64_t prime = 1000000000000037;  // if you didn't shift\nconstexpr\
    \ uint64_t base = 1009;\nconstexpr uint64_t prime = 1000000007;\nconstexpr uint64_t\
    \ base = 10007;\nuint64_t rolling_hash_push(uint64_t hash, int c) {\n    return\
    \ (hash * base + c) % prime;\n}\nuint64_t rolling_hash_shift(uint64_t hash, int\
    \ k) {\n    uint64_t e = base;\n    for (; k; k >>= 1) {\n        if (k & 1) hash\
    \ = hash * e % prime;\n        e = e * e % prime;\n    }\n    return hash;\n}\n\
    vector<uint64_t> rolling_hash_prepare(const vector<int> & s) {\n    vector<uint64_t>\
    \ hash(s.size() + 1);\n    REP (i, s.size()) {\n        hash[i + 1] = rolling_hash_push(hash[i],\
    \ s[i]);\n    }\n    return hash;\n}\nuint64_t rolling_hash_range(const vector<uint64_t>\
    \ & hash, int l, int r) {\n    return (hash[r] - rolling_hash_shift(hash[l], r\
    \ - l) + prime) % prime;\n}\nuint64_t rolling_hash(const vector<int> & s) {\n\
    \    uint64_t hash = 0;\n    for (int c : s) {\n        hash = rolling_hash_push(hash,\
    \ c);\n    }\n    return hash;\n}\n"
  code: "/**\n * @brief a rolling hash\n * @note 4 primes for modulo and and random\
    \ bases\n * @see http://hos.ac/blog/#blog0003\n */\nstruct rolling_hash {\n  \
    \  static constexpr int size = 4;\n    static const int32_t prime[size];\n   \
    \ static int32_t base[size];\n    static struct base_initializer_t {\n       \
    \ base_initializer_t() {\n            random_device device;\n            default_random_engine\
    \ gen(device());\n            REP (i, size) {\n                base[i] = uniform_int_distribution<int32_t>(256,\
    \ prime[i] - 1)(gen);\n            }\n        }\n    } base_initializer;\npublic:\n\
    \    array<int32_t, size> data;\n    rolling_hash() : data({}) {}\n    rolling_hash(char\
    \ c) {\n        REP (i, size) data[i] = c;\n    }\n    rolling_hash(const string\
    \ & s) : data({}) {\n        for (char c : s) push_back(c);\n    }\n    void push_back(char\
    \ c) {\n        REP (i, size) {\n            data[i] = (data[i] *(int64_t) base[i]\
    \ + c) % prime[i];\n        }\n    }\n    rolling_hash & operator += (rolling_hash\
    \ const & other) {\n        REP (i, size) {\n            data[i] += other.data[i];\n\
    \            if (data[i] >= prime[i]) data[i] -= prime[i];\n        }\n      \
    \  return *this;\n    }\n    rolling_hash operator + (rolling_hash const & other)\
    \ const {\n        return rolling_hash(*this) += other;\n    }\n    rolling_hash\
    \ & operator -= (rolling_hash const & other) {\n        REP (i, size) {\n    \
    \        data[i] -= other.data[i];\n            if (data[i] < 0) data[i] += prime[i];\n\
    \        }\n        return *this;\n    }\n    /**\n     * @note O(size)\n    \
    \ */\n    rolling_hash & operator <<= (array<int32_t, size> const & pow_base)\
    \ {\n        REP (i, size) {\n            data[i] = data[i] *(int64_t) pow_base[i]\
    \ % prime[i];\n        }\n        return *this;\n    }\n    /**\n     * @note\
    \ O(size log width)\n     */\n    rolling_hash & operator <<= (int width) {\n\
    \        array<int32_t, size> pow_base;\n        REP (i, size) {\n           \
    \ pow_base[i] = powmod(base[i], width, prime[i]);\n        }\n        return *this\
    \ << pow_base;\n    }\n    rolling_hash operator << (int width) const {\n    \
    \    return rolling_hash(*this) <<= width;\n    }\n    bool operator == (rolling_hash\
    \ const & other) const {\n        return data == other.data;\n    }\n    bool\
    \ operator != (rolling_hash const & other) const {\n        return not (*this\
    \ == other);\n    }\n    friend ostream & operator << (ostream & out, rolling_hash\
    \ const & that) {\n        char buffer[8 * size + 1];\n        REP (i, size) {\n\
    \            sprintf(buffer + 8 * i, \"%08x\", that.data[i]);\n        }\n   \
    \     return out << buffer;\n    }\n};\nconst int32_t rolling_hash::prime[size]\
    \ = { 1000000027, 1000000033, 1000000087, 1000000093 };\nint32_t rolling_hash::base[size];\n\
    rolling_hash::base_initializer_t rolling_hash::base_initializer;\n\nstruct rolling_hash_cumulative_sum\
    \ {\n    rolling_hash_cumulative_sum() = default;\n    int size;\n    vector<rolling_hash>\
    \ data;\n    vector<array<int32_t, rolling_hash::size> > pow_base;\n    rolling_hash_cumulative_sum(string\
    \ const & s) {\n        size = s.length();\n        data.resize(size + 1);\n \
    \       data[0] = rolling_hash();\n        REP (i, size) {\n            data[i\
    \ + 1] = data[i];\n            data[i + 1].push_back(s[i]);\n        }\n     \
    \   pow_base.resize(size + 1);\n        fill(ALL(pow_base[0]), 1);\n        REP\
    \ (i, size) {\n            REP (j, rolling_hash::size) {\n                pow_base[i\
    \ + 1][j] = pow_base[i][j] *(int64_t) rolling_hash::base[j] % rolling_hash::prime[j];\n\
    \            }\n        }\n    }\n    rolling_hash get_initial_segment(int r)\
    \ {\n        assert (0 <= r and r <= size);\n        return data[r];\n    }\n\
    \    /**\n     * @note O(rolling_hash::size)\n     */\n    rolling_hash get_range(int\
    \ l, int r) {\n        assert (0 <= l and l <= r and r <= size);\n        return\
    \ rolling_hash(data[r]) -= (rolling_hash(data[l]) <<= pow_base[r - l]);\n    }\n\
    };\n\n/**\n * @brief an adaptor to a segment tree\n * @note slow\n * @note you\
    \ should use something like cumulative sum\n */\nstruct rolling_hash_monoid {\n\
    \    typedef struct { int length; rolling_hash hash; } value_type;\n    static\
    \ value_type from_char(char c) {\n        return { 1, rolling_hash(c) };\n   \
    \ }\n    value_type unit() const {\n        return { 0, rolling_hash() };\n  \
    \  }\n    value_type append(value_type a, value_type const & b) const {\n    \
    \    if (a.length == 0) return b;\n        if (b.length == 0) return a;\n    \
    \    return { a.length + b.length, (a.hash <<= b.length) += b.hash };\n    }\n\
    };\n\nconstexpr uint64_t prime = 1000000000000037;  // if you didn't shift\nconstexpr\
    \ uint64_t base = 1009;\nconstexpr uint64_t prime = 1000000007;\nconstexpr uint64_t\
    \ base = 10007;\nuint64_t rolling_hash_push(uint64_t hash, int c) {\n    return\
    \ (hash * base + c) % prime;\n}\nuint64_t rolling_hash_shift(uint64_t hash, int\
    \ k) {\n    uint64_t e = base;\n    for (; k; k >>= 1) {\n        if (k & 1) hash\
    \ = hash * e % prime;\n        e = e * e % prime;\n    }\n    return hash;\n}\n\
    vector<uint64_t> rolling_hash_prepare(const vector<int> & s) {\n    vector<uint64_t>\
    \ hash(s.size() + 1);\n    REP (i, s.size()) {\n        hash[i + 1] = rolling_hash_push(hash[i],\
    \ s[i]);\n    }\n    return hash;\n}\nuint64_t rolling_hash_range(const vector<uint64_t>\
    \ & hash, int l, int r) {\n    return (hash[r] - rolling_hash_shift(hash[l], r\
    \ - l) + prime) % prime;\n}\nuint64_t rolling_hash(const vector<int> & s) {\n\
    \    uint64_t hash = 0;\n    for (int c : s) {\n        hash = rolling_hash_push(hash,\
    \ c);\n    }\n    return hash;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/rolling-hash.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/rolling-hash.inc.cpp
layout: document
redirect_from:
- /library/old/rolling-hash.inc.cpp
- /library/old/rolling-hash.inc.cpp.html
title: a rolling hash
---
