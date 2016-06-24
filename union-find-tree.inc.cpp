// http://abc040.contest.atcoder.jp/submissions/774959
struct union_find {
    vector<int> tree;
    explicit union_find(size_t n) : tree(n, -1) {}
    bool is_root(int a) { return tree[a] < 0; }
    int find_root(int a) { return is_root(a) ? a : (tree[a] = find_root(tree[a])); }
    int tree_size(int a) { return - tree[find_root(a)]; }
    void union_tree(int a, int b) {
        a = find_root(a); b = find_root(b);
        if (a != b) {
            if (not (tree_size(a) <= tree_size(b))) swap(a,b);
            tree[b] += tree[a];
            tree[a] = b;
        }
    }
    bool is_connected(int a, int b) { return find_root(a) == find_root(b); }
};
