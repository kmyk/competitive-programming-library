## Operations

単純無向グラフ $G = (V, E)$ であって頂点 $x \in V$ に可換 monoid $M = (M, +, 0)$ による重み $a_x \in M$ が付いたものに対し、次のクエリが offline で全体で $O(Q \log Q)$ で処理可能:

-   $\mathtt{link}(x, y)$: 頂点 $x, y$ 間に辺 $\lbrace x, y \rbrace$ を追加する。
-   $\mathtt{cut}(x, y)$: 頂点 $x, y$ 間から辺 $\lbrace x, y \rbrace$ を削除する。
-   $\mathtt{point\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{point\unicode{95}mult}(x, b)$: 頂点 $x$ の重みを $a_x \gets a_x + b$ と更新する。
-   $\mathtt{component\unicode{95}get}(x)$: 頂点 $x$ と同じ連結成分 $C \subseteq V$ に所属する頂点の重みの総和 $\sum _ {x \in C} a_x$ を計算する。

ただし offline であるので、計算結果は最後に $\mathtt{run}()$ を呼ぶことで取得する。
