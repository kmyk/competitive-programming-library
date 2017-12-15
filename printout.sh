#!/bin/bash
{
    cat <<'EOF'
\documentclass[a4paper,10pt,onecolumn,notitlepage]{article}
\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}
\usepackage{setspace}
\usepackage{listings}

\title{my library for ICPC}
EOF
    echo "\\author{$(git config user.name)}"
    cat <<'EOF'
\date{\today}

\lstset{
    language=C++,
    numbers=left,
    breaklines=true,
    basicstyle=\tiny\ttfamily,
}

\begin{document}
\maketitle
\begin{spacing}{0}
    \tableofcontents
\end{spacing}
EOF

    section() {
        name=$(echo $@ | tr _ -)
        echo "\\section{$name}"
    }
    list() {
        name=$(echo $@ | tr _ -)
        file="$@"
        echo "\\subsection{$name}"
        echo "\\lstinputlisting{$file}"
    }

    section misc
    list environment.sh
    list template.cpp

    section data structure
    list data-structure/binary-indexed-tree.inc.cpp
    list data-structure/segment-tree.inc.cpp
    list data-structure/dual-segment-tree.inc.cpp
    list data-structure/lazy-propagation-segment-tree.inc.cpp
    list data-structure/dynamic-segment-tree.inc.cpp
    list data-structure/union-find-tree.inc.cpp
    list data-structure/treap.inc.cpp
    list data-structure/sparse_table.inc.cpp
    list data-structure/sliding-window.inc.cpp

    section graph
    list graph/ford-fulkerson.inc.cpp
    list graph/dinic.inc.cpp
    list graph/minimum-cost-flow.inc.cpp
    list graph/two-edge-connected-components.inc.cpp

    section combinatorics
    list combinatorics/powmod.inc.cpp
    list combinatorics/extgcd.inc.cpp

    section number
    list number/gcd.inc.cpp
    list number/primes.inc.cpp

    section string
    list string/palindrome.inc.cpp

    section utils
    list utils/binsearch.inc.cpp
    list utils/convex-hull-trick.inc.cpp
    list utils/longest-increasing-subsequence.inc.cpp
    list utils/dice.inc.cpp
    list utils/subset.inc.cpp

    cat <<'EOF'
\end{document}
EOF
} > library.tex

pdflatex library.tex && pdflatex library.tex
