CXX=gcc

CXXFLAGS= -Wall -g
OBJECTS=cmp	copy	encode	decode	stshell

all:$(OBJECTS)
cmp:cmp.c
	$(CXX)	$(CXXFLAGS)	-o	cmp	cmp.c

copy:copy.c
	$(CXX)	$(CXXFLAGS) -o	copy	copy.c

decode:decode.c	codecA.o	codecB.o
	$(CXX)	$(CXXFLAGS) -o	decode	decode.c

encode:encode.c	codecA.o	codecB.o
	$(CXX)	$(CXXFLAGS) -o	encode	encode.c
stshell:stshell.c 
	$(CXX)	$(CXXFLAGS)	-o	stshell	stshell.c
codecA.o:codecA.c	
	$(CXX)	$(CXXFLAGS)	-c	codecA.c
codecB.o:codecB.c	
	$(CXX)	$(CXXFLAGS)	-c	codecB.c
clean:
	rm -f *.o	$(OBJECTS)
