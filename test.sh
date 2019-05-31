#!/bin/bash
set -e
which oj

CXX=${CXX:-g++}
CXXFLAGS="${CXXFLANGS:--std=c++14 -O2 -Wall -g}"

atexit() {
    [[ -n ${temp} ]] && rm -rf ${temp}
    temp=
}
trap atexit EXIT

for f in */*.test.cpp ; do
    url="$(grep -o '^# *define \+PROBLEM \(https\?://.*\)' < $f | sed 's/.* http/http/')"
    if [[ -n ${url} ]] ; then
        temp=$(mktemp -d)
        $CXX $CXXFLAGS -I . -o ${temp}/a.out $f
        oj download --system "$url" -d ${temp}/test
        oj test -c ${temp}/a.out -d ${temp}/test
        atexit
        sleep 2
    fi
done
