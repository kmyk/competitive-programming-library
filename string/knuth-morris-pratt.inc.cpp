/**
 * @brief Morris-Pratt algorithm
 * @description compute the list of the lengthes of the longest borders
 * @note O(N)
 */
template <class Iterator>
vector<int> morris_pratt(Iterator first, Iterator last) {
    int length = distance(first, last);
    vector<int> border(length + 1);
    border[0] = -1;
    int j = -1;
    REP (i, length) {
        while (j >= 0 and pattern[i] != pattern[j]) {
            j = border[j];
        }
        ++ j;
        border[i + 1] = j;
    }
    return border;
}

/*
vector<int> kmp_build_fail(string const & pattern) { // O(m)
    int m = pattern.size();
    vector<int> fali(m+1);
    fail[0] = -1;
    int j = -1;
    repeat (i,m) {
        while (j >= 0 and pattern[i] != pattern[j]) j = fail[j];
        fail[i+1] = ++ j;
    }
    return fail;
}
int kmp_match(string const & target, string const & pattern, vector<int> const & fail) { // O(n+m)
    int n = target.length();
    int m = pattern.length();
    int result = 0;
    for (int i = 0, k = 0; i < n; ++ i) {
        while (k >= 0 and pattern[k] != target[i]) k = fail[k];
        if (++ k >= m) {
            ++ result; // match at t[i-m+1 .. i]
            k = fail[k];
        }
    }
    return result;
}
int kmp_match(string const & target, string const & pattern) {
    return kmp_match(target, pattern, kmp_build_fail(pattern));
}
*/
