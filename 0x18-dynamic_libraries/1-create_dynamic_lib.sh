#!/bin/bash

# Compile all .c files into a dynamic library named liball.so
gcc -shared -o liball.so -fPIC *.c -Wall -Werror -Wextra -pedantic -std=gnu89
