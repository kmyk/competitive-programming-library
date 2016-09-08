template <typename T>
struct prbst { // persistent randomized binary search tree
    typedef T value_type;
    value_type v;
    shared_ptr<prbst> l, r;
    size_t m_size;
    static size_t size(shared_ptr<prbst> const & t) {
        return t ? t->m_size : 0;
    }
    static shared_ptr<prbst> merge(shared_ptr<prbst> const & a, shared_ptr<prbst> const & b) {
        if (not a) return b;
        if (not b) return a;
        if (compare(size(a), size(b))) {
            return make_shared<prbst>(b->v, merge(a, b->l), b->r);
        } else {
            return make_shared<prbst>(a->v, a->l, merge(a->r, b));
        }
    }
    static pair<shared_ptr<prbst>, shared_ptr<prbst> > split(shared_ptr<prbst> const & t, size_t i) { // [0, i) [i, n)
        if (not t) return { shared_ptr<prbst>(), shared_ptr<prbst>() };
        if (i <= size(t->l)) {
            shared_ptr<prbst> l, r; tie(l, r) = split(t->l, i);
            return { l, make_shared<prbst>(t->v, r, t->r) };
        } else {
            shared_ptr<prbst> l, r; tie(l, r) = split(t->r, i - size(t->l) - 1);
            return { make_shared<prbst>(t->v, t->l, l), r };
        }
    }
    static shared_ptr<prbst> insert(shared_ptr<prbst> const & t, size_t i, value_type v) {
        shared_ptr<prbst> l, r; tie(l, r) = split(t, i);
        shared_ptr<prbst> u = make_shared<prbst>(v);
        return merge(merge(l, u), r);
    }
    static pair<shared_ptr<prbst>, value_type> erase(shared_ptr<prbst> const & t, size_t i) { // (t \ t_i, t_i)
        shared_ptr<prbst> l, u, r;
        tie(l, r) = split(t, i+1);
        tie(l, u) = split(l, i);
        return { merge(l, r), u->v };
    }
// private:
    prbst(value_type v) : v(v), l(), r(), m_size(1) {}
    prbst(value_type v, shared_ptr<prbst> const & l, shared_ptr<prbst> const & r) : v(v), l(l), r(r), m_size(1 + size(l) + size(r)) {}
    static bool compare(size_t a, size_t b) {
        static random_device device;
        static default_random_engine engine(device());
        bernoulli_distribution dist(b /(double) (a + b));
        return dist(engine);
    }
};
