CC = g++
FLAGS = -O0

all: sortingAlgo

sortingAlgo: Sorting-Algorithm.cpp interactive.cpp
	$(CC) $(FLAGS) -o sorting.exe interactive.cpp Sorting-Algorithm.cpp
	
clean:
	rm *.exe;
