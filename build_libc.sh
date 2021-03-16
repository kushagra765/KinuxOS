#!/bin/sh

export TARGET=i686-elf

# Change the PATH to where you have installed the i686-elf-gcc compiler
export PATH="$HOME/cross/bin:$PATH"

mkdir libc-build
cd libc-build

# Build ctype/
i686-elf-gcc -Wall -Wextra -O2 -c ../libc/ctype/isalnum.c -o ../libc-build/isalnum.o
i686-elf-gcc -Wall -Wextra -O2 -c ../libc/ctype/isalpha.c -o ../libc-build/isalpha.o
i686-elf-gcc -Wall -Wextra -O2 -c ../libc/ctype/isblank.c -o ../libc-build/isblank.o

# Build errno/
i686-elf-gcc -Wall -Wextra -O2 -c ../libc/errno/errno.c -o ../libc-build/errno.o

# Build string/
i686-elf-gcc -Wall -Wextra -O2 -c ../libc/string/strcmp.c -o ../libc-build/strcmp.o
