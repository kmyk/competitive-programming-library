#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include <cstdio>
#include <vector>
#include "utils/macros.hpp"
#include "graph/cartesian_tree.hpp"

int main(){
    // input
    int n; scanf("%d", &n);
    std::vector<int> a(n);
    REP (i, n) {
        scanf("%d", &a[i]);
    }

    // solve
    std::vector<int> p = construct_cartesian_tree(a);

    // output
    REP (i, n) {
        printf("%d%c", p[i] == -1 ? i : p[i], i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
