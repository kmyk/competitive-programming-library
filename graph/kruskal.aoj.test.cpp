#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A"
#include "../graph/kruskal.hpp"

#include "../utils/macros.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input
    int n; scanf("%d", &n);
    vector<tuple<int, int, long long> > edges;
    REP (x, n) {
        REP (y, n) {
            long long a; scanf("%lld", &a);
            if (a != -1) {
                edges.emplace_back(x, y, a);
            }
        }
    }

    // solve
    vector<int> mst = compute_minimum_spanning_tree(n, edges);
    long long answer = 0;
    for (int i : mst) {
        answer += get<2>(edges[i]);
    }

    // output
    printf("%lld\n", answer);
    return 0;
}
