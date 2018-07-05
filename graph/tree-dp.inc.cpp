/**
 * @brief fold a rooted tree (木DP)
 * @note O(N op) time
 * @note O(N) space, not recursive
 * @note
 *     struct tree_operation {
 *         typedef int type;
 *         type operator () (int i, vector<pair<int, type> > const & args);
 *     };
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
