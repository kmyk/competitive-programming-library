#include "data_structure/dual_segment_tree.hpp"
#include "utils/monoids.hpp"

#include <cassert>
using namespace std;

int main() {
    dual_segment_tree<min_monoid<int> > segtree(12);
    segtree.range_apply(2, 7, 50);
    segtree.range_apply(5, 9, 30);
    segtree.range_apply(1, 11, 80);
    assert (segtree.point_get( 0) == min_monoid<int>().unit());
    assert (segtree.point_get( 1) ==  80);
    assert (segtree.point_get( 2) ==  50);
    assert (segtree.point_get( 3) ==  50);
    assert (segtree.point_get( 4) ==  50);
    assert (segtree.point_get( 5) ==  30);
    assert (segtree.point_get( 6) ==  30);
    assert (segtree.point_get( 7) ==  30);
    assert (segtree.point_get( 8) ==  30);
    assert (segtree.point_get( 9) ==  80);
    assert (segtree.point_get(10) ==  80);
    assert (segtree.point_get(11) == min_monoid<int>().unit());
    return 0;
}
