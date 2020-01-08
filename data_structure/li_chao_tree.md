## 概要

定義域を区間に制限された一次関数の集合 $F = \emptyset \subseteq \lbrace \lambda x \in \lbrack l, r). ax + b \mid a, b, l, r \in \mathbb{Z} \rbrace$ に対し、次が処理可能:

-   線分追加: 与えられた $f = \lambda x \lbrack l, r). ax + b$ に対し $F \gets F \cup \lbrace f \rbrace$ と均し $O(\log N)$ で更新する
-   最小値取得: 与えられた $x$ に対し $$\min _ {f \in F \wdge f : \lbrack l, r) \wedge i \in \lbrack l, r)} f(x)$$ を $O(\log N)$ で計算する
