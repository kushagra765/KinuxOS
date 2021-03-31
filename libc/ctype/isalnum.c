/* libc/ctype/isalnum.c
 * Author - @kushagra765
 */

#include <ctype.h>

int isalnum(int ch) {
  return isdigit(ch) || isalpha(ch);
}
