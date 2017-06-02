struct edge_t { int to, cap, rev; };
int maximum_flow_destructive(int s, int t, vector<vector<edge_t> > & g) { // ford fulkerson, O(EF)
    int n = g.size();
    vector<bool> used(n);
    function<int (int, int)> dfs = [&](int i, int f) {
        if (i == t) return f;
        used[i] = true;
        for (edge_t & e : g[i]) {
            if (used[e.to] or e.cap <= 0) continue;
            int nf = dfs(e.to, min(f, e.cap));
            if (nf > 0) {
                e.cap -= nf;
                g[e.to][e.rev].cap += nf;
                return nf;
            }
        }
        return 0;
    };
    int result = 0;
    while (true) {
        used.clear(); used.resize(n);
        int f = dfs(s, numeric_limits<int>::max());
        if (f == 0) break;
        result += f;
    }
    return result;
}
void add_edge(vector<vector<edge_t> > & g, int from, int to, int cap) {
    g[from].push_back((edge_t) {   to, cap, int(g[  to].size()    ) });
    g[  to].push_back((edge_t) { from,   0, int(g[from].size() - 1) });
}
int maximum_flow(int s, int t, vector<vector<edge_t> > g /* adjacency list */) { // ford fulkerson, O(FE)
    return maximum_flow_destructive(s, t, g);
}

vector<pair<int,int> > perfect_bipartite_matching(set<int> const & a, set<int> const & b, vector<vector<int> > const & g /* adjacency list */) { // O(V + FE)
    assert (a.size() + b.size() <= g.size());
    int n = g.size();
    int src = n;
    int dst = n + 1;
    vector<vector<edge_t> > h(n + 2);
    auto add_edge = [&](int from, int to, int cap) {
        h[from].push_back((edge_t) {   to, cap, int(h[  to].size()    ) });
        h[  to].push_back((edge_t) { from,   0, int(h[from].size() - 1) });
    };
    repeat (i,n) {
        if (a.count(i)) {
            add_edge(src, i, 1);
            for (int j : g[i]) if (b.count(j)) {
                add_edge(i, j, 1); // collect edges e : a -> b, from g
            }
        }
        if (b.count(i)) {
            add_edge(i, dst, 1);
        }
    }
    maximum_flow_destructive(src, dst, h);
    vector<pair<int,int> > ans;
    for (int from : a) {
        for (edge_t e : h[from]) if (b.count(e.to) and e.cap == 0) {
            ans.emplace_back(from, e.to);
        }
    }
    return ans;
}
