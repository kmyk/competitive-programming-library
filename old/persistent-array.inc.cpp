/**
 * @brief persistent array / 永続配列
 * @see http://qiita.com/imos/items/c4c5e19289a79e598b93
 * @see http://web.mit.edu/andersk/Public/6.851-presentation.pdf
 */
template <class T>
struct persistent_array { // fully persistent
    static const int SHIFT_SIZE = 3; // log of the branching factor b
    int size; // the size n
    int shift;
    array<shared_ptr<persistent_array>, (1 << SHIFT_SIZE)> children;
    shared_ptr<T> leaf;
    persistent_array(persistent_array const &) = default; // O(b)
    persistent_array() : size(0), shift(-1) {}
    persistent_array(int a_size) : size(a_size), shift(-1) { // O(n \log_b n + m b \log_b n) for number of update m
        if (size == 0) return;
        for (shift = 0; (1 << (shift * SHIFT_SIZE)) < size; ++ shift);
        if (shift == 0) {
            leaf.reset(new T());
        } else {
            int child_size = 1 << ((shift - 1) * SHIFT_SIZE);
            for (int l = 0; l < size; l += child_size) {
                int r = min(size, l + child_size);
                children[l / child_size].reset(new persistent_array(r - l));
            }
        }
    }
    T const & get(int index) const { // O(log_b n)
        return const_cast<persistent_array *>(this)->mutable_reference(index);
    }
    T & mutable_reference(int index) { // unsafe, to speed up initialization
        if (shift == 0) {
            assert (index == 0);
            return *leaf;
        }
        int l_shift = (shift - 1) * SHIFT_SIZE;
        int index_high = index >> l_shift;
        int index_low  = index & ((1 << l_shift) - 1);
        return children[index_high]->mutable_reference(index_low);
    }
    void set(int index, T const & value) { // O(b log_b n), increment m
        if (shift == 0) {
            assert (index == 0);
            leaf.reset(new T(value));
            return;
        }
        int l_shift = (shift - 1) * SHIFT_SIZE;
        int index_high = index >> l_shift;
        int index_low  = index & ((1 << l_shift) - 1);
        persistent_array *p = new persistent_array();
        *p = *(children[index_high]);
        children[index_high].reset(p);
        children[index_high]->set(index_low, value);
    }
};
template <typename T>
static ostream & operator << (ostream & out, persistent_array<T> const & a) {
    if (a.shift == 0) {
        repeat (i, 10) out << ' ';
        persistent_array<T> const *p = &a;
        out << p << ' ' << a.size << ' ' << *a.leaf<< endl;
    } else {
        repeat (i, 10 - a.shift) out << ' ';
        persistent_array<T> const *p = &a;
        out << p << ' ' << a.size << endl;
        for (auto it : a.children) if (it) out << *it;
    }
    return out;
};
