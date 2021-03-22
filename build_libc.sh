#!/bin/sh

export TARGET=i686-elf

# Change the PATH to where you have installed the i686-elf-gcc compiler
export PATH="$HOME/cross/bin:$PATH"

mkdir libc-build
cd libc-build

# Build ctype/
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/ctype/isalnum.c -o ../libc-build/isalnum.o
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/ctype/isalpha.c -o ../libc-build/isalpha.o
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/ctype/isblank.c -o ../libc-build/isblank.o
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/ctype/isdigit.c -o ../libc-build/isdigit.o
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/ctype/islower.c -o ../libc-build/islower.o

# Build errno/
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/errno/errno.c -o ../libc-build/errno.o

# Build string/
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ../libc/string/strcmp.c -o ../libc-build/strcmp.o
