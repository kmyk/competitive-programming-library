#!/bin/bash
set -e
which oj > /dev/null

CXX=${CXX:-g++}
CXXFLAGS="${CXXFLANGS:--std=c++14 -O2 -Wall -g}"

atexit() {
    [[ -n ${temp} ]] && rm -rf ${temp}
    temp=
}
trap atexit EXIT

run() {
    file="$1"
    url="$(grep -o '^# *define \+PROBLEM \(https\?://.*\)' < "$file" | sed 's/.* http/http/')"
    temp=$(mktemp -d)
    $CXX $CXXFLAGS -I . -o ${temp}/a.out "$file"
    if [[ -n ${url} ]] ; then
        sleep 2
        oj download --system "$url" -d ${temp}/test
        oj test -c ${temp}/a.out -d ${temp}/test
    else
        ${temp}/a.out
    fi
    atexit
}

if [ $# -eq 0 ] ; then
    for f in $(find . -name \*.test.cpp) ; do
        run $f
    done
else
    for f in "$@" ; do
        run "$f"
    done
fi
