/* init/init.c
 * Author - @kushagra765
 */

#include <vga.h>
#include <keyboard.h>
#include <timer.h>
#include <idt.h>
#include <gdt.h>
#include <isr.h>
#include <irq.h>
#include <terminal.h>

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
