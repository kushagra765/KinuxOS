/* init/init.c
 * Author - @kushagra765
 */

#include "../drivers/vga/vga.h"
#include "../drivers/keyboard/keyboard.h"
#include "../drivers/timer/timer.h"
#include "../kernel/idt.h"
#include "../kernel/gdt.h"
#include "../kernel/isr.h"
#include "../kernel/irq.h"
#include "../include/kinux/terminal.h"

void init() {
     clearwin(COLOR_WHT, COLOR_WHT);
     putstr("[KERNEL] Loading Kernel\n", COLOR_BLK, COLOR_WHT); 
     putstr("[KINUX] Loading the GDT...\n", COLOR_BLK, COLOR_WHT);
     init_gdt();
     putstr("[KINUX] Loading the IDT...\n", COLOR_BLK, COLOR_WHT);
     init_idt();
     putstr("[KINUX] Loading the ISR...\n", COLOR_BLK, COLOR_WHT);
     init_isr();
     putstr("[KINUX] Loading the IRQ...\n", COLOR_BLK, COLOR_WHT);
     init_irq();
     putstr("[KINUX] Loading Drivers...\n", COLOR_BLK, COLOR_WHT);
     init_timer(50);
     init_keyboard();
     __asm__ volatile("sti");
     putstr("System Loaded\n", COLOR_GRN, COLOR_WHT);
     terminal();
}
