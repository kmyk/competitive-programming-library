#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <initializer_list>
#include <tuple>
#include <vector>
#include "modulus/mint.hpp"
#include "modulus/number_theoretic_transformation.hpp"
#include "utils/macros.hpp"

/**
 * @brief formal power series / 形式的羃級数環 $\mathbb{Z}/n\mathbb{Z}\lbrack\lbrack x\rbrack\rbrack$
 */
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
    inline formal_power_series<T> operator / (T b) {
        return formal_power_series<T>(a) /= b;
    }
    inline formal_power_series<T> & operator /= (T b) {
        REP (i, size()) a[i] /= b;
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
        return formal_power_series<T>(a.begin(), a.begin() + std::min<int>(size(), k));
    }

    formal_power_series<T> inv(int n) const {
        assert (at(0) != 0);
        formal_power_series<T> res { at(0).inv() };
        for (int i = 1; i < n; i *= 2) {
            res = (res * T(2) - res * res * modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return res.modulo_x_to(n);
    }
    formal_power_series<T> exp(int n) const {
        formal_power_series<T> f{ 1 };
        formal_power_series<T> g{ 1 };
        for (int i = 1; i < n; i *= 2) {
            g = (g * 2 - f * g * g).modulo_x_to(i);
            formal_power_series<T> q = differential().modulo_x_to(i - 1);
            formal_power_series<T> w = (q + g * (f.differential() - f * q)).modulo_x_to(2 * i - 1);
            f = (f + f * (*this - w.integral()).modulo_x_to(2 * i)).modulo_x_to(2 * i);
        }
        return f.modulo_x_to(n);
    }
    inline formal_power_series<T> log(int n) const {
        assert (at(0) != 0);
        if (at(0) != 1) return (formal_power_series<T>(a) / at(0)).log(n) * at(0);
        if (size() == 1) return formal_power_series();
        return (this->differential() * this->inv(n - 1)).modulo_x_to(n - 1).integral();
    }
    inline formal_power_series<T> pow(int k, int n) const {
        return (this->log(n) * k).exp(n);
    }
};

template <class T>
inline formal_power_series<T> operator - (const formal_power_series<T> & f) {
    return formal_power_series<T>(f) *= -1;
}

template <class T>
std::ostream & operator << (std::ostream & out, const formal_power_series<T> & f) {
    bool is_zero = true;
    REP (i, f.size()) {
        if (f.at(i)) {
            if (not is_zero) out << '+';
            out << f.at(i);
            if (i) out << "x^" << i;
            is_zero = false;
        }
    }
    if (is_zero) {
        out << "0";
    }
    return out;
}
