template <class T> inline void chmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }
template <class T> inline void chmax2(T & a1, T & a2, T const & b) { if (a1 < b) { a2 = a1; a1 = b; } else if (a2 < b) { a2 = b; } }
template <class T> inline void chmin2(T & a1, T & a2, T const & b) { if (a1 > b) { a2 = a1; a1 = b; } else if (a2 > b) { a2 = b; } }
