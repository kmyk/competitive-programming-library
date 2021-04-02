---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "get the diameter of a tree / \u6728\u306E\u76F4\u5F84"
    links:
    - http://techtipshoge.blogspot.jp/2016/09/blog-post.html
  bundledCode: "#line 1 \"old/diameter.inc.cpp\"\n/**\n * @brief get the diameter\
    \ of a tree / \u6728\u306E\u76F4\u5F84\n */\n\n/**\n * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html\n\
    \ */\npair<int, int> get_eccentricity(int k, vector<vector<int> > const & tree)\
    \ {\n    pair<int, int> result = { -1, -1 };  // (depth, vertex)\n    function<void\
    \ (int, int, int)> dfs = [&](int i, int parent, int depth) {\n        chmax(result,\
    \ make_pair(depth, i));\n        for (int j : tree[i]) if (j != parent) {\n  \
    \          dfs(j, i, depth + 1);\n        }\n    };\n    dfs(k, -1, 0);\n    return\
    \ result;\n}\nint get_diameter(vector<vector<int> > const & tree) {\n    return\
    \ get_eccentricity(get_eccentricity(0, tree).second, tree).first;\n}\n"
  code: "/**\n * @brief get the diameter of a tree / \u6728\u306E\u76F4\u5F84\n */\n\
    \n/**\n * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html\n */\npair<int,\
    \ int> get_eccentricity(int k, vector<vector<int> > const & tree) {\n    pair<int,\
    \ int> result = { -1, -1 };  // (depth, vertex)\n    function<void (int, int,\
    \ int)> dfs = [&](int i, int parent, int depth) {\n        chmax(result, make_pair(depth,\
    \ i));\n        for (int j : tree[i]) if (j != parent) {\n            dfs(j, i,\
    \ depth + 1);\n        }\n    };\n    dfs(k, -1, 0);\n    return result;\n}\n\
    int get_diameter(vector<vector<int> > const & tree) {\n    return get_eccentricity(get_eccentricity(0,\
    \ tree).second, tree).first;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/diameter.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/diameter.inc.cpp
layout: document
redirect_from:
- /library/old/diameter.inc.cpp
- /library/old/diameter.inc.cpp.html
title: "get the diameter of a tree / \u6728\u306E\u76F4\u5F84"
---
