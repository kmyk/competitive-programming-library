template <typename T, typename X>
auto vectors(T a, X x) {
    return vector<T>(x, a);
}
template <typename T, typename X, typename Y, typename... Zs>
auto vectors(T a, X x, Y y, Zs... zs) {
    auto cont = vectors(a, y, zs...);
    return vector<decltype(cont)>(x, cont);
}
