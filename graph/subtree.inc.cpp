/**
 * @arg g must be a tree
 * @note O(n) time
 * @note O(n) space on heap
 */
struct subtree_info_t {
    int parent;  // in the entire tree
    int depth;  // in the entire tree
    int size;  // of the subtree
    int height;  // of the subtree
};
vector<subtree_info_t> prepare_subtree_info(vector<vector<int> > const & g, int root) {
    int n = g.size();
    vector<subtree_info_t> info(n, (subtree_info_t) { -1, -1, -1, -1 });
    vector<int> topological(n);
    topological[0] = root;
    info[root].parent = root;
    info[root].depth = 0;
    int r = 1;
    for (int l = 0; l < r; ++ l) {
        int i = topological[l];
        for (int j : g[i]) if (j != info[i].parent) {
            topological[r ++] = j;
            info[j].parent = i;
            info[j].depth = info[i].depth + 1;
        }
    }
    while ((-- r) >= 0) {
        int i = topological[r];
        info[i].size = 1;
        info[i].height = 0;
        for (int j : g[i]) if (j != info[i].parent) {
            info[i].size += info[j].size;
            info[i].height = max(info[i].height, info[j].height + 1);
        }
    }
    info[root].parent = -1;
    return info;
}

unittest {
    vector<vector<int> > g(9);
    const int root = 0;
    g[0].push_back(1);
    g[0].push_back(2);
    ;   g[2].push_back(4);
    ;   g[2].push_back(5);
    ;   g[2].push_back(6);
    ;   ;   g[6].push_back(8);
    g[0].push_back(3);
    ;   g[3].push_back(7);
    auto info = prepare_subtree_info(g, root);
    assert (info[root].parent == -1);
    assert (info[root].depth == 0);
    assert (info[root].size == g.size());
    assert (info[root].height == 3);
    assert (info[1].parent == 0);
    assert (info[1].depth == 1);
    assert (info[1].size == 1);
    assert (info[1].height == 0);
    assert (info[6].parent == 2);
    assert (info[6].depth == 2);
    assert (info[6].size == 2);
    assert (info[6].height == 1);
}
