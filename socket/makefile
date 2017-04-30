CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

BINDIR = ./bin
OBJDIR = ./obj

LIBS = error.o
PROGS = daytimetcpsrv.out daytimetcpcli.out


all: 	$(PROGS)

daytimetcpsrv.out:	daytimetcpsrv.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(OBJDIR)/$< $(OBJDIR)/error.o

daytimetcpcli.out: 	daytimetcpcli.o error.o
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(OBJDIR)/$< $(OBJDIR)/error.o
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)/$@ $<

clean:
		rm -f ./$(BINDIR)/${PROGS} ./$BINDIR/${LIBS}