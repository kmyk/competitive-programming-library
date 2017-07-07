bool is_suffix(string const & a, string const & b) {
    if (a.length() > b.length()) return false;
    return b.compare(b.length() - a.length(), a.length(), a) == 0;
}

unittest {
    assert (is_suffix("er", "atcoder"));
    assert (is_suffix("coder", "atcoder"));
    assert (not is_suffix("at", "atcoder"));
    assert (not is_suffix("error", "atcoder"));
    assert (not is_suffix("redoctatcoder", "atcoder"));
}
