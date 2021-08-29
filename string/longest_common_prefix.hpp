#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include "../string/suffix_array.hpp"
#include "../data_structure/sparse_table.hpp"
#include "../monoids/min.hpp"

/**
 * @brief Longest Common Prefix / 最長共通接頭辞 (接尾辞配列, 前処理 $O(N (\log N)^2)$ + $O(1)$)
 */
class longest_common_prefix {
    std::vector<int> rank;
    sparse_table<min_monoid<int> > table;

    void initialize(const std::string & s, const std::vector<int> & sa) {
        int n = s.length();
        std::vector<int> lcp(n, -1);  // lcp[i] is the length of the common prefix between i-th and (i+1)-th substring of s
        int h = 0;
        lcp[0] = 0;
        REP (i, n) {
            int j = sa[rank[i] - 1];
            if (h > 0) -- h;
            while (j + h < n and i + h < n and s[j + h] == s[i + h]) ++ h;
            lcp[rank[i] - 1] = h;
        }
        table = sparse_table<min_monoid<int> >(ALL(lcp));
    }

public:
    longest_common_prefix(const std::string & s) {
        std::vector<int> sa;
        compute_suffix_array(s, sa, rank);
        initialize(s, sa);
    }
    longest_common_prefix(const std::string & s, const std::vector<int> & sa, const std::vector<int> & rank_)
            : rank(rank_) {
        initialize(s, sa);
    }

    int get(int i, int j) const {
        int l = rank[i];
        int r = rank[j];
        if (l > r) std::swap(l, r);
        int n = rank.size() - 1;
        return std::min(n, table.range_get(l, r));
    }
};
