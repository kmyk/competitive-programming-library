/**
 * @brief Dinic
 * @note O(V^2 E)
 * @note based on http://algoogle.hadrori.jp/algorithm/dinic.html
 * @note tihs works with almost same speed to MiSawa's one https://gist.github.com/MiSawa/9532038 if you do s/ll/int/
 */
class max_flow {
    struct edge_t {
        int to;
        ll cap;
        int rev;
    };
    int v;
    vector<vector<edge_t> > g;
    vector<int> iter, level;
public:
    max_flow(int v_)
            : v(v_), g(v) {
    }
    void add_edge(int from, int to, ll cap) {
        g[from].push_back((edge_t) { to, cap, (int)g[to].size() });
        g[to].push_back((edge_t) { from, 0ll, (int)g[from].size() - 1 });
    }
private:
    void bfs(int src) {
        level.assign(v, -1);
        queue<int> q;
        level[src] = 0;
        q.push(src);
        while (not q.empty()) {
            int x = q.front();
            q.pop();
            for (auto & e : g[x]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[x] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    ll dfs(int x, int dst, ll flow) {
        if (x == dst) return flow;
        for (int & i = iter[x]; i < (int)g[x].size(); ++ i) {
            edge_t & e = g[x][i];
            if (e.cap > 0 and level[x] < level[e.to]) {
                ll d = dfs(e.to, dst, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
public:
    ll run_destructive(int src, int dst) {
        ll flow = 0;
        bfs(src);
        while (level[dst] >= 0) {
            iter.assign(v, 0);
            while (true) {
                ll delta = dfs(src, dst, INF);
                if (delta <= 0) break;
                flow += delta;
            }
            bfs(src);
        }
        return flow;
    }
};
