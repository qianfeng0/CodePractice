CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

BINDIR = ./bin
PROGS = POJ1753_FlipGame.out POJ2965_refrigerator.out

all: 	$(PROGS)

POJ1753_FlipGame.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ POJ1753_FlipGame.cpp

POJ2965_refrigerator.out:
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ POJ2965_refrigerator.cpp
clean:
	rm -f ./$(BINDIR)/*