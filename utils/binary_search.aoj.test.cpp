#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"
#include "../utils/binary_search.hpp"
#include "../utils/binary_search_max.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include "../utils/macros.hpp"
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> s(n);
    REP (i, n) {
        cin >> s[i];
    }

    int q; cin >> q;
    int64_t cnt = 0;
    while (q --) {
        int t_i; cin >> t_i;
        int l = binsearch(0, n, [&](int i) {
            return s[i] >= t_i;
        });
        cnt += (l < n and s[l] == t_i);

        int r = binsearch_max(0, n, [&](int i) {
            return s[i] <= t_i;
        });
        assert ((l < n and s[l] == t_i) == (l <= r));
    }

    cout << cnt << endl;
    return 0;
}
