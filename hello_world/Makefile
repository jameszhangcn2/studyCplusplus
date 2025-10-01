GTEST_DIR = /usr/local
GTEST_LIB = $(GTEST_DIR)/lib/libgtest.a
GTEST_INCLUDE = -I$(GTEST_DIR)/include

all	:HELLO TEST

HELLO	:main.o hello_world.o
	 g++ -Wall -o HELLO main.o hello_world.o

TEST	:test.o hello_world.o
	g++ -Wall -o TEST test.o hello_world.o $(GTEST_LIB) -lpthread

main.o	:main.cpp hello_world.h
	 g++ -Wall -c main.cpp

test.o	:test.cpp hello_world.h
	g++ -Wall -c test.cpp

hello_world.o	:hello_world.cpp hello_world.h
	g++ -Wall -c hello_world.cpp

clean	:
	rm *.o HELLO TEST 
