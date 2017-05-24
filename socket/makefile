CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

BINDIR = ./bin
OBJDIR = ./obj
VPATH = $(BINDIR):$(OBJDIR)

SRCS	= $(wildcard *.cpp)
OBJ 	= $(patsubst %.cpp,%.o,$(SRCS))
PROGS = daytimetcpsrv.out daytimetcpcli.out socketSrv.out socketCli.out

all: 	$(OBJ) $(PROGS)

daytimetcpsrv.out:	daytimetcpsrv.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^

daytimetcpcli.out: 	daytimetcpcli.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^
	
socketSrv.out: 	socketSrv.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^

socketCli.out: 	socketCli.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)/$@ $<

clean:
	rm -f ./$(BINDIR)/* ./$(OBJDIR)/*