CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -o
HEADER = IntPair.h
PROGS = ex9

all: $(PROGS)

ex9: ex9.o IntPair.o
	$(CXX) $(CXXFLAGS) $@ $^

ex9.o: ex9.cc $(HEADER)
	$(CXX) $(CXXFLAGS) $@ -c $<

IntPair.o: IntPair.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) $@ -c $<

clear:
	rm -f *.o *~ $(PROGS)
