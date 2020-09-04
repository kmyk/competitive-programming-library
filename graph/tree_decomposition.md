## 説明

ある (根付きではなく) 頂点に集合重みの付いた木 $T = (I, F; X)$ が無向グラフ $G = (V, E)$ の a tree decomposition であるとは、次をすべて満たすことをいう。

1.  頂点 $i \in I$ の重みは $G$ の頂点の部分集合である $X_i \subseteq V$
1.  任意の辺 $(u, v) \in E$ に対し、ある $i \in I$ が存在し、$u \in X_i$ かつ $v \in X_i$ である
1.  任意の頂点 $v \in V$ に対し、頂点の集合 $\lbrace i \in I \mid v \in X_i \rbrace$ は $T$ 上で連結

a tree decomposition $T = (I, F; X)$ の幅とは、その頂点の要素数の最大値 $\max \lbrace \unicode{35} X \mid X \in I \rbrace$ のことをいう。
無向グラフの木幅とは、その tree decompositions の幅の最大値のことをいう。

木幅 $t = 2$ が分かっていれば、a tree decomposition は次を再帰的に行うことで構成できる。

1.  次数 $2$ 以下の頂点 $v$ を好きに選ぶ。
1.  頂点 $v$ および頂点 $v$ に接続する辺をすべて取り除き (もしあれば) $v$ に隣接していた頂点間に辺を付け加えてできるグラフ $G'$ を考える。
1.  $G'$ に対する a tree decomposition $T$ を求める。
1.  (2.) で取り除いた辺に含まれる頂点を重み $X_i$ とするような頂点 $i$ を $T$ に追加し、$v$ に隣接していた頂点すべてを重みとして含むような頂点の子とする。

頂点に集合重みの付いた根付き木 $T = (I, F; i, X)$ が nice であるとは、おおまかには次のようにして帰納的に定められる。

1.  (leaf): 頂点数 $1$ でその唯一の頂点 $i$ の重みの要素数 $\unicode{35} X_i$ が $1$ な根付き木は nice である
1.  (introduce): nice な根付き木の根 $i$ の上に $X _ {i'} = X_i \cup \lbrace y \rbrace$ な新しい根を付け加えてできる根付き木は nice である
1.  (forget): nice な根付き木の根 $i$ の上に $X _ {i'} = X_i \setminus \lbrace y \rbrace$ な新しい根を付け加えてできる根付き木は nice である
1.  (join): nice なふたつの根付き木であって根 $i_1, i_2$ の重みが等しいものの上に $X _ i = X _ {i_1} = X _ {i_2}$ な新しい根を付け加えてできる根付き木は nice である

a tree decomposition であってそれを根付き木として見たとき nice であるものを a nice tree decomposition という。
a nice tree decomposition があるとその構成に沿って動的計画法ができ、その計算量は幅 $t$ に対し $O(2^t V)$ や $O(2^t t^2 V)$ などになる。
