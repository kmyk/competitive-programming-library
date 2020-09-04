## 概要

長さ $N$ の bit 列 $b = (b_0, b_1, \dots, b _ {n - 1}) \in 2^N$ に対し、次が $O(1)$ で処理可能:

-   $\mathtt{rank}(l, r)$: 区間 $\lbrack l, r)$ 中の値 $1$ の出現回数 $$\unicode{35} \lbrace i \in \lbrack l, r) \mid a_i = 1 \rbrace$$ を計算する。
-   $\mathtt{select}(k)$: 位置 $l$ 以降で $k \ge 0$ 番目に出現する値 $1$ の位置 $i$ (つまり $i \ge l$ かつ $a_i = 1$ かつ $$\unicode{35} \lbrace j \in \lbrack l, i) \mid a_j = 1 \rbrace = k$$ を満たす $i$) を計算する。
    -   ただし今回の実装では妥協の結果 $O(\log N)$ になっている
-   $\mathtt{access}(i)$: 値 $b_i$ を計算する。
