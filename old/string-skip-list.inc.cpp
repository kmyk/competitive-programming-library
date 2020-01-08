template <typename Iterator>
vector<array<int, 26> > get_next_index(Iterator first, Iterator last) {
    int n = distance(first, last);
    vector<array<int, 26> > x(n + 1);
    fill(whole(x[n]), n);
    repeat_reverse (i, n) {
        x[i] = x[i + 1];
        x[i][*(first + i) - 'a'] = i;
    }
    return x;  // x_{i, c} = \min \{ j \ge i \mid s_j = c \}
}
unittest {
    string s = "aabcab";
    auto x = get_next_index(s.begin(), s.end());
    assert (x[0][0] == 0);  // () [a]abcab
    assert (x[0][1] == 2);  // () aa[b]cab
    assert (x[0][2] == 3);  // () aab[c]ab
    assert (x[4][0] == 4);  // (aabc) [a]b
    assert (x[4][1] == 5);  // (aabc) a[b]
    assert (x[4][2] == 6);  // (aabc) ab[]
}
