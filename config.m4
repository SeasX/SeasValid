dnl config.m4 for extension seasvalid

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([seasvalid],
dnl   [for seasvalid support],
dnl   [AS_HELP_STRING([--with-seasvalid],
dnl     [Include seasvalid support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([seasvalid],
  [whether to enable seasvalid support],
  [AS_HELP_STRING([--enable-seasvalid],
    [Enable seasvalid support])],
  [no])

if test "$PHP_SEASVALID" != "no"; then
  PHP_ADD_LIBRARY(pthread)
  CFLAGS="-Wall -pthread $CFLAGS"

  seasvalid_source_file="\
    seasvalid.cc \
    seasvalid_validation.cc
  "

  PHP_NEW_EXTENSION(seasvalid, $seasvalid_source_file, $ext_shared, ,, cxx)

  PHP_ADD_INCLUDE([$ext_srcdir])
  PHP_ADD_INCLUDE([$ext_srcdir/include])

  PHP_INSTALL_HEADERS([ext/seasvalid], [*.h config.h include/*.h])

  PHP_REQUIRE_CXX()

  CXXFLAGS="$CXXFLAGS -Wall -Wno-unused-function -Wno-deprecated -Wno-deprecated-declarations"
  CXXFLAGS="$CXXFLAGS -std=c++11"

fi
