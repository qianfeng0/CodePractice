CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

BINDIR = ./bin
PROGS = 1_TwoSum.out 2_AddTwoNumbers.out 445_AddTwoNumberII.out \
		328_OddEvenLinkedList.out 237_DeleteNodeInList.out \
		7_ReverseInteger.out 9_PalindromeNumber.out

all: 	$(PROGS)

1_TwoSum.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 1_TwoSum.cpp

2_AddTwoNumbers.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 2_AddTwoNumbers.cpp

445_AddTwoNumberII.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 445_AddTwoNumberII.cpp

328_OddEvenLinkedList.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 328_OddEvenLinkedList.cpp

237_DeleteNodeInList.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 237_DeleteNodeInList.cpp

7_ReverseInteger.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 7_ReverseInteger.cpp

9_PalindromeNumber.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ 9_PalindromeNumber.cpp

clean:
	rm -f ./$(BINDIR)/*