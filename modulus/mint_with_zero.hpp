#pragma once
#include <cstdint>
#include <iostream>
#include "modulus/modpow.hpp"
#include "modulus/modinv.hpp"

/**
 * @brief 零の個数付き剰余演算の乗法群 $\mathbb{Z}/n\mathbb{Z} \times \mathbb{Z}$
 */
template <int32_t MOD>
struct zmint {
    int32_t nonzero;
    int32_t zero;
    zmint() : nonzero() {}
    zmint(int64_t nonzero_, int32_t zero_ = 0) : nonzero(nonzero_), zero(zero_) { while (nonzero and nonzero % MOD == 0) { nonzero_ /= MOD; zero_ += 1; } if (nonzero_ < 0) nonzero_ = nonzero_ % MOD + MOD; }
    zmint(int32_t nonzero_, int32_t zero_, std::nullptr_t) : nonzero(nonzero_), zero(zero_) {}
    explicit operator bool() const { return nonzero; }
    inline zmint<MOD> operator * (zmint<MOD> other) const { return zmint<MOD>(*this) *= other; }
    inline zmint<MOD> & operator *= (zmint<MOD> other) { nonzero = static_cast<uint_fast64_t>(this->nonzero) * other.nonzero % MOD; zero += other.zero; return *this; }
    inline zmint<MOD> operator / (zmint<MOD> other) const { return *this * other.inv(); }
    inline zmint<MOD> & operator /= (zmint<MOD> other) { return *this *= other.inv(); }
    inline zmint<MOD> operator - () const { return zmint<MOD>(nonzero ? MOD - nonzero : 0, zero, nullptr); }
    inline bool operator == (zmint<MOD> other) const { return nonzero == other.nonzero and zero == other.zero; }
    inline bool operator != (zmint<MOD> other) const { return nonzero != other.nonzero or zero != other.zero; }
    inline zmint<MOD> pow(uint64_t k) const { return zmint<MOD>(modpow(nonzero, k, MOD), k * zero, nullptr); }
    inline zmint<MOD> inv() const { return zmint<MOD>(modinv(nonzero, MOD), - zero, nullptr); }
};
template <int32_t MOD> zmint<MOD> operator * (int64_t nonzero, zmint<MOD> n) { return zmint<MOD>(nonzero) * n; }
template <int32_t MOD> zmint<MOD> operator / (int64_t nonzero, zmint<MOD> n) { return zmint<MOD>(nonzero) / n; }
