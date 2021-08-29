#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include "../utils/macros.hpp"

/**
 * @brief Suffix Array / 接尾辞配列 ($O(N (\log N)^2)$, Manber & Myers)
 * @arg sa[i] is the index of i-th smallest substring of s, s[sa[i], N)
 * @arg rank[i] is the rank of substring s[i, N)
 * @note 蟻本より
 */
void compute_suffix_array(std::string const & s, std::vector<int> & sa, std::vector<int> & rank) {
    int n = s.length();
    sa.resize(n + 1);
    rank.resize(n + 1);
    REP (i, n + 1) {
        sa[i] = i;
        rank[i] = i < n ? s[i] : -1;
    }
    auto rankf = [&](int i) {
        return i <= n ? rank[i] : -1;
    };
    std::vector<int> nxt(n + 1);
    for (int k = 1; k <= n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            return std::make_pair(rank[i], rankf(i + k)) < std::make_pair(rank[j], rankf(j + k));
        };
        std::sort(sa.begin(), sa.end(), cmp);
        nxt[sa[0]] = 0;
        REP3 (i, 1, n + 1) {
            nxt[sa[i]] = nxt[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        rank.swap(nxt);
    }
}
