/* libc/ctype/isalnum.c
 * Author - @kushagra765
 */

#include "../../include/ctype.h"

int isalnum(int ch) {
    return isdigit(ch) || isalpha(ch);
}
