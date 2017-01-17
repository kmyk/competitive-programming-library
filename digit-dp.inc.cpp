// http://yukicoder.me/problems/no/260
// strmodin(s, a, b, m)[i][j] = the number of digits t in mod m  for  t \le s, i = t \bmod \prod a and t contains digits j \subset b
vector<vector<ll> > strmodin(string const & s, int a, vector<int> const & b, ll m) {
    int pow_b = 1 << b.size();
    array<int,10> table = {};
    repeat (d,10) {
        auto it = whole(find, b, d);
        if (it != b.end()) table[d] |= 1 << (it - b.begin());
    }
    auto cur = vectors(a, pow_b, ll());
    auto prv = vectors(a, pow_b, ll());
    int bound_i = 0, bound_j = 0;
    for (char c : s) {
        c -= '0';
        cur.swap(prv);
        repeat (d, c) cur[(bound_i * 10 + d) % a][bound_j | table[d]] += 1;
        bound_i = (bound_i * 10 + c) % a;
        bound_j |= table[c];
        repeat (i,a) repeat (j,pow_b) {
            repeat (d,10) {
                ll & it = cur[(i * 10 + d) % a][j | table[d]];
                it = (it + prv[i][j]) % m;
            }
            prv[i][j] = 0;
        }
    }
    cur[bound_i][bound_j] += 1;
    cur[bound_i][bound_j] %= m;
    return cur;
}
