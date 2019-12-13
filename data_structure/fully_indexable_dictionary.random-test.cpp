#include "data_structure/fully_indexable_dictionary.hpp"

#include <cassert>
#include <random>
#include <vector>
#include "utils/macros.hpp"
using namespace std;

template <class RandomEngine>
void unittest(int n, RandomEngine & gen) {
    vector<bool> data(n);
    REP (i, n) {
        data[i] = bernoulli_distribution(0.5)(gen);
    }
    auto rank = [&](bool value, int l, int r) {
        return count(data.begin() + l, data.begin() + r, value);
    };
    auto select = [&](bool value, int k, int l) {
        int i = l;
        while (i < data.size() and data[i] != value) ++ i;
        while (i < data.size() and k --) {
            ++ i;
            while (i < data.size() and data[i] != value) ++ i;
        }
        return i;
    };
    fully_indexable_dictionary fid(data);
    for (int iteration = 1000; iteration --; ) {
        bool value = bernoulli_distribution(0.5)(gen);
        int l = uniform_int_distribution<int>(0, n - 1)(gen);
        int r = uniform_int_distribution<int>(l + 1, n)(gen);
        int k = uniform_int_distribution<int>(0, (r - l) * 2 / 3)(gen);
        assert (fid.rank(value, l, r) == rank(value, l, r));
        assert (fid.select(value, k, l) == select(value, k, l));
        assert (fid.access(l) == data[l]);
    }
}

int main() {
    random_device device;
    default_random_engine gen(device());
    unittest(1, gen);
    unittest(126, gen);
    unittest(127, gen);
    unittest(128, gen);
    unittest(129, gen);
    unittest(10000, gen);
    return 0;
}
