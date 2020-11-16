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

#include "Datetime.h"

static char *seasValid_format_date(char *format, int format_len, time_t ts TSRMLS_DC)
{
#if PHP_VERSION_ID >= 70000
    zend_string *_date;
    char *_date_tmp;
    _date = php_format_date(format, format_len, ts, 1 TSRMLS_CC);
    _date_tmp = estrdup(ZSTR_VAL(_date));
    zend_string_release(_date);
    return _date_tmp;
#else
    return php_format_date(format, format_len, ts, 1 TSRMLS_CC);
#endif
}

void init_remote_timeout(TSRMLS_D)
{
#ifndef PHP_WIN32
    time_t conv;
#else
    long conv;
#endif
    struct timeval tv;

#ifndef PHP_WIN32
    conv = (time_t) (SEASVALID_G(remote_timeout) * 1000000.0);
    tv.tv_sec = conv / 1000000;
#else
    conv = (long) (SEASVALID_G(remote_timeout) * 1000000.0);
    tv.tv_sec = conv / 1000000;
#endif
    tv.tv_usec = conv % 1000000;

    SEASVALID_G(remote_timeout_real) = tv;
}

/*char *make_real_date(TSRMLS_D)
{
    int now = (long)time(NULL);
    if (now > SEASVALID_G(last_min)->sec + 60)
    {
        return seasvalid_process_last_min(now, SEASVALID_INIT_FIRST_NO TSRMLS_CC);
    }

    return SEASVALID_G(last_min)->real_time;
}*/
/*
char *make_real_time(TSRMLS_D)
{
    int now = (long)time(NULL);
    if (now > SEASVALID_G(last_sec)->sec)
    {
        return seasvalid_process_last_sec(now, SEASVALID_INIT_FIRST_NO TSRMLS_CC);
    }

    return SEASVALID_G(last_sec)->real_time;
}*/

void mic_time(smart_str *buf)
{
    struct timeval now;

    timerclear(&now);
    gettimeofday(&now, NULL);

    smart_str_append_long(buf,(long)time(NULL));
    smart_str_appendc(buf,'.');
    smart_str_append_long(buf,(long)now.tv_usec / 1000);

    smart_str_0(buf);
}

static struct timeval seasvalid_get_remote_timeout(TSRMLS_D)
{
    return SEASVALID_G(remote_timeout_real);
}

