/* kernel/terminal.c
 * Author - @kushagra765
 */

#include <vga.h>
#include <uname.h>
#include <version.h>
#include <string.h>

void terminal() {
    putstr("user@Kinux: ", COLOR_BLK, COLOR_WHT);
}

void run(char command[]) {

    if (strcmp(command, "version")==0) {
        version();
    }
    else if (strcmp(command, "uname")==0) {
        uname();
    }
    else if (strcmp(command, "help")==0) {
        putstr("Available Commands: version uname help\n", COLOR_BLK, COLOR_WHT);
    }

    /* If the user presses the enter key without entering any command, do nothing */

    else if (strcmp(command, "\0")==0) {
        
    }
    else {
        putstr(command, COLOR_BLK, COLOR_WHT);
        putstr(" : Command Not Found!\n", COLOR_BLK, COLOR_WHT);
    }
    
    // Clear the command[] array
    for (int i=0; command[i] != '\0'; i++) {
        command[i] = '\0';
    }

    putstr("user@Kinux: ", COLOR_BLK, COLOR_WHT);
}
