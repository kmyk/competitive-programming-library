#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
template <class T> using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;
template <class T, class U> inline void chmax(T & a, U const & b) { a = std::max<T>(a, b); }
template <class T, class U> inline void chmin(T & a, U const & b) { a = std::min<T>(a, b); }
template <typename X, typename T> auto make_vectors(X x, T a) { return std::vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_vectors(X x, Y y, Z z, Zs... zs) { auto cont = make_vectors(y, z, zs...); return std::vector<decltype(cont)>(x, cont); }
