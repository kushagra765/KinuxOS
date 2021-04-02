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
  log_info->enabled = 1;

  /* Print OK only when log_info->enabled is set to 1 */
  if (log_info->enabled == 1) {
    putstr("[ OK ]\n", COLOR_GRN, COLOR_BLK);
  } else {
    putstr("[ FAILED ]\n", COLOR_RED, COLOR_BLK);
    panic("Cannot load log service!\n");
  }
}
