# https://github.com/primitivorm/getting-started-llvm-c-api
# https://pauladamsmith.com/blog/2015/01/how-to-get-started-with-llvm-c-api.html

CC = clang
LD = clang++
CFLAGS = $(shell llvm-config --cflags) -std=c11 -g -O0 -Wall -Wextra -Werror -Wno-missing-field-initializers
LDFLAGS = $(shell llvm-config --cxxflags --ldflags --libs core executionengine interpreter analysis native bitwriter --system-libs)

all: kaleidoscope

main.o: src/main.c
	@$(CC) $(CFLAGS) -c $<

kaleidoscope: main.o
	@$(LD) $< $(LDFLAGS) -o $@

clean:
	rm -rf *.o *.dSYM kaleidoscope tests
