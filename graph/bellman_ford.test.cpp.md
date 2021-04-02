---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: Bellman-Ford algorithm
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/bellman_ford.test.cpp: line 3: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#ifdef USE_SPFA\n#include \"graph/shortest_path_faster_algorithm.hpp\"\nauto\
    \ BELLMAN_FORD = shortest_path_faster_algorithm;\n#else\n#include \"graph/bellman_ford.hpp\"\
    \nauto BELLMAN_FORD = bellman_ford_shortest_path;\n#endif\n\n#include <algorithm>\n\
    #include <iostream>\n#include \"utils/macros.hpp\"\nusing namespace std;\n\nint\
    \ main() {\n    // input\n    int v, e, root; cin >> v >> e >> root;\n    vector<vector<pair<int,\
    \ int64_t> > > g(v);\n    REP (j, e) {\n        int s, t, dist; cin >> s >> t\
    \ >> dist;\n        g[s].emplace_back(t, dist);\n    }\n\n    // solve\n    auto\
    \ dist = BELLMAN_FORD(root, g);\n\n    // output\n    if (count(ALL(dist), LLONG_MIN))\
    \ {\n        cout << \"NEGATIVE CYCLE\" << endl;\n    } else {\n        REP (i,\
    \ v) {\n            if (dist[i] == LLONG_MAX) {\n                cout << \"INF\"\
    \ << endl;\n            } else {\n                cout << dist[i] << endl;\n \
    \           }\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - graph/bellman_ford.hpp
  - utils/macros.hpp
  isVerificationFile: true
  path: graph/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2019-12-20 06:12:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/graph/bellman_ford.test.cpp
- /verify/graph/bellman_ford.test.cpp.html
title: graph/bellman_ford.test.cpp
---
