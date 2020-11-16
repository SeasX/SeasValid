dnl config.m4 for extension seasvalid

dnl +----------------------------------------------------------------------+
dnl | SeasValid                                                              |
dnl +----------------------------------------------------------------------+
dnl | This source file is subject to version 2.0 of the Apache license,    |
dnl | that is bundled with this package in the file LICENSE, and is        |
dnl | available through the world-wide-web at the following url:           |
dnl | http://www.apache.org/licenses/LICENSE-2.0.html                      |
dnl | If you did not receive a copy of the Apache2.0 license and are unable|
dnl | to obtain it through the world-wide-web, please send a note to       |
dnl | license@php.net so we can mail you a copy immediately.               |
dnl +----------------------------------------------------------------------+
dnl | Author: Neeke.Gao  <neeke@php.net>                                   |
dnl +----------------------------------------------------------------------+

PHP_ARG_WITH(seasvalid, for seasvalid support,
[  --with-seasvalid             Include seasvalid support])

dnl Otherwise use enable:

if test "$PHP_SEASVALID" != "no"; then
  dnl # --with-seasVALID -> add include path
  dnl PHP_ADD_INCLUDE($SEASLOG_DIR/include)

    seasvalid_source_file="seasvalid.c \
        src/Datetime.c
        src/Common.c"
    PHP_NEW_EXTENSION(seasvalid, $seasvalid_source_file, $ext_shared,,,)

    PHP_ADD_INCLUDE([$ext_srcdir])
    PHP_ADD_INCLUDE([$ext_srcdir/include])

    PHP_ADD_BUILD_DIR($ext_builddir/src)
fi

