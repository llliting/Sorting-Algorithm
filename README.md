# Sorting-Algo

Collaborate with [Liting Huang](https://github.com/llliting).  

Sorting-Algorithm implements comparison sorts and counting sorts. It also provides tests to show the actual running time of data sets with different distribution.

**To run the file, type in:**
```
$ make
$ ./sorting.exe
```


**Sorting methods include:**
* bubble sort
* selection sort
* insertion sort
* merge sort
* heap sort
* quick sort
* counting sort
* radix sort 
* bucket sort  

tmp:
Roadmap:

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
