# CXX=clang++
CXX=g++

default: all

main.o: main.cpp
	${CXX} -c main.cpp

MinHeap.o: MinHeap.cpp
	${CXX} -c MinHeap.cpp

Preprocess.o: Preprocess.cpp
	${CXX} -c Preprocess.cpp

all: main.o MinHeap.o Preprocess.o
	${CXX} main.o MinHeap.o Preprocess.o -o prog2

clean: 
	/bin/rm -f *.o main.o MinHeap.o Preprocess.o prog2
