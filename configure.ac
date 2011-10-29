#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([slack-utils], [1.0.0], [slackware@hashbangbash.com], [slack-utils], [https://github.com/vbatts/slack-utils-cpp])
AM_INIT_AUTOMAKE([slack-utils], [1.0.0])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([src/config.h])

AC_PROG_LIBTOOL

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

AC_LANG(C++)
SAVED_LDFLAGS=$LDFLAGS
LDFLAGS="$LDFLAGS -lboost_filesystem"
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM([#include <boost/filesystem.hpp>],
    [  boost::filesystem::path p(); ])],
  [BOOST_THREAD_LIBS="-lboost_filesystem"],
  [AC_MSG_ERROR([libboost_filesystem is not installed.])])
LDFLAGS=$SAVED_LDFLAGS

AC_LANG(C++)
SAVED_LDFLAGS=$LDFLAGS
LDFLAGS="$LDFLAGS -lboost_regex"
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM([#include <boost/regex.hpp>],
    [  boost::regex re(); ])],
  [BOOST_THREAD_LIBS="-lboost_regex"],
  [AC_MSG_ERROR([libboost_regex is not installed.])])
LDFLAGS=$SAVED_LDFLAGS


# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strchr])

AC_OUTPUT( Makefile src/Makefile include/Makefile )

