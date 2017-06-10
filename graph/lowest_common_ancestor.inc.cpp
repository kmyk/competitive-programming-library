// https://kimiyuki.net/blog/2016/07/02/yuki-386/
// https://kimiyuki.net/blog/2015/11/13/yuki-235/
// https://kimiyuki.net/blog/2016/05/18/arc-048-d/
/**
 * @brief lowest common ancestor with doubling
 */
struct lowest_common_ancestor {
    vector<vector<int> > a;
    vector<int> depth;
    lowest_common_ancestor() = default;
    /**
     * @note O(N \log N)
     * @param g an adjacent list of the tree
     */
    lowest_common_ancestor(int root, vector<vector<int> > const & g) {
        int n = g.size();
        int log_n = max<int>(1, ceil(log2(n)));
        a.resize(log_n, vector<int>(n, -1));
        depth.resize(n, -1);
        {
            auto & parent = a[0];
            stack<int> stk;
            depth[root] = 0;
            parent[root] = -1;
            stk.push(root);
            while (not stk.empty()) {
                int x = stk.top(); stk.pop();
                for (int y : g[x]) if (depth[y] == -1) {
                    depth[y] = depth[x] + 1;
                    parent[y] = x;
                    stk.push(y);
                }
            }
        }
        repeat (k, log_n-1) {
            repeat (i, n) {
                if (a[k][i] != -1) {
                    a[k+1][i] = a[k][a[k][i]];
                }
            }
        }
    }
    /**
     * @brief find the LCA of x and y
     * @note O(log N)
     */
    int operator () (int x, int y) const {
        int log_n = a.size();
        if (depth[x] < depth[y]) swap(x,y);
        repeat_reverse (k, log_n) {
            if (a[k][x] != -1 and depth[a[k][x]] >= depth[y]) {
                x = a[k][x];
            }
        }
        assert (depth[x] == depth[y]);
        assert (x != -1);
        if (x == y) return x;
        repeat_reverse (k, log_n) {
            if (a[k][x] != a[k][y]) {
                x = a[k][x];
                y = a[k][y];
            }
        }
        assert (x != y);
        assert (a[0][x] == a[0][y]);
        return a[0][x];
    }
    /**
     * @brief find the descendant of x for y
     */
    int descendant (int x, int y) const {
        assert (depth[x] < depth[y]);
        int log_n = a.size();
        repeat_reverse (k, log_n) {
            if (a[k][y] != -1 and depth[a[k][y]] >= depth[x]+1) {
                y = a[k][y];
            }
        }
        assert (a[0][y] == x);
        return y;
    }
};
