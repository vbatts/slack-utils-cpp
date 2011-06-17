CPP = g++
CFLAGS += -I. -Wall -g -fPIC
LDFLAGS += -L.

default: all

libslackware.so: package.o system.o
	$(CPP) $(CFLAGS) -shared -o $@ package.o system.o

package.o: package.cpp package.h types.h
	$(CPP) $(CFLAGS) -c -o $@ $<

system.o: system.cpp system.h types.h
	$(CPP) $(CFLAGS) -c -o $@ $<


x: x.cpp libslackware.so types.h
	$(CPP) $(CFLAGS) $(LDFLAGS) -std=gnu++0x -o $@ $< -lslackware

all: x libslackware.so

clean:
	rm -rf *~ x *.o *.so
