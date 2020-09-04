## Operations

完全二分木上の遅延伝播セグメント木でできることに加え、$O(\log N)$ で次ができる:

-   $\mathtt{insert}(i, b)$: 列の $i$ 番目の要素の前に要素 $b$ を挿入する。
-   $\mathtt{erase}(i)$: 列の $i$ 番目の要素を削除する。
-   $\mathtt{reverse}(l, r)$: 列の $l, l+1, \dots, r-1$ 番目の要素を反転する。つまり $(a_0, a_1, \dots, a _ {l-1}, a_l, a _ {l+1}, \dots, a _ {r-1}, a_r, a _ {r + 1}, \dots, a _ {N - 1}) \gets (a_0, a_1, \dots, a _ {l-1}, a _ {r-1}, a _ {r-2}, \dots, a_l, a_r, a _ {r + 1}, \dots, a _ {N - 1})$ と更新する。
