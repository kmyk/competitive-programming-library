// https://kimiyuki.net/blog/2016/07/02/yuki-386/
// https://kimiyuki.net/blog/2015/11/13/yuki-235/
// https://kimiyuki.net/blog/2016/05/18/arc-048-d/
struct heavy_light_decomposition_t {
    int n; // |V'|
    vector<int> a; // V ->> V' epic
    vector<vector<int> > path; // V' -> V*, bottom to top order, disjoint union of codomain matchs V
    vector<map<int,int> > pfind; // V' * V -> int, find in path
    vector<int> parent; // V' -> V
    heavy_light_decomposition_t(int v, vector<vector<int> > const & g) {
        n = 0;
        a.resize(g.size());
        dfs(v, -1, g);
    }
    int dfs(int v, int p, vector<vector<int> > const & g) {
        int heavy_node = -1;
        int heavy_size = 0;
        int desc_size = 1;
        for (int w : g[v]) if (w != p) {
            int size = dfs(w, v, g);
            desc_size += size;
            if (heavy_size < size) {
                heavy_node = w;
                heavy_size = size;
            }
        }
        if (heavy_node == -1) {
            a[v] = n;
            n += 1;
            path.emplace_back();
            path.back().push_back(v);
            pfind.emplace_back();
            pfind.back()[v] = 0;
            parent.push_back(p);
        } else {
            int i = a[heavy_node];
            a[v] = i;
            pfind[i][v] = path[i].size();
            path[i].push_back(v);
            parent[i] = p;
        }
        return desc_size;
    }
};

// https://kimiyuki.net/blog/2016/07/02/yuki-386/
// https://kimiyuki.net/blog/2016/05/18/arc-048-d/
template <typename T>
T path_concat(heavy_light_decomposition_t & hl, vector<segment_tree<T> > & sts, int v, int w) {
    auto append = sts.front().append;
    auto unit   = sts.front().unit;
    T acc = unit;
    int i = hl.a[v];
    if (hl.a[w] == i) {
        assert (hl.pfind[i][v] <= hl.pfind[i][w]); // v must be a descendant of w
        acc = append(acc, sts[i].range_concat(hl.pfind[i][v], hl.pfind[i][w]+1));
    } else {
        acc = append(acc, sts[i].range_concat(hl.pfind[i][v], hl.path[i].size()));
        acc = append(acc, path_concat(hl, sts, hl.parent[i], w));
    }
    return acc;
}

// https://kimiyuki.net/blog/2016/07/02/yuki-386/
template <typename T>
T path_concat(heavy_light_decomposition_t & hl, lowest_common_ancestor_t & lca, vector<segment_tree<T> > & sts, int x, int y) {
    auto append = sts.front().append;
    auto unit   = sts.front().unit;
    int z = lca(x, y);
    T acc = unit;
    if (x != z) acc = append(acc, path_concat(hl, sts, x, lca.descendant(z, x)));
    if (y != z) acc = append(acc, path_concat(hl, sts, y, lca.descendant(z, y)));
    acc = append(acc, path_concat(hl, sts, z, z));
    return acc;
}
