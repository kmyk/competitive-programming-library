---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "strongly connected components decomposition, Kosaraju's algorithm / \u5F37\
      \u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/transpose_graph.hpp
    title: graph/transpose_graph.hpp
  - icon: ':heavy_check_mark:'
    path: hack/fastio.hpp
    title: hack/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: utils/macros.hpp
    title: utils/macros.hpp
  - icon: ':heavy_check_mark:'
    path: utils/two_satisfiability.hpp
    title: 2-SAT ($O(N)$)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"utils/two_satisfiability.yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#include <cassert>\n#include <vector>\n\
    #include <utility>\n#line 2 \"utils/macros.hpp\"\n#define REP(i, n) for (int i\
    \ = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i = (m); (i) <\
    \ (int)(n); ++ (i))\n#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0;\
    \ -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m);\
    \ -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n#line 2 \"hack/fastio.hpp\"\
    \n#include <cstdint>\n#include <cstdio>\n#include <string>\n#include <type_traits>\n\
    \ntemplate <class Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\n\
    inline Char in() { return getchar_unlocked(); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline std::string in() {\n    char c; do { c = getchar_unlocked();\
    \ } while (isspace(c));\n    std::string s;\n    do { s.push_back(c); } while\
    \ (not isspace(c = getchar_unlocked()));\n    return s;\n}\ntemplate <class Integer,\
    \ std::enable_if_t<std::is_integral_v<Integer> and not std::is_same_v<Integer,\
    \ char>, int> = 0>\ninline Integer in() {\n    char c; do { c = getchar_unlocked();\
    \ } while (isspace(c));\n    if (std::is_signed<Integer>::value and c == '-')\
    \ return -in<Integer>();\n    Integer n = 0;\n    do { n = n * 10 + c - '0'; }\
    \ while (not isspace(c = getchar_unlocked()));\n    return n;\n}\n\ntemplate <class\
    \ Char, std::enable_if_t<std::is_same_v<Char, char>, int> = 0>\ninline void out(char\
    \ c) { putchar_unlocked(c); }\ntemplate <class String, std::enable_if_t<std::is_same_v<String,\
    \ std::string>, int> = 0>\ninline void out(const std::string & s) { for (char\
    \ c : s) putchar_unlocked(c); }\ntemplate <class Integer, std::enable_if_t<std::is_integral_v<Integer>,\
    \ int> = 0>\ninline void out(Integer n) {\n    char s[20];\n    int i = 0;\n \
    \   if (std::is_signed<Integer>::value and n < 0) { putchar_unlocked('-'); n *=\
    \ -1; }\n    do { s[i ++] = n % 10; n /= 10; } while (n);\n    while (i) putchar_unlocked(s[--\
    \ i] + '0');\n}\n#line 2 \"graph/strongly_connected_components.hpp\"\n#include\
    \ <functional>\n#line 4 \"graph/transpose_graph.hpp\"\n\n/**\n * @param g is an\
    \ adjacent list of a digraph\n * @note $O(V + E)$\n * @see https://en.wikipedia.org/wiki/Transpose_graph\n\
    \ */\nstd::vector<std::vector<int> > make_transpose_graph(std::vector<std::vector<int>\
    \ > const & g) {\n    int n = g.size();\n    std::vector<std::vector<int> > h(n);\n\
    \    REP (i, n) {\n        for (int j : g[i]) {\n            h[j].push_back(i);\n\
    \        }\n    }\n    return h;\n}\n#line 7 \"graph/strongly_connected_components.hpp\"\
    \n\n/**\n * @brief strongly connected components decomposition, Kosaraju's algorithm\
    \ / \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @return the pair (the number\
    \ k of components, the function from vertices of g to components)\n * @param g\
    \ is an adjacent list of a digraph\n * @param g_rev is the transpose graph of\
    \ g\n * @note $O(V + E)$\n */\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g, const std::vector<std::vector<int> > & g_rev)\
    \ {\n    int n = g.size();\n    std::vector<int> acc(n); {\n        std::vector<bool>\
    \ used(n);\n        std::function<void (int)> dfs = [&](int i) {\n           \
    \ used[i] = true;\n            for (int j : g[i]) if (not used[j]) dfs(j);\n \
    \           acc.push_back(i);\n        };\n        REP (i,n) if (not used[i])\
    \ dfs(i);\n        reverse(ALL(acc));\n    }\n    int size = 0;\n    std::vector<int>\
    \ component_of(n); {\n        std::vector<bool> used(n);\n        std::function<void\
    \ (int)> rdfs = [&](int i) {\n            used[i] = true;\n            component_of[i]\
    \ = size;\n            for (int j : g_rev[i]) if (not used[j]) rdfs(j);\n    \
    \    };\n        for (int i : acc) if (not used[i]) {\n            rdfs(i);\n\
    \            ++ size;\n        }\n    }\n    return { size, move(component_of)\
    \ };\n}\n\nstd::pair<int, std::vector<int> > decompose_to_strongly_connected_components(const\
    \ std::vector<std::vector<int> > & g) {\n    return decompose_to_strongly_connected_components(g,\
    \ make_transpose_graph(g));\n}\n#line 6 \"utils/two_satisfiability.hpp\"\n\n/**\n\
    \ * @brief 2-SAT ($O(N)$)\n * @param n is the number of variables\n * @param cnf\
    \ is a proposition in a conjunctive normal form. Each literal is expressed as\
    \ number $x$ s.t. $1 \\le \\vert x \\vert \\le n$\n * @return a vector with the\
    \ length $n$ if SAT. It's empty if UNSAT.\n */\nstd::vector<bool> compute_two_satisfiability(int\
    \ n, const std::vector<std::pair<int, int> > & cnf) {\n    // make digraph\n \
    \   std::vector<std::vector<int> > g(2 * n);\n    auto index = [&](int x) {\n\
    \        assert (x != 0 and abs(x) <= n);\n        return x > 0 ? x - 1 : n -\
    \ x - 1;\n    };\n    for (auto it : cnf) {\n        int x, y; std::tie(x, y)\
    \ = it;  // x or y\n        g[index(- x)].push_back(index(y));  // not x implies\
    \ y\n        g[index(- y)].push_back(index(x));  // not y implies x\n    }\n\n\
    \    // do SCC\n    std::vector<int> component = decompose_to_strongly_connected_components(g).second;\n\
    \    std::vector<bool> valuation(n);\n    REP3 (x, 1, n + 1) {\n        if (component[index(x)]\
    \ == component[index(- x)]) {  // x iff not x\n            return std::vector<bool>();\
    \  // unsat\n        }\n        valuation[x - 1] = component[index(x)] > component[index(-\
    \ x)];  // use components which indices are large\n    }\n    return valuation;\n\
    }\n#line 8 \"utils/two_satisfiability.yosupo.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n    // read the header of DIMACS format\n    char const_p = in<char>();\n\
    \    assert (const_p == 'p');\n    string const_cnf = in<string>();\n    assert\
    \ (const_cnf == \"cnf\");\n\n    // input\n    int n = in<int>();\n    int m =\
    \ in<int>();\n    vector<pair<int, int> > cnf;\n    REP (i, m) {\n        int\
    \ a = in<int>();\n        int b = in<int>();\n        cnf.emplace_back(a, b);\n\
    \n        int const_zero = in<int>();\n        assert (const_zero == 0);\n   \
    \ }\n\n    // solve\n    vector<bool> model = compute_two_satisfiability(n, cnf);\n\
    \n    // output\n    if (model.empty()) {\n        out<string>(\"s UNSATISFIABLE\\\
    n\");\n    } else {\n        out<string>(\"s SATISFIABLE\\n\");\n        out<char>('v');\n\
    \        REP (i, n) {\n            out<char>(' ');\n            out<int>((model[i]\
    \ ? 1 : -1) * (i + 1));\n        }\n        out<string>(\" 0 \\n\");\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <cassert>\n\
    #include <vector>\n#include <utility>\n#include \"utils/macros.hpp\"\n#include\
    \ \"hack/fastio.hpp\"\n#include \"utils/two_satisfiability.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    // read the header of DIMACS format\n    char const_p\
    \ = in<char>();\n    assert (const_p == 'p');\n    string const_cnf = in<string>();\n\
    \    assert (const_cnf == \"cnf\");\n\n    // input\n    int n = in<int>();\n\
    \    int m = in<int>();\n    vector<pair<int, int> > cnf;\n    REP (i, m) {\n\
    \        int a = in<int>();\n        int b = in<int>();\n        cnf.emplace_back(a,\
    \ b);\n\n        int const_zero = in<int>();\n        assert (const_zero == 0);\n\
    \    }\n\n    // solve\n    vector<bool> model = compute_two_satisfiability(n,\
    \ cnf);\n\n    // output\n    if (model.empty()) {\n        out<string>(\"s UNSATISFIABLE\\\
    n\");\n    } else {\n        out<string>(\"s SATISFIABLE\\n\");\n        out<char>('v');\n\
    \        REP (i, n) {\n            out<char>(' ');\n            out<int>((model[i]\
    \ ? 1 : -1) * (i + 1));\n        }\n        out<string>(\" 0 \\n\");\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - utils/macros.hpp
  - hack/fastio.hpp
  - utils/two_satisfiability.hpp
  - graph/strongly_connected_components.hpp
  - graph/transpose_graph.hpp
  isVerificationFile: true
  path: utils/two_satisfiability.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-06-13 00:00:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: utils/two_satisfiability.yosupo.test.cpp
layout: document
redirect_from:
- /verify/utils/two_satisfiability.yosupo.test.cpp
- /verify/utils/two_satisfiability.yosupo.test.cpp.html
title: utils/two_satisfiability.yosupo.test.cpp
---
