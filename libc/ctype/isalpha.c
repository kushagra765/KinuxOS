/* libc/ctype/isalpha.c
 * Author - @kushagra765
 */

#include "../../include/ctype.h"

int isalpha(int ch) {
    return islower(ch) || isupper(ch);
}
