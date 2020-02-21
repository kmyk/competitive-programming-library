#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405"
#include <cstdio>
#include "graph/tree_decomposition.hpp"
#include "modulus/mint.hpp"
#include "utils/macros.hpp"
using namespace std;


constexpr int MOD = 1000003;
mint<MOD> solve(int n, int m, vector<vector<int> > & g) {
    // update g
    REP (x, n) {
        g[x].push_back((x + 1) % n);
        g[(x + 1) % n].push_back(x);
    }
    REP (x, n) {
        sort(ALL(g[x]));
        g[x].erase(unique(ALL(g[x])), g[x].end());
    }

    // tree decomposition
    auto [parent, bags_] = get_tree_decomposition(g);
    auto nice = get_nice_tree_decomposition(parent, bags_);

    // dp
    vector<set<int> > bags(nice.size());
    auto index = [&](int a, int x) {
        assert (bags[a].count(x));
        return distance(bags[a].begin(), bags[a].find(x));
    };
    auto translate = [&](int a, int s, int b) {
        int t = 0;
        for (int x : bags[a]) {
            if (bags[b].count(x) and (s & (1 << index(a, x)))) {
                t |= 1 << index(b, x);
            }
        }
        return t;
    };
    vector<vector<mint<MOD> > > dp(nice.size());
    REP (a, nice.size()) {
        auto [tag, x, b] = nice[a];
        if (tag == LEAF) {
            bags[a].insert(x);
            dp[a].resize(1 << bags[a].size());
            dp[a][0] += 1;
        } else if (tag == INTRODUCE) {
            bags[a] = bags[b];
            bags[a].insert(x);
            assert (bags[a].size() <= 3);
            dp[a].resize(1 << bags[a].size());
            REP (t, dp[b].size()) {
                int s = translate(b, t, a);
                dp[a][s] += dp[b][t];
            }
        } else if (tag == FORGET) {
            assert (bags[b].count(x));
            bags[a] = bags[b];
            bags[a].erase(x);
            dp[a].resize(1 << bags[a].size());
            REP (t, dp[b].size()) {
                int s = translate(b, t, a);
                if (t & (1 << index(b, x))) {
                    dp[a][s] += dp[b][t];
                } else {
                    for (int y : g[x]) {
                        if (bags[a].count(y) and not (s & (1 << index(a, y)))) {
                            int u = s | (1 << index(a, y));
                            dp[a][u] += dp[b][t];
                        }
                    }
                }
            }
        } else if (tag == JOIN) {
            assert (bags[x] == bags[b]);
            bags[a] = bags[b];
            dp[a].resize(1 << bags[a].size());
            REP (s, dp[a].size()) {
                REP (t, dp[a].size()) if ((s & t) == 0) {
                    dp[a][s | t] += dp[x][s] * dp[b][t];
                }
            }
        }
    }
    return dp.back().back();
}

int main() {
    while (true) {
        int n, m; scanf("%d%d", &n, &m);
        if (n == 0 and m == 0) break;
        vector<vector<int> > g(n);
        REP (i, m) {
            int a, b; scanf("%d%d", &a, &b);
            -- a;
            -- b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        mint<MOD> cnt = solve(n, m, g);
        printf("%d\n", cnt.value);
    }
    return 0;
}
