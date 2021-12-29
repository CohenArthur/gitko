LDFLAGS = -lgit2 -shared
CFLAGS = -Wextra -Wall -pedantic -shared -fPIC
SRC = lib.c

lib.so: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

all: lib.so
