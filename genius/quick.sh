#!/bin/bash

# this does kinda work, the idea was to include every .c file in a given folder and compile it with gcc
# I got too lazy and gave up, after all cmake is a much better solution in this case.
findfiles(){
cfiles= $(find . -name '*.c' -print) #need to include -olevel
}

compile()
{
    findfiles
    echo  "-Wall -Wpedantic -ggdb -o"  $1 $1.c "-lm"
}

debug()
{
    #compile()
    echo $1

}
