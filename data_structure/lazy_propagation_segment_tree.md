## 概要

次があるとする:

-   monoid $M = (M, \cdot, 1)$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in M^n$
-   monoid $F = (F, \circ, \mathrm{id})$ の要素の列 $f = (f_0, f_1, \dots, f _ {n - 1}) \in F^n$
-   monoid $F$ の半群 $M$ に対する作用 $\star$。つまり関数 $\star : F \times M \to M$ であって、次を満たすもの
    -   $\forall a \in M.~ \mathrm{id} \star a = a$
    -   $\forall f, g \in F.~ \forall a \in M.~ (f \circ g) \star a = f \star (g \star a)$
    -   $\forall f \in F.~ \forall a, b \in M.~ f \star (a \cdot b) = (f \star a) \cdot (f \star b)$

このとき、次が処理可能:

-   区間更新: 与えられた $l, r, f$ に対し、それぞれの $i \in [l, r)$ に対し $a_i \gets f \star a_i$ と $O(\log N)$ で更新する
-   区間積: 与えられた $l, r$ に対し、積 $a_l \cdot a _ {l + 1} \cdot \dots \cdot a _ {r - 1}$ を $O(\log N)$ で計算する
