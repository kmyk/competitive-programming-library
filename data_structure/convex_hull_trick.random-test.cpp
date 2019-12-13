#include "data_structure/convex_hull_trick.hpp"

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
    REP (iteration, 1000) {
        vector<pair<int, int> > lines;
        convex_hull_trick cht;
        REP (i, 100) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
            cht.add_line(a, b);
        }
        REP (i, 10) {
            int x = uniform_int_distribution<int>(- 100, 100)(gen);
            int y = INT_MAX;
            for (auto line : lines) {
                int a, b; tie(a, b) = line;
                y = min(y, a * x + b);
            }
            assert (cht.get_min(x) == y);
        }
    }
    return 0;
}
