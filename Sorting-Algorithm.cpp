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
        if (arr[i] > arr[i + 1]){
            cout << arr[i] << " " << arr[i + 1] << endl;
            return;
        }
    cout << "***VERIFIED***" << endl;
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
        while(j >=0 & arr[j] > key){
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
int partition (int arr[], int p, int q){
    int pivot = arr[q];
    int i = (p - 1);
    
    for (int j = p; j < q; j++)
        if (arr[j] < pivot){
            swap(&arr[++i], &arr[j]);
        }
    swap(&arr[i + 1], &arr[q]);
    return (i + 1);
}


void quickSort(int arr[], int p, int q){
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
inline void countingSort(int arr[], int size){
    int max = arr[0];
    
    for(int i = 0; i < size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    
    int* count = new int[max + 1];
    int output[size];
    
    for(int i = 0; i < size; i++)
        count[arr[i]]++;
    
    for(int i = 1; i < size; i++)
        count[i] += count[i - 1];
    
    for(int i = size - 1; i > -1; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for(int i = 0; i < size; i++)
        arr[i] = output[i];
    
    delete[] count;
}

void countSort_Radx(int arr[], int size, int exp){
    int output[size];
    int i, count[10] = {0};
    
    for (i = 0; i < size; i++)
        count[(arr[i]/exp)%10]++;
    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = size - 1; i >= 0; i--){
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++)
        max = (arr[i] > max) ? arr[i] : max;
    
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort_Radx(arr, size, exp);
}



void bucketSort(int arr[], int size) {
    int max = size;
    
    int bucket[10][max + 1];
    
    for(int i = 0; i < 10; i++)
        bucket[i][max] = 0;
    
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        for(int i = 0; i < max; i++) {
            int dig = (arr[i] / digit) % 10;
            bucket[dig][bucket[dig][max]++] = arr[i];
        }
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++)
                arr[idx++] = bucket[x][y];
            bucket[x][max] = 0;
        }
    }
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
    cout << std::setw(15) << name << ": " << std::setw(12) << time_span.count();
    cout << right;
    cout << std::setw(10) << "seconds" << endl;
}

void testOfThreePara(int arr[], int size, void (*sortAlgo)(int[], int, int), string name){
    int* arrToBeSorted = copyArray(arr, size);
    auto start = high_resolution_clock::now();
    (*sortAlgo)(arrToBeSorted, 0, size - 1);
    auto stop = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(stop - start);
    cout << left;
    cout << showpoint;
    cout << std::setw(15) << name << ": " << std::setw(12) << time_span.count();
    cout << right;
    cout << std::setw(10) << "seconds" << endl;
}


int main(){
    cout << "***** Test of Wide Range Uniform Distribution Dataset *****" << endl;
    int size = 100000;
    cout << "Large number of data: " << size << endl;
    int* arr1 = getRandom(size);
    
    testOfTwoPara(arr1, size, bubbleSort, "BubbleSort");
    testOfTwoPara(arr1, size, selectionSort, "SelectionSort");
    testOfTwoPara(arr1, size, insertionSort, "InsertionSort");
    testOfThreePara(arr1, size, quickSort, "QuickSort");
    testOfTwoPara(arr1, size, countingSort, "CountingSort");
    testOfTwoPara(arr1, size, radixSort, "RadixSort");
    testOfTwoPara(arr1, size, bucketSort, "BucketSort");
    
    size = 10000;
    cout << "\nSmall number of data: " << size << endl;
    arr1 = getRandom(size);
    
    testOfTwoPara(arr1, size, bubbleSort, "BubbleSort");
    testOfTwoPara(arr1, size, selectionSort, "SelectionSort");
    testOfTwoPara(arr1, size, insertionSort, "InsertionSort");
    testOfThreePara(arr1, size, quickSort, "QuickSort");
    testOfTwoPara(arr1, size, countingSort, "CountingSort");
    testOfTwoPara(arr1, size, radixSort, "RadixSort");
    testOfTwoPara(arr1, size, bucketSort, "BucketSort");
    
    cout << "***** Test of Narrow Range Uniform Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Normal Distribution Dataset *****" << endl;
    
    cout << "***** Test of Wide Range Chi-Squared Distribution Dataset *****" << endl;
    size = 1000;
    int arr2[1000] = {0};
    arr2[0] = 10000;
    arr2[999] = 1;
    for(int i = 1; i < 999; i ++)
        arr2[i] = 1;
    cout << "\nnumber of data: " << size << endl;
    
    testOfTwoPara(arr2, size, bubbleSort, "BubbleSort");
    testOfTwoPara(arr2, size, selectionSort, "SelectionSort");
    testOfTwoPara(arr2, size, insertionSort, "InsertionSort");
    testOfThreePara(arr2, size, quickSort, "QuickSort");
    testOfTwoPara(arr2, size, countingSort, "CountingSort");
    testOfTwoPara(arr2, size, radixSort, "RadixSort");
    testOfTwoPara(arr2, size, bucketSort, "BucketSort");
    cout << "***** Test of Narrow Range Two Picks Distribution Dataset *****" << endl;
    
    return 0;
}
