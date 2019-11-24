#include "data_structure/li_chao_tree.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;


int main() {
    random_device device;
    default_random_engine gen(device());
    REP (subtest, 1000) {
        int n = uniform_int_distribution<int>(1, 200)(gen);
        vector<int> x(n);
        REP (i, n) {
            x[i] = uniform_int_distribution<int>(- 1000, 1000)(gen);
        }
        sort(ALL(x));
        vector<int> y(n, INT_MAX);
        li_chao_tree<int> lichao(x);
        REP (add_query, 100) {
            int l = uniform_int_distribution<int>(- 1000, 1000)(gen);
            int r = uniform_int_distribution<int>(- 1000, 1000)(gen);
            if (l > r) swap(l, r);
            int a = uniform_int_distribution<int>(- 300, 300)(gen);
            int b = uniform_int_distribution<int>(- 300, 300)(gen);
            REP (i, n) {
                if (l <= x[i] and x[i] < r) {
                    y[i] = min(y[i], a * x[i] + b);
                }
            }
            int il = lower_bound(ALL(x), l) - x.begin();
            int ir = lower_bound(ALL(x), r) - x.begin();
            lichao.add_segment(il, ir, a, b);
            REP (min_query, 10) {
                int i = uniform_int_distribution<int>(0, n - 1)(gen);
                assert (lichao.get_min(i) == y[i]);
            }
        }
    }
    return 0;
}
