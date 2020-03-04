#pragma once
#include "string/suffix_array.hpp"

/**
 * @brief Longest Common Prefix / 最長共通接頭辞 ($O(N)$)
 * @arg lcp[i] is the length of the common prefix between i-th and (i+1)-th substring of s
 * @note 蟻本より
 * @note lcp.size() == n, != n + 1
 */
std::vector<int> longest_common_prefix_array(const std::string & s, const std::vector<int> & sa, const std::vector<int> & rank) {
    int n = s.length();
    std::vector<int> lcp(n);
    int h = 0;
    lcp[0] = 0;
    REP (i, n) {
        int j = sa[rank[i] - 1];
        if (h > 0) -- h;
        while (j + h < n and i + h < n and s[j + h] == s[i + h]) ++ h;
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}
