# KinuxOS
KinuxOS is an operating system for x86_64 based systems. It is based on the Kinux-Kernel.

# Features
1. GDT
2. IDT
3. ISR
4. IRQ
5. VGA Driver
6. Keyboard Driver
7. Timer Driver
8. Terminal (Supports Basic Commands)

# Building
To build KinuxOS you need i686-elf-gcc, nasm and many other packages, to install the packages and build the compiler, run `sh ./build_compiler.sh`. If you have already installed the i686-elf-gcc, modify the PATH in the `build.sh` and run it.

If you want to build the libc, run `sh ./build_libc.sh`.

# Contributing
To contribute to KinuxOS, please read the [CONTRIBUTING.md](https://github.com/kushagra765/KinuxOS/blob/main/CONTRIBUTING.md) file.
