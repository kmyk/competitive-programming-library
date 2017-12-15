/**
 * @note verified http://arc054.contest.atcoder.jp/submissions/1335245
 */
template <class Monoid>
struct dynamic_segment_tree { // on monoid
    typedef Monoid monoid_type;
    typedef typename Monoid::type underlying_type;
    struct node_t {
        int left, right; // indices on pool
        underlying_type value;
    };
    deque<node_t> pool;
    int root; // index
    int width; // of the tree
    int size; // the number of leaves
    Monoid mon;
    dynamic_segment_tree(Monoid const & a_mon = Monoid()) : mon(a_mon) {
        node_t node = { -1, -1, mon.unit() };
        pool.push_back(node);
        root = 0;
        width = 1;
        size = 1;
    }
protected:
    int create_node(int parent, bool is_right) {
        // make a new node
        int i = pool.size();
        node_t node = { -1, -1, mon.unit() };
        pool.push_back(node);
        // link from the parent
        assert (parent != -1);
        int & ptr = is_right ? pool[parent].right : pool[parent].left;
        assert (ptr == -1);
        ptr = i;
        return i;
    }
    int get_value(int i) {
        return i == -1 ? mon.unit() : pool[i].value;
    }
public:
    void point_set(int i, underlying_type z) {
        assert (0 <= i);
        while (width <= i) {
            node_t node = { root, -1, pool[root].value };
            root = pool.size();
            pool.push_back(node);
            width *= 2;
        }
        point_set(root, -1, false, 0, width, i, z);
    }
    void point_set(int i, int parent, bool is_right, int il, int ir, int j, underlying_type z) {
        if (il == j and ir == j+1) { // 0-based
            if (i == -1) {
                i = create_node(parent, is_right);
                size += 1;
            }
            pool[i].value = z;
        } else if (ir <= j or j+1 <= il) {
            // nop
        } else {
            if (i == -1) i = create_node(parent, is_right);
            point_set(pool[i].left,  i, false, il, (il+ir)/2, j, z);
            point_set(pool[i].right, i, true,  (il+ir)/2, ir, j, z);
            pool[i].value = mon.append(get_value(pool[i].left), get_value(pool[i].right));
        }
    }
    underlying_type range_concat(int l, int r) {
        assert (0 <= l and l <= r);
        if (width <= l) return mon.unit();
        return range_concat(root, 0, width, l, min(width, r));
    }
    underlying_type range_concat(int i, int il, int ir, int l, int r) {
        if (i == -1) return mon.unit();
        if (l <= il and ir <= r) { // 0-based
            return pool[i].value;
        } else if (ir <= l or r <= il) {
            return mon.unit();
        } else {
            return mon.append(
                    range_concat(pool[i].left,  il, (il+ir)/2, l, r),
                    range_concat(pool[i].right, (il+ir)/2, ir, l, r));
        }
    }
    template <class Func>
    void traverse_leaves(Func func) {
        return traverse_leaves(root, 0, width, func);
    }
    template <class Func>
    void traverse_leaves(int i, int il, int ir, Func func) {
        if (i == -1) return;
        if (ir - il == 1) {
            func(il, pool[i].value);
        } else {
            traverse_leaves(pool[i].left,  il, (il+ir)/2, func);
            traverse_leaves(pool[i].right, (il+ir)/2, ir, func);
        }
    }
};
