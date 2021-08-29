#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../modulus/modlog.hpp"
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int x, y, m; scanf("%d%d%d", &x, &y, &m);
        int k = modlog(x, y, m);
        printf("%d\n", k);
    }
    return 0;
}
