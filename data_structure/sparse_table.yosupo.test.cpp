#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../data_structure/sparse_table.hpp"

#include "../utils/macros.hpp"
#include "../monoids/min.hpp"
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // input a sequence
    int n, q; scanf("%d%d", &n, &q);
    vector<int> a(n);
    REP (i, n) {
        scanf("%d", &a[i]);
    }

    // construct the sparse table
    sparse_table<min_monoid<int> > st(ALL(a));

    // answer to queries
    while (q --) {
        int l, r; scanf("%d%d", &l, &r);
        int answer = st.range_get(l, r);
        printf("%d\n", answer);
    }
    return 0;
}
