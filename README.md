# Competitive Programming Library

[![Travis](https://img.shields.io/travis/kmyk/competitive-programming-library/master.svg)](https://travis-ci.org/kmyk/competitive-programming-library)
![License](https://img.shields.io/github/license/kmyk/competitive-programming-library.svg)

For CI, you can read the document: <https://online-judge-tools.readthedocs.io/en/master/run-ci-on-your-library.en.html>

## List of Frequently Used Algorithms / Data-Structures

-   [template.cpp](https://github.com/kmyk/competitive-programming-library/tree/master/template.cpp)
-   `data_structure/`
    -   [union find tree](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/union_find_tree.hpp)
        -   [test (AOJ DSL_1_A)](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/union_find_tree.test.cpp)
    -   [segment tree](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/segment_tree.hpp)
        -   [test (AOJ DSL_2_B)](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/dual_segment_tree.range_sum_query.test.cpp)
    -   [segment tree (dual)](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/dual_segment_tree.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/dual_segment_tree.unit.test.cpp)
        -   [test (AOJ DSL_2_D)](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/dual_segment_tree.range_update_query.test.cpp)
    -   [segment tree (lazy propagation)](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/lazy_propagation_segment_tree.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/lazy_propagation_segment_tree.unit.test.cpp)
        -   [test (DSL_2_H)](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/lazy_propagation_segment_tree.range_max_range_add.test.cpp)
    -   [convex hull trick (without monotonicity)](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/convex_hull_trick.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/convex_hull_trick.test.cpp)
-   `modulus/`
    -   [struct for modular arithmetic](https://github.com/kmyk/competitive-programming-library/blob/master/modulus/mint.hpp)
    -   [factorial](https://github.com/kmyk/competitive-programming-library/blob/master/modulus/factorial.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/modulus/factorial.unit.test.cpp)
    -   [combination](https://github.com/kmyk/competitive-programming-library/blob/master/modulus/choose.hpp)
-   `number/`
    -   [gcd](https://github.com/kmyk/competitive-programming-library/blob/master/number/gcd.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/number/gcd.test.cpp)
    -   [extgcd](https://github.com/kmyk/competitive-programming-library/blob/master/number/extgcd.inc.cpp)
    -   [prime numbers](https://github.com/kmyk/competitive-programming-library/blob/master/number/primes.inc.cpp)
    -   [matrix](https://github.com/kmyk/competitive-programming-library/blob/master/number/matrix.inc.cpp)
-   `graph/`
    -   [topological sort](https://github.com/kmyk/competitive-programming-library/blob/master/graph/topological-sort.inc.cpp)
    -   [lowest common ancestor](https://github.com/kmyk/competitive-programming-library/blob/master/graph/lowest-common-ancestor.inc.cpp)
    -   [Kruskal's algorithm](https://github.com/kmyk/competitive-programming-library/blob/master/graph/minimum-spanning-tree.inc.cpp)
    -   [Dinic's algorithm](https://github.com/kmyk/competitive-programming-library/blob/master/graph/centroid-decomposition.inc.cp://github.com/kmyk/competitive-programming-library/blob/master/graph/dinic.inc.cpp)
    -   [primal-dual](https://github.com/kmyk/competitive-programming-library/blob/master/graph/centroid-decomposition.inc.cp://github.com/kmyk/competitive-programming-library/blob/master/graph/dinic.inc.cp://github.com/kmyk/competitive-programming-library/blob/master/graph/minimum-cost-flow.inc.cpp)
-   `string/`
    -   [rolling hash](https://github.com/kmyk/competitive-programming-library/blob/master/string/rolling-hash.inc.cpp)
-   `utils/`
    -   [binary search](https://github.com/kmyk/competitive-programming-library/blob/master/utils/binary_search.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/utils/binary_search.unit.test.cpp)
        -   [test (AOJ ALDS1_4_B)](https://github.com/kmyk/competitive-programming-library/tree/master/utils/binary_search.aoj.test.cpp)

## List of Frequently Used Algorithms / Data-Structures (Advanced)

-   `modulus/`
    -   [baby-step giant-step algorithm](https://github.com/kmyk/competitive-programming-library/blob/master/modulus/discrete-log.inc.cpp)
    -   [factorial (embedding)](https://github.com/kmyk/competitive-programming-library/blob/master/modulus/factorial-embed.inc.cpp)
-   `number/`
    -   [Miller-Rabin](https://github.com/kmyk/competitive-programming-library/blob/master/number/miller-rabin.inc.cpp)
    -   [number theoretic transformation](https://github.com/kmyk/competitive-programming-library/blob/master/number/number_theoretic_transformation.hpp)
        -   [test (judge.yosupo.jp)](https://github.com/kmyk/competitive-programming-library/blob/master/number/number_theoretic_transformation.998244353.test.cpp)
        -   [test with Garner's algorithm](https://github.com/kmyk/competitive-programming-library/blob/master/number/number_theoretic_transformation.1000000007.test.cpp)
-   `graph/`
    -   [centroid decomposition](https://github.com/kmyk/competitive-programming-library/blob/master/graph/centroid-decomposition.inc.cpp)
    -   [strongly connected components decomposition](https://github.com/kmyk/competitive-programming-library/blob/master/graph/strongly_connected_components.cpp)
    -   [two-edge connected components decomposition](https://github.com/kmyk/competitive-programming-library/blob/master/graph/two-edge-connected-components.inc.cpp)
    -   [heavy light decomposition](https://github.com/kmyk/competitive-programming-library/blob/master/graph/heavy_light_decomposition.inc.cpp)
-   `string/`
    -   [Manachar's algorithm](https://github.com/kmyk/competitive-programming-library/blob/master/string/palindrome.inc.cpp)
    -   [Morris-Pratt algorithm](https://github.com/kmyk/competitive-programming-library/blob/master/string/knuth-morris-pratt.inc.cpp)
    -   [suffix array](https://github.com/kmyk/competitive-programming-library/blob/master/string/suffix-array.inc.cpp)
-   `data_structure/`
    -   [sparse table](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/sparse_table.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/sparse_table.unit.test.cpp)
    -   [fully indexable dictionary](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/fully_indexable_dictionary.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/fully_indexable_dictionary.test.cpp)
    -   [wavelet matrix](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/wavelet_matrix.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/wavelet_matrix.test.cpp)
    -   [red black tree](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/red-black-tree.inc.cpp)
    -   [persistent array](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/persistent-array.inc.cpp)
    -   [link-cut tree](https://github.com/kmyk/competitive-programming-library/blob/master/data_structure/link_cut_tree.hpp)
        -   [unittest](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/link_cut_tree.spaceships.test.cpp)
        -   [test (Marked Ancestor)](https://github.com/kmyk/competitive-programming-library/tree/master/data_structure/link_cut_tree.marked_ancestor.test.cpp)

## PDF version

[PDF](https://raw.githubusercontent.com/kmyk/competitive-programming-library/master/library.pdf) for ICPC

## License

Licensed under MIT License, but you can use this library without the copyright notice in your submissions for online judges.
