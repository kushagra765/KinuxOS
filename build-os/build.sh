#!/bin/sh

sudo apt-get update
sudo apt install nasm make gcc bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libisl-dev tar xorriso unzip mtools

mkdir $HOME/cross
mkdir $HOME/src

export PREFIX="$HOME/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

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

# Build OS
cd $HOME/src
wget https://github.com/kushagra765/KinuxOS/archive/main.zip
unzip main.zip

cd $HOME/src/KinuxOS-main/

# Build KinuxOS
mkdir build
nasm -felf32 ./boot/boot.asm -o ./build/boot.o

# Build Drivers
i686-elf-gcc -Wall -Wextra -O2 -c ./drivers/vga/vga.c -o ./build/vga.o
i686-elf-gcc -Wall -Wextra -O2 -c ./drivers/ports/ports.c -o ./build/ports.o
i686-elf-gcc -Wall -Wextra -O2 -c ./drivers/keyboard/keyboard.c -o ./build/keyboard.o
i686-elf-gcc -Wall -Wextra -O2 -c ./drivers/timer/timer.c -o ./build/timer.o

# Build OS
nasm -felf32 ./kernel/load_gdt.asm -o ./build/load_gdt.o
nasm -felf32 ./kernel/load_idt.asm -o ./build/load_idt.o
nasm -felf32 ./kernel/load_isr.asm -o ./build/load_isr.o
nasm -felf32 ./kernel/load_irq.asm -o ./build/load_irq.o
i686-elf-gcc -Wall -Wextra -O2 -c ./init/init.c -o ./build/init.o
i686-elf-gcc -Wall -Wextra -O2 -c ./kernel/gdt.c -o ./build/gdt.o
i686-elf-gcc -Wall -Wextra -O2 -c ./kernel/idt.c -o ./build/idt.o
i686-elf-gcc -Wall -Wextra -O2 -c ./kernel/isr.c -o ./build/isr.o
i686-elf-gcc -Wall -Wextra -O2 -c ./kernel/irq.c -o ./build/irq.o
i686-elf-gcc -Wall -Wextra -O2 -c ./kernel/terminal.c -o ./build/terminal.o

# Link KinuxOS
i686-elf-gcc -T linker.ld -o kinuxOS.bin -O2 -nostdlib ./build/boot.o ./build/vga.o ./build/ports.o ./build/keyboard.o ./build/timer.o ./build/init.o ./build/gdt.o ./build/load_gdt.o ./build/idt.o ./build/load_idt.o ./build/isr.o ./build/load_isr.o ./build/irq.o ./build/load_irq.o ./build/terminal.o

# Generate ISO
mkdir -p isodir/boot/grub
cp kinuxOS.bin isodir/boot/kinuxOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o kinuxOS.iso isodir
