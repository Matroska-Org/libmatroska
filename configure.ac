AC_INIT([libmatroska], [1.4.2])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects tar-pax])
AC_PROG_CXX
LT_INIT
AC_ARG_ENABLE([debug],
	AS_HELP_STRING([--enable-debug], [Add -g -DDEBUG to compile flags]),
	[enable_debug="$withval"], [enable_debug=no])
AM_CONDITIONAL([ENABLE_DEBUG], [test "$enable_debug" = yes])
PKG_CHECK_MODULES([EBML],[libebml >= 1.3.1])
AC_CONFIG_FILES([Makefile libmatroska.pc])
AC_OUTPUT
