---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://optlab.mcmaster.ca/feng/4O03/Two.Phase.Simplex.pdf
    - http://zeus.mech.kyushu-u.ac.jp/~tsuji/java_edu/Simplex_st.html
  bundledCode: "#line 1 \"old/simplex.inc.cpp\"\n\n\nvector<double> debug_c;\nvoid\
    \ linsolve_tableau(vector<double> & z, vector<vector<double> > & tableau, vector<double>\
    \ & k, vector<int> & ix) {\n    constexpr double eps = 1e-8;\n    vector<vector<double\
    \ > > & m = tableau;\n    int h = k.size();\n    int w = z.size();\n    while\
    \ (true) {\ndouble value = 0;\nrepeat (y, h) if (ix[y] < debug_c.size()) {\n \
    \   value += debug_c[ix[y]] * k[y];\n}\nfprintf(stderr, \"value %lf\\n\", value);\n\
    fprintf(stderr, \"  z : \");\nrepeat (x, w) {\nfprintf(stderr, \"%6.2lf \", z[x]);\n\
    }\nfprintf(stderr, \"\\n\");\nrepeat (y, h) {\nfprintf(stderr, \"%3d : \", ix[y]);\n\
    repeat (x, w) {\nfprintf(stderr, \"%6.2lf \", m[y][x]);\n}\nfprintf(stderr, \"\
    %6.2lf\\n\", k[y]);\n}\nfprintf(stderr, \"\\n\");\n        // select column\n\
    \        int x = min_element(whole(z)) - z.begin();\n        if (z[x] > - eps)\
    \ break;\n        // select row\n        vector<double> delta(h, INFINITY);\n\
    \        repeat (y, h) if (m[y][x] > + eps) {\n            delta[y] = k[y] / m[y][x];\n\
    \        }\n        int y = min_element(whole(delta)) - delta.begin();\n     \
    \   if (isinf(delta[y])) break;\nfprintf(stderr, \"pivot x = %d (%lf) ; y = %d\
    \ (%lf / %lf = %lf)\\n\", x, z[x], y, k[y], m[y][x], delta[y]);\n        // eliminate\n\
    \        ix[y] = x;\n        double m_y_x = m[y][x];\n        repeat (j, w) {\n\
    \            m[y][j] /= m_y_x;\n        }\n        k[y] /= m_y_x;\n        double\
    \ z_x = z[x];\n        repeat (j, w) {\n            z[j] -= z_x * m[y][j];\n \
    \       }\n        repeat (i, h) if (i != y) {\n            double m_i_x = m[i][x];\n\
    \            repeat (j, w) {\n                m[i][j] -= m_i_x * m[y][j];\n  \
    \          }\n            k[i] -= m_i_x * k[y];\n        }\n    }\n}\n\n/*\n *\
    \ max : c^T x\n * sub.to. : Ax <= b\n *            x >= 0\n */\nvector<double>\
    \ linsolve(vector<vector<double> > const & a, vector<double> const & b, vector<double>\
    \ const & c) {\ndebug_c = c;\n    // prepare\n    constexpr double eps = 1e-8;\n\
    \    int h = b.size();\n    int w = c.size();\n    // make tableau\n    int artificial\
    \ = 0;\n    vector<vector<double> > tableau(h, vector<double>(w + h));  // the\
    \ tableau\n    vector<double> k = b;\n    repeat (y, h) {\n        if (b[y] >=\
    \ 0) {\n            copy(whole(a[y]), tableau[y].begin());\n            tableau[y][w\
    \ + y] = 1;  // slack variable\n        } else {\n            repeat (x, w) {\n\
    \                tableau[y][x] = - a[y][x];\n            }\n            tableau[y][w\
    \ + y] = -1;  // surplus variable\n            k[y] *= -1;\n            artificial\
    \ += 1;\n        }\n    }\n    vector<int> ix(h);  // labels of rows\n    iota(whole(ix),\
    \ w);\n    // two-phase method\n    if (artificial) {\nfprintf(stderr, \"artificial\
    \ %d\\n\", artificial);\n        vector<double> z(w + h + artificial);  // target\
    \ function\n        int var = 0;\n        repeat (y, h) {\n            tableau[y].resize(w\
    \ + h + artificial);\n            if (b[y] < 0) {\n                tableau[y][w\
    \ + h + var] = 1;\n                repeat (x, w + h) {\n                    z[x]\
    \ -= tableau[y][x];\n                }\n                ix[y] = w + h + var;\n\
    \                ++ var;\n            }\n        }\n        linsolve_tableau(z,\
    \ tableau, k, ix);\n        repeat (y, h) {\n            assert (ix[y] < w + h);\n\
    \            tableau[y].resize(w + h);\n        }\n    }\n    // solve\n    vector<double>\
    \ z(w + h);  // target function\n    repeat (x, w) z[x] = - c[x];\n    if (artificial)\
    \ {\n        repeat (y, h) {\n            int x = ix[y];\n            int z_x\
    \ = z[x];\n            if (z_x) {\n                repeat (j, w + h) {\n     \
    \               z[j] -= z_x * tableau[y][j];\n                }\n            }\n\
    \        }\n    }\n    linsolve_tableau(z, tableau, k, ix);\n    // finalize\n\
    \    vector<double> result(w + h);\n    repeat (y, h) {\n        result[ix[y]]\
    \ = k[y];\n    }\n    return result;\n}\n\n\n\nunittest {\n    // http://zeus.mech.kyushu-u.ac.jp/~tsuji/java_edu/Simplex_st.html\n\
    \    vector<vector<double> > a {\n        { 1, 2 },\n        { 1, 1 },\n     \
    \   { 3, 1 },\n    };\n    vector<double> b {\n        14,\n        8,\n     \
    \   18,\n    };\n    vector<double> c {\n        2, 3,\n    };\n    vector<double>\
    \ x = linsolve(a, b, c);\n    constexpr double eps = 1e-8;\n    assert (abs(x[0]\
    \ - 2) < eps);\n    assert (abs(x[1] - 6) < eps);\n}\n\nunittest {\n    vector<vector<double>\
    \ > a {\n        { -2, -1 },\n        { -1, -1 },\n        { -1, -2 },\n    };\n\
    \    vector<double> b {\n        -8,\n        -6,\n        -8,\n    };\n    vector<double>\
    \ c {\n        -4, -3,\n    };\n    vector<double> x = linsolve(a, b, c);\n  \
    \  fprintf(stderr, \"%lf\\n\", x[0]);\n    fprintf(stderr, \"%lf\\n\", x[1]);\n\
    \    constexpr double eps = 1e-8;\n    repeat (y, 3) {\n        assert (a[y][0]\
    \ * x[0] + a[y][1] * x[1] < b[y] + eps);\n    }\n    assert (abs(x[0] - 2) < eps);\n\
    \    assert (abs(x[1] - 4) < eps);\n}\n\nunittest {\n    // http://optlab.mcmaster.ca/feng/4O03/Two.Phase.Simplex.pdf\n\
    \    vector<vector<double> > a {\n        { 1, 1, 1 },\n        { -2, -1, 1 },\n\
    \        { 0, 1, -1 },\n    };\n    vector<double> b {\n        40,\n        -10,\n\
    \        -10,\n    };\n    vector<double> c {\n        2, 3, 1,\n    };\n    vector<double>\
    \ x = linsolve(a, b, c);\n    constexpr double eps = 1e-8;\n    assert (abs(x[0]\
    \ - 10) < eps);\n    assert (abs(x[1] - 10) < eps);\n    assert (abs(x[2] - 20)\
    \ < eps);\n}\n\nunittest {\n    vector<vector<double> > a {\n        { 1, 1, 1\
    \ },\n        { -2, -1, 1 },\n        { 0, 1, -1 },\n    };\n    vector<double>\
    \ b {\n        40,\n        -10,\n        -10,\n    };\n    vector<double> c {\n\
    \        -2, 3, -1,\n    };\n    vector<double> x = linsolve(a, b, c);\n    constexpr\
    \ double eps = 1e-8;\n    fprintf(stderr, \"%lf\\n\", x[0]);\n    fprintf(stderr,\
    \ \"%lf\\n\", x[1]);\n    fprintf(stderr, \"%lf\\n\", x[2]);\n}\n\n\nvector<double>\
    \ linsolve_glpk(vector<vector<double> > const & a, vector<double> const & b, vector<double>\
    \ const & c) {\n    int preserved_term_out = glp_term_out(GLP_OFF);\n    int h\
    \ = b.size();\n    int w = c.size();\n    glp_prob *lp = glp_create_prob();\n\
    \    glp_set_obj_dir(lp, GLP_MAX);\n    glp_add_cols(lp, w);\n    repeat (x, w)\
    \ {\n        glp_set_col_bnds(lp, x + 1, GLP_LO, 0, INFINITY); // non-negative\n\
    \        glp_set_obj_coef(lp, x + 1, c[x]);\n    }\n    glp_add_rows(lp, h);\n\
    \    repeat (y, h) {\n        glp_set_row_bnds(lp, y + 1, GLP_UP, - INFINITY,\
    \ b[y]);\n    }\n    vector<int> ia, ja;\n    vector<double> ar;\n    ia.push_back(0);\n\
    \    ja.push_back(0);\n    ar.push_back(0);  // dummy for 1-based\n    constexpr\
    \ double eps = 1e-8;\n    repeat (y, h) repeat (x, w) {\n        if (abs(a[y][x])\
    \ > eps) {\n            ia.push_back(y + 1);\n            ja.push_back(x + 1);\n\
    \            ar.push_back(a[y][x]);\n        }\n    }\n    glp_load_matrix(lp,\
    \ ar.size() - 1, ia.data(), ja.data(), ar.data());\n    glp_simplex(lp, NULL);\n\
    \    assert (glp_get_status(lp) == GLP_OPT);\n    vector<double> result(w);\n\
    \    repeat (x, w) {\n        result[x] = glp_get_col_prim(lp, x + 1);\n    }\n\
    \    glp_delete_prob(lp);\n    glp_free_env();\n    glp_term_out(preserved_term_out);\n\
    \    return result;\n}\n"
  code: "\n\nvector<double> debug_c;\nvoid linsolve_tableau(vector<double> & z, vector<vector<double>\
    \ > & tableau, vector<double> & k, vector<int> & ix) {\n    constexpr double eps\
    \ = 1e-8;\n    vector<vector<double > > & m = tableau;\n    int h = k.size();\n\
    \    int w = z.size();\n    while (true) {\ndouble value = 0;\nrepeat (y, h) if\
    \ (ix[y] < debug_c.size()) {\n    value += debug_c[ix[y]] * k[y];\n}\nfprintf(stderr,\
    \ \"value %lf\\n\", value);\nfprintf(stderr, \"  z : \");\nrepeat (x, w) {\nfprintf(stderr,\
    \ \"%6.2lf \", z[x]);\n}\nfprintf(stderr, \"\\n\");\nrepeat (y, h) {\nfprintf(stderr,\
    \ \"%3d : \", ix[y]);\nrepeat (x, w) {\nfprintf(stderr, \"%6.2lf \", m[y][x]);\n\
    }\nfprintf(stderr, \"%6.2lf\\n\", k[y]);\n}\nfprintf(stderr, \"\\n\");\n     \
    \   // select column\n        int x = min_element(whole(z)) - z.begin();\n   \
    \     if (z[x] > - eps) break;\n        // select row\n        vector<double>\
    \ delta(h, INFINITY);\n        repeat (y, h) if (m[y][x] > + eps) {\n        \
    \    delta[y] = k[y] / m[y][x];\n        }\n        int y = min_element(whole(delta))\
    \ - delta.begin();\n        if (isinf(delta[y])) break;\nfprintf(stderr, \"pivot\
    \ x = %d (%lf) ; y = %d (%lf / %lf = %lf)\\n\", x, z[x], y, k[y], m[y][x], delta[y]);\n\
    \        // eliminate\n        ix[y] = x;\n        double m_y_x = m[y][x];\n \
    \       repeat (j, w) {\n            m[y][j] /= m_y_x;\n        }\n        k[y]\
    \ /= m_y_x;\n        double z_x = z[x];\n        repeat (j, w) {\n           \
    \ z[j] -= z_x * m[y][j];\n        }\n        repeat (i, h) if (i != y) {\n   \
    \         double m_i_x = m[i][x];\n            repeat (j, w) {\n             \
    \   m[i][j] -= m_i_x * m[y][j];\n            }\n            k[i] -= m_i_x * k[y];\n\
    \        }\n    }\n}\n\n/*\n * max : c^T x\n * sub.to. : Ax <= b\n *         \
    \   x >= 0\n */\nvector<double> linsolve(vector<vector<double> > const & a, vector<double>\
    \ const & b, vector<double> const & c) {\ndebug_c = c;\n    // prepare\n    constexpr\
    \ double eps = 1e-8;\n    int h = b.size();\n    int w = c.size();\n    // make\
    \ tableau\n    int artificial = 0;\n    vector<vector<double> > tableau(h, vector<double>(w\
    \ + h));  // the tableau\n    vector<double> k = b;\n    repeat (y, h) {\n   \
    \     if (b[y] >= 0) {\n            copy(whole(a[y]), tableau[y].begin());\n \
    \           tableau[y][w + y] = 1;  // slack variable\n        } else {\n    \
    \        repeat (x, w) {\n                tableau[y][x] = - a[y][x];\n       \
    \     }\n            tableau[y][w + y] = -1;  // surplus variable\n          \
    \  k[y] *= -1;\n            artificial += 1;\n        }\n    }\n    vector<int>\
    \ ix(h);  // labels of rows\n    iota(whole(ix), w);\n    // two-phase method\n\
    \    if (artificial) {\nfprintf(stderr, \"artificial %d\\n\", artificial);\n \
    \       vector<double> z(w + h + artificial);  // target function\n        int\
    \ var = 0;\n        repeat (y, h) {\n            tableau[y].resize(w + h + artificial);\n\
    \            if (b[y] < 0) {\n                tableau[y][w + h + var] = 1;\n \
    \               repeat (x, w + h) {\n                    z[x] -= tableau[y][x];\n\
    \                }\n                ix[y] = w + h + var;\n                ++ var;\n\
    \            }\n        }\n        linsolve_tableau(z, tableau, k, ix);\n    \
    \    repeat (y, h) {\n            assert (ix[y] < w + h);\n            tableau[y].resize(w\
    \ + h);\n        }\n    }\n    // solve\n    vector<double> z(w + h);  // target\
    \ function\n    repeat (x, w) z[x] = - c[x];\n    if (artificial) {\n        repeat\
    \ (y, h) {\n            int x = ix[y];\n            int z_x = z[x];\n        \
    \    if (z_x) {\n                repeat (j, w + h) {\n                    z[j]\
    \ -= z_x * tableau[y][j];\n                }\n            }\n        }\n    }\n\
    \    linsolve_tableau(z, tableau, k, ix);\n    // finalize\n    vector<double>\
    \ result(w + h);\n    repeat (y, h) {\n        result[ix[y]] = k[y];\n    }\n\
    \    return result;\n}\n\n\n\nunittest {\n    // http://zeus.mech.kyushu-u.ac.jp/~tsuji/java_edu/Simplex_st.html\n\
    \    vector<vector<double> > a {\n        { 1, 2 },\n        { 1, 1 },\n     \
    \   { 3, 1 },\n    };\n    vector<double> b {\n        14,\n        8,\n     \
    \   18,\n    };\n    vector<double> c {\n        2, 3,\n    };\n    vector<double>\
    \ x = linsolve(a, b, c);\n    constexpr double eps = 1e-8;\n    assert (abs(x[0]\
    \ - 2) < eps);\n    assert (abs(x[1] - 6) < eps);\n}\n\nunittest {\n    vector<vector<double>\
    \ > a {\n        { -2, -1 },\n        { -1, -1 },\n        { -1, -2 },\n    };\n\
    \    vector<double> b {\n        -8,\n        -6,\n        -8,\n    };\n    vector<double>\
    \ c {\n        -4, -3,\n    };\n    vector<double> x = linsolve(a, b, c);\n  \
    \  fprintf(stderr, \"%lf\\n\", x[0]);\n    fprintf(stderr, \"%lf\\n\", x[1]);\n\
    \    constexpr double eps = 1e-8;\n    repeat (y, 3) {\n        assert (a[y][0]\
    \ * x[0] + a[y][1] * x[1] < b[y] + eps);\n    }\n    assert (abs(x[0] - 2) < eps);\n\
    \    assert (abs(x[1] - 4) < eps);\n}\n\nunittest {\n    // http://optlab.mcmaster.ca/feng/4O03/Two.Phase.Simplex.pdf\n\
    \    vector<vector<double> > a {\n        { 1, 1, 1 },\n        { -2, -1, 1 },\n\
    \        { 0, 1, -1 },\n    };\n    vector<double> b {\n        40,\n        -10,\n\
    \        -10,\n    };\n    vector<double> c {\n        2, 3, 1,\n    };\n    vector<double>\
    \ x = linsolve(a, b, c);\n    constexpr double eps = 1e-8;\n    assert (abs(x[0]\
    \ - 10) < eps);\n    assert (abs(x[1] - 10) < eps);\n    assert (abs(x[2] - 20)\
    \ < eps);\n}\n\nunittest {\n    vector<vector<double> > a {\n        { 1, 1, 1\
    \ },\n        { -2, -1, 1 },\n        { 0, 1, -1 },\n    };\n    vector<double>\
    \ b {\n        40,\n        -10,\n        -10,\n    };\n    vector<double> c {\n\
    \        -2, 3, -1,\n    };\n    vector<double> x = linsolve(a, b, c);\n    constexpr\
    \ double eps = 1e-8;\n    fprintf(stderr, \"%lf\\n\", x[0]);\n    fprintf(stderr,\
    \ \"%lf\\n\", x[1]);\n    fprintf(stderr, \"%lf\\n\", x[2]);\n}\n\n\nvector<double>\
    \ linsolve_glpk(vector<vector<double> > const & a, vector<double> const & b, vector<double>\
    \ const & c) {\n    int preserved_term_out = glp_term_out(GLP_OFF);\n    int h\
    \ = b.size();\n    int w = c.size();\n    glp_prob *lp = glp_create_prob();\n\
    \    glp_set_obj_dir(lp, GLP_MAX);\n    glp_add_cols(lp, w);\n    repeat (x, w)\
    \ {\n        glp_set_col_bnds(lp, x + 1, GLP_LO, 0, INFINITY); // non-negative\n\
    \        glp_set_obj_coef(lp, x + 1, c[x]);\n    }\n    glp_add_rows(lp, h);\n\
    \    repeat (y, h) {\n        glp_set_row_bnds(lp, y + 1, GLP_UP, - INFINITY,\
    \ b[y]);\n    }\n    vector<int> ia, ja;\n    vector<double> ar;\n    ia.push_back(0);\n\
    \    ja.push_back(0);\n    ar.push_back(0);  // dummy for 1-based\n    constexpr\
    \ double eps = 1e-8;\n    repeat (y, h) repeat (x, w) {\n        if (abs(a[y][x])\
    \ > eps) {\n            ia.push_back(y + 1);\n            ja.push_back(x + 1);\n\
    \            ar.push_back(a[y][x]);\n        }\n    }\n    glp_load_matrix(lp,\
    \ ar.size() - 1, ia.data(), ja.data(), ar.data());\n    glp_simplex(lp, NULL);\n\
    \    assert (glp_get_status(lp) == GLP_OPT);\n    vector<double> result(w);\n\
    \    repeat (x, w) {\n        result[x] = glp_get_col_prim(lp, x + 1);\n    }\n\
    \    glp_delete_prob(lp);\n    glp_free_env();\n    glp_term_out(preserved_term_out);\n\
    \    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/simplex.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/simplex.inc.cpp
layout: document
redirect_from:
- /library/old/simplex.inc.cpp
- /library/old/simplex.inc.cpp.html
title: old/simplex.inc.cpp
---
