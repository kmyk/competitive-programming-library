---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/dice.inc.cpp\"\nstruct dice_t { // regular hexahedron\
    \ group\n    //       ______\n    //      \\      \\      4\n    //     / \\ \
    \  C  \\    2156\n    //    / A \\______\\    3 ^\n    //    \\ A /    B /   ^^\
    \ |\n    //     \\ /   B  /    ab bottom\n    //      v__B___/\n    int a, b;\
    \ // in [1, 6]\n    int c() const {\n        static const int table[6][6] = {\n\
    \            { 0, 3, 5, 2, 4, 0 },\n            { 4, 0, 1, 6, 0, 3 },\n      \
    \      { 2, 6, 0, 0, 1, 5 },\n            { 5, 1, 0, 0, 6, 2 },\n            {\
    \ 3, 0, 6, 1, 0, 4 },\n            { 0, 4, 2, 5, 3, 0 },\n        };\n       \
    \ assert (table[a-1][b-1] != 0);\n        return  table[a-1][b-1];\n    }\n};\n\
    dice_t rotate_up(   dice_t dice) { return (dice_t) { dice.a, 7 - dice.c() }; }\n\
    dice_t rotate_right(dice_t dice) { return (dice_t) { 7 - dice.c(), dice.b }; }\n\
    dice_t rotate_down( dice_t dice) { return (dice_t) { dice.a, dice.c() }; }\ndice_t\
    \ rotate_left( dice_t dice) { return (dice_t) { dice.c(), dice.b }; }\nbool operator\
    \ == (dice_t x, dice_t y) { return x.a == y.a and x.b == y.b; }\n"
  code: "struct dice_t { // regular hexahedron group\n    //       ______\n    //\
    \      \\      \\      4\n    //     / \\   C  \\    2156\n    //    / A \\______\\\
    \    3 ^\n    //    \\ A /    B /   ^^ |\n    //     \\ /   B  /    ab bottom\n\
    \    //      v__B___/\n    int a, b; // in [1, 6]\n    int c() const {\n     \
    \   static const int table[6][6] = {\n            { 0, 3, 5, 2, 4, 0 },\n    \
    \        { 4, 0, 1, 6, 0, 3 },\n            { 2, 6, 0, 0, 1, 5 },\n          \
    \  { 5, 1, 0, 0, 6, 2 },\n            { 3, 0, 6, 1, 0, 4 },\n            { 0,\
    \ 4, 2, 5, 3, 0 },\n        };\n        assert (table[a-1][b-1] != 0);\n     \
    \   return  table[a-1][b-1];\n    }\n};\ndice_t rotate_up(   dice_t dice) { return\
    \ (dice_t) { dice.a, 7 - dice.c() }; }\ndice_t rotate_right(dice_t dice) { return\
    \ (dice_t) { 7 - dice.c(), dice.b }; }\ndice_t rotate_down( dice_t dice) { return\
    \ (dice_t) { dice.a, dice.c() }; }\ndice_t rotate_left( dice_t dice) { return\
    \ (dice_t) { dice.c(), dice.b }; }\nbool operator == (dice_t x, dice_t y) { return\
    \ x.a == y.a and x.b == y.b; }\n"
  dependsOn: []
  isVerificationFile: false
  path: old/dice.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/dice.inc.cpp
layout: document
redirect_from:
- /library/old/dice.inc.cpp
- /library/old/dice.inc.cpp.html
title: old/dice.inc.cpp
---
