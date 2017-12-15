#!/bin/bash

cat <<EOF > ~/.vimrc
syntax on
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set relativenumber
EOF

setxkbmap -option ctrl:swapcaps

alias e=vim
alias cxx='$CXX -std=c++14 -Wall -O2'
alias cxxo='$CXX -std=c++14 -Wall -O3 -mtune=native -march=native'
alias cxxg='$CXX -std=c++14 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG'

judge() { for f in test/*.in ; do ; echo $f ; diff <(./a.out < $f) ${f%.in}.out ; done ; }
