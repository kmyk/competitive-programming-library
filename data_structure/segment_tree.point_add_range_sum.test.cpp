#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../data_structure/segment_tree.hpp"
#include "../monoids/plus.hpp"
#include "../utils/macros.hpp"
#include <cstdint>
#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<int64_t> a(n);
    REP (i, n) {
        scanf("%lld", &a[i]);
    }
    segment_tree<plus_monoid<int64_t> > segtree(ALL(a));
    while (q --) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 0) {
            segtree.point_set(x, segtree.point_get(x) + y);
        } else if (t == 1) {
            int64_t answer = segtree.range_get(x, y);
            printf("%lld\n", answer);
        }
    }
    return 0;
}
