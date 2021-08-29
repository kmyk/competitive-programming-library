#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../data_structure/union_find_tree.hpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    union_find_tree uft(n);
    while (q --) {
        int t, u, v; scanf("%d%d%d", &t, &u, &v);
        if (t == 0) {
            uft.unite_trees(u, v);
        } else if (t == 1) {
            bool answer = uft.is_same(u, v);
            printf("%d\n", (int)answer);
        }
    }
    return 0;
}
