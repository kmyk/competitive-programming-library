:%! sh -c "`cat`"
#!/bin/sh
cat <<EOF
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
#define dump(x) cerr << #x " = " << x << endl
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T, class U> inline void chmax(T & a, U const & b) { a = max<T>(a, b); }
template <class T, class U> inline void chmin(T & a, U const & b) { a = min<T>(a, b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }
template <typename T> ostream & operator << (ostream & out, vector<T> const & xs) { REP (i, (int)xs.size() - 1) out << xs[i] << ' '; if (not xs.empty()) out << xs.back(); return out; }
template<typename Functor> struct fix_type { Functor functor; template<typename... Args> decltype(auto) operator() (Args && ... args) const & { return functor(functor, std::forward<Args>(args)...); } };
template<typename Functor> fix_type<typename std::decay<Functor>::type> fix(Functor && functor) { return { std::forward<Functor>(functor) }; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    return 0;
}
EOF
