---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: fold a rooted tree / 木DP <small>(old/tree-dp.inc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/tree-dp.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 18:35:19+09:00


* see: <a href="https://twitter.com/tmaehara/status/980787099472297985">https://twitter.com/tmaehara/status/980787099472297985</a>
* see: <a href="https://twitter.com/tmaehara/status/980787099472297985">https://twitter.com/tmaehara/status/980787099472297985</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief fold a rooted tree / 木DP
 * @note O(N op) time
 * @note O(N) space, not recursive
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type operator () (int i, vector<pair<int, type> > const & args);
 *     };
 * @note interfaceちょっと微妙じゃない？ どうせ一緒にadd()実装する あと辺に重みがあると修正がつらい
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    int n = g.size();
    vector<typename TreeOperation::type> data(n);
    stack<tuple<bool, int, int> > stk;
    stk.emplace(false, root, -1);
    while (not stk.empty()) {
        bool state; int x, parent; tie(state, x, parent) = stk.top(); stk.pop();
        if (not state) {
            stk.emplace(true, x, parent);
            for (int y : g[x]) if (y != parent) {
                stk.emplace(false, y, x);
            }
        } else {
            vector<pair<int, typename TreeOperation::type> > args;
            for (int y : g[x]) if (y != parent) {
                args.emplace_back(y, data[y]);
            }
            data[x] = op(x, args);
        }
    };
    return data;
}

/**
 * @brief rerooting (全方位木DP)
 * @note O(N op) time
 * @note O(N) space, not recursive
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type      add(int i, type data_i, int j, type data_j);  // add    a subtree j to   the root i
 *         type subtract(int i, type data_i, int j, type data_j);  // remove a subtree j from the root i
 *     };
 * @note if add & subtract are slow, you can merge them
 * @see https://twitter.com/tmaehara/status/980787099472297985
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    stack<pair<int, int> > stk;
    stk.emplace(root, -1);
    while (not stk.empty()) {
        int x, parent; tie(x, parent) = stk.top(); stk.pop();
        if (parent != -1) {
            data[x] = op.add(x, data[x], parent, op.subtract(parent, data[parent], x, data[x]));
        }
        for (int y : g[x]) if (y != parent) {
            stk.emplace(y, x);
        }
    }
    return data;
}

// 注意: まだverifyしてない
struct height_tree_operation {
    typedef pair<int, int> type;
    type operator () (int i, vector<pair<int, type> > const & args) {
        type acc = make_pair(INT_MIN, INT_MIN);
        for (auto arg : args) {
            acc = add(i, acc, arg.first, arg.second);
        }
        return acc;
    }
    type add(int i, type data_i, int j, type data_j) {  // add a subtree j to the root i
        array<int, 3> height = {{ data_i.first, data_i.second, data_j.first + 1 }};  // NOTE: the length is corrent
        sort(height.rbegin(), height.rend());
        return make_pair(height[0], height[1]);
    }
    type subtract(int i, type data_i, int j, type data_j) {  // remove a subtree j from the root i
        if (data_i.first == data_j.first + 1) {
            return make_pair(data_i.second, INT_MIN);  // NOTE: this is correct
        } else {
            return data_i;
        }
    }
};

struct heights_tree_operation {
    typedef multiset<int> type;  // heights of subtrees
    type operator () (int i, vector<pair<int, type> > const & args) {
        type data;
        for (auto arg : args) {
            data = add(i, data, arg.first, arg.second);
        }
        return data;
    }
    type add(int i, type data_i, int j, type data_j) {  // add a subtree j to the root i
        int height = 1 + accumulate(ALL(data_j), 0, [&](int a, int b) { return max(a, b); });
        data_i.insert(height);
        return data_i;
    }
    type subtract(int i, type data_i, int j, type data_j) {  // remove a subtree j from the root i
        int height = 1 + accumulate(ALL(data_j), 0, [&](int a, int b) { return max(a, b); });
        auto it = data_i.find(height);
        data_i.erase(it);
        return data_i;
    }
};
unittest {
    vector<vector<int> > g(9);
    constexpr int root = 0;
    g[0].push_back(1);
    g[0].push_back(2);
    ;   g[2].push_back(4);
    ;   g[2].push_back(5);
    ;   g[2].push_back(6);
    ;   ;   g[6].push_back(8);
    g[0].push_back(3);
    ;   g[3].push_back(7);
    auto dp1 = fold_rooted_tree(g, root, heights_tree_operation());
    auto dp2 = reroot_folded_rooted_tree(dp1, g, root, heights_tree_operation());
    assert (dp1[root] == dp2[root]);
    assert (dp1[2] == multiset<int>({ 1, 1, 2 }));
    assert (dp2[2] == multiset<int>({ 1, 1, 2, 3 }));
    assert (dp1[3] == multiset<int>({ 1 }));
    assert (dp2[3] == multiset<int>({ 1, 4 }));
}



// 簡略化したやつ 未検証

/**
 * @brief fold a rooted tree (木DP)
 * @note O(N op) time
 * @note O(N) space on stack
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type unit(int i);  // get an initial value of root i
 *         type add(int i, type data_i, int j, type data_j);  // add a subtree j to the root i
 *     };
 * @note you can replace unit() + add() with a single function
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    int n = g.size();
    vector<typename TreeOperation::type> data(n);
    function<void (int, int)> go = [&](int i, int parent) {
        data[i] = op.unit(i);
        for (int j : g[i]) if (j != parent) {
            go(j, i);
            data[i] = op.add(i, data[i], j, data[j]);
        }
    };
    go(root, -1);
    return data;
}

/**
 * @brief rerooting (全方位木DP)
 * @note O(N op) time
 * @note O(N) space on stack
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type      add(int i, type data_i, int j, type data_j);  // add    a subtree j to   the root i
 *         type subtract(int i, type data_i, int j, type data_j);  // remove a subtree j from the root i
 *     };
 * @note a commutative group is one of the structures for this
 * @note you can replace add() + subtract() with a single function
 * @see https://twitter.com/tmaehara/status/980787099472297985
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    function<void (int, int)> go = [&](int i, int parent) {
        if (parent != -1) {
            data[i] = op.add(i, data[i], op.subtract(parent, data[parent], i, data[i]));
        }
        for (int j : g[i]) if (j != parent) {
            go(j, i);
        }
    };
    go(root, -1);
    return data;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/tree-dp.inc.cpp"
/**
 * @brief fold a rooted tree / 木DP
 * @note O(N op) time
 * @note O(N) space, not recursive
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type operator () (int i, vector<pair<int, type> > const & args);
 *     };
 * @note interfaceちょっと微妙じゃない？ どうせ一緒にadd()実装する あと辺に重みがあると修正がつらい
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    int n = g.size();
    vector<typename TreeOperation::type> data(n);
    stack<tuple<bool, int, int> > stk;
    stk.emplace(false, root, -1);
    while (not stk.empty()) {
        bool state; int x, parent; tie(state, x, parent) = stk.top(); stk.pop();
        if (not state) {
            stk.emplace(true, x, parent);
            for (int y : g[x]) if (y != parent) {
                stk.emplace(false, y, x);
            }
        } else {
            vector<pair<int, typename TreeOperation::type> > args;
            for (int y : g[x]) if (y != parent) {
                args.emplace_back(y, data[y]);
            }
            data[x] = op(x, args);
        }
    };
    return data;
}

/**
 * @brief rerooting (全方位木DP)
 * @note O(N op) time
 * @note O(N) space, not recursive
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type      add(int i, type data_i, int j, type data_j);  // add    a subtree j to   the root i
 *         type subtract(int i, type data_i, int j, type data_j);  // remove a subtree j from the root i
 *     };
 * @note if add & subtract are slow, you can merge them
 * @see https://twitter.com/tmaehara/status/980787099472297985
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    stack<pair<int, int> > stk;
    stk.emplace(root, -1);
    while (not stk.empty()) {
        int x, parent; tie(x, parent) = stk.top(); stk.pop();
        if (parent != -1) {
            data[x] = op.add(x, data[x], parent, op.subtract(parent, data[parent], x, data[x]));
        }
        for (int y : g[x]) if (y != parent) {
            stk.emplace(y, x);
        }
    }
    return data;
}

// 注意: まだverifyしてない
struct height_tree_operation {
    typedef pair<int, int> type;
    type operator () (int i, vector<pair<int, type> > const & args) {
        type acc = make_pair(INT_MIN, INT_MIN);
        for (auto arg : args) {
            acc = add(i, acc, arg.first, arg.second);
        }
        return acc;
    }
    type add(int i, type data_i, int j, type data_j) {  // add a subtree j to the root i
        array<int, 3> height = {{ data_i.first, data_i.second, data_j.first + 1 }};  // NOTE: the length is corrent
        sort(height.rbegin(), height.rend());
        return make_pair(height[0], height[1]);
    }
    type subtract(int i, type data_i, int j, type data_j) {  // remove a subtree j from the root i
        if (data_i.first == data_j.first + 1) {
            return make_pair(data_i.second, INT_MIN);  // NOTE: this is correct
        } else {
            return data_i;
        }
    }
};

struct heights_tree_operation {
    typedef multiset<int> type;  // heights of subtrees
    type operator () (int i, vector<pair<int, type> > const & args) {
        type data;
        for (auto arg : args) {
            data = add(i, data, arg.first, arg.second);
        }
        return data;
    }
    type add(int i, type data_i, int j, type data_j) {  // add a subtree j to the root i
        int height = 1 + accumulate(ALL(data_j), 0, [&](int a, int b) { return max(a, b); });
        data_i.insert(height);
        return data_i;
    }
    type subtract(int i, type data_i, int j, type data_j) {  // remove a subtree j from the root i
        int height = 1 + accumulate(ALL(data_j), 0, [&](int a, int b) { return max(a, b); });
        auto it = data_i.find(height);
        data_i.erase(it);
        return data_i;
    }
};
unittest {
    vector<vector<int> > g(9);
    constexpr int root = 0;
    g[0].push_back(1);
    g[0].push_back(2);
    ;   g[2].push_back(4);
    ;   g[2].push_back(5);
    ;   g[2].push_back(6);
    ;   ;   g[6].push_back(8);
    g[0].push_back(3);
    ;   g[3].push_back(7);
    auto dp1 = fold_rooted_tree(g, root, heights_tree_operation());
    auto dp2 = reroot_folded_rooted_tree(dp1, g, root, heights_tree_operation());
    assert (dp1[root] == dp2[root]);
    assert (dp1[2] == multiset<int>({ 1, 1, 2 }));
    assert (dp2[2] == multiset<int>({ 1, 1, 2, 3 }));
    assert (dp1[3] == multiset<int>({ 1 }));
    assert (dp2[3] == multiset<int>({ 1, 4 }));
}



// 簡略化したやつ 未検証

/**
 * @brief fold a rooted tree (木DP)
 * @note O(N op) time
 * @note O(N) space on stack
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type unit(int i);  // get an initial value of root i
 *         type add(int i, type data_i, int j, type data_j);  // add a subtree j to the root i
 *     };
 * @note you can replace unit() + add() with a single function
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> fold_rooted_tree(vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    int n = g.size();
    vector<typename TreeOperation::type> data(n);
    function<void (int, int)> go = [&](int i, int parent) {
        data[i] = op.unit(i);
        for (int j : g[i]) if (j != parent) {
            go(j, i);
            data[i] = op.add(i, data[i], j, data[j]);
        }
    };
    go(root, -1);
    return data;
}

/**
 * @brief rerooting (全方位木DP)
 * @note O(N op) time
 * @note O(N) space on stack
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type      add(int i, type data_i, int j, type data_j);  // add    a subtree j to   the root i
 *         type subtract(int i, type data_i, int j, type data_j);  // remove a subtree j from the root i
 *     };
 * @note a commutative group is one of the structures for this
 * @note you can replace add() + subtract() with a single function
 * @see https://twitter.com/tmaehara/status/980787099472297985
 */
template <typename TreeOperation>
vector<typename TreeOperation::type> reroot_folded_rooted_tree(vector<typename TreeOperation::type> data, vector<vector<int> > const & g, int root, TreeOperation op = TreeOperation()) {
    function<void (int, int)> go = [&](int i, int parent) {
        if (parent != -1) {
            data[i] = op.add(i, data[i], op.subtract(parent, data[parent], i, data[i]));
        }
        for (int j : g[i]) if (j != parent) {
            go(j, i);
        }
    };
    go(root, -1);
    return data;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

