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
    auto generate_digraph = [&](int n, int m) {
        vector<vector<pair<int, int64_t> > > g(n);
        REP (e, m) {
            int x = uniform_int_distribution<int>(0, n - 1)(gen);
            int y = uniform_int_distribution<int>(0, n - 1)(gen);
            int64_t cost = uniform_int_distribution<int64_t>(- 1000000, 10000000)(gen);
            g[x].emplace_back(y, cost);
        }
        return g;
    };

    // compare with Bellman Ford
    REP (iteration, 200) {
        int n = iteration + 1;
        int m = uniform_int_distribution<int>(0, 10 * n)(gen);
        auto g = generate_digraph(n, m);
        int root = uniform_int_distribution<int>(0, n - 1)(gen);
        assert (bellman_ford_shortest_path(root, g) == shortest_path_faster_algorithm(root, g));
    }

    // run against big graph
    int n = 10000;
    int m = 100000;
    auto g = generate_digraph(n, m);
    int root = uniform_int_distribution<int>(0, n - 1)(gen);
    volatile auto dist = shortest_path_faster_algorithm(root, g);
    return 0;
}
