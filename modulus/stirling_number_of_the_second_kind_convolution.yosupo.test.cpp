#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "../modulus/stirling_number_of_the_second_kind_convolution.hpp"
#include "../hack/fastio.hpp"
#include "../utils/macros.hpp"

constexpr int MOD = 998244353;
int main() {
    int n = in<int>();
    auto f = stirling_number_of_the_second_kind_convolution<MOD>(n);
    REP (k, n + 1) {
        out<int>(f[k].value);
        out<char>(k < n ? ' ' : '\n');
    }
    return 0;
}
