:%! sh -c "`cat`"
#!/bin/sh
cat <<EOF
/**
 * @file .cpp
 * @author `git config user.name`
 * @date `date +'%a. %d, %Y'`
 */
#include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = int(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = int(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)
#define dump(x) cerr << #x " = " << x << endl
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T> inline void chmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }
template <typename T> ostream & operator << (ostream & out, vector<T> const & xs) { REP (i, int(xs.size()) - 1) out << xs[i] << ' '; if (not xs.empty()) out << xs.back(); return out; }
void graphviz(vector<vector<int> > const & g, bool is_digraph = false, string const & name = "graph") { ofstream ofs(name + ".dot"); ofs << (is_digraph ? "di" : "") << "graph graph_name {" << endl; ofs << "    graph [ bgcolor = \"#00000000\" ]" << endl; ofs << "    node [ shape = circle, style = filled, fillcolor = \"#ffffffff\" ]" << endl; REP (i, g.size()) for (int j : g[i]) if (is_digraph or i <= j) ofs << "    " << i << (is_digraph ? " -> " : " -- ") << j << endl; ofs << "}" << endl; ofs.close(); system(("dot -T png " + name + ".dot > " + name + ".png").c_str()); } /* {{{ }}} */
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
bool is_on_field(int y, int x, int h, int w) { return 0 <= y and y < h and 0 <= x and x < w; }
int main() {
    int n; scanf("%d", &n);
    vector<ll> a(n); REP (i, n) scanf("%lld", &a[i]);
    vector<vector<int> > f = vectors(h, w, int());
    REP (y, h) REP (x, w) scanf("%d", &f[y][x]);
    printf("%lld\n", ans);
    return 0;
}
EOF
