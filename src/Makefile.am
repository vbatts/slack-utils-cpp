ACLOCAL_AMFLAGS = -I m4 --install


bin_PROGRAMS= slack-utils

lib_LTLIBRARIES=	libslackware.la

slack_utils_LDADD= libslackware.la

slack_utils_SOURCES=		\
		main.cpp

libslackware_la_SOURCES=	\
		package.cpp	\
		system.cpp

noinst_PROGRAMS= x

x_CXXFLAGS=	-std=gnu++0x 

x_SOURCES=			\
		x.cpp

EXTRA_DIST=			\
		README		\
		LICENSE

$(PACKAGE)-$(VERSION).tar.gz: dist


