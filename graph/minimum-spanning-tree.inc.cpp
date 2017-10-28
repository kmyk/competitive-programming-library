template <typename T> struct weighted_edge { int u, v; T w; };
template <typename T> bool operator < (weighted_edge<T> const & a, weighted_edge<T> const & b) { return make_tuple(a.w, a.u, a.v) < make_tuple(b.w, b.u, b.v); }
template <typename T>
vector<vector<weighted_edge<T> > > minimum_spanning_tree(int n, vector<weighted_edge<T> > edges) { // Kruskal's method, O(E \log E)
    vector<vector<weighted_edge<T> > > tree(n);
    disjoint_sets sets(n);
    whole(sort, edges);
    for (auto e : edges) {
        if (not sets.is_same(e.u, e.v)) {
            sets.union_sets(e.u, e.v);
            tree[e.u].push_back( (weighted_edge<T>) { e.u, e.v, e.w } );
            tree[e.v].push_back( (weighted_edge<T>) { e.v, e.u, e.w } );
        }
    }
    return tree;
}
