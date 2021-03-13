/* libc/ctype/isalnum.c
 * Author - @kushagra765
 */

#include "../../include/ctype.h"

int isalnum(int c) {
    return isdigit(c) || isalpha(c);
}
