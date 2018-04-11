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
        int i = toupper(c) - 'A';
        if (not t->children[i]) t->children[i] = make_shared<trie_t<T> >();
        t = t->children[i];
    }
    t->data = data;
    return original_t;
}
template <typename T>
shared_ptr<trie_t<T> > trie_find(shared_ptr<trie_t<T> > const & t, string const & s, int i) {
    if (t == nullptr) return t;
    if (i == s.length()) return t;
    char c = s[i];
    int j = toupper(c) - 'A';
    return trie_find(t->children[j], s, i + 1);
}
