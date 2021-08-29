#pragma once
#include <cassert>
#include <vector>
#include "../utils/macros.hpp"
#include "../graph/euler_tour_preorder.hpp"
#include "../data_structure/segment_tree.hpp"

/**
 * @brief Euler Tour (subtree queries, with commutative monoids)
 * @docs data_structure/euler_tour_subtree_query.md
 */
template <class CommutativeMonoid>
class euler_tour_subtree_query {
    typedef typename CommutativeMonoid::value_type value_type;
    segment_tree<CommutativeMonoid> data;
    std::vector<int> left, right;

public:
    euler_tour_subtree_query(const std::vector<std::vector<int> > & g, int root, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : data(g.size(), mon_) {
        std::vector<int> tour;
        do_euler_tour_preorder(g, root, tour, left, right);
    }
    template <class InputIterator>
    euler_tour_subtree_query(const std::vector<std::vector<int> > & g, int root, InputIterator first, InputIterator last, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : data(std::distance(first, last), mon_) {
        assert ((int)g.size() == std::distance(first, last));
        std::vector<int> tour;
        do_euler_tour_preorder(g, root, tour, left, right);
        REP (x, g.size()) {
            data.unsafe_point_set(left[x], *(first ++));
        }
        data.unsafe_rebuild();
    }

    void vertex_set(int x, value_type a) {
        assert (0 <= x and x < (int)left.size());
        return data.point_set(left[x], a);
    }
    value_type vertex_get(int x) {
        assert (0 <= x and x < (int)left.size());
        return data.point_get(left[x]);
    }
    value_type subtree_get(int x) {
        assert (0 <= x and x < (int)left.size());
        return data.range_get(left[x], right[x]);
    }
};
