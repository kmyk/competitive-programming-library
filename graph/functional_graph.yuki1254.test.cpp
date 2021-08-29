#define PROBLEM "https://yukicoder.me/problems/no/1254"
#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include "../utils/macros.hpp"
#include "../graph/functional_graph.hpp"
using namespace std;

vector<int> solve(int n, const vector<pair<int, int> >& edges) {
    vector<vector<int> > g(n);
    map<pair<int, int>, int> lookup;
    REP (i, edges.size()) {
        auto [a, b] = edges[i];
        g[a].push_back(b);
        g[b].push_back(a);
        lookup[make_pair(a, b)] = i;
        lookup[make_pair(b, a)] = i;
    }

    auto cycle = get_namori_cycle(g);
    vector<int> ans;
    REP (i, cycle.size()) {
        int a = cycle[i];
        int b = cycle[(i + 1) % cycle.size()];
        ans.push_back(lookup[make_pair(a, b)]);
    }
    sort(ALL(ans));
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int> > edges(n);
    REP (i, n) {
        int a, b; scanf("%d%d", &a, &b);
        -- a;
        -- b;
        edges[i] = make_pair(a, b);
    }
    vector<int> ans = solve(n, edges);
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) {
        printf("%d%c", ans[i] + 1, i + 1 < ans.size() ? ' ' : '\n');
    }
    return 0;
}
