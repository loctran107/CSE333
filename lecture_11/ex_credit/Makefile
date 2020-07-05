CXX = g++
CXXFLAGS = -Wall -g -std=c++11
HEADERS = Point3D.h
PROGS = Point3D_main

all: $(PROGS)

Point3D_main: Point3D_main.o Point3D.o 
	$(CXX) $(CXXFLAGS) -o $@ $<

Point3D_main.o: Point3D_main.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c Point3D_main.cc

Point3D.o: Point3D.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

