#pragma once
#include <algorithm>

/**
 * @note if arguments are negative, the result may be negative
 */
template <typename T>
T gcd(T a, T b) {
    while (a) {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
