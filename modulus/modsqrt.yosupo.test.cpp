#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "../modulus/modsqrt.hpp"
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int y, p; scanf("%d%d", &y, &p);
        int x = modsqrt(y, p);
        printf("%d\n", x);
    }
    return 0;
}
