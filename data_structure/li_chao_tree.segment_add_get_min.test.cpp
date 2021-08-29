#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../data_structure/li_chao_tree.hpp"
#include "../utils/macros.hpp"
#include <cstdio>
#include <climits>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    // input
    int n, q; scanf("%d%d", &n, &q);
    vector<int64_t> xs;
    vector<tuple<int64_t, int64_t, int64_t, int64_t> > segments;
    REP (i, n) {
        int64_t l, r, a, b; scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
        xs.push_back(l);
        xs.push_back(r);
        segments.emplace_back(l, r, a, b);
    }
    vector<tuple<int, int64_t, int64_t, int64_t, int64_t, int64_t> > queries;
    REP (j, q) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int64_t l, r, a, b; scanf("%lld%lld%lld%lld", &l, &r, &a, &b);
            xs.push_back(l);
            xs.push_back(r);
            queries.emplace_back(t, l, r, a, b, -1);
        } else if (t == 1) {
            int64_t p; scanf("%lld", &p);
            xs.push_back(p);
            queries.emplace_back(t, -1, -1, -1, -1, p);
        } else {
            assert (false);
        }
    }

    // construct
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    li_chao_tree lichao(xs);

    // output
    for (auto [l, r, a, b] : segments) {
        lichao.add_segment(l, r, a, b);
    }
    for (auto [t, l, r, a, b, p] : queries) {
        if (t == 0) {
            lichao.add_segment(l, r, a, b);
        } else if (t == 1) {
            int64_t q = lichao.get_min(p);
            if (q == INT64_MAX) {
                printf("INFINITY\n");
            } else {
                printf("%lld\n", q);
            }
        } else {
            assert (false);
        }
    }
    return 0;
}
