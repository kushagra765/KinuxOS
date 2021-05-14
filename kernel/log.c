/* kernel/log.c
 * Author - @kushagra765
 */

#include <kinux/kernel.h>
#include <kinux/log.h>
#include <vga/vga.h>

struct log *log_info;

void warn_log(const char *str) {
  putstr("WARN: ", COLOR_RED, COLOR_BLK);
  printm(str);
  log_info->last_log = str;
}

void error_log(const char *str) {
  putstr("ERROR: ", COLOR_RED, COLOR_BLK);
  printm(str);
  log_info->last_log = str;
}

void show_log() {
  printm("Last Log: \n");
  printm(log_info->last_log);
}

void init_log() {
  putstr("[ OK ]\n", COLOR_GRN, COLOR_BLK);
}
