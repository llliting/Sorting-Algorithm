CC = g++
FLAGS = -Wall -O0

all: sortingAlgo

sortingAlgo: Sorting-Algorithm.cpp
	$(CC) $(FLAGS) -o sorting.exe interactive.cpp
	
clean:
	rm *.exe;