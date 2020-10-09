---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/red-black-tree.inc.cpp\"\n/**\n * @note almost all operations\
    \ are O(log N)\n */\ntemplate <class T>\nclass red_black_tree {\n\n    enum color_t\
    \ { BLACK, RED };\n    struct node_t {\n        bool is_leaf;\n        union {\n\
    \            T data;\n            struct {\n                color_t m_color;\n\
    \                int m_rank;\n                int m_size;\n                node_t\
    \ *left;\n                node_t *right;\n            };\n        };\n       \
    \ node_t() = default;\n        node_t(T const & a_data)\n                : is_leaf(true)\n\
    \                , data(a_data) {\n        }\n        node_t(node_t *l, node_t\
    \ *r, color_t c)  // non-leaf node\n                : is_leaf(false)\n       \
    \         , m_color(c)\n                , m_rank(max(rank(l) + (color(l) == BLACK),\n\
    \                             rank(r) + (color(r) == BLACK)))\n              \
    \  , m_size(size(l) + size(r))\n                , left(l)\n                , right(r)\
    \ {\n        }\n    };\n    struct node_deleter {\n        void operator () (node_t\
    \ *t) const {\n            assert (t != nullptr);\n            if (not t->is_leaf)\
    \ {\n                (*this)(t->right);\n                (*this)(t->left);\n \
    \           }\n            delete t;\n        }\n    };\n\n    static inline color_t\
    \ color(node_t const *t) {\n        return t->is_leaf ? BLACK : t->m_color;\n\
    \    }\n    static inline int rank(node_t const *t) {\n        return t->is_leaf\
    \ ? 0 : t->m_rank;\n    }\n    static inline int size(node_t const *t) {\n   \
    \     return t->is_leaf ? 1 : t->m_size;\n    }\n\n    /**\n     * @note trees\
    \ a, b are consumed  (at set_left()/set_right())\n     */\n    static node_t *merge(node_t\
    \ *a, node_t *b) {\n        if (a == nullptr) return b;\n        if (b == nullptr)\
    \ return a;\n        node_t *c = merge_relax(a, b);\n        c->m_color = BLACK;\n\
    \        return c;\n    }\n    /*\n     * @note the root of returned tree may\
    \ violates the color constraint\n     */\n    static node_t *merge_relax(node_t\
    \ *a, node_t *b) {\n        if (rank(a) < rank(b)) {\n            assert (not\
    \ b->is_leaf);\n            return set_left(b, merge_relax(a, b->left));\n   \
    \     } else if (rank(a) > rank(b)) {\n            assert (not a->is_leaf);\n\
    \            return set_right(a, merge_relax(a->right, b));\n        } else {\n\
    \            a->m_color = BLACK;\n            b->m_color = BLACK;\n          \
    \  return new node_t(a, b, RED);\n        }\n    }\n    static node_t *set_left(node_t\
    \ *b, node_t *c) {\n        if (b->m_color == BLACK and c->m_color == RED and\
    \ color(c->left) == RED) {\n            if (color(b->right) == BLACK) {\n    \
    \            *b = node_t(c->right, b->right, RED);\n                *c = node_t(c->left,\
    \ b, BLACK);\n                swap(b, c);\n            } else {\n            \
    \    b->right->m_color = BLACK;\n                c->m_color = BLACK;\n       \
    \         *b = node_t(c, b->right, RED);\n            }\n        } else {\n  \
    \          *b = node_t(c, b->right, b->m_color);\n        }\n        return b;\n\
    \    }\n    static node_t *set_right(node_t *a, node_t *c) {\n        if (a->m_color\
    \ == BLACK and c->m_color == RED and color(c->right) == RED) {\n            if\
    \ (color(a->left) == BLACK) {\n                *a = node_t(a->left, c->left, RED);\n\
    \                *c = node_t(a, c->right, BLACK);\n                swap(a, c);\n\
    \            } else {\n                a->left->m_color = BLACK;\n           \
    \     c->m_color = BLACK;\n                *a = node_t(a->left, c, RED);\n   \
    \         }\n        } else {\n            *a = node_t(a->left, c, a->m_color);\n\
    \        }\n        return a;\n    }\n\n    /**\n     * @note tree a is consumed\
    \  (at explicit delete and merge())\n     */\n    static pair<node_t *, node_t\
    \ *> split(node_t *a, int k) {\n        if (k == 0) {\n            return make_pair(\
    \ nullptr, a );\n        }\n        assert (a != nullptr);\n        if (k == size(a))\
    \ {\n            return make_pair( a, nullptr );\n        }\n        assert (not\
    \ a->is_leaf);\n        node_t *a_left  = a->left;\n        node_t *a_right =\
    \ a->right;\n        delete a;\n        if (k < size(a_left)) {\n            node_t\
    \ *l, *r; tie(l, r) = split(a_left, k);\n            return make_pair( l, merge(r,\
    \ a_right) );\n        } else if (k > size(a_left)) {\n            node_t *l,\
    \ *r; tie(l, r) = split(a_right, k - size(a_left));\n            return make_pair(\
    \ merge(a_left, l), r );\n        } else {\n            return make_pair( a_left,\
    \ a_right );\n        }\n    }\n\n    /**\n     * @tparam (A, B) = (node_t const\
    \ *, T const &), (node_t *, T &)\n     */\n    template <class A, class B>\n \
    \   static B get_generic(A a, int i) {\n        if (a->is_leaf) {\n          \
    \  assert (i == 0);\n            return a->data;\n        } else {\n         \
    \   if (i < size(a->left)) {\n                return get_generic<A, B>(a->left,\
    \ i);\n            } else {\n                return get_generic<A, B>(a->right,\
    \ i - size(a->left));\n            }\n        }\n    }\n\nprivate:\n    unique_ptr<node_t,\
    \ node_deleter> root;\n\npublic:\n    red_black_tree<T>() = default;\n    red_black_tree<T>(node_t\
    \ *a_root) : root(a_root) {}\n\n    static red_black_tree<T> merge(red_black_tree<T>\
    \ & l, red_black_tree<T> & r) {\n        node_t *a = l.root.release();\n     \
    \   node_t *b = r.root.release();\n        if (a == nullptr) return red_black_tree<T>(b);\n\
    \        if (b == nullptr) return red_black_tree<T>(a);\n        return red_black_tree<T>(merge(a,\
    \ b));\n    }\n    pair<red_black_tree<T>, red_black_tree<T> > split(int k) {\n\
    \        assert (0 <= k and k <= size());\n        node_t *l, *r; tie(l, r) =\
    \ split(root.release(), k);\n        return make_pair( red_black_tree<T>(l), red_black_tree<T>(r)\
    \ );\n    }\n\n    void insert(int i, T const & data) {\n        assert (0 <=\
    \ i and i <= size());\n        if (empty()) {\n            root.reset(new node_t(data));\n\
    \            return;\n        } else {\n            node_t *l, *r; tie(l, r) =\
    \ split(root.release(), i);\n            root.reset( merge(merge(l, new node_t(data)),\
    \ r) );\n        }\n    }\n    void erase(int i) {\n        assert (0 <= i and\
    \ i < size());\n        node_t *l, *r; tie(l, r) = split(root.release(), i + 1);\n\
    \        node_t *m; tie(l, m) = split(l, i);\n        node_deleter()(m);\n   \
    \     root.reset( merge(l, r) );\n    }\n\n    void set(int i, T const & data)\
    \ {\n        assert (0 <= i and i < size());\n        get_generic<node_t *, T\
    \ &>(root.get(), i) = data;\n    }\n    T const & get(int i) const {\n       \
    \ assert (0 <= i and i < size());\n        return get_generic<node_t const *,\
    \ T const &>(root.get(), i);\n    }\n\n    void push_back(T const & data) {\n\
    \        root.reset( merge(root.release(), new node_t(data)) );\n    }\n    void\
    \ push_front(T const & data) {\n        root.reset( merge(new node_t(data), root.release())\
    \ );\n    }\n    void pop_back() {\n        int k = size() - 1;\n        auto\
    \ lr = split(root.release(), k);\n        root.reset(lr.first);\n        node_deleter()(lr.second);\n\
    \    }\n    void pop_front() {\n        auto lr = split(root.release(), 1);\n\
    \        node_deleter()(lr.first);\n        root.reset(lr.second);\n    }\n  \
    \  int size() const {\n        return root ? size(root.get()) : 0;\n    }\n  \
    \  bool empty() const {\n        return not root;\n    }\n    void clear() {\n\
    \        root = nullptr;\n    }\n};\n\nunittest {\n    default_random_engine gen;\n\
    \    auto generate = [&]() {\n        red_black_tree<double> rbtree;\n       \
    \ deque<double> dec;\n        REP (iteration, 100) {\n            double value\
    \ = uniform_real_distribution<double>()(gen);\n            if (bernoulli_distribution(0.5)(gen))\
    \ {\n                rbtree.push_back(value);\n                dec.push_back(value);\n\
    \            } else {\n                rbtree.push_front(value);\n           \
    \     dec.push_front(value);\n            }\n        }\n        return make_pair(\
    \ move(rbtree), dec );\n    };\n    REP (iteration, 1000) {\n        red_black_tree<double>\
    \ rbtree;\n        deque<double> dec;\n        tie(rbtree, dec) = generate();\n\
    \        REP (iteration, 100) {\n            assert (rbtree.size() == dec.size());\n\
    \            int k = uniform_int_distribution<int>(0, rbtree.size())(gen);\n \
    \           int i = rbtree.empty() ? -1 : uniform_int_distribution<int>(0, rbtree.size()\
    \ - 1)(gen);\n            double value = uniform_real_distribution<double>()(gen);\n\
    \            switch (uniform_int_distribution<int>(0, 8)(gen)) {\n           \
    \     case 0:  // merge\n                    {\n                        red_black_tree<double>\
    \ rbtree2;\n                        deque<double> dec2;\n                    \
    \    tie(rbtree2, dec2) = generate();\n                        rbtree = red_black_tree<double>::merge(rbtree,\
    \ rbtree2);\n                        copy(ALL(dec2), back_inserter(dec));\n  \
    \                  }\n                    break;\n                case 1:  //\
    \ split\n                    if (bernoulli_distribution(0.5)(gen)) {\n       \
    \                 rbtree = rbtree.split(k).first;\n                        dec.erase(dec.begin()\
    \ + k, dec.end());\n                    } else {\n                        rbtree\
    \ = rbtree.split(k).second;\n                        dec.erase(dec.begin(), dec.begin()\
    \ + k);\n                    }\n                    break;\n                case\
    \ 2:  // insert\n                    rbtree.insert(k, value);\n              \
    \      dec.push_back(value);\n                    rotate(dec.begin() + k, dec.begin()\
    \ + (dec.size() - 1), dec.end());\n                    break;\n              \
    \  case 3:  // erase\n                    if (not rbtree.empty()) {\n        \
    \                rbtree.erase(i);\n                        rotate(dec.begin()\
    \ + i, dec.begin() + (i + 1), dec.end());\n                        dec.pop_back();\n\
    \                    }\n                    break;\n                case 4:  //\
    \ push_back\n                    rbtree.push_back(value);\n                  \
    \  dec.push_back(value);\n                    break;\n                case 5:\
    \  // push_front\n                    rbtree.push_front(value);\n            \
    \        dec.push_front(value);\n                    break;\n                case\
    \ 6:  // pop_back\n                    if (not rbtree.empty()) {\n           \
    \             rbtree.pop_front();\n                        dec.pop_front();\n\
    \                    }\n                    break;\n                case 7:  //\
    \ pop_front\n                    if (not rbtree.empty()) {\n                 \
    \       rbtree.pop_back();\n                        dec.pop_back();\n        \
    \            }\n                    break;\n                case 8:  // set\n\
    \                    if (not rbtree.empty()) {\n                        rbtree.set(i,\
    \ value);\n                        dec[i] = value;\n                    }\n  \
    \                  break;\n                default:\n                    assert\
    \ (false);\n            }\n            REP (i, rbtree.size()) {\n            \
    \    assert (rbtree.get(i) == dec[i]);\n            }\n        }\n    }\n}\n"
  code: "/**\n * @note almost all operations are O(log N)\n */\ntemplate <class T>\n\
    class red_black_tree {\n\n    enum color_t { BLACK, RED };\n    struct node_t\
    \ {\n        bool is_leaf;\n        union {\n            T data;\n           \
    \ struct {\n                color_t m_color;\n                int m_rank;\n  \
    \              int m_size;\n                node_t *left;\n                node_t\
    \ *right;\n            };\n        };\n        node_t() = default;\n        node_t(T\
    \ const & a_data)\n                : is_leaf(true)\n                , data(a_data)\
    \ {\n        }\n        node_t(node_t *l, node_t *r, color_t c)  // non-leaf node\n\
    \                : is_leaf(false)\n                , m_color(c)\n            \
    \    , m_rank(max(rank(l) + (color(l) == BLACK),\n                           \
    \  rank(r) + (color(r) == BLACK)))\n                , m_size(size(l) + size(r))\n\
    \                , left(l)\n                , right(r) {\n        }\n    };\n\
    \    struct node_deleter {\n        void operator () (node_t *t) const {\n   \
    \         assert (t != nullptr);\n            if (not t->is_leaf) {\n        \
    \        (*this)(t->right);\n                (*this)(t->left);\n            }\n\
    \            delete t;\n        }\n    };\n\n    static inline color_t color(node_t\
    \ const *t) {\n        return t->is_leaf ? BLACK : t->m_color;\n    }\n    static\
    \ inline int rank(node_t const *t) {\n        return t->is_leaf ? 0 : t->m_rank;\n\
    \    }\n    static inline int size(node_t const *t) {\n        return t->is_leaf\
    \ ? 1 : t->m_size;\n    }\n\n    /**\n     * @note trees a, b are consumed  (at\
    \ set_left()/set_right())\n     */\n    static node_t *merge(node_t *a, node_t\
    \ *b) {\n        if (a == nullptr) return b;\n        if (b == nullptr) return\
    \ a;\n        node_t *c = merge_relax(a, b);\n        c->m_color = BLACK;\n  \
    \      return c;\n    }\n    /*\n     * @note the root of returned tree may violates\
    \ the color constraint\n     */\n    static node_t *merge_relax(node_t *a, node_t\
    \ *b) {\n        if (rank(a) < rank(b)) {\n            assert (not b->is_leaf);\n\
    \            return set_left(b, merge_relax(a, b->left));\n        } else if (rank(a)\
    \ > rank(b)) {\n            assert (not a->is_leaf);\n            return set_right(a,\
    \ merge_relax(a->right, b));\n        } else {\n            a->m_color = BLACK;\n\
    \            b->m_color = BLACK;\n            return new node_t(a, b, RED);\n\
    \        }\n    }\n    static node_t *set_left(node_t *b, node_t *c) {\n     \
    \   if (b->m_color == BLACK and c->m_color == RED and color(c->left) == RED) {\n\
    \            if (color(b->right) == BLACK) {\n                *b = node_t(c->right,\
    \ b->right, RED);\n                *c = node_t(c->left, b, BLACK);\n         \
    \       swap(b, c);\n            } else {\n                b->right->m_color =\
    \ BLACK;\n                c->m_color = BLACK;\n                *b = node_t(c,\
    \ b->right, RED);\n            }\n        } else {\n            *b = node_t(c,\
    \ b->right, b->m_color);\n        }\n        return b;\n    }\n    static node_t\
    \ *set_right(node_t *a, node_t *c) {\n        if (a->m_color == BLACK and c->m_color\
    \ == RED and color(c->right) == RED) {\n            if (color(a->left) == BLACK)\
    \ {\n                *a = node_t(a->left, c->left, RED);\n                *c =\
    \ node_t(a, c->right, BLACK);\n                swap(a, c);\n            } else\
    \ {\n                a->left->m_color = BLACK;\n                c->m_color = BLACK;\n\
    \                *a = node_t(a->left, c, RED);\n            }\n        } else\
    \ {\n            *a = node_t(a->left, c, a->m_color);\n        }\n        return\
    \ a;\n    }\n\n    /**\n     * @note tree a is consumed  (at explicit delete and\
    \ merge())\n     */\n    static pair<node_t *, node_t *> split(node_t *a, int\
    \ k) {\n        if (k == 0) {\n            return make_pair( nullptr, a );\n \
    \       }\n        assert (a != nullptr);\n        if (k == size(a)) {\n     \
    \       return make_pair( a, nullptr );\n        }\n        assert (not a->is_leaf);\n\
    \        node_t *a_left  = a->left;\n        node_t *a_right = a->right;\n   \
    \     delete a;\n        if (k < size(a_left)) {\n            node_t *l, *r; tie(l,\
    \ r) = split(a_left, k);\n            return make_pair( l, merge(r, a_right) );\n\
    \        } else if (k > size(a_left)) {\n            node_t *l, *r; tie(l, r)\
    \ = split(a_right, k - size(a_left));\n            return make_pair( merge(a_left,\
    \ l), r );\n        } else {\n            return make_pair( a_left, a_right );\n\
    \        }\n    }\n\n    /**\n     * @tparam (A, B) = (node_t const *, T const\
    \ &), (node_t *, T &)\n     */\n    template <class A, class B>\n    static B\
    \ get_generic(A a, int i) {\n        if (a->is_leaf) {\n            assert (i\
    \ == 0);\n            return a->data;\n        } else {\n            if (i < size(a->left))\
    \ {\n                return get_generic<A, B>(a->left, i);\n            } else\
    \ {\n                return get_generic<A, B>(a->right, i - size(a->left));\n\
    \            }\n        }\n    }\n\nprivate:\n    unique_ptr<node_t, node_deleter>\
    \ root;\n\npublic:\n    red_black_tree<T>() = default;\n    red_black_tree<T>(node_t\
    \ *a_root) : root(a_root) {}\n\n    static red_black_tree<T> merge(red_black_tree<T>\
    \ & l, red_black_tree<T> & r) {\n        node_t *a = l.root.release();\n     \
    \   node_t *b = r.root.release();\n        if (a == nullptr) return red_black_tree<T>(b);\n\
    \        if (b == nullptr) return red_black_tree<T>(a);\n        return red_black_tree<T>(merge(a,\
    \ b));\n    }\n    pair<red_black_tree<T>, red_black_tree<T> > split(int k) {\n\
    \        assert (0 <= k and k <= size());\n        node_t *l, *r; tie(l, r) =\
    \ split(root.release(), k);\n        return make_pair( red_black_tree<T>(l), red_black_tree<T>(r)\
    \ );\n    }\n\n    void insert(int i, T const & data) {\n        assert (0 <=\
    \ i and i <= size());\n        if (empty()) {\n            root.reset(new node_t(data));\n\
    \            return;\n        } else {\n            node_t *l, *r; tie(l, r) =\
    \ split(root.release(), i);\n            root.reset( merge(merge(l, new node_t(data)),\
    \ r) );\n        }\n    }\n    void erase(int i) {\n        assert (0 <= i and\
    \ i < size());\n        node_t *l, *r; tie(l, r) = split(root.release(), i + 1);\n\
    \        node_t *m; tie(l, m) = split(l, i);\n        node_deleter()(m);\n   \
    \     root.reset( merge(l, r) );\n    }\n\n    void set(int i, T const & data)\
    \ {\n        assert (0 <= i and i < size());\n        get_generic<node_t *, T\
    \ &>(root.get(), i) = data;\n    }\n    T const & get(int i) const {\n       \
    \ assert (0 <= i and i < size());\n        return get_generic<node_t const *,\
    \ T const &>(root.get(), i);\n    }\n\n    void push_back(T const & data) {\n\
    \        root.reset( merge(root.release(), new node_t(data)) );\n    }\n    void\
    \ push_front(T const & data) {\n        root.reset( merge(new node_t(data), root.release())\
    \ );\n    }\n    void pop_back() {\n        int k = size() - 1;\n        auto\
    \ lr = split(root.release(), k);\n        root.reset(lr.first);\n        node_deleter()(lr.second);\n\
    \    }\n    void pop_front() {\n        auto lr = split(root.release(), 1);\n\
    \        node_deleter()(lr.first);\n        root.reset(lr.second);\n    }\n  \
    \  int size() const {\n        return root ? size(root.get()) : 0;\n    }\n  \
    \  bool empty() const {\n        return not root;\n    }\n    void clear() {\n\
    \        root = nullptr;\n    }\n};\n\nunittest {\n    default_random_engine gen;\n\
    \    auto generate = [&]() {\n        red_black_tree<double> rbtree;\n       \
    \ deque<double> dec;\n        REP (iteration, 100) {\n            double value\
    \ = uniform_real_distribution<double>()(gen);\n            if (bernoulli_distribution(0.5)(gen))\
    \ {\n                rbtree.push_back(value);\n                dec.push_back(value);\n\
    \            } else {\n                rbtree.push_front(value);\n           \
    \     dec.push_front(value);\n            }\n        }\n        return make_pair(\
    \ move(rbtree), dec );\n    };\n    REP (iteration, 1000) {\n        red_black_tree<double>\
    \ rbtree;\n        deque<double> dec;\n        tie(rbtree, dec) = generate();\n\
    \        REP (iteration, 100) {\n            assert (rbtree.size() == dec.size());\n\
    \            int k = uniform_int_distribution<int>(0, rbtree.size())(gen);\n \
    \           int i = rbtree.empty() ? -1 : uniform_int_distribution<int>(0, rbtree.size()\
    \ - 1)(gen);\n            double value = uniform_real_distribution<double>()(gen);\n\
    \            switch (uniform_int_distribution<int>(0, 8)(gen)) {\n           \
    \     case 0:  // merge\n                    {\n                        red_black_tree<double>\
    \ rbtree2;\n                        deque<double> dec2;\n                    \
    \    tie(rbtree2, dec2) = generate();\n                        rbtree = red_black_tree<double>::merge(rbtree,\
    \ rbtree2);\n                        copy(ALL(dec2), back_inserter(dec));\n  \
    \                  }\n                    break;\n                case 1:  //\
    \ split\n                    if (bernoulli_distribution(0.5)(gen)) {\n       \
    \                 rbtree = rbtree.split(k).first;\n                        dec.erase(dec.begin()\
    \ + k, dec.end());\n                    } else {\n                        rbtree\
    \ = rbtree.split(k).second;\n                        dec.erase(dec.begin(), dec.begin()\
    \ + k);\n                    }\n                    break;\n                case\
    \ 2:  // insert\n                    rbtree.insert(k, value);\n              \
    \      dec.push_back(value);\n                    rotate(dec.begin() + k, dec.begin()\
    \ + (dec.size() - 1), dec.end());\n                    break;\n              \
    \  case 3:  // erase\n                    if (not rbtree.empty()) {\n        \
    \                rbtree.erase(i);\n                        rotate(dec.begin()\
    \ + i, dec.begin() + (i + 1), dec.end());\n                        dec.pop_back();\n\
    \                    }\n                    break;\n                case 4:  //\
    \ push_back\n                    rbtree.push_back(value);\n                  \
    \  dec.push_back(value);\n                    break;\n                case 5:\
    \  // push_front\n                    rbtree.push_front(value);\n            \
    \        dec.push_front(value);\n                    break;\n                case\
    \ 6:  // pop_back\n                    if (not rbtree.empty()) {\n           \
    \             rbtree.pop_front();\n                        dec.pop_front();\n\
    \                    }\n                    break;\n                case 7:  //\
    \ pop_front\n                    if (not rbtree.empty()) {\n                 \
    \       rbtree.pop_back();\n                        dec.pop_back();\n        \
    \            }\n                    break;\n                case 8:  // set\n\
    \                    if (not rbtree.empty()) {\n                        rbtree.set(i,\
    \ value);\n                        dec[i] = value;\n                    }\n  \
    \                  break;\n                default:\n                    assert\
    \ (false);\n            }\n            REP (i, rbtree.size()) {\n            \
    \    assert (rbtree.get(i) == dec[i]);\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/red-black-tree.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/red-black-tree.inc.cpp
layout: document
redirect_from:
- /library/old/red-black-tree.inc.cpp
- /library/old/red-black-tree.inc.cpp.html
title: old/red-black-tree.inc.cpp
---
