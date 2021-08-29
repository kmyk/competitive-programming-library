#define PROBLEM "https://atcoder.jp/contests/arc117/tasks/arc117_c"
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
#include "../utils/macros.hpp"
#include "../modulus/mint.hpp"
#include "../modulus/mint_with_zero.hpp"
using namespace std;

int solve(int n, const std::vector<int>& a) {
    std::vector<zmint<3> > fact(n + 1);
    fact[0] = 1;
    REP (i, n) {
        fact[i + 1] = (i + 1) * fact[i];
    }
    auto choose = [&](int n, int r) {
        return (fact[n] * fact[n - r].inv() * fact[r].inv()).to_mint();
    };

    mint<3> b = 0;
    REP (i, n) {
        b += choose(n - 1, i) * a[i];
    }
    if (n % 2 == 0) {
        b *= -1;
    }
    return b.value;
}

int main() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    assert (s.length() == n);
    std::vector<int> a(n);
    REP (i, n) {
        a[i] = (s[i] == 'W' ? 0 : s[i] == 'R' ? 1 : s[i] == 'B' ? 2 : -1);
        assert (a[i] != -1);
    }
    int ans = solve(n, a);
    assert (0 <= ans and ans < 3);
    std::array<char, 3> table = {{ 'W', 'R', 'B' }};
    std::cout << table[ans] << std::endl;
    return 0;
}

