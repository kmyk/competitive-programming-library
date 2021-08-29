#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../data_structure/segment_tree.hpp"
#include "../monoids/linear_function.hpp"
#include "../monoids/dual.hpp"
#include "../modulus/mint.hpp"
#include "../utils/macros.hpp"
#include <cstdint>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int n, q; scanf("%d%d", &n, &q);
    segment_tree<dual_monoid<linear_function_monoid<mint<MOD> > > > segtree(n);
    REP (i, n) {
        int a, b; scanf("%d%d", &a, &b);
        segtree.point_set(i, make_pair(a, b));
    }
    while (q --) {
        int f, x, y, z; scanf("%d%d%d%d", &f, &x, &y, &z);
        if (f == 0) {
            segtree.point_set(x, make_pair(y, z));
        } else if (f == 1) {
            mint<MOD> a, b; tie(a, b) = segtree.range_get(x, y);
            printf("%d\n", (a * z + b).value);
        }
    }
    return 0;
}
