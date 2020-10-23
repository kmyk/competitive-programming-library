#pragma once
#include <algorithm>
#include <cmath>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

// struct mo_struct {
//     typedef int64_t value_type;
//     typedef int64_t result_type;
//     void add_right(int nr, value_type x_r) {
//     }
//     void add_left(int nl, value_type x_nl) {
//     }
//     void remove_right(int nr, value_type x_nr) {
//     }
//     void remove_left(int nl, value_type x_l) {
//     }
//     result_type query() {
//         return 0;
//     }
// };

template <class Mo>
std::vector<typename Mo::result_type> run_mo_algorithm(Mo mo, const std::vector<typename Mo::value_type>& values, const std::vector<std::pair<int, int> >& queries) {
    int n = values.size();
    int m = queries.size();

    // sort queries
    int sq_n = std::sqrt(n);
    std::vector<int> order(m);
    std::iota(ALL(order), 0);
    std::sort(ALL(order), [&](int i, int j) {
        int l_i, r_i; std::tie(l_i, r_i) = queries[i];
        int l_j, r_j; std::tie(l_j, r_j) = queries[j];
        return std::make_pair(l_i / sq_n, r_i) < std::make_pair(l_j / sq_n, r_j);
    });

    // compute queries
    std::vector<typename Mo::result_type> ans(m);
    int l = 0;
    int r = 0;
    for (int j : order) {
        int nl, nr; std::tie(nl, nr) = queries[j];
        for (; r < nr; ++ r) mo.add_right(r + 1, values[r]);
        for (; nl < l; -- l) mo.add_left(l - 1, values[l - 1]);
        for (; nr < r; -- r) mo.remove_right(r - 1, values[r - 1]);
        for (; l < nl; ++ l) mo.remove_left(l + 1, values[l]);
        ans[j] = mo.query();
    }
    return ans;
}
