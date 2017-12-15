template <typename T>
struct trie_t {
    T data;
    array<shared_ptr<trie_t>, 26> children;
};
template <typename T>
shared_ptr<trie_t<T> > trie_insert(shared_ptr<trie_t<T> > original_t, string const & s, T data) {
    if (not original_t) original_t = make_shared<trie_t<T> >();
    auto t = original_t;
    for (char c : s) {
        assert (isalpha(c));
        c = toupper(c) - 'A';
        if (not t->children[c]) t->children[c] = make_shared<trie_t<T> >();
        t = t->children[c];
    }
    t->data = data;
    return original_t;
}
