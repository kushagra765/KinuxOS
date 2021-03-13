#!/bin/sh

sudo apt-get update
sudo apt install nasm make gcc bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libisl-dev tar xorriso

export PREFIX="$HOME/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

mkdir $HOME/cross

mkdir $HOME/src
cd $HOME/src

wget https://ftp.gnu.org/gnu/binutils/binutils-2.36.tar.gz
wget https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.gz

tar -xf gcc-10.2.0.tar.gz
tar -xf binutils-2.36.tar.gz

mkdir binutils-build
cd binutils-build
../binutils-2.36/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

cd $HOME/src

which -- $TARGET-as || echo $TARGET-as not found
 
mkdir gcc-build
cd gcc-build
../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
