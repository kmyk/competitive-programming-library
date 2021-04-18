---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "get the diameter of a tree / \u6728\u306E\u76F4\u5F84"
    links:
    - http://techtipshoge.blogspot.jp/2016/09/blog-post.html
  bundledCode: "#line 2 \"graph/diameter_of_tree.hpp\"\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n\n/**\n * @brief get the diameter of a tree /\
    \ \u6728\u306E\u76F4\u5F84\n * @note $O(N)$\n * @return (depth, vertex)\n * @sa\
    \ http://techtipshoge.blogspot.jp/2016/09/blog-post.html\n */\nstd::pair<int,\
    \ int> get_eccentricity(int root, const std::vector<std::vector<int> >& tree)\
    \ {\n    std::pair<int, int> result = { -1, -1 };  // (depth, vertex)\n    auto\
    \ dfs = [&](auto&& dfs, int x, int parent, int depth) -> void {\n        result\
    \ = std::max(result, std::make_pair(depth, x));\n        for (int y : tree[x])\
    \ if (y != parent) {\n            dfs(dfs, y, x, depth + 1);\n        }\n    };\n\
    \    dfs(dfs, root, -1, 0);\n    return result;\n}\n\nint get_diameter(const std::vector<std::vector<int>\
    \ >& tree) {\n    return get_eccentricity(get_eccentricity(0, tree).second, tree).first;\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief get the diameter of a tree / \u6728\u306E\u76F4\u5F84\n * @note\
    \ $O(N)$\n * @return (depth, vertex)\n * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html\n\
    \ */\nstd::pair<int, int> get_eccentricity(int root, const std::vector<std::vector<int>\
    \ >& tree) {\n    std::pair<int, int> result = { -1, -1 };  // (depth, vertex)\n\
    \    auto dfs = [&](auto&& dfs, int x, int parent, int depth) -> void {\n    \
    \    result = std::max(result, std::make_pair(depth, x));\n        for (int y\
    \ : tree[x]) if (y != parent) {\n            dfs(dfs, y, x, depth + 1);\n    \
    \    }\n    };\n    dfs(dfs, root, -1, 0);\n    return result;\n}\n\nint get_diameter(const\
    \ std::vector<std::vector<int> >& tree) {\n    return get_eccentricity(get_eccentricity(0,\
    \ tree).second, tree).first;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/diameter_of_tree.hpp
  requiredBy: []
  timestamp: '2021-04-18 22:48:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/diameter_of_tree.hpp
layout: document
redirect_from:
- /library/graph/diameter_of_tree.hpp
- /library/graph/diameter_of_tree.hpp.html
title: "get the diameter of a tree / \u6728\u306E\u76F4\u5F84"
---
