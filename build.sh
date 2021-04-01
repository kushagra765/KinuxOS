#!/bin/sh

sudo apt install nasm mtools

export TARGET=i686-elf

# Change the PATH to where you have installed the i686-elf-gcc compiler
export PATH="./compiler/toolchain/bin:$PATH"

# Build KinuxOS
mkdir build
nasm -felf32 ./boot/boot.asm -o ./build/boot.o

# Build Commands
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -c ./bin/version/version.c -o ./build/version.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -c ./bin/uname/uname.c -o ./build/uname.o

# Build Drivers
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ./drivers/vga/vga.c -o ./build/vga.o
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -c ./drivers/ports/ports.c -o ./build/ports.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -I./include/ -I./kernel/ -c ./drivers/keyboard/keyboard.c -o ./build/keyboard.o 
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -I./kernel/ -c ./drivers/timer/timer.c -o ./build/timer.o

# Build OS
nasm -felf32 ./kernel/load_gdt.asm -o ./build/load_gdt.o
nasm -felf32 ./kernel/load_idt.asm -o ./build/load_idt.o
nasm -felf32 ./kernel/load_isr.asm -o ./build/load_isr.o
nasm -felf32 ./kernel/load_irq.asm -o ./build/load_irq.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -I./kernel/ -c ./init/init.c -o ./build/init.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -c ./kernel/gdt.c -o ./build/gdt.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -c ./kernel/idt.c -o ./build/idt.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./drivers/ -I./include/ -c ./kernel/isr.c -o ./build/isr.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -c ./kernel/irq.c -o ./build/irq.o
i686-elf-gcc -Wall -Wextra -O2 -I./include/ -I./drivers/ -I./bin/ -c ./kernel/terminal.c -o ./build/terminal.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -c ./kernel/log.c -o ./build/log.o
i686-elf-gcc -Wall -Wextra -O2 -I./drivers/ -I./include/ -c ./kernel/panic.c -o ./build/panic.o

# Link KinuxOS
i686-elf-gcc -T linker.ld -o kinuxOS.bin -O2 -nostdlib ./build/boot.o ./build/version.o ./build/uname.o ./build/vga.o ./build/ports.o ./build/keyboard.o ./build/timer.o ./build/init.o ./build/gdt.o ./build/load_gdt.o ./build/idt.o ./build/load_idt.o ./build/isr.o ./build/load_isr.o ./build/irq.o ./build/load_irq.o ./build/terminal.o ./build/log.o ./build/panic.o

# Generate ISO
mkdir -p isodir/boot/grub
cp kinuxOS.bin isodir/boot/kinuxOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o kinuxOS.iso isodir
