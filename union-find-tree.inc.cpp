// http://abc040.contest.atcoder.jp/submissions/774959
// http://codeforces.com/contest/687/submission/18818699
struct disjoint_sets {
    vector<int> data;
    explicit disjoint_sets(size_t n) : data(n, -1) {}
    bool is_root(int a) { return data[a] < 0; }
    int find_root(int a) { return is_root(a) ? a : (data[a] = find_root(data[a])); }
    int set_size(int a) { return - data[find_root(a)]; }
    void union_sets(int a, int b) {
        a = find_root(a); b = find_root(b);
        if (a != b) {
            if (set_size(a) > set_size(b)) swap(a,b);
            data[b] += data[a];
            data[a] = b;
        }
    }
    bool is_same(int a, int b) { return find_root(a) == find_root(b); }
};
