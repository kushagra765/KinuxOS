/* libc/ctype/islower.c
 * Author - @kushagra765
 */

#include <ctype.h>

int islower(int ch) {
    return ch >= 'a' && ch <= 'z';
}
