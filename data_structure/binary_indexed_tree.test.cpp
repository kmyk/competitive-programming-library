#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <cstdio>
#include <tuple>
#include <vector>
#include "../data_structure/binary_indexed_tree.hpp"
#include "../monoids/plus.hpp"
#include "../utils/macros.hpp"
using namespace std;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<long long> a(n);
    REP (i, n) {
        scanf("%lld", &a[i]);
    }
    binary_indexed_tree<plus_monoid<long long> > bit(ALL(a));
    while (q --) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 0) {
            bit.point_mult(x, y);
        } else if (t == 1) {
            long long answer = bit.initial_range_get(y) - bit.initial_range_get(x);
            printf("%lld\n", answer);
        }
    }
    return 0;
}
