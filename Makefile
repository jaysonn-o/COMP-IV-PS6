CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic -Werror -g
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
BOOST_LIBS = -lboost_unit_test_framework
DEPS = RandWriter.hpp TextWriter.cpp
OBJS = RandWriter.o TextWriter.o
Test = test.o RandWriter.o

all: RandWriter TextWriter TextWriter.a test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

RandWriter: $(OBJS)
	$(CC) $(CFLAGS) -o RandWriter $(OBJS) $(LIBS)

TextWriter: $(OBJS)
	$(CC) $(CFLAGS) -o TextWriter $(OBJS) $(LIBS)

TextWriter.a: $(OBJS)
	ar rcs TextWriter.a $(OBJS)

test: $(Test)
	$(CC) $(CFLAGS) -o test $(Test) TextWriter.a $(BOOST_LIBS)

clean:
	rm -f RandWriter TextWriter TextWriter.a test *.o *.test

lint:
	cpplint *.cpp *.hpp

.PHONY: all clean lint
