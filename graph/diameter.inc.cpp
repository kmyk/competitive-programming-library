/**
 * @brief get the diameter of a tree / 木の直径
 */

/**
 * @sa http://techtipshoge.blogspot.jp/2016/09/blog-post.html
 */
pair<int, int> get_eccentricity(int k, vector<vector<int> > const & tree) {
    pair<int, int> result = { -1, -1 };  // (depth, vertex)
    function<void (int, int, int)> dfs = [&](int i, int parent, int depth) {
        chmax(result, make_pair(depth, i));
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
