#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../data_structure/lazy_propagation_segment_tree.hpp"
#include "../monoids/plus_count.hpp"
#include "../monoids/linear_function.hpp"
#include "../monoids/linear_function_plus_count_action.hpp"
#include "../modulus/mint.hpp"
#include "../utils/macros.hpp"
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    vector<pair<mint<MOD>, int> > a(n);
    REP (i, n) {
        int a_i; scanf("%d", &a_i);
        a[i].first = a_i;
        a[i].second = 1;
    }
    lazy_propagation_segment_tree<plus_count_monoid<mint<MOD> >, linear_function_monoid<mint<MOD> >, linear_function_plus_count_action<mint<MOD> > > segtree(ALL(a));
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, b, c; scanf("%d%d%d%d", &l, &r, &b, &c);
            pair<mint<MOD>, mint<MOD> > f(b, c);
            segtree.range_apply(l, r, f);
        } else if (t == 1) {
            int l, r; scanf("%d%d", &l, &r);
            mint<MOD> answer = segtree.range_get(l, r).first;
            printf("%d\n", answer.value);
        }
    }
    return 0;
}
