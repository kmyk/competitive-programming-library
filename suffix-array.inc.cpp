// https://kimiyuki.net/blog/2016/04/23/s8pc-2-e/
// https://kimiyuki.net/blog/2016/04/09/arc-050-d/
// https://kimiyuki.net/blog/2016/01/31/hackerrank-worldcodesprint-print-string/
// https://kimiyuki.net/blog/2016/01/30/discovery-2016-qual-c/
// https://kimiyuki.net/blog/2016/01/30/aoj-2644/
vector<int> suffix_array(string const & s) { // O(N (\log N)^2), sa[i] is the index of i-th smallest substring of s
    int n = s.length();
    vector<int> sa(n+1);
    vector<int> rank(n+1);
    repeat (i,n+1) {
        sa[i] = i;
        rank[i] = i < n ? s[i] : -1;
    }
    auto rankf = [&](int i) { return i <= n ? rank[i] : -1; };
    vector<int> nxt(n+1);
    for (int k = 1; k <= n; k <<= 1) {
        auto cmp = [&](int i, int j) { return make_pair(rank[i], rankf(i + k)) < make_pair(rank[j], rankf(j + k)); };
        sort(sa.begin(), sa.end(), cmp);
        nxt[sa[0]] = 0;
        repeat_from (i,1,n+1) {
            nxt[sa[i]] = nxt[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        rank.swap(nxt);
    }
    return sa;
}
vector<int> longest_common_prefix_array(string const & s, vector<int> const & sa) {
    int n = s.length();
    vector<int> rank(n+1);
    repeat (i,n+1) rank[sa[i]] = i;
    vector<int> lcp(n);
    int h = 0;
    lcp[0] = 0;
    repeat (i,n) {
        int j = sa[rank[i] - 1];
        if (h > 0) -- h;
        while (j + h < n and i + h < n and s[j + h] == s[i + h]) ++ h;
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}

int sa_lower_bound(string const & s, vector<int> const & sa, string const & t) { // returns an index on suffix array
    int n = s.size();
    int l = 0, r = n+1; // (l, r]
    while (l + 1 < r) {
        int m = (l + r) / 2;
        (s.compare(sa[m], string::npos, t) < 0 ? l : r) = m;
    }
    return r;
}
int sa_prefix_upper_bound(string const & s, vector<int> const & sa, string const & t) { // returns an index on suffix array
    int n = s.size();
    int l = 0, r = n+1; // (l, r]
    while (l + 1 < r) {
        int m = (l + r) / 2;
        (s.compare(sa[m], t.size(), t) <= 0 ? l : r) = m;
    }
    return r;
}
int sa_match(string const & target, string const & pattern, vector<int> const & sa, segment_tree<int> const & lcp) { // O(m \log n)
    int l = sa_lower_bound(target, sa, pattern);
    int r = sa_prefix_upper_bound(target, sa, pattern);
    return r - l;
}
