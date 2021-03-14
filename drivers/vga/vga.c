/* drivers/vga/vga.c
 *  Author - @jaychandra6
 */

#include "../../include/kinux/ports.h"
#include "vga.h"

volatile vga_char *TEXT_AREA = (vga_char*) VGA_START;

unsigned char vga_color(const unsigned char fg_color, const unsigned char bg_color) {
    // Put bg color in the higher 4 bits and mask those of fg
    return (bg_color << 4) | (fg_color & 0x0F);
}


void clearwin(unsigned char fg_color, unsigned char bg_color) {
    const char space = ' ';
    unsigned char clear_color = vga_color(fg_color, bg_color);

    const vga_char clear_char = {
        .character = space,
        .style = clear_color
    };

    for(unsigned long i = 0; i < VGA_EXTENT; i++) {
        TEXT_AREA[i] = clear_char;
    }
}


void putchar(const char character, const unsigned char fg_color, const unsigned char bg_color) {
    unsigned short position = get_cursor_pos();

    if (character == '\n') {
        unsigned char current_row = (unsigned char) (position / VGA_WIDTH);

        if (++current_row >= VGA_HEIGHT) {
            scroll_line();
        }
        else {
            set_cursor_pos(0, current_row);
        }
    }

    else if (character == '\r') {
        unsigned char current_row = (unsigned char) (position / VGA_WIDTH);

        set_cursor_pos(0, current_row);
    }

    else if (character == '\t') {
        // Turn tab to 4 spaces
        for (unsigned char i = 0; i < 4; i++){
            putchar(' ', fg_color, bg_color);
        }
        advance_cursor();
    }

    else {
        unsigned char style = vga_color(fg_color, bg_color);
        vga_char printed = {
            .character = character,
            .style = style
        };

        TEXT_AREA[position] = printed;

        advance_cursor();
    }
}


void putstr(const char *string, const unsigned char fg_color, const unsigned char bg_color) {
    while (*string != '\0') {
        putchar(*string++, fg_color, bg_color);
    }
}


unsigned short get_cursor_pos() {
    unsigned short position = 0;

    byte_out(CURSOR_PORT_COMMAND, 0x0F);
    position |= byte_in(CURSOR_PORT_DATA);

    byte_out(CURSOR_PORT_COMMAND, 0x0E);
    position |= byte_in(CURSOR_PORT_DATA) << 8;

    return position;
}


void show_cursor() {
    unsigned char current;

    byte_out(CURSOR_PORT_COMMAND, 0x0A);
    current = byte_in(CURSOR_PORT_DATA);
    byte_out(CURSOR_PORT_DATA, current & 0xC0);

    byte_out(CURSOR_PORT_COMMAND, 0x0B);
    current = byte_in(CURSOR_PORT_DATA);
    byte_out(CURSOR_PORT_DATA, current & 0xE0);
}


void hide_cursor() {
    byte_out(CURSOR_PORT_COMMAND, 0x0A);
    byte_out(CURSOR_PORT_DATA, 0x20);
}


void advance_cursor() {
    unsigned short pos = get_cursor_pos();
    pos++;

    if (pos >= VGA_EXTENT) {
        scroll_line();
    }

    byte_out(CURSOR_PORT_COMMAND, 0x0F);
    byte_out(CURSOR_PORT_DATA, (unsigned char) (pos & 0xFF));

    byte_out(CURSOR_PORT_COMMAND, 0x0E);
    byte_out(CURSOR_PORT_DATA, (unsigned char) ((pos >> 8) & 0xFF));
}


void set_cursor_pos(unsigned char x, unsigned char y) {
    unsigned short pos = (unsigned short) x + ((unsigned short) VGA_WIDTH * y);

    if (pos >= VGA_EXTENT) {
        pos = VGA_EXTENT - 1;
    }

    byte_out(CURSOR_PORT_COMMAND, 0x0F);
    byte_out(CURSOR_PORT_DATA, (unsigned char) (pos & 0xFF));

    byte_out(CURSOR_PORT_COMMAND, 0x0E);
    byte_out(CURSOR_PORT_DATA, (unsigned char) ((pos >> 8) & 0xFF));
}


void scroll_line() {
    // Copy memory buffer upward
    for(unsigned short i = 1; i < VGA_HEIGHT; i++) {
        for(unsigned short j = 0; j < VGA_WIDTH; j++) {
            unsigned short to_pos = j + ((i - 1) * VGA_WIDTH);
            unsigned short from_pos = j + (i * VGA_WIDTH);

            TEXT_AREA[to_pos] = TEXT_AREA[from_pos];
        }
    }

    // Clear the final row
    unsigned short i = VGA_HEIGHT - 1;
    for(unsigned short j = 0; j < VGA_WIDTH; j++) {
        unsigned short pos = j + (i * VGA_WIDTH);

        vga_char current = TEXT_AREA[pos];
        vga_char clear = {
            .character=' ',
            .style = current.style
        };

        TEXT_AREA[pos] = clear;
    }

    set_cursor_pos(0, VGA_HEIGHT - 1);
}
