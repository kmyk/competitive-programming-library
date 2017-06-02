#include <random>
#include <memory>

// https://www.hackerrank.com/contests/zalando-codesprint/challenges/give-me-the-order/submissions/code/6004391
template <typename T>
struct treap {
    typedef T value_type;
    typedef double key_type;
    value_type v;
    key_type k;
    shared_ptr<treap> l, r;
    size_t m_size;
    treap(value_type v)
            : v(v)
            , k(generate())
            , l()
            , r()
            , m_size(1) {
    }
    static size_t size(shared_ptr<treap> const & t) {
        return t ? t->m_size : 0;
    }
    static shared_ptr<treap> merge(shared_ptr<treap> const & a, shared_ptr<treap> const & b) { // destructive
        if (not a) return b;
        if (not b) return a;
        if (a->k > b->k) {
            a->r = merge(a->r, b);
            return update(a);
        } else {
            b->l = merge(a, b->l);
            return update(b);
        }
    }
    static pair<shared_ptr<treap>, shared_ptr<treap> > split(shared_ptr<treap> const & t, size_t i) { // [0, i) [i, n), destructive
        if (not t) return { shared_ptr<treap>(), shared_ptr<treap>() };
        if (i <= size(t->l)) {
            shared_ptr<treap> u; tie(u, t->l) = split(t->l, i);
            return { u, update(t) };
        } else {
            shared_ptr<treap> u; tie(t->r, u) = split(t->r, i - size(t->l) - 1);
            return { update(t), u };
        }
    }
    static shared_ptr<treap> insert(shared_ptr<treap> const & t, size_t i, value_type v) { // destructive
        shared_ptr<treap> l, r; tie(l, r) = split(t, i);
        shared_ptr<treap> u = make_shared<treap>(v);
        return merge(merge(l, u), r);
    }
    static pair<shared_ptr<treap>,shared_ptr<treap> > erase(shared_ptr<treap> const & t, size_t i) { // (t \ t_i, t_i), destructive
        shared_ptr<treap> l, u, r;
        tie(l, r) = split(t, i+1);
        tie(l, u) = split(l, i);
        return { merge(l, r), u };
    }
private:
    static shared_ptr<treap> update(shared_ptr<treap> const & t) {
        if (t) {
            t->m_size = 1 + size(t->l) + size(t->r);
        }
        return t;
    }
    static key_type generate() {
        static random_device device;
        static default_random_engine engine(device());
        static uniform_real_distribution<double> dist;
        return dist(engine);
    }
};
