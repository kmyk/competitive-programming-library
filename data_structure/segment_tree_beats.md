## 概要

整数 $\mathbb{Z} = (\mathbb{Z}, +, 0, \le)$ の要素の列 $a = (a_0, a_1, \dots, a _ {n - 1}) \in \mathbb{Z}^n$ に対し、次が処理可能:

-   区間 chmin: 与えられた $l, r, b$ に対し、それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets \min(a_i, b)$ という更新をまとめて均し $O((\log N)^2)$ で行う
-   区間 chmax: 与えられた $l, r, b$ に対し、それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets \max(a_i, b)$ という更新をまとめて均し $O((\log N)^2)$ で行う
-   区間加算: 与えられた $l, r, b$ に対し、それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets a_i + b$ という更新をまとめて $O(\log N)$ で行う
-   区間代入: 与えられた $l, r, b$ に対し、それぞれの $i \in \lbrack l, r)$ に対し $a_i \gets b$ という更新をまとめて $O(\log N)$ で行う
-   区間 min: 与えられた $l, r$ に対し、$\min _ {i \in [l, r)} a_i$ を $O(\log N)$ で計算する
-   区間 max: 与えられた $l, r$ に対し、$\max _ {i \in [l, r)} a_i$ を $O(\log N)$ で計算する
-   区間和: 与えられた $l, r$ に対し、$\sum _ {i \in [l, r)} a_i$ を $O(\log N)$ で計算する
