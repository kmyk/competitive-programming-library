#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../data_structure/sliding_window_aggregation.hpp"
#include "../monoids/linear_function.hpp"
#include "../monoids/dual.hpp"
#include "../modulus/mint.hpp"
#include <cstdio>
#include <tuple>
using namespace std;

constexpr int MOD = 998244353;
int main() {
    int q; scanf("%d", &q);
    sliding_window_aggregation<dual_monoid<linear_function_monoid<mint<MOD> > > > swag;
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int a, b; scanf("%d%d", &a, &b);
            swag.push(make_pair(a, b));
        } else if (t == 1) {
            swag.pop();
        } else if (t == 2) {
            int x; scanf("%d", &x);
            mint<MOD> a, b; tie(a, b) = swag.accumulate();
            printf("%d\n", (a * x + b).value);
        }
    }
    return 0;
}
