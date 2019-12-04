<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data_structure/persistent-array.inc.cpp
* category: data_structure


[Back to top page](../../index.html)



## Code
```cpp
// http://qiita.com/imos/items/c4c5e19289a79e598b93
// http://web.mit.edu/andersk/Public/6.851-presentation.pdf
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

```

[Back to top page](../../index.html)

