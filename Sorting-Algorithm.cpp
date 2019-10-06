//
//  main.cpp
//  Sort-Algo-Project
//
//  Created by 肖正义 on 10/6/19.
//  Copyright © 2019 Zhengyi Xiao. All rights reserved.
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

void selectionSort(){
    
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
void quckSort(){
    
}

void randomQuckSort(){
    
}

void countingSort(){
    
}

void radixSort(){
    
}

void bucketSort(){
    
}

using namespace std::chrono;

int main()
{
    
    cout << "***** Test of Wide Range Uniform Distribution Dataset *****" << endl;
    int size = 100000;
    int* arr1 = getRandom(size);
    
    //Bublesort test starts here
    int* arrBobbleSort = copyArray(arr1, size);
    auto start = high_resolution_clock::now();
    bubbleSort(arrBobbleSort, size);
    auto stop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(stop - start);
    cout << "Bubble Sort: " << time_span.count() << " seconds; " << endl;
    
    //Maske sure start by coping a new array from arr1
    
    return 0;
}
