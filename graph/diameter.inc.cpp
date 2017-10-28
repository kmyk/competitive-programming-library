// http://techtipshoge.blogspot.jp/2016/09/blog-post.html

// CAUTION: 未検証
pair<int, int> get_eccentricity(int k, vector<vector<int> > const & tree) {
    pair<int, int> result = { -1, -1 };
    function<void (int, int, int)> dfs = [&](int i, int parent, int depth) {
        setmax(result, make_pair(depth, i));
        for (int j : tree[i]) if (j != parent) {
            dfs(j, i, depth + 1);
        }
    };
    dfs(k, -1, 0);
    return result;
}
int get_diameter(vector<vector<int> > const & tree) {
    return get_eccentricity(get_eccentricity(0, tree).second, tree).first;
}

int get_centroid(vector<vector<int> > const & tree) {
    int n = tree.size();
    int centroid = -1;
    int centroid_weight = INT_MAX;
    function<int (int, int)> dfs = [&](int i, int parent) {
        int acc_weight = 0;
        int max_weight = -1;
        for (int j : tree[i]) if (j != parent) {
            int weight = dfs(j, i);
            acc_weight += weight;
            setmax(max_weight, weight);
        }
        setmax(max_weight, n - (1 + acc_weight));
        if (max_weight < centroid_weight) {
            centroid_weight = max_weight;
            centroid = i;
        }
        return 1 + acc_weight;
    };
    dfs(0, -1);
    return centroid;
}
