#! /bin/bash

set -e
target=$1
shift
rm -rf /tmp/urbi-assemble
mkdir /tmp/urbi-assemble /tmp/urbi-assemble/stage /tmp/urbi-assemble/final
workdir=/tmp/urbi-assemble
for l in "$@"; do
    (cd $workdir/stage && ar x $l)
    # mais quelle purge!
    dups=$(ar t $l |sort |uniq -d)
    for d in $(echo $dups); do
        (cd $workdir/stage && ar xN 1 $l $d && mv $d _dup_$d && ar xN 2 $l $d)
    done
    for f in $(ls $workdir/stage); do
        mv $workdir/stage/$f $workdir/final/$(basename $l .a)_$f
    done
done
ar cru $target $workdir/final/*
