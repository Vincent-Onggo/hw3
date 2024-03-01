CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.o llrec-test.o
	g++ -g -Wall llrec.o llrec-test.o -o llrec-test

llrec.o: llrec.cpp llrec.h
	g++ -g -Wall -c llrec.cpp -o llrec.o

llrec-test.o: llrec-test.cpp
	g++ -g -Wall -c llrec-test.cpp -o llrec-test.o

clean:
	rm -f *.o llrec-test *~

.PHONY: clean
