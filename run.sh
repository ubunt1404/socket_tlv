#!/bin/bash
gcc -c *.c
gcc -o test *.o
rm -rf *.o
./test -p 80 -i 192.168.0.16
