#include "graph/subtree.hpp"
#include <cassert>
using namespace std;

int main() {
    vector<vector<int> > g(9);
    const int root = 0;
    g[0].push_back(1);
    g[0].push_back(2);
    ;   g[2].push_back(4);
    ;   g[2].push_back(5);
    ;   g[2].push_back(6);
    ;   ;   g[6].push_back(8);
    g[0].push_back(3);
    ;   g[3].push_back(7);
    auto info = prepare_subtree_info(g, root);
    assert (info[root].parent == -1);
    assert (info[root].depth == 0);
    assert (info[root].size == g.size());
    assert (info[root].height == 3);
    assert (info[1].parent == 0);
    assert (info[1].depth == 1);
    assert (info[1].size == 1);
    assert (info[1].height == 0);
    assert (info[6].parent == 2);
    assert (info[6].depth == 2);
    assert (info[6].size == 2);
    assert (info[6].height == 1);
    return 0;
}
