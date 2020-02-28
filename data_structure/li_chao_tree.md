## 概要

ありえる座標の有限集合 $X \subseteq \mathbb{Z}$ が固定されているとする。
一次関数と区間の対の集合 $F = \emptyset \subseteq \lbrace \lbrack l, r) \mid l, r \in X \wedge l \le r \rbrace \times \lbrace \lambda x. ax + b \mid a, b \in \mathbb{Z} \rbrace$ に対し、次が $O(\log N)$ amortized (一部は $O(\log N)$) で処理可能:

-   $\mathtt{add\unicode{95}segment}(l, r, f)$: $l, r \in X$ でなければならない。$F \gets F \cup \lbrace (f, \lbrack l, r) \rbrace$ と更新する。
-   $\mathtt{get\unicode{95}min}(x)$: $x \in X$ でなければならない。$$\min _ {(f, \lbrack l, r) \in F \wedge x \lbrack l, r))} f(x)$$ を $O(\log N)$ で計算する。
