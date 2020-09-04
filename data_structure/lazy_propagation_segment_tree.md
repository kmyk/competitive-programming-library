## 概要

次があるとする:

-   monoid $M = (M, \cdot, 1)$
-   monoid $F = (F, \circ, \mathrm{id})$
-   monoid $F$ の半群 $M$ に対する作用 $\star$。つまり関数 $\star : F \times M \to M$ であって、次を満たすもの
    -   $\forall a \in M.~ \mathrm{id} \star a = a$
    -   $\forall f, g \in F.~ \forall a \in M.~ (f \circ g) \star a = f \star (g \star a)$
    -   $\forall f \in F.~ \forall a, b \in M.~ f \star (a \cdot b) = (f \star a) \cdot (f \star b)$

このとき monoid $M$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in M^n$ に対し、次が $O(\log N)$ で処理可能:

-   $\mathtt{range\unicode{95}apply}(l, r, g)$: それぞれの $i \in [l, r)$ に対し $a_i \gets g \star a_i$ と更新する。
-   $\mathtt{range\unicode{95}get}(l, r)$: 積 $a_l \cdot a _ {l + 1} \cdot \dots \cdot a _ {r - 1}$ を計算する。

他にも:

-   $\mathtt{point\unicode{95}get}(i)$: 値 $a_i$ を計算する。
-   $\mathtt{point\unicode{95}set}(i, b)$: $a_i \gets b$ と更新する。
-   $\mathtt{range\unicode{95}set}(l, r, b)$: それぞれの $i \in [l, r)$ に対し $a_i \gets b$ と更新する。
