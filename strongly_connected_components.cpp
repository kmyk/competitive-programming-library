// https://kimiyuki.net/blog/2015/12/22/arc-010-d/
// https://kimiyuki.net/blog/2016/06/12/jag2016-domestic2-d/
struct strongly_connected_components {
    static pair<int,vector<int> > decompose(vector<vector<int> > const & g) { // adjacent list
        strongly_connected_components scc(g);
        return { scc.k, scc.c };
    }
private:
    int n;
    vector<vector<int> > to, from;
    explicit strongly_connected_components(vector<vector<int> > const & g) : n(g.size()), to(g), from(n) {
        repeat (i,n) for (int j : to[i]) from[j].push_back(i);
        decompose();
    }
    vector<bool> used;
    vector<int> vs;
    void dfs(int i) {
        used[i] = true;
        for (int j : to[i]) if (not used[j]) dfs(j);
        vs.push_back(i);
    }
    int k; // number of scc
    vector<int> c; // i-th vertex in g is in c_i-th vertex in scc-decomposed g
    void rdfs(int i) {
        used[i] = true;
        c[i] = k;
        for (int j : from[i]) if (not used[j]) rdfs(j);
    }
    void decompose() {
        used.clear(); used.resize(n, false);
        repeat (i,n) if (not used[i]) dfs(i);
        used.clear(); used.resize(n, false);
        k = 0;
        c.resize(n);
        reverse(vs.begin(), vs.end());
        for (int i : vs) if (not used[i]) {
            rdfs(i);
            k += 1;
        }
    }
};
