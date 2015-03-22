CXX = g++

CXXFLAGS = -g
LDFLAGS = -g

SubDir = src
VPATH = $(SubDir)
#vpath %.cc src

quicksort:Quicksort.cc
	$(CXX) $(CXXFLAGS) -o quicksort $(SubDir)/Quicksort.cc

.PHONY:clean

clean:
	@rm quicksort
	@rm -r quicksort.dSYM
