#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <initializer_list>
#include <tuple>
#include <vector>
#include "modulus/mint.hpp"
#include "number/number_theoretic_transformation.hpp"
#include "utils/macros.hpp"

template <class T>
struct formal_power_series {
    std::vector<T> a;

    inline size_t size() const { return a.size(); }
    inline bool empty() const { return a.empty(); }
    inline T at(int i) const { return (i < size() ? a[i] : T(0)); }
    inline const std::vector<T> & data() const { return a; }

    formal_power_series() = default;
    formal_power_series(const std::vector<T> & a_) : a(a_) { shrink(); }
    formal_power_series(const std::initializer_list<T> & init) : a(init) { shrink(); }
    template <class Iterator>
    formal_power_series(Iterator first, Iterator last) : a(first, last) { shrink(); }
    void shrink() { while (not a.empty() and a.back().value == 0) a.pop_back(); }

    inline formal_power_series<T> operator + (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) += other;
    }
    inline formal_power_series<T> operator - (const formal_power_series<T> & other) const {
        return formal_power_series<T>(a) -= other;
    }
    inline formal_power_series<T> & operator += (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] += other.a[i];
        return *this;
    }
    inline formal_power_series<T> & operator -= (const formal_power_series<T> & other) {
        if (a.size() < other.a.size()) a.resize(other.a.size(), T(0));
        REP (i, other.a.size()) a[i] -= other.a[i];
        return *this;
    }
    inline formal_power_series<T> operator * (const formal_power_series<T> & other) const {
        return formal_power_series<T>(ntt_convolution(a, other.a));
    }
    inline formal_power_series<T> operator * (T b) {
        return formal_power_series<T>(a) *= b;
    }
    inline formal_power_series<T> & operator *= (T b) {
        REP (i, size()) a[i] *= b;
        return *this;
    }

    inline formal_power_series<T> integral() const {
        std::vector<T> b(size() + 1);
        REP (i, size()) {
            b[i + 1] = a[i] / (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> differential() const {
        if (empty()) return *this;
        std::vector<T> b(size() - 1);
        REP (i, size() - 1) {
            b[i] = a[i + 1] * (i + 1);
        }
        return b;
    }
    inline formal_power_series<T> modulo_x_to(int k) const {
        return {{ a.begin(), a.begin() + std::min<int>(size(), k) }};
        // return formal_power_series<T>(a.begin(), a.begin() + std::min<int>(size(), k));
    }

    formal_power_series<T> inv() const {
        assert (at(0) != 0);
        formal_power_series<T> res { at(0).inv() };
        for (int i = 1; i < size(); i *= 2) {
            res = (res * T(2) - res * res * modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return res.modulo_x_to(size());
        /*
        formal_power_series<T> b { a[0].inv() };
        formal_power_series<T> two { 2 };
        for (int i = 1; i < size(); i *= 2) {
            const int m = std::min<int>(size(), i * 2);
            b = b.modulo_x_to(m);
            b = (this->modulo_x_to(m) * b + two) * b;
        }
        return b;
        */
    }
    formal_power_series<T> exp() const {
        auto & h = *this;
        formal_power_series<T> f { 1 };
        formal_power_series<T> g { 1 };
        for (int m = 1; m <= size(); m <<= 1) {
            g = g * 2 - (f * (g * g)).modulo_x_to(m);
            auto q = h.differential().modulo_x_to(m - 1);
            auto w = (q + g * (f.differential() - f * q)).modulo_x_to(2 * m - 1);
            f = f + (f * (h - w.integral())).modulo_x_to(2 * m);
        }
        return f;
    }
    inline formal_power_series<T> log() const {
        return (this->differential() * this->inv()).integral();
    }
    inline formal_power_series<T> pow(int k) const {
        return (this->log() * k).exp();
    }
};
