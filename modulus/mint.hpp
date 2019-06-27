#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>

template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    inline mint<MOD> operator + (mint<MOD> other) const { int32_t c = this->value + other.value; return mint<MOD>(c >= MOD ? c - MOD : c); }
    inline mint<MOD> operator - (mint<MOD> other) const { int32_t c = this->value - other.value; return mint<MOD>(c <    0 ? c + MOD : c); }
    inline mint<MOD> operator * (mint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return mint<MOD>(c < 0 ? c + MOD : c); }
    inline mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline mint<MOD> & operator *= (mint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    inline mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0); }
    mint<MOD> pow(uint64_t k) const {
        mint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1) y *= x;
            x *= x;
        }
        return y;
    }
    mint<MOD> inv() const {
        assert (value != 0);
        int64_t a = value, b = MOD;
        int64_t x = 0, y = 1;
        for (int64_t u = 1, v = 0; a; ) {
            int64_t q = b / a;
            x -= q * u; std::swap(x, u);
            y -= q * v; std::swap(y, v);
            b -= q * a; std::swap(b, a);
        }
        assert (value * x + MOD * y == b);
        assert (b == 1);
        return x;
    }
    inline mint<MOD> operator /  (mint<MOD> other) const { return *this *  other.inv(); }
    inline mint<MOD> operator /= (mint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (mint<MOD> other) const { return value == other.value; }
    inline bool operator != (mint<MOD> other) const { return value != other.value; }
};
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }
