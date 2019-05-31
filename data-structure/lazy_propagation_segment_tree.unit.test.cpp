#include "utils/common.hpp"
#include "data-structure/lazy_propagation_segment_tree.hpp"
using namespace std;

int main() {
    lazy_propagation_segment_tree<min_monoid, plus_with_int_max_operator_monoid> segtree(9);
    segtree.point_set(2, 2);
    segtree.point_set(3, 3);
    segtree.point_set(4, 4);
    segtree.point_set(6, 6);
    assert (segtree.range_concat(2, 3) == 2);
    assert (segtree.range_concat(5, 8) == 6);
    segtree.range_apply(1, 4, 9);
    assert (segtree.range_concat(3, 6) == 4);
    assert (segtree.range_concat(0, 3) == 11);
    return 0;
}
