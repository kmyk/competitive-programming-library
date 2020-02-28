## 概要

整数 $\mathbb{Z} = (\mathbb{Z}, +, 0, \le)$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in \mathbb{Z}^n$ に対し、次が $O((\log N)^2)$ amortized (一部は $O(\log N)$) で処理可能:

-   $\mathtt{range\unicode{95}chmin}(l, r, b)$: それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets \min(a_i, b)$ と更新する。
-   $\mathtt{range\unicode{95}chmax}(l, r, b)$: それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets \max(a_i, b)$ と更新する。
-   $\mathtt{range\unicode{95}add}(l, r, b)$: それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets a_i + b$ と更新する。
-   $\mathtt{range\unicode{95}update}(l, r, b)$: それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets b$ と更新する。
-   $\mathtt{range\unicode{95}min}(l, r)$: $\min _ {i \in [l, r)} a_i$ を計算する。
-   $\mathtt{range\unicode{95}max}(l, r)$: $\max _ {i \in [l, r)} a_i$ を計算する。
-   $\mathtt{range\unicode{95}sum}(l, r)$: $\sum _ {i \in [l, r)} a_i$ を計算する。

他にも:

-   $\mathtt{point\unicode{95}set}(i, b)$: $a_i \gets b$ と更新する。
-   $\mathtt{point\unicode{95}get}(i)$: 値 $a_i$ を計算する。
