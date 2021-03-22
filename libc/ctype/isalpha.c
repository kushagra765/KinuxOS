/* libc/ctype/isalpha.c
 * Author - @kushagra765
 */

#include <ctype.h>

int isalpha(int ch) {
    return islower(ch) || isupper(ch);
}
