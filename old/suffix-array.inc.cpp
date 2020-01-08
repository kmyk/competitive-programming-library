/**
 * @brief suffix array
 * @note O(N (\log N)^2), Manber & Myers, 蟻本
 * @note sa[i] is the index of i-th smallest substring of s, s[sa[i], N)
 * @note rank[i] is the rank of substring s[i, N)
 */
void suffix_array(string const & s, vector<int> & sa, vector<int> & rank) {
    int n = s.length();
    sa.resize(n + 1);
    rank.resize(n + 1);
    REP (i, n + 1) {
        sa[i] = i;
        rank[i] = i < n ? s[i] : -1;
    }
    auto rankf = [&](int i) { return i <= n ? rank[i] : -1; };
    vector<int> nxt(n + 1);
    for (int k = 1; k <= n; k <<= 1) {
        auto cmp = [&](int i, int j) { return make_pair(rank[i], rankf(i + k)) < make_pair(rank[j], rankf(j + k)); };
        sort(sa.begin(), sa.end(), cmp);
        nxt[sa[0]] = 0;
        REP3 (i, 1, n + 1) {
            nxt[sa[i]] = nxt[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        rank.swap(nxt);
    }
}

/**
 * @description lcp[i] is the length of the common prefix between i-th and (i+1)-th substring of s
 * @note O(N), 蟻本
 * @note lcp.size() == n, != n + 1
 */
vector<int> longest_common_prefix_array(string const & s, vector<int> const & sa, vector<int> const & rank) {
    int n = s.length();
    vector<int> lcp(n);
    int h = 0;
    lcp[0] = 0;
    REP (i, n) {
        int j = sa[rank[i] - 1];
        if (h > 0) -- h;
        while (j + h < n and i + h < n and s[j + h] == s[i + h]) ++ h;
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}

unittest {
    constexpr int n = 100;
    default_random_engine gen;
    string s;
    REP (i, n) s += uniform_int_distribution<char>('a', 'z')(gen);
    vector<int> sa, rank; suffix_array(s, sa, rank);
    vector<int> lcp = longest_common_prefix_array(s, sa, rank);
    REP (i, n + 1) {
        assert (sa[rank[i]] == i);
    }
    auto compute_lcp = [](string s, string t) {
        int i = 0;
        while (i < s.length() and i < t.length() and s[i] == t[i]) ++ i;
        return i;
    };
    REP (i, n) {
        assert (lcp[i] == compute_lcp(s.substr(sa[i]), s.substr(sa[i + 1])));
    }
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
