/* kernel/panic.c
 * Author - @kushagra765
 */

#include <kinux/kernel.h>
#include <vga/vga.h>

void panic(const char *str) {
  putstr("Kernel Panic: ", COLOR_RED, COLOR_BLK);
  putstr(str, COLOR_RED, COLOR_BLK);
  __asm__ volatile("hlt");
}
