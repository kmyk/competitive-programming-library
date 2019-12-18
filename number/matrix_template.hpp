#pragma once
#include <array>
#include <cstdint>
#include "utils/macros.hpp"

template <typename T, size_t H, size_t W>
using matrix = std::array<std::array<T, W>, H>;

template <typename T, size_t A, size_t B, size_t C>
matrix<T, A, C> operator * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {
    matrix<T, A, C> c = {};
    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];
    return c;
}
template <typename T, size_t H, size_t W>
std::array<T, H> operator * (matrix<T, H, W> const & a, std::array<T, W> const & b) {
    std::array<T, H> c = {};
    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> operator + (matrix<T, H, W> const & a, matrix<T, H, W> const & b) {
    matrix<T, H, W> c;
    REP (y, H) REP (x, W) c[y][x] = a[y][x] + b[y][x];
    return c;
}

template <typename T, size_t N>
std::array<T, N> operator + (std::array<T, N> const & a, std::array<T, N> const & b) {
    std::array<T, N> c;
    REP (i, N) c[i] = a[i] + b[i];
    return c;
}

template <typename T, size_t H, size_t W>
matrix<T, H, W> zero_matrix() {
    return {};
}

template <typename T, size_t N>
matrix<T, N, N> unit_matrix() {
    matrix<T, N, N> a = {};
    REP (i, N) a[i][i] = 1;
    return a;
}

template <typename T, size_t N>
matrix<T, N, N> powmat(matrix<T, N, N> x, int64_t k) {
    matrix<T, N, N> y = unit_matrix<T, N>();
    for (; k; k >>= 1) {
        if (k & 1) y = y * x;
        x = x * x;
    }
    return y;
}
