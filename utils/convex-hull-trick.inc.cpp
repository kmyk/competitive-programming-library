// http://d.hatena.ne.jp/sune2/20140310/1394440369
// http://techtipshoge.blogspot.jp/2013/06/convex-hull-trickdequepop-back.html
// http://satanic0258.hatenablog.com/entry/2016/08/16/181331
// http://wcipeg.com/wiki/Convex_hull_trick
// verified: http://codeforces.com/contest/631/submission/31828502
struct line_t { ll a, b; };
bool operator < (line_t lhs, line_t rhs) { return make_pair(- lhs.a, lhs.b) < make_pair(- rhs.a, rhs.b); }
struct rational_t { ll num, den; };
rational_t make_rational(ll num, ll den = 1) {
    if (den < 0) { num *= -1; den *= -1; }
    return { num, den };
}
bool operator < (rational_t lhs, rational_t rhs) {
    if (lhs.num ==   LLONG_MAX or rhs.num == - LLONG_MAX) return false;
    if (lhs.num == - LLONG_MAX or rhs.num ==   LLONG_MAX) return true;
    return lhs.num * rhs.den < rhs.num * lhs.den;
}
struct convex_hull_trick {
    convex_hull_trick() {
        lines.insert({ + LLONG_MAX, 0 });  // sentinels
        lines.insert({ - LLONG_MAX, 0 });
        cross.emplace(make_rational(- LLONG_MAX), (line_t) { - LLONG_MAX, 0 });
    }
    void add_line(ll a, ll b) {
        auto it = lines.insert({ a, b }).first;
        if (not is_required(*prev(it), { a, b }, *next(it))) {
            lines.erase(it);
            return;
        }
        cross.erase(cross_point(*prev(it), *next(it)));
        {  // remove right lines
            auto ju = prev(it);
            while (ju != lines.begin() and not is_required(*prev(ju), *ju, { a, b })) -- ju;
            cross_erase(ju, prev(it));
            it = lines.erase(++ ju, it);
        }
        {  // remove left lines
            auto ju = next(it);
            while(next(ju) != lines.end() and not is_required({ a, b }, *ju, *next(ju))) ++ ju;
            cross_erase(++ it, ju);
            it = prev(lines.erase(it, ju));
        }
        cross.emplace(cross_point(*prev(it), *it), *it);
        cross.emplace(cross_point(*it, *next(it)), *next(it));
    }
    ll get_min(ll x) const {
        line_t f = prev(cross.lower_bound(make_rational(x)))->second;
        return f.a * x + f.b;
    }
private:
    set<line_t> lines;
    map<rational_t, line_t> cross;
    template <typename Iterator>
    void cross_erase(Iterator first, Iterator last) {
        for (; first != last; ++ first) {
            cross.erase(cross_point(*first, *next(first)));
        }
    }
    rational_t cross_point(line_t f1, line_t f2) const {
        if (f1.a ==   LLONG_MAX) return make_rational(- LLONG_MAX);
        if (f2.a == - LLONG_MAX) return make_rational(  LLONG_MAX);
        return make_rational(f1.b - f2.b, f2.a - f1.a);
    }
    bool is_required(line_t f1, line_t f2, line_t f3) const {
        if (f1.a == f2.a and f1.b <= f2.b) return false;
        if (f1.a == LLONG_MAX or f3.a == - LLONG_MAX) return true;
        return (f2.a - f1.a) * (f3.b - f2.b) < (f2.b - f1.b) * (f3.a - f2.a);
    }
};
unittest {
    default_random_engine gen;
    repeat (iteration, 1000) {
        vector<pair<int, int> > lines;
        convex_hull_trick cht;
        repeat (i, 100) {
            int a = uniform_int_distribution<int>(- 30, 30)(gen);
            int b = uniform_int_distribution<int>(- 30, 30)(gen);
            lines.emplace_back(a, b);
            cht.add_line(a, b);
        }
        repeat (i, 10) {
            int x = uniform_int_distribution<int>(- 100, 100)(gen);
            int y = INT_MAX;
            for (auto line : lines) {
                int a, b; tie(a, b) = line;
                setmin(y, a * x + b);
            }
            assert (cht.get_min(x) == y);
        }
    }
}
struct inverted_convex_hull_trick {
    convex_hull_trick data;
    void add_line(ll a, ll b) { data.add_line(- a, - b); }
    ll get_max(ll x) { return - data.get_min(x); }
};
