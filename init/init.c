/* init/init.c
 * Author - @kushagra765
 */

#include <gdt.h>
#include <idt.h>
#include <irq.h>
#include <isr.h>
#include <keyboard/keyboard.h>
#include <kinux/log.h>
#include <kinux/terminal.h>
#include <timer/timer.h>
#include <vga/vga.h>

void init() {
  printm("Loading Kernel\n");
  printm("Loading the GDT... ");
  init_gdt();
  printm("Loading the IDT... ");
  init_idt();
  printm("Loading the ISR's... ");
  init_isr();
  printm("Loading the IRQ's... ");
  init_irq();
  printm("Loading Drivers... ");
  init_timer(50);
  init_keyboard();
  putstr("[ OK ]\n", COLOR_GRN, COLOR_BLK);
  printm("Starting Log Service... ");
  init_log();
  __asm__ volatile("sti");
  putstr("System Loaded\n", COLOR_GRN, COLOR_BLK);
  terminal();
}
