#pragma once
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class scanner {
    static constexpr int N = 65536;
    static constexpr int K = 64;
    char buf[K + N];
    int l = 0;
    int r = 0;
    void flush() {
        if (K < r - l) return;
        memmove(buf + K - (r - l), buf + l, r - l);
        l = K - (r - l);
        r = K + read(STDIN_FILENO, buf + K, N);
        assert (l < r);
    }
    void prepare() {
        flush();
        while (isspace(buf[l])) {
            ++ l;
            flush();
        }
    }
public:
    scanner() = default;
    scanner(const scanner &) = delete;
    scanner & operator = (const scanner &) = delete;
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline char get() {
        prepare();
        return buf[l ++];
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    std::string get() {
        prepare();
        std::string s;
        do {
            s.push_back(buf[l ++]);
            if (r == l) flush();
        } while (not isspace(buf[l]));
        return s;
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    Integer get() {
        prepare();
        bool is_negative = false;
        if (std::is_signed<Integer>::value and buf[l] == '-') {
            is_negative = true;
            ++ l;
        }
        Integer x = 0;
        while (l < r and isdigit(buf[l])) {
            x *= 10;
            x += buf[l] - '0';
            ++ l;
        }
        if (std::is_signed<Integer>::value and is_negative) {
            x *= -1;
        }
        return x;
    }
};
