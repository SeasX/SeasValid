/*
+----------------------------------------------------------------------+
| SeasLog                                                              |
+----------------------------------------------------------------------+
| This source file is subject to version 2.0 of the Apache license,    |
| that is bundled with this package in the file LICENSE, and is        |
| available through the world-wide-web at the following url:           |
| http://www.apache.org/licenses/LICENSE-2.0.html                      |
| If you did not receive a copy of the Apache2.0 license and are unable|
| to obtain it through the world-wide-web, please send a note to       |
| license@php.net so we can mail you a copy immediately.               |
+----------------------------------------------------------------------+
| Author: Neeke.Gao  <neeke@php.net>                                   |
+----------------------------------------------------------------------+
*/

#ifndef _PHP_SEASVALID_H_
#define _PHP_SEASVALID_H_

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "include/seasValid.h"

#ifdef PHP_WIN32
#include "win32/time.h"
#include <windows.h>
#elif defined(NETWARE)
#include <sys/timeval.h>
#include <sys/time.h>
#else
#include <unistd.h>
#include <sys/time.h>
#endif

extern zend_module_entry seasvalid_module_entry;
#define phpext_seaslog_ptr &seasvalid_module_entry

#ifdef PHP_WIN32
# define PHP_SEASVALID_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_SEASVALID_API __attribute__ ((visibility("default")))
#else
# define PHP_SEASVALID_API
#endif

#if PHP_VERSION_ID < 70000
typedef long zend_long;
#endif

ZEND_BEGIN_MODULE_GLOBALS(seasvalid)
    char *host_name;
    int  host_name_len;

	char *request_id;
	int  request_id_len;

	char *process_id;
    int  process_id_len;
ZEND_END_MODULE_GLOBALS(seasvalid)

extern ZEND_DECLARE_MODULE_GLOBALS(seasvalid);

#ifdef ZTS
#include "TSRM.h"
#define SEASVALID_G(v) TSRMG(seasvalid_globals_id, zend_seasvalid_globals *, v)
#else
#define SEASVALID_G(v) (seasvalid_globals.v)
#endif

#ifndef E_EXCEPTION
# define E_EXCEPTION (1<<15L)
#endif

PHP_MINIT_FUNCTION(seasvalid);
PHP_MSHUTDOWN_FUNCTION(seasvalid);
PHP_RINIT_FUNCTION(seasvalid);
PHP_RSHUTDOWN_FUNCTION(seasvalid);
PHP_MINFO_FUNCTION(seasvalid);

PHP_FUNCTION(seasvalid_get_author);

extern zend_class_entry *seasvalid_ce;
PHP_METHOD(SEASVALID_RES_NAME, __construct);
PHP_METHOD(SEASVALID_RES_NAME, getRequestID);
PHP_METHOD(SEASVALID_RES_NAME, getBuffer);
PHP_METHOD(SEASVALID_RES_NAME, log);

#endif /* _PHP_SEASVALID_H_ */

