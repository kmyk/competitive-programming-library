---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree_decomposition.hpp
    title: "\u6728\u5206\u89E3 (\u6728\u5E45 $t \\le 2$)"
  - icon: ':question:'
    path: modulus/mint.hpp
    title: "quotient ring / \u5270\u4F59\u74B0 $\\mathbb{Z}/n\\mathbb{Z}$"
  - icon: ':question:'
    path: modulus/modinv.hpp
    title: modulus/modinv.hpp
  - icon: ':question:'
    path: modulus/modpow.hpp
    title: modulus/modpow.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405
  bundledCode: "#line 1 \"graph/tree_decomposition.aoj_2405.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405\"\n#include\
    \ <cstdio>\n#line 2 \"graph/tree_decomposition.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#line 5 \"graph/tree_decomposition.hpp\"\n#include <cstdint>\n#include\
    \ <functional>\n#include <set>\n#include <stack>\n#include <tuple>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utils/macros.hpp\"\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) -\
    \ 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i)\
    \ >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 14 \"\
    graph/tree_decomposition.hpp\"\n\n/**\n * @brief \u6728\u5206\u89E3 (\u6728\u5E45\
    \ $t \\le 2$)\n * @docs graph/tree_decomposition.md\n * @note $O(N)$ ?\n * @see\
    \ https://ei1333.hateblo.jp/entry/2020/02/12/150319\n * @arg g is a simple connected\
    \ graph $G = (V, E)$ whose treewidth $t \\le 2$\n * @return a decomposed tree\
    \ $T = (I, F)$ as a triple of (the root, the list of children $c : I \\to \\mathcal{P}\
    \ \\to I$, what vertices are contained $X : I \\to \\mathcal{P}(V)$)\n */\ninline\
    \ std::pair<std::vector<int>, std::vector<std::vector<int> > > get_tree_decomposition(const\
    \ std::vector<std::vector<int> > & g) {\n    int n = g.size();\n\n    // prepare\
    \ the info about g\n    std::vector<int> used(n, -1);\n    std::vector<int> degree(n);\n\
    \    std::unordered_set<int64_t> edges;\n    auto pack = [&](int x, int y) {\n\
    \        if (x > y) std::swap(x, y);\n        return ((int64_t)x << 32) | y;\n\
    \    };\n    REP (x, n) {\n        degree[x] = g[x].size();\n        for (int\
    \ y : g[x]) if (x < y) {\n            edges.insert(pack(x, y));\n        }\n \
    \   }\n\n    // prepare the info about t\n    std::vector<int> parent;\n    std::vector<int>\
    \ antecedent;\n    std::function<int (int)> find_root = [&](int a) {\n       \
    \ // union-find tree with only path-compression\n        return (antecedent[a]\
    \ == -1 ? a : antecedent[a] = find_root(antecedent[a]));\n    };\n    std::vector<std::vector<int>\
    \ > bags;\n\n    // construct the tree with a stack\n    std::stack<int> stk;\n\
    \    REP (x, n) {\n        if (g[x].size() <= 2) {\n            stk.push(x);\n\
    \        }\n    }\n    while (not stk.empty()) {\n        int x = stk.top();\n\
    \        stk.pop();\n        if (degree[x] == 0) continue;\n        used[x] =\
    \ bags.size();\n        parent.push_back(-1);\n        antecedent.push_back(-1);\n\
    \        bags.emplace_back();\n        auto & bag = bags.back();\n\n        //\
    \ make the new bag\n        bag.push_back(x);\n        for (int y : g[x]) {\n\
    \            if (used[y] == -1) {\n                // add a vertex y into the\
    \ new bag\n                bag.push_back(y);\n\n            } else if (used[y]\
    \ >= 0) {\n                // connect a bag used[y] as a child\n             \
    \   int root = find_root(used[y]);\n                if (root == used[x]) {\n \
    \                   // nop\n\n                } else if (bags[used[y]].size()\
    \ == 2) {\n                    // the sub-bag is removing a vertex\n         \
    \           if (parent[root] == -1) {\n                        parent[root] =\
    \ antecedent[root] = used[x];\n                    }\n                    assert\
    \ (bags[used[y]][1] == x);\n                    bag.push_back(y);\n\n        \
    \        } else if (bags[used[y]].size() == 3) {\n                    // the sub-bag\
    \ is removing an edge\n                    if (parent[root] == -1) {\n       \
    \                 parent[root] = antecedent[root] = used[x];\n               \
    \     }\n                    assert (bags[root][1] == x or bags[root][2] == x);\n\
    \                    bag.push_back(bags[root][1] ^ bags[root][2] ^ x);\n     \
    \               used[bags[root][0]] = used[x];\n                } else {\n   \
    \                 assert (false);\n                }\n\n            } else {\n\
    \                // nop\n            }\n        }\n        std::sort(bag.begin()\
    \ + 1, bag.end());\n        bag.erase(std::unique(bag.begin() + 1, bag.end()),\
    \ bag.end());\n        assert (bag.size() == degree[x] + 1);\n\n        // remove\
    \ and add edges\n        auto decr = [&](int y) {\n            -- degree[y];\n\
    \            if (degree[y] == 2) {\n                stk.push(y);\n           \
    \ }\n        };\n        if (degree[x] == 1) {\n            decr(bag[1]);\n  \
    \      } if (degree[x] == 2) {\n            if (not edges.insert(pack(bag[1],\
    \ bag[2])).second) {\n                decr(bag[1]);\n                decr(bag[2]);\n\
    \            }\n        }\n        degree[x] = 0;\n    }\n\n    if (std::count(ALL(degree),\
    \ 0) != n) return std::make_pair(std::vector<int>(), std::vector<std::vector<int>\
    \ >());\n    assert (std::count(ALL(parent), -1) == 1);\n    return std::make_pair(parent,\
    \ bags);\n}\n\nenum nice_tree_decomposition_tag {\n    LEAF,\n    INTRODUCE,\n\
    \    FORGET,\n    JOIN,\n};\n\n/**\n * @note $O(t N)$\n */\ninline std::vector<std::tuple<nice_tree_decomposition_tag,\
    \ int, int> > get_nice_tree_decomposition(const std::vector<int> & parent, const\
    \ std::vector<std::vector<int> > & bags) {\n    assert (not parent.empty());\n\
    \    assert (parent.back() == -1);  // assume that vertices are topologically\
    \ sorted and reversed\n    int n = parent.size();\n    std::vector<std::vector<int>\
    \ > children(n);\n    std::vector<int> node(n, -1);\n    std::vector<std::tuple<nice_tree_decomposition_tag,\
    \ int, int> > nice;\n    REP (a, n) {\n        assert (not bags[a].empty());\n\
    \        if (children[a].empty()) {\n            for (int x : bags[a]) {\n   \
    \             if (x == bags[a].front()) {\n                    nice.emplace_back(LEAF,\
    \ x, -1);\n                } else {\n                    nice.emplace_back(INTRODUCE,\
    \ x, nice.size() - 1);\n                }\n            }\n            node[a]\
    \ = nice.size() - 1;\n        } else {\n            for (int b : children[a])\
    \ {\n                for (int y : bags[b]) {\n                    if (not count(ALL(bags[a]),\
    \ y)) {\n                        nice.emplace_back(FORGET, y, node[b]);\n    \
    \                    node[b] = nice.size() - 1;\n                    }\n     \
    \           }\n                for (int x : bags[a]) {\n                    if\
    \ (not count(ALL(bags[b]), x)) {\n                        nice.emplace_back(INTRODUCE,\
    \ x, node[b]);\n                        node[b] = nice.size() - 1;\n         \
    \           }\n                }\n                if (b == children[a].front())\
    \ {\n                    std::swap(node[a], node[b]);\n                } else\
    \ {\n                    nice.emplace_back(JOIN, node[a], node[b]);\n        \
    \            node[a] = nice.size() - 1;\n                }\n            }\n  \
    \      }\n        if (parent[a] != -1) {\n            children[parent[a]].push_back(a);\n\
    \        }\n    };\n    for (int x : bags.back()) {\n        nice.emplace_back(FORGET,\
    \ x, node.back());\n        node.back() = nice.size() - 1;\n    }\n    return\
    \ nice;\n}\n#line 3 \"modulus/mint.hpp\"\n#include <iostream>\n#line 4 \"modulus/modpow.hpp\"\
    \n\ninline int32_t modpow(uint_fast64_t x, uint64_t k, int32_t MOD) {\n    assert\
    \ (/* 0 <= x and */ x < (uint_fast64_t)MOD);\n    uint_fast64_t y = 1;\n    for\
    \ (; k; k >>= 1) {\n        if (k & 1) (y *= x) %= MOD;\n        (x *= x) %= MOD;\n\
    \    }\n    assert (/* 0 <= y and */ y < (uint_fast64_t)MOD);\n    return y;\n\
    }\n#line 5 \"modulus/modinv.hpp\"\n\ninline int32_t modinv_nocheck(int32_t value,\
    \ int32_t MOD) {\n    assert (0 <= value and value < MOD);\n    if (value == 0)\
    \ return -1;\n    int64_t a = value, b = MOD;\n    int64_t x = 0, y = 1;\n   \
    \ for (int64_t u = 1, v = 0; a; ) {\n        int64_t q = b / a;\n        x -=\
    \ q * u; std::swap(x, u);\n        y -= q * v; std::swap(y, v);\n        b -=\
    \ q * a; std::swap(b, a);\n    }\n    if (not (value * x + MOD * y == b and b\
    \ == 1)) return -1;\n    if (x < 0) x += MOD;\n    assert (0 <= x and x < MOD);\n\
    \    return x;\n}\n\ninline int32_t modinv(int32_t x, int32_t MOD) {\n    int32_t\
    \ y = modinv_nocheck(x, MOD);\n    assert (y != -1);\n    return y;\n}\n#line\
    \ 6 \"modulus/mint.hpp\"\n\n/**\n * @brief quotient ring / \u5270\u4F59\u74B0\
    \ $\\mathbb{Z}/n\\mathbb{Z}$\n */\ntemplate <int32_t MOD>\nstruct mint {\n   \
    \ int32_t value;\n    mint() : value() {}\n    mint(int64_t value_) : value(value_\
    \ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}\n    mint(int32_t\
    \ value_, std::nullptr_t) : value(value_) {}\n    explicit operator bool() const\
    \ { return value; }\n    inline mint<MOD> operator + (mint<MOD> other) const {\
    \ return mint<MOD>(*this) += other; }\n    inline mint<MOD> operator - (mint<MOD>\
    \ other) const { return mint<MOD>(*this) -= other; }\n    inline mint<MOD> operator\
    \ * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }\n    inline\
    \ mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value\
    \ >= MOD) this->value -= MOD; return *this; }\n    inline mint<MOD> & operator\
    \ -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value\
    \ += MOD; return *this; }\n    inline mint<MOD> & operator *= (mint<MOD> other)\
    \ { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this;\
    \ }\n    inline mint<MOD> operator - () const { return mint<MOD>(this->value ?\
    \ MOD - this->value : 0, nullptr); }\n    inline bool operator == (mint<MOD> other)\
    \ const { return value == other.value; }\n    inline bool operator != (mint<MOD>\
    \ other) const { return value != other.value; }\n    inline mint<MOD> pow(uint64_t\
    \ k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }\n    inline mint<MOD>\
    \ inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }\n    inline mint<MOD>\
    \ operator / (mint<MOD> other) const { return *this * other.inv(); }\n    inline\
    \ mint<MOD> & operator /= (mint<MOD> other) { return *this *= other.inv(); }\n\
    };\ntemplate <int32_t MOD> mint<MOD> operator + (int64_t value, mint<MOD> n) {\
    \ return mint<MOD>(value) + n; }\ntemplate <int32_t MOD> mint<MOD> operator -\
    \ (int64_t value, mint<MOD> n) { return mint<MOD>(value) - n; }\ntemplate <int32_t\
    \ MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value)\
    \ * n; }\ntemplate <int32_t MOD> mint<MOD> operator / (int64_t value, mint<MOD>\
    \ n) { return mint<MOD>(value) / n; }\ntemplate <int32_t MOD> std::istream & operator\
    \ >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value;\
    \ return in; }\ntemplate <int32_t MOD> std::ostream & operator << (std::ostream\
    \ & out, mint<MOD> n) { return out << n.value; }\n#line 6 \"graph/tree_decomposition.aoj_2405.test.cpp\"\
    \nusing namespace std;\n\n\nconstexpr int MOD = 1000003;\nmint<MOD> solve(int\
    \ n, int m, vector<vector<int> > & g) {\n    // add the implicitly given edges\
    \ to g\n    REP (x, n) {\n        g[x].push_back((x + 1) % n);\n        g[(x +\
    \ 1) % n].push_back(x);\n    }\n    REP (x, n) {\n        sort(ALL(g[x]));\n \
    \       g[x].erase(unique(ALL(g[x])), g[x].end());\n    }\n\n    // get a tree\
    \ decomposition\n    auto [parent, bags_] = get_tree_decomposition(g);\n    auto\
    \ nice = get_nice_tree_decomposition(parent, bags_);\n\n    // dp on a nice tree\
    \ decomposition\n    vector<set<int> > bags(nice.size());\n    auto index = [&](int\
    \ a, int x) {\n        assert (bags[a].count(x));\n        return distance(bags[a].begin(),\
    \ bags[a].find(x));\n    };\n    auto translate = [&](int a, int s, int b) {\n\
    \        int t = 0;\n        for (int x : bags[a]) {\n            if (bags[b].count(x)\
    \ and (s & (1 << index(a, x)))) {\n                t |= 1 << index(b, x);\n  \
    \          }\n        }\n        return t;\n    };\n    vector<vector<mint<MOD>\
    \ > > dp(nice.size());\n    REP (a, nice.size()) {\n        auto [tag, x, b] =\
    \ nice[a];\n\n        if (tag == LEAF) {\n            bags[a].insert(x);\n   \
    \         dp[a].resize(1 << bags[a].size());\n            dp[a][0] += 1;\n\n \
    \       } else if (tag == INTRODUCE) {\n            bags[a] = bags[b];\n     \
    \       bags[a].insert(x);\n            assert (bags[a].size() <= 3);\n      \
    \      dp[a].resize(1 << bags[a].size());\n            REP (t, dp[b].size()) {\n\
    \                int s = translate(b, t, a);\n                dp[a][s] += dp[b][t];\n\
    \            }\n\n        } else if (tag == FORGET) {\n            assert (bags[b].count(x));\n\
    \            bags[a] = bags[b];\n            bags[a].erase(x);\n            dp[a].resize(1\
    \ << bags[a].size());\n            REP (t, dp[b].size()) {\n                int\
    \ s = translate(b, t, a);\n                if (t & (1 << index(b, x))) {\n   \
    \                 dp[a][s] += dp[b][t];\n                } else {\n          \
    \          for (int y : g[x]) {\n                        if (bags[a].count(y)\
    \ and not (s & (1 << index(a, y)))) {\n                            int u = s |\
    \ (1 << index(a, y));\n                            dp[a][u] += dp[b][t];\n   \
    \                     }\n                    }\n                }\n          \
    \  }\n\n        } else if (tag == JOIN) {\n            assert (bags[x] == bags[b]);\n\
    \            bags[a] = bags[b];\n            dp[a].resize(1 << bags[a].size());\n\
    \            REP (s, dp[a].size()) {\n                REP (t, dp[a].size()) if\
    \ ((s & t) == 0) {\n                    dp[a][s | t] += dp[x][s] * dp[b][t];\n\
    \                }\n            }\n\n        }\n    }\n    return dp.back().back();\n\
    }\n\nint main() {\n    while (true) {\n        int n, m; scanf(\"%d%d\", &n, &m);\n\
    \        if (n == 0 and m == 0) break;\n        vector<vector<int> > g(n);\n \
    \       REP (i, m) {\n            int a, b; scanf(\"%d%d\", &a, &b);\n       \
    \     -- a;\n            -- b;\n            g[a].push_back(b);\n            g[b].push_back(a);\n\
    \        }\n        mint<MOD> cnt = solve(n, m, g);\n        printf(\"%d\\n\"\
    , cnt.value);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405\"\
    \n#include <cstdio>\n#include \"../graph/tree_decomposition.hpp\"\n#include \"\
    ../modulus/mint.hpp\"\n#include \"../utils/macros.hpp\"\nusing namespace std;\n\
    \n\nconstexpr int MOD = 1000003;\nmint<MOD> solve(int n, int m, vector<vector<int>\
    \ > & g) {\n    // add the implicitly given edges to g\n    REP (x, n) {\n   \
    \     g[x].push_back((x + 1) % n);\n        g[(x + 1) % n].push_back(x);\n   \
    \ }\n    REP (x, n) {\n        sort(ALL(g[x]));\n        g[x].erase(unique(ALL(g[x])),\
    \ g[x].end());\n    }\n\n    // get a tree decomposition\n    auto [parent, bags_]\
    \ = get_tree_decomposition(g);\n    auto nice = get_nice_tree_decomposition(parent,\
    \ bags_);\n\n    // dp on a nice tree decomposition\n    vector<set<int> > bags(nice.size());\n\
    \    auto index = [&](int a, int x) {\n        assert (bags[a].count(x));\n  \
    \      return distance(bags[a].begin(), bags[a].find(x));\n    };\n    auto translate\
    \ = [&](int a, int s, int b) {\n        int t = 0;\n        for (int x : bags[a])\
    \ {\n            if (bags[b].count(x) and (s & (1 << index(a, x)))) {\n      \
    \          t |= 1 << index(b, x);\n            }\n        }\n        return t;\n\
    \    };\n    vector<vector<mint<MOD> > > dp(nice.size());\n    REP (a, nice.size())\
    \ {\n        auto [tag, x, b] = nice[a];\n\n        if (tag == LEAF) {\n     \
    \       bags[a].insert(x);\n            dp[a].resize(1 << bags[a].size());\n \
    \           dp[a][0] += 1;\n\n        } else if (tag == INTRODUCE) {\n       \
    \     bags[a] = bags[b];\n            bags[a].insert(x);\n            assert (bags[a].size()\
    \ <= 3);\n            dp[a].resize(1 << bags[a].size());\n            REP (t,\
    \ dp[b].size()) {\n                int s = translate(b, t, a);\n             \
    \   dp[a][s] += dp[b][t];\n            }\n\n        } else if (tag == FORGET)\
    \ {\n            assert (bags[b].count(x));\n            bags[a] = bags[b];\n\
    \            bags[a].erase(x);\n            dp[a].resize(1 << bags[a].size());\n\
    \            REP (t, dp[b].size()) {\n                int s = translate(b, t,\
    \ a);\n                if (t & (1 << index(b, x))) {\n                    dp[a][s]\
    \ += dp[b][t];\n                } else {\n                    for (int y : g[x])\
    \ {\n                        if (bags[a].count(y) and not (s & (1 << index(a,\
    \ y)))) {\n                            int u = s | (1 << index(a, y));\n     \
    \                       dp[a][u] += dp[b][t];\n                        }\n   \
    \                 }\n                }\n            }\n\n        } else if (tag\
    \ == JOIN) {\n            assert (bags[x] == bags[b]);\n            bags[a] =\
    \ bags[b];\n            dp[a].resize(1 << bags[a].size());\n            REP (s,\
    \ dp[a].size()) {\n                REP (t, dp[a].size()) if ((s & t) == 0) {\n\
    \                    dp[a][s | t] += dp[x][s] * dp[b][t];\n                }\n\
    \            }\n\n        }\n    }\n    return dp.back().back();\n}\n\nint main()\
    \ {\n    while (true) {\n        int n, m; scanf(\"%d%d\", &n, &m);\n        if\
    \ (n == 0 and m == 0) break;\n        vector<vector<int> > g(n);\n        REP\
    \ (i, m) {\n            int a, b; scanf(\"%d%d\", &a, &b);\n            -- a;\n\
    \            -- b;\n            g[a].push_back(b);\n            g[b].push_back(a);\n\
    \        }\n        mint<MOD> cnt = solve(n, m, g);\n        printf(\"%d\\n\"\
    , cnt.value);\n    }\n    return 0;\n}\n"
  dependsOn:
  - graph/tree_decomposition.hpp
  - utils/macros.hpp
  - modulus/mint.hpp
  - modulus/modpow.hpp
  - modulus/modinv.hpp
  isVerificationFile: true
  path: graph/tree_decomposition.aoj_2405.test.cpp
  requiredBy: []
  timestamp: '2021-08-30 04:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/tree_decomposition.aoj_2405.test.cpp
layout: document
redirect_from:
- /verify/graph/tree_decomposition.aoj_2405.test.cpp
- /verify/graph/tree_decomposition.aoj_2405.test.cpp.html
title: graph/tree_decomposition.aoj_2405.test.cpp
---
