## 概要

monoid $F = (F, \circ, \mathrm{id})$ の要素の列 $f = (f_0, f_1, \dots, f _ {n - 1}) \in F^n$ に対し、次が処理可能:

-   区間更新: 与えられた $l, r, g$ に対し、それぞれの $i \in [l, r)$ に対し $f_i \gets g \circ f_i$ と $O(\log N)$ で更新する
-   点取得: 与えられた $i$ に対し、値 $f_i$ を $O(\log N)$ で計算する
