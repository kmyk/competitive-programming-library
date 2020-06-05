#define PROBLEM "https://yukicoder.me/problems/no/1073"
#include "number/matrix_template.hpp"
#include "modulus/mint.hpp"
#include <iostream>
using namespace std;


constexpr int MOD = 1000000007;
mint<MOD> solve(int64_t n) {
    matrix<mint<MOD>, 6, 6> f = {{
        {{ 0, 0, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 1, 0, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 1, 0, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 0, 1, 0, mint<MOD>(6).inv() }},
        {{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() }},
    }};
    array<mint<MOD>, 6> x = {{
        0,
        0,
        0,
        0,
        0,
        1,
    }};
    return (powmat(f, n) * x)[5];
}

int main() {
    int64_t n; cin >> n;
    auto ans = solve(n);
    cout << ans << endl;
    return 0;
}
