CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

LIBS = -lpthread
BINDIR = ./bin
OBJDIR = ./obj

VPATH := $(BINDIR):$(OBJDIR)

PROGS = chatroomSrv.out chatroomCli.out


all: 	$(PROGS)

chatroomSrv.out:	chatroomSrv.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(OBJDIR)/$< $(OBJDIR)/error.o $(LIBS)

chatroomCli.out: 	chatroomCli.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(addprefix $(), $^) $(LIBS)
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)/$@ $<

clean:
		rm -f ./$(BINDIR)/* ./$(OBJDIR)/*