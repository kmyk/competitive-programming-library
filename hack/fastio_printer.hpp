#pragma once
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <type_traits>
#include <unistd.h>

class printer {
    static constexpr int N = 131072;
    static constexpr int K = 64;
    char buf[N];
    int i = 0;
    inline void flush() {
        write(STDOUT_FILENO, buf, i);
        i = 0;
    }
public:
    printer() = default;
    printer(const printer &) = delete;
    printer & operator = (const printer &) = delete;
    ~printer() {
        flush();
    }
    template <class Char, std::enable_if_t<std::is_same<Char, char>::value, int> = 0>
    inline void put(char c) {
        if (i == N) flush();
        buf[i ++] = c;
    }
    template <class String, std::enable_if_t<std::is_same<String, std::string>::value, int> = 0>
    void put(const std::string & s) {
        for (int l = 0; l < (int)s.length(); ) {
            if (i == N) flush();
            int r = std::min<int>(s.length(), l + (N - i));
            memcpy(buf + i, s.data() + l, r - l);
            i += r - l;
            l = r;
        }
    }
    template <class Integer, std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    void put(Integer x) {
        if (N - i < K) flush();
        if (std::is_signed<Integer>::value and x < 0) {
            x *= -1;
            buf[i ++] = '-';
        }
        if (x == 0) {
            buf[i ++] = '0';
            return;
        }
        char s[K];
        int j = 0;
        while (x) {
            s[j ++] = x % 10 + '0';
            x /= 10;
        }
        while (j) {
            buf[i ++] = s[-- j];
        }
    }
};
