#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../data_structure/convex_hull_trick.hpp"
#include "../utils/macros.hpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    convex_hull_trick cht;
    REP (i, n) {
        int64_t a, b; scanf("%lld%lld", &a, &b);
        cht.add_line(a, b);
    }
    while (q --) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int64_t a, b; scanf("%lld%lld", &a, &b);
            cht.add_line(a, b);
        } else if (t == 1) {
            int64_t p; scanf("%lld", &p);
            printf("%lld\n", cht.get_min(p));
        } else {
            assert (false);
        }
    }
    return 0;
}
