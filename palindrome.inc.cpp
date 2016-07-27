// http://snuke.hatenablog.com/entry/2014/12/02/235837
vector<int> manacher(string const & s) { // radiuses of odd palindromes, O(N)
    int n = s.length();
    vector<int> r(n);
    int i = 0, j = 0;
    while (i < n) {
        while (i-j >= 0 and i+j < n and s[i-j] == s[i+j]) ++ j;
        r[i] = j;
        int k = 1;
        while (i-k >= 0 and i+k < n and k+r[i-k] < j) {
            r[i+k] = r[i-k];
            ++ k;
        }
        i += k;
        j -= k;
    }
    return r;
}
vector<int> odd_palindrome_length(string const & s) {
    int n = s.length();
    vector<int> r = manacher(s);
    vector<int> l(n);
    repeat (i,n) l[i-r[i]+1] = 2*r[i]-1;
    repeat (i,n-1) setmax(l[i+1], l[i]-2);
    return l;
}
vector<int> even_palindrome_length(string const & s) {
    int n = s.length();
    string t(2*n+1, '\0');
    repeat (i,n) t[2*i+1] = s[i];
    vector<int> r = manacher(t);
    vector<int> l(n);
    repeat (i,n) if (r[2*i+2] >= 3) l[i-r[2*i+2]/2+1] = r[2*i+2]-1;
    repeat (i,n-1) setmax(l[i+1], l[i]-2);
    return l;
}
