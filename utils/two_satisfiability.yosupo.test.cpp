#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <cassert>
#include <vector>
#include <utility>
#include "../utils/macros.hpp"
#include "../hack/fastio.hpp"
#include "../utils/two_satisfiability.hpp"
using namespace std;

int main() {
    // read the header of DIMACS format
    char const_p = in<char>();
    assert (const_p == 'p');
    string const_cnf = in<string>();
    assert (const_cnf == "cnf");

    // input
    int n = in<int>();
    int m = in<int>();
    vector<pair<int, int> > cnf;
    REP (i, m) {
        int a = in<int>();
        int b = in<int>();
        cnf.emplace_back(a, b);

        int const_zero = in<int>();
        assert (const_zero == 0);
    }

    // solve
    vector<bool> model = compute_two_satisfiability(n, cnf);

    // output
    if (model.empty()) {
        out<string>("s UNSATISFIABLE\n");
    } else {
        out<string>("s SATISFIABLE\n");
        out<char>('v');
        REP (i, n) {
            out<char>(' ');
            out<int>((model[i] ? 1 : -1) * (i + 1));
        }
        out<string>(" 0 \n");
    }
    return 0;
}
