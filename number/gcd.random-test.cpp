#include "number/gcd.hpp"

#include <cassert>

int main() {
    assert (gcd(0, 0) == 0);
    assert (gcd(42, 0) == 42);
    assert (gcd(0, 42) == 42);
    assert (gcd(3, -12) == 3);
    assert (gcd(-3, 12) == -3);
    assert (gcd(7, -12) == -1);
    assert (gcd(-7, 12) == 1);
    assert (gcd(-9, -12) == -3);
    assert (gcd(-1, -1) == -1);
    return 0;
}
