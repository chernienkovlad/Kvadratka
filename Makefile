CC=g++
CFLAGS=-Wall -Wextra -Werror
SOURCES1=main.cpp sources/kvadratka.cpp sources/introduction.cpp
HEADERS1=sources/kvadratka.h sources/introduction.h
SOURCES2=$(SOURCES1) unit_tests/unit_tests.cpp
HEADERS2=$(HEADERS1) unit_tests/unit_tests.h
EXECUTABLE1=kv
EXECUTABLE2=kv_tests

all: build_main

build_main: $(SOURCES1) $(HEADERS1)
	$(CC) $(CFLAGS) $(SOURCES1) -o $(EXECUTABLE1) -D MAIN

build_tests: $(SOURCES2) $(HEADERS2)
	$(CC) $(CFLAGS) $(SOURCES2) -o $(EXECUTABLE2) -D TESTS

rebuild: clean all

clean:
	rm -rf $(EXECUTABLE1) $(EXECUTABLE2)