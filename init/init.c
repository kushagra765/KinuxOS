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
     printm("Loading Kernel\n");
     printm("Loading the GDT... ");
     init_gdt();
     printm("Loading the IDT... ");
     init_idt();
     printm("Loading the ISR... ");
     init_isr();
     printm("Loading the IRQ... ");
     init_irq();
     printm("Loading Drivers... ");
     init_timer(50);
     init_keyboard();
     putstr("[ OK ]\n", COLOR_GRN, COLOR_BLK);
     __asm__ volatile("sti");
     putstr("System Loaded\n", COLOR_GRN, COLOR_BLK);
     terminal();
}
