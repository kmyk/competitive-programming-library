#include "graph/bellman_ford.hpp"
#include "graph/shortest_path_faster_algorithm.hpp"

#include <cassert>
#include <random>
#include <vector>
#include <iostream>
#include "utils/macros.hpp"
using namespace std;

int main() {
    default_random_engine gen;
    REP (iteration, 1000) {
        int n = iteration + 1;
        int m = uniform_int_distribution<int>(0, 10 * n)(gen);
        vector<vector<pair<int, int64_t> > > g(n);
        REP (e, m) {
            int x = uniform_int_distribution<int>(0, n - 1)(gen);
            int y = uniform_int_distribution<int>(0, n - 1)(gen);
            int64_t cost = uniform_int_distribution<int>(- 1000, 10000)(gen);
            g[x].emplace_back(y, cost);
        }
        int root = uniform_int_distribution<int>(0, n - 1)(gen);
        assert (bellman_ford_shortest_path(root, g) == shortest_path_faster_algorithm(root, g));
    }
    return 0;
}
