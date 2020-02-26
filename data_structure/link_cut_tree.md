## Operations

根付き木からなる森 $G$ を動的に操作できる。頂点数を $N$ として均し $O(\log N)$ で次が処理できる。

-   $\mathtt{link}(x, y)$: 根である頂点 $x$ から頂点 $y$ に辺を追加する。
-   $\mathtt{cut}(x)$: 根でない頂点 $x$ とその親との間の辺を削除する。
-   この森における接続性についての様々な質問
    -   $\mathtt{get\unicode{95}parent}(x)$
    -   $\mathtt{get\unicode{95}root}(x)$
    -   $\mathtt{are\unicode{95}connected}(x, y)$
    -   $\mathtt{get\unicode{95}lowest\unicode{95}common\unicode{95}ancestor}(x, y)$
-   $\mathtt{evert}(x)$: 頂点 $x$ を根にする。つまり、頂点 $x$ からその所属する木の根までの辺をすべて反転させる。

加えて、それぞれの頂点 $x$ に monoid 値重み $a_x \in M$ を乗せて、次が処理できる。

-   $\mathtt{point\unicode{95}set}(x, b)$: 頂点 $x$ の重みを $a_x \gets b$ と更新する。
-   $\mathtt{path\unicode{95}get}(x, y)$: 頂点 $x$ から $y$ への唯一のパス $x, z_1, z_2, \dots, y$ に沿った重みの積 $a_x \cdot a _ {z_1} \cdot a _ {z_2} \cdot \dots \cdot a_y$ を計算する。
