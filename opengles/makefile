CC = gcc
CFLAGS = 
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS = -lGL -lglut -lGLU

BINDIR = ./bin
OBJDIR = ./obj

VPATH := $(BINDIR):$(OBJDIR)

SRCS	= $(wildcard *.cpp)
OBJ 	= $(patsubst %.cpp,%.o,$(SRCS))
PROGS 	= $(patsubst %.cpp,%.out,$(SRCS))

all: $(PROGS)

# %.out : %.o
# 	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $(OBJDIR)/$^ $(LDFLAGS)

# %.o : %.cpp
# 	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)/$@ $^

%.out : %.cpp
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ ./$^ $(LDFLAGS)

clean:
	rm -f ./$(BINDIR)/* ./$(OBJDIR)/*