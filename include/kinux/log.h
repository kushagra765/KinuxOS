#ifndef _LOG_H
#define _LOG_H

/* include/kinux/log.h
 * Author - @kushagra765
 */

struct log {
     int enabled;
     const char *last_log;
};

void init_log();
void warn_log(const char *str);
void error_log(const char *str);
void show_log();

#endif //_LOG_H