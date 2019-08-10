#include <cassert>
#include <utility>
#include <vector>
#include "utils/macros.hpp"

/**
 * @brief Lagrange interpolation
 * @note O(n^2)
 * @note works on any field
 * @note the error is very big
 */
std::vector<long double> lagrange_interpolate(const std::vector<std::pair<long double, long double> > & points) {
    // given ((x_0, y_1), \dots, (x_{n - 1}, y_{n - 1}))
    int n = points.size();

    // functions
    auto mul_monomial = [&](std::vector<long double> & f, long double a) {  // f \gets f \cdot (x - a)
        assert (f[n] == 0);
        REP_R (i, n + 1) {
            f[i] = (i >= 1 ? f[i - 1] : 0) - a * f[i];
        }
    };
    auto div_monomial = [&](std::vector<long double> & f, long double a) {  // f \gets f / (x - a)
        long double last = 0;
        REP_R (i, n + 1) {
            std::swap(f[i], last);
            last += a * f[i];
        }
    };
    auto apply = [&](std::vector<long double> & f, long double x) {  // f(x)
        long double y = 0;
        REP_R (i, n + 1) {
            y = y * x + f[i];
        }
        return y;
    };

    // let g = \prod_i (x - x_i)
    // let g_i = g / (x - x_i)
    // assert for all j \ne i. g_i(x_j) = 0
    std::vector<long double> g(n + 1);
    g[0] = 1;
    for (auto point : points) {
        mul_monomial(g, point.first);
    }

    // let c_i = y_i / g_i(x_i)
    // let f = \sum_i c_i g_i / (x - x_i)
    // assert for all i. f(x_i) = y_i
    std::vector<long double> f(n + 1);
    for (auto point : points) {
        div_monomial(g, point.first);
        long double c_i = point.second / apply(g, point.first);
        REP (j, n + 1) {
            f[j] += c_i * g[j];
        }
        mul_monomial(g, point.first);
    }
    assert (f.back() == 0);
    f.pop_back();
    return f;
}
