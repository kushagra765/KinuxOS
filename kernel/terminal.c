/* kernel/terminal.c
 * Author - @kushagra765
 */

#include <vga.h>
#include <uname.h>
#include <version.h>
#include <string.h>
#include <log.h>

void terminal() {
    putstr("user@Kinux: ", COLOR_WHT, COLOR_BLK);
}

void run(char command[]) {

    if (strcmp(command, "version")==0) {
        version();
    }
    else if (strcmp(command, "uname")==0) {
        uname();
    }
    else if (strcmp(command, "log")==0) {
        show_log();
    }
    else if (strcmp(command, "help")==0) {
        putstr("Available Commands: version uname log help\n", COLOR_WHT, COLOR_BLK);
    }

    /* If the user presses the enter key without entering any command, do nothing */

    else if (strcmp(command, "\0")==0) {
        
    }
    else {
        putstr(command, COLOR_WHT, COLOR_BLK);
        putstr(" : Command Not Found!\n", COLOR_WHT, COLOR_BLK);
    }
    
    // Clear the command[] array
    for (int i=0; command[i] != '\0'; i++) {
        command[i] = '\0';
    }
    
    putstr("user@Kinux: ", COLOR_WHT, COLOR_BLK);
}
