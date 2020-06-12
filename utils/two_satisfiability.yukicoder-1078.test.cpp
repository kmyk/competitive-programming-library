#define PROBLEM "https://yukicoder.me/problems/no/1078"
#include <cassert>
#include <iostream>
#include "utils/macros.hpp"
#include "utils/two_satisfiability.hpp"
using namespace std;

vector<vector<bool> > solve(int n, vector<int> & s, vector<int> & t, vector<int> & u) {
    auto var = [&](int y, int x) { return y * n + x; };
    vector<pair<int, int> > cnf;
    REP (y, n) {
        REP (x, n) {
            int a = var(s[y], x) + 1;
            int b = var(x, t[y]) + 1;
            if (u[y] == 0) {
                cnf.emplace_back(a, b);
            } else if (u[y] == 1) {
                cnf.emplace_back(- a, b);
            } else if (u[y] == 2) {
                cnf.emplace_back(a, - b);
            } else if (u[y] == 3) {
                cnf.emplace_back(- a, - b);
            } else {
                assert (false);
            }
        }
    }
    auto ev = compute_two_satisfiability(n * n, cnf);
    if (ev.empty()) {
        return vector<vector<bool> >();
    } else {
        vector<vector<bool> > a(n, vector<bool>(n));
        REP (y, n) {
            REP (x, n) {
                a[y][x] = ev[var(y, x)];
            }
        }
        return a;
    }
}

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> s(n);
    REP (i, n) {
        scanf("%d", &s[i]);
        -- s[i];
    }
    vector<int> t(n);
    REP (i, n) {
        scanf("%d", &t[i]);
        -- t[i];
    }
    vector<int> u(n);
    REP (i, n) {
        scanf("%d", &u[i]);
    }

    // solve
    auto a = solve(n, s, t, u);

    // output
    if (a.empty()) {
        printf("%d\n", -1);
    } else {
        REP (y, n) {
            REP (x, n) {
                printf("%d%c", (int)a[y][x], x + 1 < n ? ' ' : '\n');
            }
        }
    }
    return 0;
}
