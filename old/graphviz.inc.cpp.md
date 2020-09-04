---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"old/graphviz.inc.cpp\"\nvoid graphviz(vector<vector<int>\
    \ > const & g, bool is_digraph = false, string const & name = \"graph\") {\n \
    \   ofstream ofs(name + \".dot\");\n    ofs << (is_digraph ? \"di\" : \"\") <<\
    \ \"graph graph_name {\" << endl;\n    ofs << \"    graph [ bgcolor = \\\"#00000000\\\
    \" ]\" << endl;\n    ofs << \"    node [ shape = circle, style = filled, fillcolor\
    \ = \\\"#ffffffff\\\" ]\" << endl;\n    REP (i, g.size()) for (int j : g[i]) if\
    \ (is_digraph or i <= j) ofs << \"    \" << i << (is_digraph ? \" -> \" : \" --\
    \ \") << j << endl;\n    ofs << \"}\" << endl;\n    ofs.close();\n    system((\"\
    dot -T png \" + name + \".dot > \" + name + \".png\").c_str());\n}\n"
  code: "void graphviz(vector<vector<int> > const & g, bool is_digraph = false, string\
    \ const & name = \"graph\") {\n    ofstream ofs(name + \".dot\");\n    ofs <<\
    \ (is_digraph ? \"di\" : \"\") << \"graph graph_name {\" << endl;\n    ofs <<\
    \ \"    graph [ bgcolor = \\\"#00000000\\\" ]\" << endl;\n    ofs << \"    node\
    \ [ shape = circle, style = filled, fillcolor = \\\"#ffffffff\\\" ]\" << endl;\n\
    \    REP (i, g.size()) for (int j : g[i]) if (is_digraph or i <= j) ofs << \"\
    \    \" << i << (is_digraph ? \" -> \" : \" -- \") << j << endl;\n    ofs << \"\
    }\" << endl;\n    ofs.close();\n    system((\"dot -T png \" + name + \".dot >\
    \ \" + name + \".png\").c_str());\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: old/graphviz.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: old/graphviz.inc.cpp
layout: document
redirect_from:
- /library/old/graphviz.inc.cpp
- /library/old/graphviz.inc.cpp.html
title: old/graphviz.inc.cpp
---
