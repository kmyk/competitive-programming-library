#pragma once
#include <algorithm>
#include <vector>
#include "../utils/macros.hpp"

template <class T>
struct coordinate_compression {
    std::vector<T> data;
    coordinate_compression() = default;
    template <class Iterator>
    coordinate_compression(Iterator first, Iterator last) {
        unsafe_insert(first, last);
        unsafe_rebuild();
    }
    template <class Iterator>
    void unsafe_insert(Iterator first, Iterator last) {
        data.insert(data.end(), first, last);
    }
    void unsafe_rebuild() {
        std::sort(ALL(data));
        data.erase(std::unique(ALL(data)), data.end());
    }
    int operator [] (const T & value) {
        return std::lower_bound(ALL(data), value) - data.begin();
    }
};
