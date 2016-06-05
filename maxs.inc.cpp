template <typename T>
T maxs(T x) { return x; }
template <typename T, typename... Ts>
T maxs(T x, T y, Ts... zs) { return max(x, maxs(y, zs...)); }

template <typename T>
T mins(T x) { return x; }
template <typename T, typename... Ts>
T mins(T x, T y, Ts... zs) { return min(x, mins(y, zs...)); }
