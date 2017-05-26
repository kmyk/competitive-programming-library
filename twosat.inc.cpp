
vector<bool> twosat(int n, vector<pair<int, int> > const & cnf) {
    // make digraph
    vector<vector<int> > g(2*n);
    auto i = [&](int x) { assert (x != 0 and abs(x) <= n); return x > 0 ? x-1 : n-x-1; };
    for (auto it : cnf) {
        int x, y; tie(x, y) = it; // x or y
        g[i(- x)].push_back(i(y)); // not x implies y
        g[i(- y)].push_back(i(x)); // not y implies x
    }
    // do SCC
    vector<int> component = strongly_connected_components::decompose(g).second;
    vector<bool> valuation(n);
    repeat_from (x,1,n+1) {
        if (component[i(x)] == component[i(- x)]) { // x iff not x
            return vector<bool>(); // unsat
        }
        valuation[x-1] = component[i(x)] > component[i(- x)]; // use components which indices are large
    }
    return valuation;
}
