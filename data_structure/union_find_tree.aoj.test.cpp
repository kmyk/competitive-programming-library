#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "../data_structure/union_find_tree.hpp"
#include <cstdio>

int main() {
    int n, q; scanf("%d%d", &n, &q);
    union_find_tree uft(n);
    while (q --) {
        int com, x, y; scanf("%d%d%d", &com, &x, &y);
        if (com == 0) {
            uft.unite_trees(x, y);
        } else if (com == 1) {
            bool answer = uft.is_same(x, y);
            printf("%d\n", (int)answer);
        }
    }
    return 0;
}
