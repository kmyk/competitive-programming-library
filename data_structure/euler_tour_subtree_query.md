## Operations

根付き木 $T$ であってそれぞれの頂点 $x$ に可換 monoid 重み $a_x \in M$ が乗ったものがあるとする。頂点数を $N$ として均し $O(\log N)$ で次が処理できる。

-   $\mathtt{vertex\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{vertex\unicode{95}get}(x)$: 頂点 $x$ の重み $a_x$ を計算する。
-   $\mathtt{subtree\unicode{95}get}(x, y)$: 頂点 $x$ を根とする部分木に属する頂点の重みの総和 $$\sum _ {y ~\text{is a descendent of}~ x} a_y$$ を計算する。
