#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include <cstdio>
#include <vector>
#include "../utils/macros.hpp"
#include "../data_structure/sparse_table.hpp"
#include "../monoids/gcd.hpp"

long long solve(int n, const std::vector<long long> & a) {
    sparse_table<gcd_monoid<long long> > table(ALL(a));
    int r = 0;
    long long ans = 0;
    REP (l, n) {
        while (r < n and table.range_get(l, r) != 1) {
            ++ r;
        }
        if (r == n and table.range_get(l, r) != 1) {
            break;
        }
        ans += n - r + 1;
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    std::vector<long long> a(n);
    REP (i, n) {
        scanf("%lld", &a[i]);
    }
    printf("%lld\n", solve(n, a));
    return 0;
}
