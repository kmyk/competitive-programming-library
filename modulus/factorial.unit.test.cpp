#include "utils/common.hpp"
#include "modulus/factorial.hpp"
using namespace std;

int main() {
    constexpr int32_t MOD = 1e9 + 7;
    assert (fact<MOD>(0) == 1);
    assert (fact<MOD>(1) == 1);
    assert (fact<MOD>(2) == 2);
    assert (fact<MOD>(3) == 6);
    assert (fact<MOD>(4) == 24);
    assert (fact<MOD>(5) == 120);
    assert (fact<MOD>(6) == 720);
    assert (fact<MOD>(7) == 5040);
    assert (fact<MOD>(8) == 40320);
    assert (fact<MOD>(9) == 362880);
    assert (fact<MOD>(10) == 3628800);
    assert (fact<MOD>(11) == 39916800);
    assert (fact<MOD>(12) == 479001600);
    assert (fact<MOD>(13) == 227020758);
    assert (fact<MOD>(14) == 178290591);
    assert (fact<MOD>(15) == 674358851);
    return 0;
}
