## 概要

頂点数 $N$ で辺数 $0$ の無向グラフ $G = (V, E)$ に対し、次が $O(\alpha(N))$ amortized (ただし $\alpha$ は Ackermann 関数の逆関数) で処理可能。

-   $\mathtt{unite\unicode{95}trees}(u, v)$: 頂点 $u, v$ 間に辺を追加する。
    -   $u, v$ 間の辺は無向であることに注意
-   $\mathtt{find\unicode{95}root}(v)$: 頂点 $v$ の所属する連結成分の代表元を取得する。
-   $\mathtt{is\unicode{95}same}(u, v)$: 頂点 $u, v$ が同じ連結成分に所属するかを判定する。
-   $\mathtt{tree\unicode{95}size}(v)$: 頂点 $v$ の所属する連結成分の要素数を取得する。
