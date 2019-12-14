/**
 * @brief a structure to make a midpoint for given two points
 */
class midpoint {
    vector<bool> data;
    midpoint(vector<bool> const & data_) : data(data_) {}
public:
    midpoint() : data({ false, true }) {}
    static midpoint min() { return midpoint(vector<bool>()); }
    static midpoint max() { return midpoint(vector<bool>(1, true)); }
    /**
     * @brief for given $a$ and $c$, make $b$ s.t. $a < b < c$
     */
    midpoint between(midpoint const & other) const {
        auto const & a = this->data;
        auto const & b = other.data;
        vector<bool> c(::max(a.size(), b.size()) + 1);
        bool is_carried = false;
        REP_R (i, ::max(a.size(), b.size())) {
            bool a_i = (i < a.size() and a[i]);
            bool b_i = (i < b.size() and b[i]);
            c[i + 1]   = a_i ^ b_i ^ is_carried;
            is_carried = a_i + b_i + is_carried >= 2;
        }
        c[0] = is_carried;
        while (not c.empty() and not c.back()) {
            c.pop_back();
        }
        return midpoint(c);
    }
    bool operator < (midpoint const & other) const {
        return this->data < other.data;
    }
};
