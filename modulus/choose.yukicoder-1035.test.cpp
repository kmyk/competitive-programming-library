#define PROBLEM "https://yukicoder.me/problems/no/1035"
#include <iostream>
#include "utils/macros.hpp"
#include "modulus/mint.hpp"
#include "modulus/choose.hpp"
using namespace std;

constexpr int64_t MOD = 1000000007;
mint<MOD> solve(int n, int m) {
    mint<MOD> ans = 0;
    REP (i, m + 1) {
        int sign = (i % 2 == 0 ? 1 : -1);
        ans += sign * choose<MOD>(m, m - i) * mint<MOD>(m - i).pow(n);
    }
    return ans;
}

int main() {
    int N, M; cin >> N >> M;
    cout << solve(N, M) << endl;
    return 0;
}
