#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "string/longest_common_prefix.hpp"
#include "hack/fastio.hpp"

int main() {
    std::string s = in<std::string>();
    int n = s.length();
    longest_common_prefix lcp(s);
    REP (i, n) {
        out<int>(lcp.get(0, i));
        out<char>(i < n - 1 ? ' ' : '\n');
    }
    return 0;
}
