# Sorting-Algo

Collaborate with [Liting Huang](https://github.com/llliting).  

Sorting-Algorithm implements most of common used comparison sorts and linear sorts with some slight adujusment. It also provides a sample test case to show the actual running time of the sorting algorithm.

**To run the sample test, type in:**
```
$ make
$ ./sorting.exe
```
**Sorting Algorithms:**
* bubble sort
* recursive bubble sort
* bubble sort(inline assembly code)(NOT DONE YET)
* selection sort
* insertion sort
* recursive insertion sort
* merge sort
* merge sort with insertion sort in merge proceduce*
* merge sort with selection sort in merge proceduce*
* heap sort
* quick sort
* randomized quick sort (three median method)*
* counting sort
* radix sort 
* bucket sort  

\*The implementations are based closely on the Introduction To Algorithms implementation described by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein.

To do

sorting-algorithm.cpp
  1) use inline asm to rewrite one sorting algo
  2) void compress()
  
in tools folder: 
  datasetGeneator.py:
    generate different datasets.
    
  interactive.py:
    Promote one 1) to selete sorting algorithms or 2) some default tests to run
      Especially some special tests with some that have small modifications
      Try compress to improve quicksort
    Call the functions in cpp files
    Make few tables and graphs:
      1) Matplotlib, numpy, and other python packages (on A-N)
      2) Gnuplot (on Terminal)
    Generate a running report in Excel
