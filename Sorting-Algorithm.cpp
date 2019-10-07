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
#include <iomanip>

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

void verify(int arr[], int size){
    for(int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            cout << "***VERIGIED***" << endl;
    cout << "***SORTING IS NOT CORRECT***" << endl;
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

//Do the range test here *for me
void countingSort(int arr[], int size){
    int max = arr[0];
    int min = arr[0];
    
    for(int i = 0; i < size; i++){
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    
    int* count = new int[max - min + 1];
    int* output = new int[size];
    
    for(int i = 0; i < size; i++)
        count[arr[i]-min]++;
    
    for(int i = 1; i < size; i++)
        count[i] += count[i-1];
    
    for(int i = size - 1; i > -1; i--)
    {
        output[count[arr[i]-min] -1 ] = arr[i];
        count[arr[i]-min]--;
    }
    
    for(int i = 0; i < size; i++)
        arr[i] = output[i];
    
    delete[] count;
    delete[] output;
    //verify(arr, size);
}

void radixSort(){
    
}

void bucketSort(){
    
}



using namespace std::chrono;

void testOfTwoPara(int arr[], int size, void (*sortAlgo)(int[], int), string name){
    int* arrToBeSorted = copyArray(arr, size);
    auto start = high_resolution_clock::now();
    (*sortAlgo)(arrToBeSorted, size);
    auto stop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(stop - start);
    cout << left;
    cout << showpoint;
    cout << std::setw(15) << name << ": " << time_span.count();
    cout << right;
    cout << std::setw(15) << "seconds" << endl;
}

void testOfThreePara(int arr[], int size, void (*sortAlgo)(int[], int, int), string name){
    int* arrToBeSorted = copyArray(arr, size);
    auto start = high_resolution_clock::now();
    (*sortAlgo)(arrToBeSorted, 0, size - 1);
    auto stop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(stop - start);
    cout << left;
    cout << std::setw(15) << name << ": " << time_span.count() << " seconds  " << endl;
}


int main(){
    cout << "***** Test of Wide Range Uniform Distribution Dataset *****" << endl;
    int size = 10000;
    cout << "Large number of data: " << size << endl;
    int* arr1 = getRandom(size);
    
    testOfTwoPara(arr1, size, bubbleSort, "BubbleSort");
    testOfTwoPara(arr1, size, selectionSort, "SelectionSort");
    testOfTwoPara(arr1, size, insertionSort, "InsertionSort");
    testOfThreePara(arr1, size, quickSort, "QuickSort");
    testOfTwoPara(arr1, size, countingSort, "CountingSort");
    
    
    size = 1000;
    cout << "\nSmall number of data: " << size << endl;
    arr1 = getRandom(size);
    
    testOfTwoPara(arr1, size, bubbleSort, "BubbleSort");
    testOfTwoPara(arr1, size, selectionSort, "SelectionSort");
    testOfTwoPara(arr1, size, insertionSort, "InsertionSort");
    testOfThreePara(arr1, size, quickSort, "QuickSort");
    testOfTwoPara(arr1, size, countingSort, "CountingSort");
    
    
    cout << "***** Test of Narrow Range Uniform Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Normal Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Chi-Squared Distribution Dataset *****" << endl;
    
    cout << "***** Test of Narrow Range Two Picks Distribution Dataset *****" << endl;
    
    return 0;
}
