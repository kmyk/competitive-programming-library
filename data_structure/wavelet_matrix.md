## 概要

完備辞書を $K$ 本ならべて $2^K$ 未満の自然数に対応させたような静的データ構造。

## Operations

ある固定された自然数 $K$ と $2^K$ 未満の自然数の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in (2^K)^N$ に対し、次が $O(K)$ で処理可能:

-   $\mathtt{rank}(b, l, r)$: 区間 $\lbrack l, r)$ 中の値 $b$ の出現回数 $$\unicode{35} \lbrace i \in \lbrack l, r) \mid a_i = b \rbrace$$ を計算する。
-   $\mathtt{select}(b, k, l)$: 位置 $l$ 以降で $k \ge 0$ 番目に出現する値 $b$ の位置 $i$ (つまり $i \ge l$ かつ $a_i = b$ かつ $$\unicode{35} \lbrace j \in \lbrack l, i) \mid a_j = b \rbrace = k$$ を満たす $i$) を計算する。
    -   ただし今回の実装では完備辞書側の妥協の結果 $O(K \log N)$ になっている
-   $\mathtt{access}(i)$: 値 $a_i$ を計算する。
-   $\mathtt{quantile}(k, l, r)$: 区間 $\lbrack l, r)$ 内で $k \ge 0$ 番目に小さい要素 $a_i$ (つまり $$\unicode{35} \lbrace j \in \lbrack l, r) \mid (a_j, j) \lt (a_i, i) \rbrace = k$$ を満たす $i$) を計算する。
-   $\mathtt{range\unicode{95}frequency}(l, r, b_l, b_r)$: 区間 $\lbrack l, r)$ 内における $b_l$ 以上 $b_r$ 未満の要素の数 $$\unicode{35} \lbrace i \in \lbrack l, r) \mid a_i \in \lbrack b_l, b_r) \rbrace$$ を計算する。
