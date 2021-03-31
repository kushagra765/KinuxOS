/* libc/ctype/isdigit.c
 * Author - @kushagra765
 */

#include <ctype.h>

int isdigit(int ch) {
  return ch >= MIN_DIGIT && ch <= MAX_DIGIT;
}
