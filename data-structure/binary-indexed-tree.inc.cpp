template <typename Monoid>
struct binary_indexed_tree { // on monoid
    typedef typename Monoid::underlying_type underlying_type;
    vector<underlying_type> data;
    Monoid mon;
    binary_indexed_tree(size_t n, Monoid const & a_mon = Monoid()) : mon(a_mon) {
        data.resize(n, mon.unit());
    }
    void point_append(size_t i, underlying_type z) { // data[i] += z
        for (size_t j = i + 1; j <= data.size(); j += j & -j) data[j - 1] = mon.append(data[j - 1], z);
    }
    underlying_type initial_range_concat(size_t i) { // sum [0, i)
        underlying_type acc = mon.unit();
        for (size_t j = i; 0 < j; j -= j & -j) acc = mon.append(data[j - 1], acc);
        return acc;
    }
};

unittest {
    binary_indexed_tree<plus_t> bit(8);
    bit.point_append(3, 4);
    bit.point_append(4, 3);
    bit.point_append(7, 1);
    assert (bit.initial_range_concat(3) == 0);
    assert (bit.initial_range_concat(5) == 7);
    assert (bit.initial_range_concat(8) == 8);
    bit.point_append(4, 2);
    assert (bit.initial_range_concat(3) == 0);
    assert (bit.initial_range_concat(5) == 9);
    assert (bit.initial_range_concat(8) == 10);
}
