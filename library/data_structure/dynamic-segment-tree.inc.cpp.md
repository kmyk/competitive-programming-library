---
layout: default
---

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


# :warning: data_structure/dynamic-segment-tree.inc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dynamic-segment-tree.inc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-09 01:50:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @note verified http://arc054.contest.atcoder.jp/submissions/1335245
 * @note verified https://csacademy.com/contest/ceoi-2018-day-2/task/fibonacci-representations-small/
 * @note you can implement this with unordered_map, but the constructor requires the size
 */
template <class Monoid>
struct dynamic_segment_tree { // on monoid
    typedef Monoid monoid_type;
    typedef typename Monoid::value_type value_type;
    struct node_t {
        int left, right; // indices on pool
        value_type value;
    };
    deque<node_t> pool;
    stack<int> bin;
    int root; // index
    ll width; // of the tree
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
        int i;
        if (bin.empty()) {
            i = pool.size();
            node_t node = { -1, -1, mon.unit() };
            pool.push_back(node);
        } else {
            i = bin.top();
            bin.pop();
            pool[i] = { -1, -1, mon.unit() };
        }
        // link from the parent
        assert (parent != -1);
        int & ptr = is_right ? pool[parent].right : pool[parent].left;
        assert (ptr == -1);
        ptr = i;
        return i;
    }
    value_type get_value(int i) {
        return i == -1 ? mon.unit() : pool[i].value;
    }
public:
    void point_set(ll i, value_type z) {
        assert (0 <= i);
        while (width <= i) {
            node_t node = { root, -1, pool[root].value };
            root = pool.size();
            pool.push_back(node);
            width *= 2;
        }
        point_set(root, -1, false, 0, width, i, z);
    }
    void point_set(int i, int parent, bool is_right, ll il, ll ir, ll j, value_type z) {
        if (il == j and ir == j + 1) { // 0-based
            if (i == -1) {
                i = create_node(parent, is_right);
                size += 1;
            }
            pool[i].value = z;
        } else if (ir <= j or j + 1 <= il) {
            // nop
        } else {
            if (i == -1) i = create_node(parent, is_right);
            point_set(pool[i].left,  i, false, il, (il + ir) / 2, j, z);
            point_set(pool[i].right, i, true,  (il + ir) / 2, ir, j, z);
            pool[i].value = mon.append(get_value(pool[i].left), get_value(pool[i].right));
        }
    }
    void point_delete(ll i) {
        assert (0 <= i);
        if (width <= i) return;
        root = point_delete(root, -1, false, 0, width, i);
    }
    int point_delete(int i, int parent, bool is_right, ll il, ll ir, ll j) {
        if (i == -1) {
            return -1;
        } else if (il == j and ir == j + 1) { // 0-based
            bin.push(i);
            size -= 1;
            return -1;
        } else if (ir <= j or j + 1 <= il) {
            return i;
        } else {
            pool[i].left  = point_delete(pool[i].left,  i, false, il, (il + ir) / 2, j);
            pool[i].right = point_delete(pool[i].right, i, true,  (il + ir) / 2, ir, j);
            if (pool[i].left == -1 and pool[i].right == -1 and i != root) {
                bin.push(i);
                size -= 1;
                return -1;
            } else {
                pool[i].value = mon.append(get_value(pool[i].left), get_value(pool[i].right));
                return i;
            }
        }
    }
    value_type range_concat(ll l, ll r) {
        assert (0 <= l and l <= r);
        if (width <= l) return mon.unit();
        return range_concat(root, 0, width, l, min(width, r));
    }
    value_type range_concat(int i, ll il, ll ir, ll l, ll r) {
        if (i == -1) return mon.unit();
        if (l <= il and ir <= r) { // 0-based
            return pool[i].value;
        } else if (ir <= l or r <= il) {
            return mon.unit();
        } else {
            return mon.append(
                    range_concat(pool[i].left,  il, (il + ir) / 2, l, r),
                    range_concat(pool[i].right, (il + ir) / 2, ir, l, r));
        }
    }
    template <class Func>
    void traverse_leaves(Func func) {
        return traverse_leaves(root, 0, width, func);
    }
    template <class Func>
    void traverse_leaves(ll i, ll il, ll ir, Func func) {
        if (i == -1) return;
        if (ir - il == 1) {
            func(il, pool[i].value);
        } else {
            traverse_leaves(pool[i].left,  il, (il + ir) / 2, func);
            traverse_leaves(pool[i].right, (il + ir) / 2, ir, func);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/dynamic-segment-tree.inc.cpp"
/**
 * @note verified http://arc054.contest.atcoder.jp/submissions/1335245
 * @note verified https://csacademy.com/contest/ceoi-2018-day-2/task/fibonacci-representations-small/
 * @note you can implement this with unordered_map, but the constructor requires the size
 */
template <class Monoid>
struct dynamic_segment_tree { // on monoid
    typedef Monoid monoid_type;
    typedef typename Monoid::value_type value_type;
    struct node_t {
        int left, right; // indices on pool
        value_type value;
    };
    deque<node_t> pool;
    stack<int> bin;
    int root; // index
    ll width; // of the tree
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
        int i;
        if (bin.empty()) {
            i = pool.size();
            node_t node = { -1, -1, mon.unit() };
            pool.push_back(node);
        } else {
            i = bin.top();
            bin.pop();
            pool[i] = { -1, -1, mon.unit() };
        }
        // link from the parent
        assert (parent != -1);
        int & ptr = is_right ? pool[parent].right : pool[parent].left;
        assert (ptr == -1);
        ptr = i;
        return i;
    }
    value_type get_value(int i) {
        return i == -1 ? mon.unit() : pool[i].value;
    }
public:
    void point_set(ll i, value_type z) {
        assert (0 <= i);
        while (width <= i) {
            node_t node = { root, -1, pool[root].value };
            root = pool.size();
            pool.push_back(node);
            width *= 2;
        }
        point_set(root, -1, false, 0, width, i, z);
    }
    void point_set(int i, int parent, bool is_right, ll il, ll ir, ll j, value_type z) {
        if (il == j and ir == j + 1) { // 0-based
            if (i == -1) {
                i = create_node(parent, is_right);
                size += 1;
            }
            pool[i].value = z;
        } else if (ir <= j or j + 1 <= il) {
            // nop
        } else {
            if (i == -1) i = create_node(parent, is_right);
            point_set(pool[i].left,  i, false, il, (il + ir) / 2, j, z);
            point_set(pool[i].right, i, true,  (il + ir) / 2, ir, j, z);
            pool[i].value = mon.append(get_value(pool[i].left), get_value(pool[i].right));
        }
    }
    void point_delete(ll i) {
        assert (0 <= i);
        if (width <= i) return;
        root = point_delete(root, -1, false, 0, width, i);
    }
    int point_delete(int i, int parent, bool is_right, ll il, ll ir, ll j) {
        if (i == -1) {
            return -1;
        } else if (il == j and ir == j + 1) { // 0-based
            bin.push(i);
            size -= 1;
            return -1;
        } else if (ir <= j or j + 1 <= il) {
            return i;
        } else {
            pool[i].left  = point_delete(pool[i].left,  i, false, il, (il + ir) / 2, j);
            pool[i].right = point_delete(pool[i].right, i, true,  (il + ir) / 2, ir, j);
            if (pool[i].left == -1 and pool[i].right == -1 and i != root) {
                bin.push(i);
                size -= 1;
                return -1;
            } else {
                pool[i].value = mon.append(get_value(pool[i].left), get_value(pool[i].right));
                return i;
            }
        }
    }
    value_type range_concat(ll l, ll r) {
        assert (0 <= l and l <= r);
        if (width <= l) return mon.unit();
        return range_concat(root, 0, width, l, min(width, r));
    }
    value_type range_concat(int i, ll il, ll ir, ll l, ll r) {
        if (i == -1) return mon.unit();
        if (l <= il and ir <= r) { // 0-based
            return pool[i].value;
        } else if (ir <= l or r <= il) {
            return mon.unit();
        } else {
            return mon.append(
                    range_concat(pool[i].left,  il, (il + ir) / 2, l, r),
                    range_concat(pool[i].right, (il + ir) / 2, ir, l, r));
        }
    }
    template <class Func>
    void traverse_leaves(Func func) {
        return traverse_leaves(root, 0, width, func);
    }
    template <class Func>
    void traverse_leaves(ll i, ll il, ll ir, Func func) {
        if (i == -1) return;
        if (ir - il == 1) {
            func(il, pool[i].value);
        } else {
            traverse_leaves(pool[i].left,  il, (il + ir) / 2, func);
            traverse_leaves(pool[i].right, (il + ir) / 2, ir, func);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

