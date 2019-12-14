/**
 * @brief get a central path of a catapillar graph
 * @arg g is a tree
 * @return a central path; i.e. a longest path
 * @note $O(n)$
 * @note an empty vector if g is not a catapillar
 * @see https://en.wikipedia.org/wiki/Caterpillar_tree
 * @note example problem: https://atcoder.jp/contests/arc095/tasks/arc095_d
 */
vector<int> get_catapillar_central_path(const vector<vector<int> > & g) {
    int n = g.size();

    // construct the tree with non-leaf vertices
    int m = 0;
    vector<vector<int> > h(n);
    REP (i, n) if (g[i].size() != 1) {
        ++ m;
        for (int j : g[i]) if (g[j].size() != 1) {
            h[i].push_back(j);
        }
    }

    // the tree must be a path graph
    REP (i, n) {
        if (h[i].size() >= 3) {
            return vector<int>();
        }
    }

    // reconstruct the path
    if (m == 0) {
        if (n == 1) {
            return vector<int>({ 0 });
        } else if (n == 2) {
            return vector<int>({ 0, 1 });
        } else {
            assert (false);
        }

    } else {
        assert (n >= 3);
        vector<int> path;
        int i = 0;
        while (g[i].size() == 1 or h[i].size() == 2) {
            ++ i;
        }
        for (int j : g[i]) if (g[i].size() == 1) {
            path.push_back(j);
            break;
        }
        int parent = path.back();
        while (true) {
            path.push_back(i);
            bool found = false;
            for (int j : h[i]) if (j != parent) {
                parent = i;
                i = j;
                found = true;
                break;
            }
            if (not found) {
                break;
            }
        }
        for (int j : g[i]) if (g[i].size() == 1 and j != parent) {
            path.push_back(j);
            break;
        }
        return path;
    }
}
