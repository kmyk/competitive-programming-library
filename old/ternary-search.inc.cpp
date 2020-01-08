/**
 * @arg f must be a downward-convex function
 * @retrun argmin f
 * @note f is called (iteration + 1) times
 */
template <class Function>
double golden_section_search(double l, double r, int iteration, Function f) {
    static const double GOLDEN_RATIO = (1 + sqrt(5)) / 2;
    double m1 = l + (r - l) / (GOLDEN_RATIO + 1);
    double m2 = l + (r - l) / GOLDEN_RATIO;  // NOTE: this equals to GOLDEN_RATIO / (GOLDEN_RATIO + 1.0)
    double f1 = f(m1);
    double f2 = f(m2);
    while (iteration --) {
        if (f1 < f2){
            r = m2;
            m2 = m1;
            f2 = f1;
            m1 = l + (r - l) / (GOLDEN_RATIO + 1);
            f1 = f(m1);
        } else {
            l = m1;
            m1 = m2;
            f1 = f2;
            m2 = l + (r - l) / GOLDEN_RATIO;
            f2 = f(m2);
        }
    }
    return (l + r) / 2;
}
