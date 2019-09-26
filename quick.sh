#!/bin/bash

findfiles(){
cfiles= $(find . -name '*.c' -print)
}

compile()
{
    findfiles
    echo  "-Wall -Wpedantic -ggdb -o"  $1 $cfiles "-lm"
}

debug()
{
    compile()
    echo "gdb" $1

}
