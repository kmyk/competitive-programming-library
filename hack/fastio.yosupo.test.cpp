#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../hack/fastio.hpp"

int main() {
    int t = in<int>();
    while (t --) {
        uint64_t a = in<uint64_t>();
        uint64_t b = in<uint64_t>();
        out<uint64_t>(a + b);
        out<char>('\n');
    }
    return 0;
}
