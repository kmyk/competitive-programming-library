// https://kimiyuki.net/blog/2016/07/02/yuki-386/
// https://kimiyuki.net/blog/2015/11/13/yuki-235/
// https://kimiyuki.net/blog/2016/05/18/arc-048-d/
struct lowest_common_ancestor_t {
    vector<vector<int> > a;
    vector<int> depth;
    lowest_common_ancestor_t(int v, vector<vector<int> > const & g) {
        int n = g.size();
        int l = 1 + floor(log2(n));
        a.resize(l);
        repeat (k,l) a[k].resize(n, -1);
        depth.resize(n);
        dfs(v, -1, 0, g, a[0], depth);
        repeat (k,l-1) {
            repeat (i,n) {
                if (a[k][i] != -1) {
                    a[k+1][i] = a[k][a[k][i]];
                }
            }
        }
    }
    static void dfs(int v, int p, int current_depth, vector<vector<int> > const & g, vector<int> & parent, vector<int> & depth) {
        parent[v] = p;
        depth[v] = current_depth;
        for (int w : g[v]) if (w != p) {
            dfs(w, v, current_depth + 1, g, parent, depth);
        }
    }
    // find lca of x, y
    int operator () (int x, int y) const { // O(log N)
        int l = a.size();
        if (depth[x] < depth[y]) swap(x,y);
        repeat_reverse (k,l) {
            if (a[k][x] != -1 and depth[a[k][x]] >= depth[y]) {
                x = a[k][x];
            }
        }
        assert (depth[x] == depth[y]);
        assert (x != -1);
        if (x == y) return x;
        repeat_reverse (k,l) {
            if (a[k][x] != a[k][y]) {
                x = a[k][x];
                y = a[k][y];
            }
        }
        assert (x != y);
        assert (a[0][x] == a[0][y]);
        return a[0][x];
    }
    // find the descendant of x for y
    int descendant (int x, int y) const {
        assert (depth[x] < depth[y]);
        int l = a.size();
        repeat_reverse (k,l) {
            if (a[k][y] != -1 and depth[a[k][y]] >= depth[x]+1) {
                y = a[k][y];
            }
        }
        assert (a[0][y] == x);
        return y;
    }
};
