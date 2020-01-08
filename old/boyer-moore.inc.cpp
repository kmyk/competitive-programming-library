array<int,26> bm_build_skip(string const & pattern) { // O(m)
    int m = pattern.length();
    array<int,26> skip = {};
    repeat (i,m) skip[pattern[i]-'a'] = m-i-1;
    return skip;
}
vector<int> bm_build_next(string const & pattern) { // O(m)
    int m = pattern.length();
    int g[m]; fill(g, g+m, m);
    vector<int> next(m);
    repeat (i,m) next[i] = 2*m-i-1;
    int j = m;
    for (int i = m-1; i >= 0; --i, --j) {
        g[i] = j;
        while (j < m and pattern[j] != pattern[i]) {
            next[j] = min(next[j], m-i-1);
            j = g[j];
        }
    }
    repeat (i,m) {
        next[i] = min(next[i], j+m-i);
        if (i >= j) j = g[j];
    }
    return next;
}
int bm_match(string const & target, string const & pattern, array<int,26> const & skip, vector<int> const & next) { // O(nm)
    int n = target.length();
    int m = pattern.length();
    int result = 0;
    for (int i = m-1; i < n; ) {
        int j = m-1;
        while (j >= 0 and target[i] == pattern[j]) { --i; --j; }
        if (j < 0) {
            ++ result; // match at text[i+1, ..., i+m]
            i += m + 1;
        } else {
            i += max(skip[target[i]-'a'], next[j]);
        }
    }
    return result;
}
int bm_match(string const & target, string const & pattern) { // Boyer-Moore
    return bm_match(target, pattern, bm_build_skip(pattern), bm_build_next(pattern));
}
