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
