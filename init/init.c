/* init/init.c
 * Author - @kushagra765
*/

#include "../drivers/vga/vga.h"
#include "../drivers/keyboard/keyboard.h"
#include "../include/kinux/ports.h"
#include "../include/stdint.h"
#include "../kernel/idt.h"
#include "../kernel/gdt.h"
#include "../kernel/isr.h"
#include "../kernel/irq.h"
#include "../include/kinux/terminal.h"

void main() {
     putstr("[KERNEL] Loading Kernel\n", COLOR_WHT, COLOR_BLK); 
     putstr("[KINUX] Loading the GDT...\n", COLOR_WHT, COLOR_BLK);
     init_gdt();
     putstr("[KINUX] Loading the IDT...\n", COLOR_WHT, COLOR_BLK);
     init_idt();
     putstr("[KINUX] Loading the ISR...\n", COLOR_WHT, COLOR_BLK);
     init_isr();
     putstr("[KINUX] Loading the IRQ...\n", COLOR_WHT, COLOR_BLK);
     init_irq();
     init_keyboard();
     __asm__ volatile("sti");
     clearwin(COLOR_WHT, COLOR_LBU);
     putstr("System Loaded\n", COLOR_GRN, COLOR_LBU);
     putstr("Welcome to KinuxOS!\n", COLOR_WHT, COLOR_LBU);
     terminal();
}
