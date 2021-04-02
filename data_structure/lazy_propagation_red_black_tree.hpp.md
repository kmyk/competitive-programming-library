---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
    title: data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: data_structure/lazy_propagation_red_black_tree.md
    document_title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u8D64\u9ED2\u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/lazy_propagation_red_black_tree.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <memory>\n#include <type_traits>\n\
    #include <vector>\n\n/**\n * @brief Lazy Propagation Segment Tree / \u9045\u5EF6\
    \u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids, \u8D64\u9ED2\u6728\
    )\n * @docs data_structure/lazy_propagation_red_black_tree.md\n * @tparam MonoidX\
    \ is a monoid\n * @tparam MonoidF is a monoid\n * @tparam Action is a function\
    \ phi : F * X -> X where the partial applied phi(f, -) : X -> X is a homomorphism\
    \ on X\n */\ntemplate <class MonoidX, class MonoidF, class Action>\nclass lazy_propagation_red_black_tree\
    \ {\n    static_assert (std::is_invocable_r<typename MonoidX::value_type, Action,\
    \ typename MonoidF::value_type, typename MonoidX::value_type>::value, \"\");\n\
    \    typedef typename MonoidX::value_type value_type;\n    typedef typename MonoidF::value_type\
    \ operator_type;\n\n    enum color_t { BLACK, RED };\n    struct node_t {\n  \
    \      bool is_leaf;\n        value_type data;\n        operator_type lazy;  //\
    \ NOTE: this->lazy is already applied to this->data\n        bool reversed;\n\
    \        color_t color;\n        int rank;\n        int size;\n        node_t\
    \ *left;\n        node_t *right;\n        node_t() = default;\n        node_t(value_type\
    \ const & a_data)\n                : is_leaf(true)\n                , data(a_data)\n\
    \                , color(BLACK)\n                , rank(0)\n                ,\
    \ size(1) {\n        }\n        node_t(node_t *l, node_t *r, color_t c)  // non-leaf\
    \ node\n                : is_leaf(false)\n                , data(MonoidX().mult(l->data,\
    \ r->data))\n                , lazy(MonoidF().unit())\n                , reversed(false)\n\
    \                , color(c)\n                , rank(std::max(l->rank + (l->color\
    \ == BLACK),\n                                r->rank + (r->color == BLACK)))\n\
    \                , size(l->size + r->size)\n                , left(l)\n      \
    \          , right(r) {\n        }\n    };\n    struct node_deleter {\n      \
    \  void operator () (node_t *t) const {\n            assert (t != nullptr);\n\
    \            if (not t->is_leaf) {\n                (*this)(t->right);\n     \
    \           (*this)(t->left);\n            }\n            delete t;\n        }\n\
    \    };\n\n    static void propagate_only_operator(node_t *a) {\n        MonoidF\
    \ mon_f;\n        Action act;\n        if (not a->is_leaf) {\n            if (a->lazy\
    \ != mon_f.unit()) {\n                auto const & l = a->left;\n            \
    \    auto const & r = a->right;\n                l->data = act(a->lazy, l->data);\n\
    \                r->data = act(a->lazy, r->data);\n                if (not l->is_leaf)\
    \ l->lazy = mon_f.mult(a->lazy, l->lazy);\n                if (not r->is_leaf)\
    \ r->lazy = mon_f.mult(a->lazy, r->lazy);\n                a->lazy = mon_f.unit();\n\
    \            }\n        }\n    }\n    static void propagate_only_reverse(node_t\
    \ *a) {\n        if (not a->is_leaf) {\n            if (a->reversed) {\n     \
    \           auto const & l = a->left;\n                auto const & r = a->right;\n\
    \                if (not l->is_leaf) l->reversed = not l->reversed;\n        \
    \        if (not r->is_leaf) r->reversed = not r->reversed;\n                std::swap(a->left,\
    \ a->right);  // CAUTION: auto const & l, r are destroyed\n                a->reversed\
    \ = false;\n            }\n        }\n    }\n    static void propagate(node_t\
    \ *a) {\n        propagate_only_operator(a);\n        propagate_only_reverse(a);\n\
    \    }\n\n    /**\n     * @note trees a, b are consumed  (at set_left()/set_right())\n\
    \     */\n    static node_t *merge(node_t *a, node_t *b) {\n        if (a == nullptr)\
    \ return b;\n        if (b == nullptr) return a;\n        node_t *c = merge_relax(a,\
    \ b);\n        c->color = BLACK;\n        return c;\n    }\n    /*\n     * @note\
    \ the root of returned tree may violates the color constraint\n     */\n    static\
    \ node_t *merge_relax(node_t *a, node_t *b) {\n        if ((a->rank) < b->rank)\
    \ {\n            assert (not b->is_leaf);\n            propagate(b);\n       \
    \     return set_left(b, merge_relax(a, b->left));\n        } else if (a->rank\
    \ > b->rank) {\n            assert (not a->is_leaf);\n            propagate(a);\n\
    \            return set_right(a, merge_relax(a->right, b));\n        } else {\n\
    \            a->color = BLACK;\n            b->color = BLACK;\n            return\
    \ new node_t(a, b, RED);\n        }\n    }\n    static node_t *set_left(node_t\
    \ *b, node_t *c) {\n        if (b->color == BLACK and c->color == RED and c->left->color\
    \ == RED) {\n            if (b->right->color == BLACK) {\n                *b =\
    \ node_t(c->right, b->right, RED);\n                *c = node_t(c->left, b, BLACK);\n\
    \                std::swap(b, c);\n            } else {\n                b->right->color\
    \ = BLACK;\n                c->color = BLACK;\n                *b = node_t(c,\
    \ b->right, RED);\n            }\n        } else {\n            *b = node_t(c,\
    \ b->right, b->color);\n        }\n        return b;\n    }\n    static node_t\
    \ *set_right(node_t *a, node_t *c) {\n        if (a->color == BLACK and c->color\
    \ == RED and c->right->color == RED) {\n            if (a->left->color == BLACK)\
    \ {\n                *a = node_t(a->left, c->left, RED);\n                *c =\
    \ node_t(a, c->right, BLACK);\n                std::swap(a, c);\n            }\
    \ else {\n                a->left->color = BLACK;\n                c->color =\
    \ BLACK;\n                *a = node_t(a->left, c, RED);\n            }\n     \
    \   } else {\n            *a = node_t(a->left, c, a->color);\n        }\n    \
    \    return a;\n    }\n\n    /**\n     * @note tree a is consumed  (at explicit\
    \ delete and merge())\n     */\n    static std::pair<node_t *, node_t *> split(node_t\
    \ *a, int k) {\n        if (k == 0) {\n            return std::make_pair( nullptr,\
    \ a );\n        }\n        assert (a != nullptr);\n        if (k == a->size) {\n\
    \            return std::make_pair( a, nullptr );\n        }\n        assert (not\
    \ a->is_leaf);\n        propagate(a);\n        node_t *a_left  = a->left;\n  \
    \      node_t *a_right = a->right;\n        delete a;\n        if (k < a_left->size)\
    \ {\n            node_t *l, *r; tie(l, r) = split(a_left, k);\n            return\
    \ std::make_pair( l, merge(r, a_right) );\n        } else if (k > a_left->size)\
    \ {\n            node_t *l, *r; tie(l, r) = split(a_right, k - a_left->size);\n\
    \            return std::make_pair( merge(a_left, l), r );\n        } else {\n\
    \            return std::make_pair( a_left, a_right );\n        }\n    }\n\n \
    \   static void range_apply(node_t *a, int l, int r, const operator_type & func)\
    \ {\n        MonoidX mon_x;\n        MonoidF mon_f;\n        Action act;\n   \
    \     if (l == r) return;\n        if (l == 0 and r == a->size) {\n          \
    \  a->data = act(func, a->data);\n            if (not a->is_leaf) a->lazy = mon_f.mult(func,\
    \ a->lazy);\n            return;\n        }\n        assert (not a->is_leaf);\n\
    \        propagate(a);\n        int k = a->left->size;\n        if (r <= k) {\n\
    \            range_apply(a->left, l, r, func);\n        } else if (k <= l) {\n\
    \            range_apply(a->right, l - k, r - k, func);\n        } else {\n  \
    \          range_apply(a->left, l, k, func);\n            range_apply(a->right,\
    \ 0, r - k, func);\n        }\n        a->data = act(a->lazy, mon_x.mult(a->left->data,\
    \ a->right->data));\n    }\n\n    static value_type range_get(node_t *a, int l,\
    \ int r) {\n        MonoidX mon_x;\n        assert (l < r);\n        if (l ==\
    \ 0 and r == a->size) return a->data;\n        assert (not a->is_leaf);\n    \
    \    propagate(a);\n        int k = a->left->size;\n        if (r <= k) {\n  \
    \          return range_get(a->left, l, r);\n        } else if (k <= l) {\n  \
    \          return range_get(a->right, l - k, r - k);\n        } else {\n     \
    \       return mon_x.mult(\n                    range_get(a->left, l, k),\n  \
    \                  range_get(a->right, 0, r - k));\n        }\n    }\n\n    static\
    \ node_t *reverse(node_t *a, int l, int r) {\n        // TODO: find ways to do\
    \ without split. there may be clever ways using recursion\n        if (l == r)\
    \ return a;\n        node_t *bl, *br; tie(bl, br) = split(a, r);\n        node_t\
    \ *bm; tie(bl, bm) = split(bl, l);\n        if (not bm->is_leaf) bm->reversed\
    \ = not bm->reversed;\n        return merge(merge(bl, bm), br);\n    }\n\n   \
    \ static void point_set(node_t *a, int i, const value_type & value) {\n      \
    \  MonoidX mon_x;\n        Action act;\n        if (a->is_leaf) {\n          \
    \  assert (i == 0);\n            a->data = value;\n        } else {\n        \
    \    propagate_only_reverse(a);  // should we do full propagation?\n         \
    \   if (i < a->left->size) {\n                point_set(a->left, i, value);\n\
    \            } else {\n                point_set(a->right, i - a->left->size,\
    \ value);\n            }\n            a->data = act(a->lazy,\n               \
    \     mon_x.mult(a->left->data, a->right->data));\n        }\n    }\n\n    static\
    \ value_type & point_get(node_t *a, int i) {\n        if (a->is_leaf) {\n    \
    \        assert (i == 0);\n            return a->data;\n        } else {\n   \
    \         propagate(a);\n            if (i < a->left->size) {\n              \
    \  return point_get(a->left, i);\n            } else {\n                return\
    \ point_get(a->right, i - a->left->size);\n            }\n        }\n    }\n\n\
    private:\n    std::unique_ptr<node_t, node_deleter> root;\n\npublic:\n    lazy_propagation_red_black_tree()\
    \ = default;\n    lazy_propagation_red_black_tree(node_t *a_root)\n          \
    \  : root(a_root) {\n    }\n    template <class InputIterator>\n    lazy_propagation_red_black_tree(InputIterator\
    \ first, InputIterator last)\n            : root(nullptr) {\n        for (; first\
    \ != last; ++ first) {\n            this->push_back(*first);\n        }\n    }\n\
    \n    static lazy_propagation_red_black_tree merge(lazy_propagation_red_black_tree\
    \ & l, lazy_propagation_red_black_tree & r) {\n        node_t *a = l.root.release();\n\
    \        node_t *b = r.root.release();\n        if (a == nullptr) return lazy_propagation_red_black_tree(b);\n\
    \        if (b == nullptr) return lazy_propagation_red_black_tree(a);\n      \
    \  return lazy_propagation_red_black_tree(merge(a, b));\n    }\n    std::pair<lazy_propagation_red_black_tree,\
    \ lazy_propagation_red_black_tree> split(int k) {\n        assert (0 <= k and\
    \ k <= size());\n        node_t *l, *r; tie(l, r) = split(root.release(), k);\n\
    \        return std::make_pair( lazy_propagation_red_black_tree(l), lazy_propagation_red_black_tree(r)\
    \ );\n    }\n\n    void insert(int i, const value_type & data) {\n        assert\
    \ (0 <= i and i <= size());\n        if (empty()) {\n            root.reset(new\
    \ node_t(data));\n            return;\n        } else {\n            node_t *l,\
    \ *r; tie(l, r) = split(root.release(), i);\n            root.reset( merge(merge(l,\
    \ new node_t(data)), r) );\n        }\n    }\n    void erase(int i) {\n      \
    \  assert (0 <= i and i < size());\n        node_t *l, *r; tie(l, r) = split(root.release(),\
    \ i + 1);\n        node_t *m; tie(l, m) = split(l, i);\n        node_deleter()(m);\n\
    \        root.reset( merge(l, r) );\n    }\n\n    void point_set(int i, const\
    \ value_type & value) {\n        assert (0 <= i and i < size());\n        point_set(root.get(),\
    \ i, value);\n    }\n    value_type const & point_get(int i) const {\n       \
    \ assert (0 <= i and i < size());\n        return point_get(const_cast<node_t\
    \ *>(root.get()), i);\n    }\n\n    void range_apply(int l, int r, const operator_type\
    \ & func) {\n        assert (0 <= l and l <= r and r <= size());\n        if (l\
    \ == r) return;\n        range_apply(root.get(), l, r, func);\n    }\n    value_type\
    \ const range_get(int l, int r) const {\n        assert (0 <= l and l <= r and\
    \ r <= size());\n        if (l == r) return MonoidX().unit();\n        return\
    \ range_get(const_cast<node_t *>(root.get()), l, r);\n    }\n    void reverse(int\
    \ l, int r) {\n        assert (0 <= l and l <= r and r <= size());\n        if\
    \ (not root) return;\n        root.reset( reverse(root.release(), l, r) );\n \
    \   }\n\n    void push_back(const value_type & data) {\n        root.reset( merge(root.release(),\
    \ new node_t(data)) );\n    }\n    void push_front(const value_type & data) {\n\
    \        root.reset( merge(new node_t(data), root.release()) );\n    }\n    void\
    \ pop_back() {\n        int k = size() - 1;\n        auto lr = split(root.release(),\
    \ k);\n        root.reset(lr.first);\n        node_deleter()(lr.second);\n   \
    \ }\n    void pop_front() {\n        auto lr = split(root.release(), 1);\n   \
    \     node_deleter()(lr.first);\n        root.reset(lr.second);\n    }\n    int\
    \ size() const {\n        return root ? root.get()->size : 0;\n    }\n    bool\
    \ empty() const {\n        return not root;\n    }\n    void clear() {\n     \
    \   root = nullptr;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <memory>\n\
    #include <type_traits>\n#include <vector>\n\n/**\n * @brief Lazy Propagation Segment\
    \ Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (monoids,\
    \ \u8D64\u9ED2\u6728)\n * @docs data_structure/lazy_propagation_red_black_tree.md\n\
    \ * @tparam MonoidX is a monoid\n * @tparam MonoidF is a monoid\n * @tparam Action\
    \ is a function phi : F * X -> X where the partial applied phi(f, -) : X -> X\
    \ is a homomorphism on X\n */\ntemplate <class MonoidX, class MonoidF, class Action>\n\
    class lazy_propagation_red_black_tree {\n    static_assert (std::is_invocable_r<typename\
    \ MonoidX::value_type, Action, typename MonoidF::value_type, typename MonoidX::value_type>::value,\
    \ \"\");\n    typedef typename MonoidX::value_type value_type;\n    typedef typename\
    \ MonoidF::value_type operator_type;\n\n    enum color_t { BLACK, RED };\n   \
    \ struct node_t {\n        bool is_leaf;\n        value_type data;\n        operator_type\
    \ lazy;  // NOTE: this->lazy is already applied to this->data\n        bool reversed;\n\
    \        color_t color;\n        int rank;\n        int size;\n        node_t\
    \ *left;\n        node_t *right;\n        node_t() = default;\n        node_t(value_type\
    \ const & a_data)\n                : is_leaf(true)\n                , data(a_data)\n\
    \                , color(BLACK)\n                , rank(0)\n                ,\
    \ size(1) {\n        }\n        node_t(node_t *l, node_t *r, color_t c)  // non-leaf\
    \ node\n                : is_leaf(false)\n                , data(MonoidX().mult(l->data,\
    \ r->data))\n                , lazy(MonoidF().unit())\n                , reversed(false)\n\
    \                , color(c)\n                , rank(std::max(l->rank + (l->color\
    \ == BLACK),\n                                r->rank + (r->color == BLACK)))\n\
    \                , size(l->size + r->size)\n                , left(l)\n      \
    \          , right(r) {\n        }\n    };\n    struct node_deleter {\n      \
    \  void operator () (node_t *t) const {\n            assert (t != nullptr);\n\
    \            if (not t->is_leaf) {\n                (*this)(t->right);\n     \
    \           (*this)(t->left);\n            }\n            delete t;\n        }\n\
    \    };\n\n    static void propagate_only_operator(node_t *a) {\n        MonoidF\
    \ mon_f;\n        Action act;\n        if (not a->is_leaf) {\n            if (a->lazy\
    \ != mon_f.unit()) {\n                auto const & l = a->left;\n            \
    \    auto const & r = a->right;\n                l->data = act(a->lazy, l->data);\n\
    \                r->data = act(a->lazy, r->data);\n                if (not l->is_leaf)\
    \ l->lazy = mon_f.mult(a->lazy, l->lazy);\n                if (not r->is_leaf)\
    \ r->lazy = mon_f.mult(a->lazy, r->lazy);\n                a->lazy = mon_f.unit();\n\
    \            }\n        }\n    }\n    static void propagate_only_reverse(node_t\
    \ *a) {\n        if (not a->is_leaf) {\n            if (a->reversed) {\n     \
    \           auto const & l = a->left;\n                auto const & r = a->right;\n\
    \                if (not l->is_leaf) l->reversed = not l->reversed;\n        \
    \        if (not r->is_leaf) r->reversed = not r->reversed;\n                std::swap(a->left,\
    \ a->right);  // CAUTION: auto const & l, r are destroyed\n                a->reversed\
    \ = false;\n            }\n        }\n    }\n    static void propagate(node_t\
    \ *a) {\n        propagate_only_operator(a);\n        propagate_only_reverse(a);\n\
    \    }\n\n    /**\n     * @note trees a, b are consumed  (at set_left()/set_right())\n\
    \     */\n    static node_t *merge(node_t *a, node_t *b) {\n        if (a == nullptr)\
    \ return b;\n        if (b == nullptr) return a;\n        node_t *c = merge_relax(a,\
    \ b);\n        c->color = BLACK;\n        return c;\n    }\n    /*\n     * @note\
    \ the root of returned tree may violates the color constraint\n     */\n    static\
    \ node_t *merge_relax(node_t *a, node_t *b) {\n        if ((a->rank) < b->rank)\
    \ {\n            assert (not b->is_leaf);\n            propagate(b);\n       \
    \     return set_left(b, merge_relax(a, b->left));\n        } else if (a->rank\
    \ > b->rank) {\n            assert (not a->is_leaf);\n            propagate(a);\n\
    \            return set_right(a, merge_relax(a->right, b));\n        } else {\n\
    \            a->color = BLACK;\n            b->color = BLACK;\n            return\
    \ new node_t(a, b, RED);\n        }\n    }\n    static node_t *set_left(node_t\
    \ *b, node_t *c) {\n        if (b->color == BLACK and c->color == RED and c->left->color\
    \ == RED) {\n            if (b->right->color == BLACK) {\n                *b =\
    \ node_t(c->right, b->right, RED);\n                *c = node_t(c->left, b, BLACK);\n\
    \                std::swap(b, c);\n            } else {\n                b->right->color\
    \ = BLACK;\n                c->color = BLACK;\n                *b = node_t(c,\
    \ b->right, RED);\n            }\n        } else {\n            *b = node_t(c,\
    \ b->right, b->color);\n        }\n        return b;\n    }\n    static node_t\
    \ *set_right(node_t *a, node_t *c) {\n        if (a->color == BLACK and c->color\
    \ == RED and c->right->color == RED) {\n            if (a->left->color == BLACK)\
    \ {\n                *a = node_t(a->left, c->left, RED);\n                *c =\
    \ node_t(a, c->right, BLACK);\n                std::swap(a, c);\n            }\
    \ else {\n                a->left->color = BLACK;\n                c->color =\
    \ BLACK;\n                *a = node_t(a->left, c, RED);\n            }\n     \
    \   } else {\n            *a = node_t(a->left, c, a->color);\n        }\n    \
    \    return a;\n    }\n\n    /**\n     * @note tree a is consumed  (at explicit\
    \ delete and merge())\n     */\n    static std::pair<node_t *, node_t *> split(node_t\
    \ *a, int k) {\n        if (k == 0) {\n            return std::make_pair( nullptr,\
    \ a );\n        }\n        assert (a != nullptr);\n        if (k == a->size) {\n\
    \            return std::make_pair( a, nullptr );\n        }\n        assert (not\
    \ a->is_leaf);\n        propagate(a);\n        node_t *a_left  = a->left;\n  \
    \      node_t *a_right = a->right;\n        delete a;\n        if (k < a_left->size)\
    \ {\n            node_t *l, *r; tie(l, r) = split(a_left, k);\n            return\
    \ std::make_pair( l, merge(r, a_right) );\n        } else if (k > a_left->size)\
    \ {\n            node_t *l, *r; tie(l, r) = split(a_right, k - a_left->size);\n\
    \            return std::make_pair( merge(a_left, l), r );\n        } else {\n\
    \            return std::make_pair( a_left, a_right );\n        }\n    }\n\n \
    \   static void range_apply(node_t *a, int l, int r, const operator_type & func)\
    \ {\n        MonoidX mon_x;\n        MonoidF mon_f;\n        Action act;\n   \
    \     if (l == r) return;\n        if (l == 0 and r == a->size) {\n          \
    \  a->data = act(func, a->data);\n            if (not a->is_leaf) a->lazy = mon_f.mult(func,\
    \ a->lazy);\n            return;\n        }\n        assert (not a->is_leaf);\n\
    \        propagate(a);\n        int k = a->left->size;\n        if (r <= k) {\n\
    \            range_apply(a->left, l, r, func);\n        } else if (k <= l) {\n\
    \            range_apply(a->right, l - k, r - k, func);\n        } else {\n  \
    \          range_apply(a->left, l, k, func);\n            range_apply(a->right,\
    \ 0, r - k, func);\n        }\n        a->data = act(a->lazy, mon_x.mult(a->left->data,\
    \ a->right->data));\n    }\n\n    static value_type range_get(node_t *a, int l,\
    \ int r) {\n        MonoidX mon_x;\n        assert (l < r);\n        if (l ==\
    \ 0 and r == a->size) return a->data;\n        assert (not a->is_leaf);\n    \
    \    propagate(a);\n        int k = a->left->size;\n        if (r <= k) {\n  \
    \          return range_get(a->left, l, r);\n        } else if (k <= l) {\n  \
    \          return range_get(a->right, l - k, r - k);\n        } else {\n     \
    \       return mon_x.mult(\n                    range_get(a->left, l, k),\n  \
    \                  range_get(a->right, 0, r - k));\n        }\n    }\n\n    static\
    \ node_t *reverse(node_t *a, int l, int r) {\n        // TODO: find ways to do\
    \ without split. there may be clever ways using recursion\n        if (l == r)\
    \ return a;\n        node_t *bl, *br; tie(bl, br) = split(a, r);\n        node_t\
    \ *bm; tie(bl, bm) = split(bl, l);\n        if (not bm->is_leaf) bm->reversed\
    \ = not bm->reversed;\n        return merge(merge(bl, bm), br);\n    }\n\n   \
    \ static void point_set(node_t *a, int i, const value_type & value) {\n      \
    \  MonoidX mon_x;\n        Action act;\n        if (a->is_leaf) {\n          \
    \  assert (i == 0);\n            a->data = value;\n        } else {\n        \
    \    propagate_only_reverse(a);  // should we do full propagation?\n         \
    \   if (i < a->left->size) {\n                point_set(a->left, i, value);\n\
    \            } else {\n                point_set(a->right, i - a->left->size,\
    \ value);\n            }\n            a->data = act(a->lazy,\n               \
    \     mon_x.mult(a->left->data, a->right->data));\n        }\n    }\n\n    static\
    \ value_type & point_get(node_t *a, int i) {\n        if (a->is_leaf) {\n    \
    \        assert (i == 0);\n            return a->data;\n        } else {\n   \
    \         propagate(a);\n            if (i < a->left->size) {\n              \
    \  return point_get(a->left, i);\n            } else {\n                return\
    \ point_get(a->right, i - a->left->size);\n            }\n        }\n    }\n\n\
    private:\n    std::unique_ptr<node_t, node_deleter> root;\n\npublic:\n    lazy_propagation_red_black_tree()\
    \ = default;\n    lazy_propagation_red_black_tree(node_t *a_root)\n          \
    \  : root(a_root) {\n    }\n    template <class InputIterator>\n    lazy_propagation_red_black_tree(InputIterator\
    \ first, InputIterator last)\n            : root(nullptr) {\n        for (; first\
    \ != last; ++ first) {\n            this->push_back(*first);\n        }\n    }\n\
    \n    static lazy_propagation_red_black_tree merge(lazy_propagation_red_black_tree\
    \ & l, lazy_propagation_red_black_tree & r) {\n        node_t *a = l.root.release();\n\
    \        node_t *b = r.root.release();\n        if (a == nullptr) return lazy_propagation_red_black_tree(b);\n\
    \        if (b == nullptr) return lazy_propagation_red_black_tree(a);\n      \
    \  return lazy_propagation_red_black_tree(merge(a, b));\n    }\n    std::pair<lazy_propagation_red_black_tree,\
    \ lazy_propagation_red_black_tree> split(int k) {\n        assert (0 <= k and\
    \ k <= size());\n        node_t *l, *r; tie(l, r) = split(root.release(), k);\n\
    \        return std::make_pair( lazy_propagation_red_black_tree(l), lazy_propagation_red_black_tree(r)\
    \ );\n    }\n\n    void insert(int i, const value_type & data) {\n        assert\
    \ (0 <= i and i <= size());\n        if (empty()) {\n            root.reset(new\
    \ node_t(data));\n            return;\n        } else {\n            node_t *l,\
    \ *r; tie(l, r) = split(root.release(), i);\n            root.reset( merge(merge(l,\
    \ new node_t(data)), r) );\n        }\n    }\n    void erase(int i) {\n      \
    \  assert (0 <= i and i < size());\n        node_t *l, *r; tie(l, r) = split(root.release(),\
    \ i + 1);\n        node_t *m; tie(l, m) = split(l, i);\n        node_deleter()(m);\n\
    \        root.reset( merge(l, r) );\n    }\n\n    void point_set(int i, const\
    \ value_type & value) {\n        assert (0 <= i and i < size());\n        point_set(root.get(),\
    \ i, value);\n    }\n    value_type const & point_get(int i) const {\n       \
    \ assert (0 <= i and i < size());\n        return point_get(const_cast<node_t\
    \ *>(root.get()), i);\n    }\n\n    void range_apply(int l, int r, const operator_type\
    \ & func) {\n        assert (0 <= l and l <= r and r <= size());\n        if (l\
    \ == r) return;\n        range_apply(root.get(), l, r, func);\n    }\n    value_type\
    \ const range_get(int l, int r) const {\n        assert (0 <= l and l <= r and\
    \ r <= size());\n        if (l == r) return MonoidX().unit();\n        return\
    \ range_get(const_cast<node_t *>(root.get()), l, r);\n    }\n    void reverse(int\
    \ l, int r) {\n        assert (0 <= l and l <= r and r <= size());\n        if\
    \ (not root) return;\n        root.reset( reverse(root.release(), l, r) );\n \
    \   }\n\n    void push_back(const value_type & data) {\n        root.reset( merge(root.release(),\
    \ new node_t(data)) );\n    }\n    void push_front(const value_type & data) {\n\
    \        root.reset( merge(new node_t(data), root.release()) );\n    }\n    void\
    \ pop_back() {\n        int k = size() - 1;\n        auto lr = split(root.release(),\
    \ k);\n        root.reset(lr.first);\n        node_deleter()(lr.second);\n   \
    \ }\n    void pop_front() {\n        auto lr = split(root.release(), 1);\n   \
    \     node_deleter()(lr.first);\n        root.reset(lr.second);\n    }\n    int\
    \ size() const {\n        return root ? root.get()->size : 0;\n    }\n    bool\
    \ empty() const {\n        return not root;\n    }\n    void clear() {\n     \
    \   root = nullptr;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_propagation_red_black_tree.hpp
  requiredBy: []
  timestamp: '2020-03-04 20:56:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/lazy_propagation_red_black_tree.range_affine_range_sum.test.cpp
documentation_of: data_structure/lazy_propagation_red_black_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_propagation_red_black_tree.hpp
- /library/data_structure/lazy_propagation_red_black_tree.hpp.html
title: "Lazy Propagation Segment Tree / \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
  \u30F3\u30C8\u6728 (monoids, \u8D64\u9ED2\u6728)"
---
## Operations

完全二分木上の遅延伝播セグメント木でできることに加え、$O(\log N)$ で次ができる:

-   $\mathtt{insert}(i, b)$: 列の $i$ 番目の要素の前に要素 $b$ を挿入する。
-   $\mathtt{erase}(i)$: 列の $i$ 番目の要素を削除する。
-   $\mathtt{reverse}(l, r)$: 列の $l, l+1, \dots, r-1$ 番目の要素を反転する。つまり $(a_0, a_1, \dots, a _ {l-1}, a_l, a _ {l+1}, \dots, a _ {r-1}, a_r, a _ {r + 1}, \dots, a _ {N - 1}) \gets (a_0, a_1, \dots, a _ {l-1}, a _ {r-1}, a _ {r-2}, \dots, a_l, a_r, a _ {r + 1}, \dots, a _ {N - 1})$ と更新する。
