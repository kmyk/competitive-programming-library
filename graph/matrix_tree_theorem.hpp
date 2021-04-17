#pragma once
#include <cassert>
#include <vector>

namespace matrix_tree_theorem {

template <class T>
T determinant(const std::vector<std::vector<T> >& original_a) {
    int n = original_a.size();
    auto a = original_a;
    T det = 1;
    REP (i, n) {
        REP (j, i) {
            if (a[j][j] == 0) {
                int k = j + 1;
                for (; k < n; ++ k) {
                    if (a[k][j] != 0) break;
                }
                if (k == n) return 0;
                REP3 (l, j, n) {
                    swap(a[j][l], a[k][l]);
                }
            }
            assert (a[j][j] != 0);
            T t = a[i][j] / a[j][j];
            REP3 (k, j + 1, n) {
                a[i][k] -= a[j][k] * t;
            }
        }
    }
    REP (i, a.size()) det *= a[i][i];
    return det;
}

template <class T>
std::vector<std::vector<T> > small_matrix(const std::vector<std::vector<T> >& a) {
    int n = a.size();
    assert (n >= 1);
    auto b = a;
    b.resize(n - 1);
    REP (y, n - 1) {
        b[y].resize(n - 1);
    }
    return b;
}

template <class T>
std::vector<std::vector<T> > laplacian_matrix_from_adjacency_matrix(const std::vector<std::vector<T> >& a) {
    REP (y, a.size()) {
        REP (x, a[y].size()) {
            if (y == x) {
                assert (a[y][x] == 0);
            }
        }
    }
    std::vector<std::vector<T> > l = a;
    REP (y, l.size()) {
        REP (x, l[y].size()) {
            if (y == x) {
                l[y][y] += l[y][x];
                l[y][x] *= -1;
            }
        }
    }
    return l;
}

/**
 * @brief 全域木の個数を数える (行列木定理)
 * @arg a is an adjacency matrix of a graph without self-loops. Multiple edges are allowed.
 */
template <class T>
T count_spanning_trees(const std::vector<std::vector<T> >& a) {
    return determinant(small_matrix(laplacian_matrix_from_adjacency_matrix(a)));
}

}
