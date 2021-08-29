#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../hack/fastio_scanner.hpp"
#include "../hack/fastio_printer.hpp"

scanner sc;
printer pr;

int main() {
    int t = sc.get<int>();
    while (t --) {
        uint64_t a = sc.get<uint64_t>();
        uint64_t b = sc.get<uint64_t>();
        pr.put<uint64_t>(a + b);
        pr.put<char>('\n');
    }
    return 0;
}
