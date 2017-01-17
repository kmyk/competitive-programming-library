// http://yukicoder.me/submissions/142657
struct sequence {
    vector<int> data;
    int offset, cycle;
};
sequence iterate(int a, function<int (int)> f) {
    sequence xs;
    map<int, int> used;
    while (not used.count(a)) {
        used[a] = xs.data.size();
        xs.data.push_back(a);
        a = f(a);
    }
    xs.offset  = used[a];
    xs.cycle = xs.data.size() - xs.offset;
    return xs;
}
int at(sequence const & xs, int i) {
    return xs.data[i < xs.offset ? i : (i - xs.offset) % xs.cycle + xs.offset];
}
