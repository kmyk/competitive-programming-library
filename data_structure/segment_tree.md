## 概要

monoid $M = (M, \cdot, 1)$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in M^n$ に対し、次が $O(\log N)$ で処理可能:

-   $\mathtt{point\unicode{95}set}(i, b)$: $a_i \gets b$ と更新する。
-   $\mathtt{range\unicode{95}get}(l, r)$: 積 $a_l \cdot a _ {l + 1} \cdot \dots \cdot a _ {r - 1}$ を計算する。
