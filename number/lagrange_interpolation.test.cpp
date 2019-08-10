#include "number/lagrange_interpolation.hpp"

#include <cassert>
#include <random>
#include <set>
#include <tuple>
#include <utility>
#include <iostream>
using namespace std;

long double apply(std::vector<long double> & f, long double x) {
    long double y = 0;
    REP_R (i, f.size()) {
        y = y * x + f[i];
    }
    return y;
}

int main() {
    default_random_engine gen;
    REP (iteration, 20) {
        // generate
        vector<pair<long double, long double> > points;
        set<int> used;
        REP (i, iteration) {
            int z_i = uniform_int_distribution<int>(- 100, 100)(gen);
            if (used.count(z_i)) continue;
            used.insert(z_i);
            long double x_i = z_i / 10.0L;
            long double y_i = uniform_int_distribution<int>(- 100, 100)(gen) / 10.0L;
            points.emplace_back(x_i, y_i);
        }

        // run
        auto f = lagrange_interpolate(points);

        // check
        constexpr long double eps = 1e-8;
        assert (f.size() == points.size());
        for (auto point : points) {
            long double x, y; tie(x, y) = point;
            assert (abs(apply(f, x) - y) < eps);
        }
    }
}
