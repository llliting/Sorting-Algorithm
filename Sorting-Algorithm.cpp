//
//  Sorting-Algorithm.cpp
//  Sort-Algo-Project
//
//  Created by 肖正义 on 10/6/19.
//  Copyright © 2019 Zhengyi Xiao and Liting Huang. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include <math.h>

using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int* getRandom(int size) {
    int* arr = new int[size];
    
    srand( (unsigned)time(NULL));
    for (int i = 0; i < size; ++i)
        arr[i] = rand();
    
    return arr;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* copyArray(int arr[], int size){
    int* sortedArr = new int[size];
    for(int i = 0; i < size; i++)
        sortedArr[i] = arr[i];
    return sortedArr;
}


void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void recursiveBubbleSort(){
    
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i ++){
        int* small = &arr[i];
        for(int j = i+1; j < size; j ++)
            if(arr[j] < *small)
                small = &arr[j];
        swap(small, &arr[i]);
    }
}

void insertionSort(){
    
}

void recursiveInsertionSort(){
    
}

void mergeSort(){
    
}

//Sikp this
void mergeSortWithInsertion(){
    
}

void heapSort(){
    
}

//Stop here
int partition (int arr[], int p, int q)
{
    int pivot = arr[q];
    int i = (p - 1);
    
    for (int j = p; j < q; j++)
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    swap(&arr[i + 1], &arr[q]);
    return (i + 1);
}


void quickSort(int arr[], int p, int q)
{
    if (p < q)
    {
        int par = partition(arr, p, q);
        quickSort(arr, p, par - 1);
        quickSort(arr, par + 1, q);
    }
}

void randomQuckSort(){
    
}

void countingSort(){
    
}

void radixSort(){
    
}

void bucketSort(){
    
}

bool verify(int arr[], int size){
    for(int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

using namespace std::chrono;

int main()
{
    
    cout << "***** Test of Wide Range Uniform Distribution Dataset *****" << endl;
    int size = 100000;
    cout << "Large number of data: " << size << endl;
    int* arr1 = getRandom(size);
    
    //Bubblesort test starts here
    int* arrBubbleSort = copyArray(arr1, size);
    auto start = high_resolution_clock::now();
    bubbleSort(arrBubbleSort, size);
    auto stop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(stop - start);
    cout << "Bubble Sort   : " << time_span.count() << " seconds  " << endl;
    
    //Selection sort test
    int* arrSelectionSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    selectionSort(arrSelectionSort, size);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Selection Sort: " << time_span.count() << " seconds  " << endl;
    
    //Quick sort test
    int* arrQuickSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    quickSort(arrQuickSort, 0, size - 1);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Quick Sort    : " << time_span.count() << " seconds " << endl;
    
    size = 10000;
    cout << "Small number of data: " << size << endl;
    arr1 = getRandom(size);
    
    //Bubblesort test starts here
    arrBubbleSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    bubbleSort(arrBubbleSort, size);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Bubble Sort   : " << time_span.count() << " seconds  " << endl;
    
    //Selection sort test
    arrSelectionSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    selectionSort(arrSelectionSort, size);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Selection Sort: " << time_span.count() << " seconds  " << endl;
    
    //Quick sort test
    arrQuickSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    quickSort(arrQuickSort, 0, size - 1);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Quick Sort    : " << time_span.count() << " seconds " << endl;
    
    
    cout << "***** Test of Narrow Range Uniform Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Normal Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Chi-Squared Distribution Dataset *****" << endl;
    
    cout << "***** Test of Narrow Range Two Picks Distribution Dataset *****" << endl;
    
    return 0;
}
