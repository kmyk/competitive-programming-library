#pragma once
#include <vector>

/**
 * @brief a disjoint set structure with monoid
 * @note union-by-size + path-compression
 */
template <class Monoid>
struct union_find_tree_with_monoid {
    typedef typename Monoid::value_type value_type;
    const Monoid mon;
    std::vector<int> data;
    std::vector<value_type> value;

    union_find_tree_with_monoid() = default;
    union_find_tree_with_monoid(std::size_t n, Monoid const & mon_ = Monoid()) : mon(mon_), data(n, -1), value(n, mon.unit()) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int tree_size(int i) { return - data[find_root(i)]; }
    int unite_trees(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (tree_size(i) < tree_size(j)) std::swap(i, j);
            data[i] += data[j];
            data[j] = i;
            value[i] = mon.mult(value[i], value[j]);
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
    value_type get_value(int i) { return value[find_root(i)]; }
    void set_value(int i, value_type z) { value[find_root(i)] = z; }
};
