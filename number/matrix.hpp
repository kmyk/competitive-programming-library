#pragma once
#include <cstdint>
#include <vector>
#include "../utils/macros.hpp"

template <typename T>
std::vector<std::vector<T> > operator * (const std::vector<std::vector<T> >& a, const std::vector<std::vector<T> >& b) {
    int n = a.size();
    std::vector<std::vector<T> > c(n, std::vector<T>(n));
    REP (y, n) {
        REP (z, n) {
            REP (x, n) {
                c[y][x] += a[y][z] * b[z][x];
            }
        }
    }
    return c;
}

template <typename T>
std::vector<T> operator * (const std::vector<std::vector<T> >& a, const std::vector<T>& b) {
    int n = a.size();
    std::vector<T> c(n);
    REP (y, n) {
        REP (z, n) {
            c[y] += a[y][z] * b[z];
        }
    }
    return c;
}

template <typename T>
std::vector<std::vector<T> > unit_matrix(int n) {
    auto e = std::vector<std::vector<T> >(n, std::vector<T>(n));
    REP (i, n) {
        e[i][i] = 1;
    }
    return e;
}

template <typename T>
std::vector<std::vector<T> > zero_matrix(int n) {
    return std::vector<std::vector<T> >(n, std::vector<T>(n));
}

template <typename T>
std::vector<std::vector<T> > matpow(std::vector<std::vector<T> > x, int64_t y) {
    int n = x.size();
    auto z = unit_matrix<T>(n);
    for (int64_t i = 1; i <= y; i <<= 1) {
        if (y & i) {
            z = z * x;
        }
        x = x * x;
    }
    return z;
}
