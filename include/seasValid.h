/*
  +----------------------------------------------------------------------+
  | SeasLog                                                              |
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

#ifndef _SEASLOG_H_
#define _SEASLOG_H_

#include "php.h"
#include "php_ini.h"
#include "main/php_main.h"
#include "php_streams.h"
#include "zend_extensions.h"
#include "zend_exceptions.h"
#include "ext/standard/info.h"
#include "ext/standard/file.h"
#include "ext/standard/php_string.h"
#include "ext/date/php_date.h"
#include "php7_wrapper.h"

#if PHP_VERSION_ID >= 70000
#include "zend_smart_str.h"
#else
#include "ext/standard/php_smart_str.h"
#endif

#include <stdlib.h>

#define SEASVALID_RES_NAME                        "SeasValid"
#define SEASVALID_AUTHOR                          "Chitao.Gao  [ neeke@php.net ]"
#define SEASVALID_VERSION                         "1.0.0"
#define SEASVALID_VERSION_ID                      20201011
#define SEASVALID_SUPPORTS                        "https://github.com/SeasX/SeasValid"

#define SEASVALID_CLI_KEY                         "cli"
#define SEASVALID_PHPDBG_KEY                      "phpdbg"

#define SEASVALID_LOG_LINE_FEED_STR               "\n"

#define SEASVALID_TRIM_WRAP                       32

#endif /* _SEASVALID_H_ */

