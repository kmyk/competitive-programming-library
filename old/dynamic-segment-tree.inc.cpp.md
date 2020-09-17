---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://arc054.contest.atcoder.jp/submissions/1335245
    - https://csacademy.com/contest/ceoi-2018-day-2/task/fibonacci-representations-small/
  bundledCode: "#line 1 \"old/dynamic-segment-tree.inc.cpp\"\n/**\n * @note verified\
    \ http://arc054.contest.atcoder.jp/submissions/1335245\n * @note verified https://csacademy.com/contest/ceoi-2018-day-2/task/fibonacci-representations-small/\n\
    \ * @note you can implement this with unordered_map, but the constructor requires\
    \ the size\n */\ntemplate <class Monoid>\nstruct dynamic_segment_tree { // on\
    \ monoid\n    typedef Monoid monoid_type;\n    typedef typename Monoid::value_type\
    \ value_type;\n    struct node_t {\n        int left, right; // indices on pool\n\
    \        value_type value;\n    };\n    deque<node_t> pool;\n    stack<int> bin;\n\
    \    int root; // index\n    ll width; // of the tree\n    int size; // the number\
    \ of leaves\n    Monoid mon;\n    dynamic_segment_tree(Monoid const & a_mon =\
    \ Monoid()) : mon(a_mon) {\n        node_t node = { -1, -1, mon.unit() };\n  \
    \      pool.push_back(node);\n        root = 0;\n        width = 1;\n        size\
    \ = 1;\n    }\nprotected:\n    int create_node(int parent, bool is_right) {\n\
    \        // make a new node\n        int i;\n        if (bin.empty()) {\n    \
    \        i = pool.size();\n            node_t node = { -1, -1, mon.unit() };\n\
    \            pool.push_back(node);\n        } else {\n            i = bin.top();\n\
    \            bin.pop();\n            pool[i] = { -1, -1, mon.unit() };\n     \
    \   }\n        // link from the parent\n        assert (parent != -1);\n     \
    \   int & ptr = is_right ? pool[parent].right : pool[parent].left;\n        assert\
    \ (ptr == -1);\n        ptr = i;\n        return i;\n    }\n    value_type get_value(int\
    \ i) {\n        return i == -1 ? mon.unit() : pool[i].value;\n    }\npublic:\n\
    \    void point_set(ll i, value_type z) {\n        assert (0 <= i);\n        while\
    \ (width <= i) {\n            node_t node = { root, -1, pool[root].value };\n\
    \            root = pool.size();\n            pool.push_back(node);\n        \
    \    width *= 2;\n        }\n        point_set(root, -1, false, 0, width, i, z);\n\
    \    }\n    void point_set(int i, int parent, bool is_right, ll il, ll ir, ll\
    \ j, value_type z) {\n        if (il == j and ir == j + 1) { // 0-based\n    \
    \        if (i == -1) {\n                i = create_node(parent, is_right);\n\
    \                size += 1;\n            }\n            pool[i].value = z;\n \
    \       } else if (ir <= j or j + 1 <= il) {\n            // nop\n        } else\
    \ {\n            if (i == -1) i = create_node(parent, is_right);\n           \
    \ point_set(pool[i].left,  i, false, il, (il + ir) / 2, j, z);\n            point_set(pool[i].right,\
    \ i, true,  (il + ir) / 2, ir, j, z);\n            pool[i].value = mon.append(get_value(pool[i].left),\
    \ get_value(pool[i].right));\n        }\n    }\n    void point_delete(ll i) {\n\
    \        assert (0 <= i);\n        if (width <= i) return;\n        root = point_delete(root,\
    \ -1, false, 0, width, i);\n    }\n    int point_delete(int i, int parent, bool\
    \ is_right, ll il, ll ir, ll j) {\n        if (i == -1) {\n            return\
    \ -1;\n        } else if (il == j and ir == j + 1) { // 0-based\n            bin.push(i);\n\
    \            size -= 1;\n            return -1;\n        } else if (ir <= j or\
    \ j + 1 <= il) {\n            return i;\n        } else {\n            pool[i].left\
    \  = point_delete(pool[i].left,  i, false, il, (il + ir) / 2, j);\n          \
    \  pool[i].right = point_delete(pool[i].right, i, true,  (il + ir) / 2, ir, j);\n\
    \            if (pool[i].left == -1 and pool[i].right == -1 and i != root) {\n\
    \                bin.push(i);\n                size -= 1;\n                return\
    \ -1;\n            } else {\n                pool[i].value = mon.append(get_value(pool[i].left),\
    \ get_value(pool[i].right));\n                return i;\n            }\n     \
    \   }\n    }\n    value_type range_concat(ll l, ll r) {\n        assert (0 <=\
    \ l and l <= r);\n        if (width <= l) return mon.unit();\n        return range_concat(root,\
    \ 0, width, l, min(width, r));\n    }\n    value_type range_concat(int i, ll il,\
    \ ll ir, ll l, ll r) {\n        if (i == -1) return mon.unit();\n        if (l\
    \ <= il and ir <= r) { // 0-based\n            return pool[i].value;\n       \
    \ } else if (ir <= l or r <= il) {\n            return mon.unit();\n        }\
    \ else {\n            return mon.append(\n                    range_concat(pool[i].left,\
    \  il, (il + ir) / 2, l, r),\n                    range_concat(pool[i].right,\
    \ (il + ir) / 2, ir, l, r));\n        }\n    }\n    template <class Func>\n  \
    \  void traverse_leaves(Func func) {\n        return traverse_leaves(root, 0,\
    \ width, func);\n    }\n    template <class Func>\n    void traverse_leaves(ll\
    \ i, ll il, ll ir, Func func) {\n        if (i == -1) return;\n        if (ir\
    \ - il == 1) {\n            func(il, pool[i].value);\n        } else {\n     \
    \       traverse_leaves(pool[i].left,  il, (il + ir) / 2, func);\n           \
    \ traverse_leaves(pool[i].right, (il + ir) / 2, ir, func);\n        }\n    }\n\
    };\n"
  code: "/**\n * @note verified http://arc054.contest.atcoder.jp/submissions/1335245\n\
    \ * @note verified https://csacademy.com/contest/ceoi-2018-day-2/task/fibonacci-representations-small/\n\
    \ * @note you can implement this with unordered_map, but the constructor requires\
    \ the size\n */\ntemplate <class Monoid>\nstruct dynamic_segment_tree { // on\
    \ monoid\n    typedef Monoid monoid_type;\n    typedef typename Monoid::value_type\
    \ value_type;\n    struct node_t {\n        int left, right; // indices on pool\n\
    \        value_type value;\n    };\n    deque<node_t> pool;\n    stack<int> bin;\n\
    \    int root; // index\n    ll width; // of the tree\n    int size; // the number\
    \ of leaves\n    Monoid mon;\n    dynamic_segment_tree(Monoid const & a_mon =\
    \ Monoid()) : mon(a_mon) {\n        node_t node = { -1, -1, mon.unit() };\n  \
    \      pool.push_back(node);\n        root = 0;\n        width = 1;\n        size\
    \ = 1;\n    }\nprotected:\n    int create_node(int parent, bool is_right) {\n\
    \        // make a new node\n        int i;\n        if (bin.empty()) {\n    \
    \        i = pool.size();\n            node_t node = { -1, -1, mon.unit() };\n\
    \            pool.push_back(node);\n        } else {\n            i = bin.top();\n\
    \            bin.pop();\n            pool[i] = { -1, -1, mon.unit() };\n     \
    \   }\n        // link from the parent\n        assert (parent != -1);\n     \
    \   int & ptr = is_right ? pool[parent].right : pool[parent].left;\n        assert\
    \ (ptr == -1);\n        ptr = i;\n        return i;\n    }\n    value_type get_value(int\
    \ i) {\n        return i == -1 ? mon.unit() : pool[i].value;\n    }\npublic:\n\
    \    void point_set(ll i, value_type z) {\n        assert (0 <= i);\n        while\
    \ (width <= i) {\n            node_t node = { root, -1, pool[root].value };\n\
    \            root = pool.size();\n            pool.push_back(node);\n        \
    \    width *= 2;\n        }\n        point_set(root, -1, false, 0, width, i, z);\n\
    \    }\n    void point_set(int i, int parent, bool is_right, ll il, ll ir, ll\
    \ j, value_type z) {\n        if (il == j and ir == j + 1) { // 0-based\n    \
    \        if (i == -1) {\n                i = create_node(parent, is_right);\n\
    \                size += 1;\n            }\n            pool[i].value = z;\n \
    \       } else if (ir <= j or j + 1 <= il) {\n            // nop\n        } else\
    \ {\n            if (i == -1) i = create_node(parent, is_right);\n           \
    \ point_set(pool[i].left,  i, false, il, (il + ir) / 2, j, z);\n            point_set(pool[i].right,\
    \ i, true,  (il + ir) / 2, ir, j, z);\n            pool[i].value = mon.append(get_value(pool[i].left),\
    \ get_value(pool[i].right));\n        }\n    }\n    void point_delete(ll i) {\n\
    \        assert (0 <= i);\n        if (width <= i) return;\n        root = point_delete(root,\
    \ -1, false, 0, width, i);\n    }\n    int point_delete(int i, int parent, bool\
    \ is_right, ll il, ll ir, ll j) {\n        if (i == -1) {\n            return\
    \ -1;\n        } else if (il == j and ir == j + 1) { // 0-based\n            bin.push(i);\n\
    \            size -= 1;\n            return -1;\n        } else if (ir <= j or\
    \ j + 1 <= il) {\n            return i;\n        } else {\n            pool[i].left\
    \  = point_delete(pool[i].left,  i, false, il, (il + ir) / 2, j);\n          \
    \  pool[i].right = point_delete(pool[i].right, i, true,  (il + ir) / 2, ir, j);\n\
    \            if (pool[i].left == -1 and pool[i].right == -1 and i != root) {\n\
    \                bin.push(i);\n                size -= 1;\n                return\
    \ -1;\n            } else {\n                pool[i].value = mon.append(get_value(pool[i].left),\
    \ get_value(pool[i].right));\n                return i;\n            }\n     \
    \   }\n    }\n    value_type range_concat(ll l, ll r) {\n        assert (0 <=\
    \ l and l <= r);\n        if (width <= l) return mon.unit();\n        return range_concat(root,\
    \ 0, width, l, min(width, r));\n    }\n    value_type range_concat(int i, ll il,\
    \ ll ir, ll l, ll r) {\n        if (i == -1) return mon.unit();\n        if (l\
    \ <= il and ir <= r) { // 0-based\n            return pool[i].value;\n       \
    \ } else if (ir <= l or r <= il) {\n            return mon.unit();\n        }\
    \ else {\n            return mon.append(\n                    range_concat(pool[i].left,\
    \  il, (il + ir) / 2, l, r),\n                    range_concat(pool[i].right,\
    \ (il + ir) / 2, ir, l, r));\n        }\n    }\n    template <class Func>\n  \
    \  void traverse_leaves(Func func) {\n        return traverse_leaves(root, 0,\
    \ width, func);\n    }\n    template <class Func>\n    void traverse_leaves(ll\
    \ i, ll il, ll ir, Func func) {\n        if (i == -1) return;\n        if (ir\
    \ - il == 1) {\n            func(il, pool[i].value);\n        } else {\n     \
    \       traverse_leaves(pool[i].left,  il, (il + ir) / 2, func);\n           \
    \ traverse_leaves(pool[i].right, (il + ir) / 2, ir, func);\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: old/dynamic-segment-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/dynamic-segment-tree.inc.cpp
layout: document
redirect_from:
- /library/old/dynamic-segment-tree.inc.cpp
- /library/old/dynamic-segment-tree.inc.cpp.html
title: old/dynamic-segment-tree.inc.cpp
---
