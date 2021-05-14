#ifndef _LOG_H
#define _LOG_H

/* include/kinux/log.h
 * Author - @kushagra765
 */

struct log {
  int is_quiet;
  int is_fatal;
  const char *last_log;
};

void init_log();
void warn_log(const char *str);
void error_log(const char *str);
void info_log(const char *str);
void show_log();

#endif //_LOG_H
