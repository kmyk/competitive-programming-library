/**
 * @brief euler tour
 * @arg g must be a tree, directed or undirected
 * @note for constraints, see the unittest
 */
void do_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
        tour.push_back(x);
    };
    go(root, -1);
}
unittest {
    default_random_engine gen;
    int n = 100;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> tour, left, right; do_euler_tour(g, 0, tour, left, right);
    assert (tour.size() == 2 * n);
    REP (i, n) {
        assert (tour[ left[i]] == i);
        assert (tour[right[i]] == i);
    }
}

/**
 * @brief euler tour, push vertices only visiting
 * @arg g must be a tree, directed or undirected
 */
void do_left_euler_tour(vector<vector<int> > const & g, int root, vector<int> & tour, vector<int> & left, vector<int> & right) {
    int n = g.size();
    tour.clear();
    left.resize(n);
    right.resize(n);
    function<void (int, int)> go = [&](int x, int parent) {
        left[x] = tour.size();
        tour.push_back(x);
        for (int y : g[x]) if (y != parent) {
            go(y, x);
        }
        right[x] = tour.size();
    };
    go(root, -1);
}
unittest {
    default_random_engine gen;
    int n = 100;
    vector<vector<int> > g(n);
    REP (i, n - 1) {
        int j = uniform_int_distribution<int>(i + 1, n - 1)(gen);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> tour, left, right; do_left_euler_tour(g, 0, tour, left, right);
    assert (tour.size() == n);
    REP (i, n) {
        assert (tour[left[i]] == i);
    }
}
