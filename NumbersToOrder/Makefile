# Ian Cowan
# Jack Pharies
# CSC 341 W20
# Makefile for C++ Numbers To Order

PROGRAM=numbers
CLASSES=
SRCS=NumbersToOrder.cc
HDRS=NumbersToOrder.hh

RM=rm -rf
CXX=g++
CXXFLAGS=-g -O0 --std=c++11 -Wfatal-errors -Wall -Wextra -pedantic -fstack-check
CXXEXT=cc
LDFLAGS=-g
LDLIBS=

# Object files
OBJS=$(subst .cc,.o,$(SRCS))

run: all
#	./$(PROGRAM)
#	valgrind ./$(PROGRAM)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	@echo "Build successful.  Type ./$(PROGRAM) to run program."

$(OBJS): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) -c $^

clean:	
	$(RM) $(PROGRAM) $(OBJS) *.gch $(PROGRAM).dSYM

