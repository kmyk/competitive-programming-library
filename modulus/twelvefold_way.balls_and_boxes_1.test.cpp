#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"
#include <iostream>
#include "../modulus/twelvefold_way.hpp"
using namespace std;

constexpr int MOD = 1e9 + 7;
int main() {
    int n, k; cin >> n >> k;
    cout << twelvefold_lla<MOD>(n, k) << endl;
    return 0;
}
