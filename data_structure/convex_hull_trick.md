## 概要

一次関数の集合 $F = \emptyset \subseteq \lbrace \lambda x. ax + b \mid a, b \in \mathbb{Z} \rbrace$ に対し、次が処理可能:

-   直線追加: 与えられた $f = \lambda x. ax + b$ に対し $F \gets F \cup \lbrace f \rbrace$ と均し $O(\log N)$ で更新する
-   最小値取得: 与えられた $x$ に対し $\min _ {f \in F} f(x)$ を $O(\log N)$ で計算する
