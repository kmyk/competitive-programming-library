#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../graph/strongly_connected_components.hpp"

/**
 * @brief 2-SAT ($O(N)$)
 * @param n is the number of variables
 * @param cnf is a proposition in a conjunctive normal form. Each literal is expressed as number $x$ s.t. $1 \le \vert x \vert \le n$
 * @return a vector with the length $n$ if SAT. It's empty if UNSAT.
 */
std::vector<bool> compute_two_satisfiability(int n, const std::vector<std::pair<int, int> > & cnf) {
    // make digraph
    std::vector<std::vector<int> > g(2 * n);
    auto index = [&](int x) {
        assert (x != 0 and abs(x) <= n);
        return x > 0 ? x - 1 : n - x - 1;
    };
    for (auto it : cnf) {
        int x, y; std::tie(x, y) = it;  // x or y
        g[index(- x)].push_back(index(y));  // not x implies y
        g[index(- y)].push_back(index(x));  // not y implies x
    }

    // do SCC
    std::vector<int> component = decompose_to_strongly_connected_components(g).second;
    std::vector<bool> valuation(n);
    REP3 (x, 1, n + 1) {
        if (component[index(x)] == component[index(- x)]) {  // x iff not x
            return std::vector<bool>();  // unsat
        }
        valuation[x - 1] = component[index(x)] > component[index(- x)];  // use components which indices are large
    }
    return valuation;
}
