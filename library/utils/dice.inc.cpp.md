<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: utils/dice.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
```cpp
struct dice_t { // regular hexahedron group
    //       ______
    //      \      \      4
    //     / \   C  \    2156
    //    / A \______\    3 ^
    //    \ A /    B /   ^^ |
    //     \ /   B  /    ab bottom
    //      v__B___/
    int a, b; // in [1, 6]
    int c() const {
        static const int table[6][6] = {
            { 0, 3, 5, 2, 4, 0 },
            { 4, 0, 1, 6, 0, 3 },
            { 2, 6, 0, 0, 1, 5 },
            { 5, 1, 0, 0, 6, 2 },
            { 3, 0, 6, 1, 0, 4 },
            { 0, 4, 2, 5, 3, 0 },
        };
        assert (table[a-1][b-1] != 0);
        return  table[a-1][b-1];
    }
};
dice_t rotate_up(   dice_t dice) { return (dice_t) { dice.a, 7 - dice.c() }; }
dice_t rotate_right(dice_t dice) { return (dice_t) { 7 - dice.c(), dice.b }; }
dice_t rotate_down( dice_t dice) { return (dice_t) { dice.a, dice.c() }; }
dice_t rotate_left( dice_t dice) { return (dice_t) { dice.c(), dice.b }; }
bool operator == (dice_t x, dice_t y) { return x.a == y.a and x.b == y.b; }

```

[Back to top page](../../index.html)

