#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <optional>
#include <tuple>
#include <vector>
#include "../data_structure/union_find_tree_foldable_undoable.hpp"
#include "../data_structure/reporting_segment_tree.hpp"
#include "../utils/macros.hpp"

/**
 * @brief Dynamic Connectivity (offline, commutative monoids)
 * @docs data_structure/dynamic_connectivity_offline.md
 */
template <class CommutativeMonoid>
class dynamic_connectivity_offline {
    typedef typename CommutativeMonoid::value_type value_type;
    enum query_tag {
        LINK,
        ADD,
    };
    struct query_type {
        query_tag tag;
        int l, r;
        int a;
        int64_t b;
    };

    const CommutativeMonoid mon;
    int size;
    int time;
    std::vector<query_type> set_queries;
    std::vector<std::pair<int, int> > get_queries;
    std::map<std::pair<int, int>, int> current_edges;
    std::vector<std::vector<std::pair<int, value_type> > > current_values;

    void flush_time() {
        if (not get_queries.empty() and get_queries.back().first == time) {
            ++ time;
        }
    }

public:
    /**
     * @arg size is the number of vertices
     */
    dynamic_connectivity_offline(int size_, const CommutativeMonoid & mon_ = CommutativeMonoid())
            : mon(mon_) {
        size = size_;
        time = 0;
        current_values.resize(size);
    }
    void link(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (not current_edges.count(edge));
        current_edges[edge] = time;
    }
    void cut(int x, int y) {
        flush_time();
        auto edge = std::minmax({ x, y });
        assert (current_edges.count(edge));
        set_queries.emplace_back((query_type) {
            LINK,
            current_edges[edge],
            time,
            edge.first,
            edge.second,
        });
        current_edges.erase(edge);
    }
    void point_set(int x, value_type value) {
        flush_time();
        while (not current_values[x].empty()) {
            auto [l, value_] = current_values[x].back();
            current_values[x].pop_back();
            set_queries.emplace_back((query_type) {
                ADD,
                l,
                time,
                x,
                value_,
            });
        }
        current_values[x].emplace_back(time, value);
    }
    void point_mult(int x, value_type value) {
        flush_time();
        current_values[x].emplace_back(time, value);
    }
    void component_get(int x) {
        get_queries.emplace_back(time, x);
    }

    /**
     * @note $O(Q \log Q)$
     */
    std::vector<value_type> run() {
        std::vector<value_type> results;
        auto it = get_queries.begin();

        // close half-open queries
        int current_size = set_queries.size();
        for (auto [edge, l] : current_edges) {
            set_queries.emplace_back((query_type) {
                LINK,
                l,
                time + 1,
                edge.first,
                edge.second,
            });
        }
        REP (x, size) {
            for (auto [l, value] : current_values[x]) {
                set_queries.emplace_back((query_type) {
                    ADD,
                    l,
                    time + 1,
                    x,
                    value,
                });
            }
        }

        // prepare undoable union-find tree
        union_find_tree_foldable_undoable<CommutativeMonoid> uft(size, mon);
        auto add = [&](int i) {
            auto & q = set_queries[i];
            if (q.tag == LINK) {
                uft.unite_trees(q.a, q.b);
            } else if (q.tag == ADD) {
                uft.tree_set(q.a, mon.mult(uft.tree_get(q.a), q.b));
            } else {
                assert (false);
            }
        };
        auto remove = [&](int i) {
            uft.undo();
        };
        auto report = [&](int t) {
            for (; it != get_queries.end() and it->first == t; ++ it) {
                int x = it->second;
                results.push_back(uft.tree_get(x));
            }
        };

        // use segment trees on time-axis for queries
        reporting_segment_tree<int> segtree(time + 1);
        REP (i, set_queries.size()) {
            auto & q = set_queries[i];
            segtree.add_segment(q.l, q.r, i);
        }
        segtree.traverse_segments(add, remove, report);

        // re-open closed queries
        set_queries.resize(current_size);

        assert (it == get_queries.end());
        return results;
    }
};
