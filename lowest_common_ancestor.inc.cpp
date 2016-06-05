// http://solorab.net/blog/2015/11/13/yuki-235/
// http://solorab.net/blog/2016/05/18/arc-048-d/
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
    int operator () (int x, int y) const {
        int l = a.size();
        if (depth[x] < depth[y]) swap(x,y);
        repeat_reverse (k,l) {
            if (a[k][x] != -1 and depth[a[k][x]] >= depth[y]) {
                x = a[k][x];
            }
        }
        assert (depth[x] == depth[y]);
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
};
