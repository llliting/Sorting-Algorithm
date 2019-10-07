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

void insertionSort(int arr[], int size){
    int i,j, key;
    for(i = 1; i < size; i ++){
        key = arr[i];
        j = i-1;
        while(j>=0 & arr[j] > key){
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }
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
void quickSort(){
    
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
    int size = 1000;
    int* arr1 = getRandom(size);
    
    //Bubblesort test starts here
    int* arrBubbleSort = copyArray(arr1, size);
    auto start = high_resolution_clock::now();
    bubbleSort(arrBubbleSort, size);
    auto stop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(stop - start);
    cout << "Bubble Sort: " << time_span.count() << " seconds; " << endl;
    cout << "Verified: " << verify(arrBubbleSort, size) << endl;
    
    //Selection sort test
    int* arrSelectionSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    selectionSort(arrSelectionSort, size);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Selection Sort: " << time_span.count() << " seconds; " << endl;
    cout << "Verified: " << verify(arrSelectionSort, size) << endl;

    int* arrInsertionSort = copyArray(arr1, size);
    start = high_resolution_clock::now();
    insertionSort(arrInsertionSort, size);
    stop = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(stop - start);
    cout << "Insertion Sort: " << time_span.count() << " seconds; " << endl;
    cout << "Verified: " << verify(arrInsertionSort, size) << endl;
    
    cout << "***** Test of Narrow Range Uniform Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Normal Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Chi-Squared Distribution Dataset *****" << endl;
    
    cout << "***** Test of Narrow Range Two Picks Distribution Dataset *****" << endl;
    
    return 0;
}
