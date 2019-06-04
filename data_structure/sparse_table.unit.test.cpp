#include "data_structure/sparse_table.hpp"

#include <algorithm>
#include <cassert>
#include <climits>
#include <random>
using namespace std;

int main() {
    random_device device;
    default_random_engine gen(device());

    int n = uniform_int_distribution<int>(1, 500)(gen);
    vector<int> data(n);
    REP (i, n) data[i] = uniform_int_distribution<int>(- 1000000, 1000000)(gen);
    sparse_table<max_semilattice> table(data);
    auto range_concat = [&](int l, int r) {
        int acc = INT_MIN;
        REP3 (i, l, r) {
            acc = max(acc, data[i]);
        }
        return acc;
    };

    REP (iteration, 500) {
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        assert (table.range_concat(l, r) == range_concat(l, r));
    }
    return 0;
}
