---
layout: default
---

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


# :warning: utils/simplex.inc.cpp
* category: utils


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp


vector<double> debug_c;
void linsolve_tableau(vector<double> & z, vector<vector<double> > & tableau, vector<double> & k, vector<int> & ix) {
    constexpr double eps = 1e-8;
    vector<vector<double > > & m = tableau;
    int h = k.size();
    int w = z.size();
    while (true) {
double value = 0;
repeat (y, h) if (ix[y] < debug_c.size()) {
    value += debug_c[ix[y]] * k[y];
}
fprintf(stderr, "value %lf\n", value);
fprintf(stderr, "  z : ");
repeat (x, w) {
fprintf(stderr, "%6.2lf ", z[x]);
}
fprintf(stderr, "\n");
repeat (y, h) {
fprintf(stderr, "%3d : ", ix[y]);
repeat (x, w) {
fprintf(stderr, "%6.2lf ", m[y][x]);
}
fprintf(stderr, "%6.2lf\n", k[y]);
}
fprintf(stderr, "\n");
        // select column
        int x = min_element(whole(z)) - z.begin();
        if (z[x] > - eps) break;
        // select row
        vector<double> delta(h, INFINITY);
        repeat (y, h) if (m[y][x] > + eps) {
            delta[y] = k[y] / m[y][x];
        }
        int y = min_element(whole(delta)) - delta.begin();
        if (isinf(delta[y])) break;
fprintf(stderr, "pivot x = %d (%lf) ; y = %d (%lf / %lf = %lf)\n", x, z[x], y, k[y], m[y][x], delta[y]);
        // eliminate
        ix[y] = x;
        double m_y_x = m[y][x];
        repeat (j, w) {
            m[y][j] /= m_y_x;
        }
        k[y] /= m_y_x;
        double z_x = z[x];
        repeat (j, w) {
            z[j] -= z_x * m[y][j];
        }
        repeat (i, h) if (i != y) {
            double m_i_x = m[i][x];
            repeat (j, w) {
                m[i][j] -= m_i_x * m[y][j];
            }
            k[i] -= m_i_x * k[y];
        }
    }
}

/*
 * max : c^T x
 * sub.to. : Ax <= b
 *            x >= 0
 */
vector<double> linsolve(vector<vector<double> > const & a, vector<double> const & b, vector<double> const & c) {
debug_c = c;
    // prepare
    constexpr double eps = 1e-8;
    int h = b.size();
    int w = c.size();
    // make tableau
    int artificial = 0;
    vector<vector<double> > tableau(h, vector<double>(w + h));  // the tableau
    vector<double> k = b;
    repeat (y, h) {
        if (b[y] >= 0) {
            copy(whole(a[y]), tableau[y].begin());
            tableau[y][w + y] = 1;  // slack variable
        } else {
            repeat (x, w) {
                tableau[y][x] = - a[y][x];
            }
            tableau[y][w + y] = -1;  // surplus variable
            k[y] *= -1;
            artificial += 1;
        }
    }
    vector<int> ix(h);  // labels of rows
    iota(whole(ix), w);
    // two-phase method
    if (artificial) {
fprintf(stderr, "artificial %d\n", artificial);
        vector<double> z(w + h + artificial);  // target function
        int var = 0;
        repeat (y, h) {
            tableau[y].resize(w + h + artificial);
            if (b[y] < 0) {
                tableau[y][w + h + var] = 1;
                repeat (x, w + h) {
                    z[x] -= tableau[y][x];
                }
                ix[y] = w + h + var;
                ++ var;
            }
        }
        linsolve_tableau(z, tableau, k, ix);
        repeat (y, h) {
            assert (ix[y] < w + h);
            tableau[y].resize(w + h);
        }
    }
    // solve
    vector<double> z(w + h);  // target function
    repeat (x, w) z[x] = - c[x];
    if (artificial) {
        repeat (y, h) {
            int x = ix[y];
            int z_x = z[x];
            if (z_x) {
                repeat (j, w + h) {
                    z[j] -= z_x * tableau[y][j];
                }
            }
        }
    }
    linsolve_tableau(z, tableau, k, ix);
    // finalize
    vector<double> result(w + h);
    repeat (y, h) {
        result[ix[y]] = k[y];
    }
    return result;
}



unittest {
    // http://zeus.mech.kyushu-u.ac.jp/~tsuji/java_edu/Simplex_st.html
    vector<vector<double> > a {
        { 1, 2 },
        { 1, 1 },
        { 3, 1 },
    };
    vector<double> b {
        14,
        8,
        18,
    };
    vector<double> c {
        2, 3,
    };
    vector<double> x = linsolve(a, b, c);
    constexpr double eps = 1e-8;
    assert (abs(x[0] - 2) < eps);
    assert (abs(x[1] - 6) < eps);
}

unittest {
    vector<vector<double> > a {
        { -2, -1 },
        { -1, -1 },
        { -1, -2 },
    };
    vector<double> b {
        -8,
        -6,
        -8,
    };
    vector<double> c {
        -4, -3,
    };
    vector<double> x = linsolve(a, b, c);
    fprintf(stderr, "%lf\n", x[0]);
    fprintf(stderr, "%lf\n", x[1]);
    constexpr double eps = 1e-8;
    repeat (y, 3) {
        assert (a[y][0] * x[0] + a[y][1] * x[1] < b[y] + eps);
    }
    assert (abs(x[0] - 2) < eps);
    assert (abs(x[1] - 4) < eps);
}

unittest {
    // http://optlab.mcmaster.ca/feng/4O03/Two.Phase.Simplex.pdf
    vector<vector<double> > a {
        { 1, 1, 1 },
        { -2, -1, 1 },
        { 0, 1, -1 },
    };
    vector<double> b {
        40,
        -10,
        -10,
    };
    vector<double> c {
        2, 3, 1,
    };
    vector<double> x = linsolve(a, b, c);
    constexpr double eps = 1e-8;
    assert (abs(x[0] - 10) < eps);
    assert (abs(x[1] - 10) < eps);
    assert (abs(x[2] - 20) < eps);
}

unittest {
    vector<vector<double> > a {
        { 1, 1, 1 },
        { -2, -1, 1 },
        { 0, 1, -1 },
    };
    vector<double> b {
        40,
        -10,
        -10,
    };
    vector<double> c {
        -2, 3, -1,
    };
    vector<double> x = linsolve(a, b, c);
    constexpr double eps = 1e-8;
    fprintf(stderr, "%lf\n", x[0]);
    fprintf(stderr, "%lf\n", x[1]);
    fprintf(stderr, "%lf\n", x[2]);
}


vector<double> linsolve_glpk(vector<vector<double> > const & a, vector<double> const & b, vector<double> const & c) {
    int preserved_term_out = glp_term_out(GLP_OFF);
    int h = b.size();
    int w = c.size();
    glp_prob *lp = glp_create_prob();
    glp_set_obj_dir(lp, GLP_MAX);
    glp_add_cols(lp, w);
    repeat (x, w) {
        glp_set_col_bnds(lp, x + 1, GLP_LO, 0, INFINITY); // non-negative
        glp_set_obj_coef(lp, x + 1, c[x]);
    }
    glp_add_rows(lp, h);
    repeat (y, h) {
        glp_set_row_bnds(lp, y + 1, GLP_UP, - INFINITY, b[y]);
    }
    vector<int> ia, ja;
    vector<double> ar;
    ia.push_back(0);
    ja.push_back(0);
    ar.push_back(0);  // dummy for 1-based
    constexpr double eps = 1e-8;
    repeat (y, h) repeat (x, w) {
        if (abs(a[y][x]) > eps) {
            ia.push_back(y + 1);
            ja.push_back(x + 1);
            ar.push_back(a[y][x]);
        }
    }
    glp_load_matrix(lp, ar.size() - 1, ia.data(), ja.data(), ar.data());
    glp_simplex(lp, NULL);
    assert (glp_get_status(lp) == GLP_OPT);
    vector<double> result(w);
    repeat (x, w) {
        result[x] = glp_get_col_prim(lp, x + 1);
    }
    glp_delete_prob(lp);
    glp_free_env();
    glp_term_out(preserved_term_out);
    return result;
}

```
{% endraw %}

[Back to top page](../../index.html)

