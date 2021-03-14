/* libc/string/strcmp.c
 * Author - @kushagra765
 */

int strcmp(const char *str1, const char *str2) {
  
    while (*str1 == *str2) {
       *str1++;
       *str2++;
    }
    
    return *str1 - *str2;
}
