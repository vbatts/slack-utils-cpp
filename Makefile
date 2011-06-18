PRGNAM = slack-utils-cpp
VERSION = 1.0.0

CPP = g++
CFLAGS += -I. -Wall -g -fPIC
LDFLAGS += -L.

PREFIX = /usr

default: all

libslackware.so: package.o system.o
	$(CPP) $(CFLAGS) -shared -o $@ package.o system.o

package.o: package.cpp package.h types.h
	$(CPP) $(CFLAGS) -c -o $@ $<

system.o: system.cpp system.h types.h
	$(CPP) $(CFLAGS) -c -o $@ $<

x: x.cpp
	$(CPP) $(CFLAGS) $(LDFLAGS) -std=gnu++0x -o $@ $<


main: main.cpp libslackware.so types.h
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $@ $< -lslackware


docs:
	doxygen .

pdf: docs
	cd latex && $(MAKE)

all: x main libslackware.so

install: main libslackware.so docs
	install -d $(DESTDIR)$(PREFIX)/bin
	install -d $(DESTDIR)$(PREFIX)/lib$(LIBDIRSUFFIX)
	install -d $(DESTDIR)$(PREFIX)/include/slackware
	install -d $(DESTDIR)$(PREFIX)/doc/$(PRGNAM)-$(VERSION)/
	install -m 0755 main $(DESTDIR)$(PREFIX)/bin/slack-utils-cpp
	install -m 0755 libslackware.so $(DESTDIR)$(PREFIX)/lib$(LIBDIRSUFFIX)/libslackware.so
	install -m 0644 slackware.h $(DESTDIR)$(PREFIX)/include/slackware.h
	install -m 0644 package.h $(DESTDIR)$(PREFIX)/include/slackware/package.h
	install -m 0644 system.h $(DESTDIR)$(PREFIX)/include/slackware/system.h
	install -m 0644 types.h $(DESTDIR)$(PREFIX)/include/slackware/types.h
	cp -a html/ $(DESTDIR)$(PREFIX)/doc/$(PRGNAM)-$(VERSION)/


clean:
	rm -rf main *~ x *.o *.so latex/ html/

