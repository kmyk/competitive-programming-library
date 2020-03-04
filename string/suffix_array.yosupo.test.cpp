#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <cassert>
#include <string>
#include <vector>
#include "string/suffix_array.hpp"
#include "hack/fastio.hpp"
using namespace std;

int main() {
    string s = in<string>();
    int n = s.length();
    vector<int> sa, rank;
    compute_suffix_array(s, sa, rank);
    assert ((int)sa.size() == n + 1);
    assert (sa[0] == n);
    REP (i, n) {
        out<int>(sa[i + 1]);
        out<char>(i < n - 1 ? ' ' : '\n');
    }
    return 0;
}
