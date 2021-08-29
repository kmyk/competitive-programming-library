#define PROBLEM "https://yukicoder.me/problems/no/1073"
#include "../number/matrix.hpp"
#include "../modulus/mint.hpp"
#include <iostream>
using namespace std;


constexpr int MOD = 1000000007;
mint<MOD> solve(int64_t n) {
    vector<vector<mint<MOD> > > f = {
        vector<mint<MOD> >{ 0, 0, 0, 0, 0, mint<MOD>(6).inv() },
        vector<mint<MOD> >{ 1, 0, 0, 0, 0, mint<MOD>(6).inv() },
        vector<mint<MOD> >{ 0, 1, 0, 0, 0, mint<MOD>(6).inv() },
        vector<mint<MOD> >{ 0, 0, 1, 0, 0, mint<MOD>(6).inv() },
        vector<mint<MOD> >{ 0, 0, 0, 1, 0, mint<MOD>(6).inv() },
        vector<mint<MOD> >{ 0, 0, 0, 0, 1, mint<MOD>(6).inv() },
    };
    vector<mint<MOD> > x = {
        0,
        0,
        0,
        0,
        0,
        1,
    };
    return (matpow(f, n) * x)[5];
}

int main() {
    int64_t n; cin >> n;
    auto ans = solve(n);
    cout << ans << endl;
    return 0;
}
