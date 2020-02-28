## 概要

一次関数の集合 $F = \emptyset \subseteq \lbrace \lambda x. ax + b \mid a, b \in \mathbb{Z} \rbrace$ に対し、次が $O(\log N)$ amortized (一部は $O(\log N)$) で処理可能:

-   $\mathtt{add\unicode{95}line}(f)$: $F \gets F \cup \lbrace f \rbrace$ と更新する。
-   $\mathtt{get\unicode{95}min}(x)$: 最小値 $\min _ {f \in F} f(x)$ を計算する。
