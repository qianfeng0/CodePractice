CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

BINDIR = ./bin
PROGS = 1_TwoSum.out 2_AddTwoNumbers.out 445_AddTwoNumberII.out \
		328_OddEvenLinkedList.out

all: 	$(PROGS)

1_TwoSum.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 1_TwoSum.cpp

2_AddTwoNumbers.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 2_AddTwoNumbers.cpp

445_AddTwoNumberII.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 445_AddTwoNumberII.cpp

328_OddEvenLinkedList.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 328_OddEvenLinkedList.cpp

clean:
	rm -f ./$(BINDIR)/*