/* drivers/timer/timer.c
 * Author - @kushagra765
 */

#include "../../include/kinux/ports.h"
#include "../../kernel/irq.h"
#include "timer.h"

int kernel_timer_ticks = 0;

void handler_timer() {
     kernel_timer_ticks++;
}

void init_timer(int frequency) {
  
     install_irq_handler(0, handler_timer);
     int divisor = 1193180 / frequency;
     
     byte_out(0x43, 0x36);
     byte_out(0x40, frequency & 0xFF);
     byte_out(0x40, frequency >> 8);
}
