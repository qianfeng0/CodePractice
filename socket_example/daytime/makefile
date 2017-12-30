CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

BINDIR = ./bin
OBJDIR = ./obj
#VPATH = $(BINDIR):$(OBJDIR)

SRCS	= $(wildcard *.cpp)
OBJ 	= $(patsubst %.cpp,%.o,$(SRCS))
PROGS = daytimeTcpSrv.out daytimeTcpCli.out

all: 	$(PROGS)

daytimeTcpSrv.out:	daytimeTcpSrv.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(OBJDIR)/$^

daytimeTcpCli.out: 	daytimeTcpCli.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(OBJDIR)/$^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)/$@ $<

clean:
	rm -f ./$(BINDIR)/* ./$(OBJDIR)/*