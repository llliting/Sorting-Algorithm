CC = g++
FLAGS = -Wall -O0

all: sortingAlgo

sortingAlgo: Sorting-Algorithm.cpp
	$(CC) $(FLAGS) -o sorting.exe Sorting-Algorithm.cpp
	
clean:
	rm *.exe;