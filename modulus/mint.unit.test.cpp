#include "modulus/mint.hpp"

#include <cassert>
using namespace std;

int main() {
    constexpr int MOD = 1000000007;

    // ctor
    assert (mint<MOD>(-2).value == MOD - 2);
    assert (mint<MOD>(1000ll * MOD + 3).value == 3);

    // pow
    assert (mint<MOD>(2).pow(3) == 8);
    assert (mint<MOD>(2).pow(MOD - 1) == 1);
    assert (mint<MOD>(7).pow(MOD - 2) * 7 == 1);
    assert (mint<MOD>(42).pow(MOD - 1) == 1);

    // inv
    assert (mint<256>(1).inv() * 1 == 1);
    assert (mint<256>(3).inv() * 3 == 1);
    assert (mint<256>(5).inv() * 5 == 1);
    assert (mint<256>(7).inv() * 7 == 1);
    assert (mint<256>(13).inv() * 13 == 1);
    assert (mint<MOD>(1).inv() * 1 == 1);
    assert (mint<MOD>(2).inv() * 2 == 1);
    assert (mint<MOD>(3).inv() * 3 == 1);
    assert (mint<MOD>(4).inv() * 4 == 1);
    assert (mint<MOD>(42).inv() * 42 == 1);
    return 0;
}
