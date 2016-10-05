// https://kimiyuki.net/blog/2015/12/19/srm-676-med/
template <typename C>
int mex(C const & xs) {
    int y = 0;
    for (int x : xs) { // xs must be sorted (duplication is permitted)
        if (y <  x) break;
        if (y == x) ++ y;
    }
    return y;
}
