#define PROBLEM "https://yukicoder.me/problems/no/856"
#include <algorithm>
#include <iostream>
#include <vector>
#include "utils/macros.hpp"
#include "modulus/mint.hpp"
#include "number/fast_fourier_transformation.hpp"
using namespace std;

constexpr int64_t MOD = 1000000007;

mint<MOD> solve(int n, const vector<int> &a) {
    // \prod_i \prod_{j > i} (A_i + A_j)
    mint<MOD> x = 1;
    {
        int max_a = *max_element(ALL(a));
        vector<long double> cnt(max_a + 1);
        for (int a_i : a) {
            ++ cnt[a_i];
        }
        cnt = fft_convolution(cnt, cnt);
        for (int a_i : a) {
            -- cnt[2 * a_i];
        }
        REP (i, cnt.size()) {
            cnt[i] /= 2;
        }
        REP (i, cnt.size()) {
            int64_t k = round(cnt[i]);
            assert (abs(cnt[i] - k) <= 1e-6);
            x *= mint<MOD>(i).pow(k);
        }
    }

    // \prod_i \prod_{j > i} A_i^{A_j}
    mint<MOD> y = 1;
    {
        int64_t sum_a_j = 0;
        REP_R (i, n) {
            y *= mint<MOD>(a[i]).pow(sum_a_j);
            sum_a_j += a[i];
        }
    }

    // \min_i \mimn_{j > i} (A_i + A_j)A_i^{A_j}
    mint<MOD> z = 0;
    {
        double log_z = INFINITY;
        int64_t a_j = a[n - 1];
        REP_R (i, n - 1) {
            double log_a_i_a_j = log(a[i] + a_j) + a_j * log(a[i]);
            if (log_a_i_a_j < log_z) {
                log_z = log_a_i_a_j;
                z = mint<MOD>(a[i] + a_j) * mint<MOD>(a[i]).pow(a_j);
            }
            a_j = min<int64_t>(a[i], a_j);
        }
    }
    return x * y / z;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    auto ans = solve(n, a);
    cout << ans << endl;
    return 0;
}
