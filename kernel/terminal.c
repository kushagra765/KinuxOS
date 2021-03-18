/* kernel/terminal.c
 * Author - @kushagra765
 */

#include "../include/kinux/terminal.h"
#include "../include/string.h"
#include "../drivers/vga/vga.h"

void terminal() {
    putstr("user@Kinux: \n", COLOR_BLK, COLOR_WHT);
}

void run(char command[]) {

    if (strcmp(command, "version")==0) {
        putstr("v0.1\n", COLOR_BLK, COLOR_WHT);
    }
    else if (strcmp(command, "about")==0) {
        putstr("KinuxOS\n", COLOR_BLK, COLOR_WHT);
    }
    else if (strcmp(command, "help")==0) {
        putstr("Available Commands: version about help\n", COLOR_BLK, COLOR_WHT);
    }
    else {
        putstr("Command Not Found!\n", COLOR_BLK, COLOR_WHT); 
    }
    
    // Clear the command[] array
    for (int i=0; command[i] != '\0'; i++) {
        command[i] = '\0';
    }

    putstr("user@Kinux: \n", COLOR_BLK, COLOR_WHT);
}
