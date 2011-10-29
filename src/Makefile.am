ACLOCAL_AMFLAGS = -I m4 --install


bin_PROGRAMS= 			\
		slack-utils

lib_LTLIBRARIES=		\
		libslackware.la

slack_utils_CPPFLAGS= 		\
		-I../include

slack_utils_LDFLAGS= 		\
		-I../include	\
		-static

slack_utils_LDADD= 		\
		-lboost_program_options \
		libslackware.la

slack_utils_SOURCES=		\
		parse_args.cpp	\
		main.cpp

libslackware_la_LIBADD=		\
		-lboost_filesystem \
		-lboost_regex

libslackware_la_CPPFLAGS=	\
		-I../include

libslackware_la_LDFLAGS=	\
		-I../include	\
		-release $(VERSION)

libslackware_la_SOURCES=	\
		package.cpp	\
		system.cpp


noinst_PROGRAMS= x

x_CXXFLAGS=	-std=gnu++0x 

x_SOURCES=			\
		x.cpp

