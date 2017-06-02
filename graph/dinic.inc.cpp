// https://kimiyuki.net/blog/2016/01/16/arc-031-d/
double maximum_flow(int s, int t, vector<vector<double> > const & capacity /* adjacency matrix */) { // dinic, O(V^2E)
    int n = capacity.size();
    vector<vector<double> > flow(n, vector<double>(n));
    auto residue = [&](int i, int j) { return capacity[i][j] - flow[i][j]; };
    vector<vector<int> > g(n); repeat (i,n) repeat (j,n) if (capacity[i][j] or capacity[j][i]) g[i].push_back(j); // adjacency list
    double result = 0;
    while (true) {
        vector<int> level(n, -1); level[s] = 0;
        queue<int> q; q.push(s);
        for (int d = n; not q.empty() and level[q.front()] < d; ) {
            int i = q.front(); q.pop();
            if (i == t) d = level[i];
            for (int j : g[i]) if (level[j] == -1 and residue(i,j) > 0) {
                level[j] = level[i] + 1;
                q.push(j);
            }
        }
        vector<bool> finished(n);
        function<double (int, double)> augmenting_path = [&](int i, double cur) -> double {
            if (i == t or cur == 0) return cur;
            if (finished[i]) return 0;
            finished[i] = true;
            for (int j : g[i]) if (level[i] < level[j]) {
                double f = augmenting_path(j, min(cur, residue(i,j)));
                if (f > 0) {
                    flow[i][j] += f;
                    flow[j][i] -= f;
                    finished[i] = false;
                    return f;
                }
            }
            return 0;
        };
        bool cont = false;
        while (true) {
            double f = augmenting_path(s, numeric_limits<double>::max());
            if (f == 0) break;
            result += f;
            cont = true;
        }
        if (not cont) break;
    }
    return result;
}
