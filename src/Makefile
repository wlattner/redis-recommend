CFLAGS=-std=c99 -Wall -pedantic -g3 -fPIC
LDFLAGS=-shared
#LDFLAGS=-shared -undefined dynamic_lookup

all: redis-recommend.so

redis-recommend.so: redis-recommend.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	$(RM) -r *.o *.so *.so.dSYM
