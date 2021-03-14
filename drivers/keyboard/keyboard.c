/* drivers/keyboard/keyboard.c
 * Author - @kushagra765
 */

#include "../../include/kinux/ports.h"
#include "../vga/vga.h"
#include "../../kernel/irq.h"
#include "../../include/stdint.h"
#include "keyboard.h"

uint8_t keyboard_layout[128] = {
     0,  27, '1', '2', '3', '4', '5', '6', '7', '8',
  '9', '0', '-', '=', '\b',
  '\t',			
  'q', 'w', 'e', 'r',	
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	
    0,			
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	
 '\'', '`',   0,		
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			
  'm', ',', '.', '/',   0,				
  '*',
    0,	
  ' ',	
    0,	
    0,	
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	
    0,	
    0,	
    0,	
    0,	
    0,	
  '-',
    0,	
    0,
    0,
  '+',
    0,	
    0,	
    0,	
    0,	
    0,	
    0,   0,   0,
    0,	
    0,	
    0,	
};

void handler_keyboard() {
     uint8_t keyboard_key_scancode;
     
     keyboard_key_scancode = byte_in(DATA_PORT);
     
     if (keyboard_key_scancode & 0x80) {
       // Shift, Ctrl keys to be implemented
     
     }
     else {
        putchar(keyboard_layout[keyboard_key_scancode], COLOR_WHT, COLOR_LBU);
     }
}

void init_keyboard() {
     install_irq_handler(1, handler_keyboard);
}
