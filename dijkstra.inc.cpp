// https://kimiyuki.net/blog/2017/03/24/cf-786-b/
vector<ll> dijkstra(vector<vector<pair<int, ll> > > const & g, int root) {
    vector<ll> dist(n, inf);
    priority_queue<pair<ll, int> > que;
    dist[root] = 0;
    que.emplace(- dist[root], root);
    while (not que.empty()) {
        ll cost; int i; tie(cost, i) = que.top(); que.pop();
        if (dist[i] < - cost) continue;
        for (auto it : g[i]) {
            int j; ll delta; tie(j, delta) = it;
            if (- cost + delta < dist[j]) {
                dist[j] = - cost + delta;
                que.emplace(cost - delta, j);
            }
        }
    }
    return dist;
}

template <typename T>
vector<T> original_dijkstra(vector<vector<pair<int, T> > > const & g, int start, T inf) { // O(V^2)
    int n = g.size();
    vector<double> dist(n, inf);
    vector<int> ixs(n); whole(iota, ixs, 0);
    dist[start] = 0;
    repeat (loop,n) {
        int i; {
            auto it = whole(min_element, ixs, [&](int i, int j) { return dist[i] < dist[j]; });
            i = *it;
            *it = ixs.back();
            ixs.pop_back();
        }
        for (auto it : g[i]) {
            int j; T cost; tie(j, cost) = it;
            setmin(dist[j], dist[i] + cost);
        }
    }
    return dist;
}
