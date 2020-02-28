## 概要

monoid $F = (F, \circ, \mathrm{id})$ の要素の列 $f = (f_0, f_1, \dots, f _ {n - 1}) \in F^n$ に対し、次が $O(\log N)$ で処理可能:

-   $\mathtt{range\unicode{95}set}(l, r, g)$: それぞれの $i \in [l, r)$ に対し $f_i \gets g \circ f_i$ と更新する。
-   $\mathtt{point\unicode{95}get}(i)$: 値 $f_i$ を計算する。
