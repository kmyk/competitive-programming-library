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
judge() { for f in test/*.in ; do ; echo $f ; diff <(cat $f | ./a.out) ${f%.in}.out ; done ; }
