CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec.o llrec-test.o stack.o
	$(CXX) $(CXXFLAGS) llrec.o llrec-test.o stack.o -o llrec-test

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp -o llrec-test.o

# Add stack.o compilation target
stack.o: stack.cpp stack.h
	$(CXX) $(CXXFLAGS) -c stack.cpp -o stack.o

clean:
	rm -f *.o llrec-test *~

.PHONY: clean
