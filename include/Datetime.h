/*
  +----------------------------------------------------------------------+
  | SeasValid                                                              |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Chitao Gao  <neeke@php.net>                                  |
  +----------------------------------------------------------------------+
*/

#ifndef _SEASVALID_DATETIME_H_
#define _SEASVALID_DATETIME_H_

#include "php_seasValid.h"

char *make_real_time(TSRMLS_D);
void init_remote_timeout(TSRMLS_D);
char *seaslog_process_last_sec(int now, int if_first TSRMLS_DC);
void mic_time(smart_str *buf);
char *make_time_RFC3339(TSRMLS_D);
char *make_real_date(TSRMLS_D);
char *make_real_time(TSRMLS_D);
char *seaslog_process_last_min(int now, int if_first TSRMLS_DC);

#endif /* _SEASVALID_DATETIME_H_ */

