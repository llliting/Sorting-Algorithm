//
//  Sorting-Algorithm.cpp
//  Sort-Algo-Project
//
//  Created by Zhengyi Xiao on 10/6/19.
//  Copyright © 2019 Zhengyi Xiao and Liting Huang. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include <math.h>
#include <iomanip>

using namespace std;

inline void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

inline int* getRandom(int size) {
    int* arr = new int[size];
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; ++i)
        arr[i] = rand();
    
    return arr;
}

inline void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

inline int* copyArray(int arr[], int size){
    int* sortedArr = new int[size];
    for(int i = 0; i < size; i++)
        sortedArr[i] = arr[i];
    return sortedArr;
}

inline void verify(int arr[], int size){
    for(int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]){
            cout << "***WRONG***: " << arr[i] << " " << arr[i + 1] << endl;
            return;
        }
    cout << "***VERIFIED***" << endl;
}

inline void bubbleSort(int arr[], int size){
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

inline void recursiveBubbleSort(int arr[], int size){
    if (size == 1)
        return;
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    recursiveBubbleSort(arr, size - 1);
}

inline void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i ++){
        int* small = &arr[i];
        for(int j = i+1; j < size; j ++)
            if(arr[j] < *small)
                small = &arr[j];
        swap(small, &arr[i]);
    }
}

inline void insertionSort(int arr[], int size){
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

inline void recursiveInsertionSort(int arr[], int size){
    if (size == 1)
        return;
    
    recursiveInsertionSort(arr, size - 1);
    int j = size - 2;
    
    while (j >= 0 && arr[j] > arr[size-1]){
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = arr[size-1];
}

inline void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

inline void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

inline void insertion_sort(int A[], int p, int r) {
    int i, j, key;
    
    for (j = p + 1; j <= r; j++) {
        key = A[j];
        i = j - 1;
        while (i >= p && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

inline void mergeSortInsertion(int A[], int p, int r) {
    if (p >= r) return;
    
    if (r - p < 20){
        insertion_sort(A, p, r);
    }
    else{
        int q = (p + r) / 2;
        mergeSortInsertion(A, p, q);
        mergeSortInsertion(A, q + 1, r);
        merge(A, p, q, r);
    }
}

inline void selection_sort(int A[], int p, int r) {
    int min, temp;
    for (int i = p; i < r; i++) {
        min = i;
        for (int j = i + 1; j <= r; j++)
            if (A[j] < A[min])
                min = j;
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

inline void mergeSortSelection(int A[], int p, int r) {
    if (p >= r)
        return;
    if (r - p < 20) {
        selection_sort(A, p, r);
    }
    else {
        int q = (p + r) / 2;
        mergeSortSelection(A, p, q);
        mergeSortSelection(A, q + 1, r);
        merge(A, p, q, r);
    }
}

inline void maxHeap(int arr[], int size, int i){
    int largest = i;
    int l = (i << 1) + 1;
    int r = (i << 1) + 2;
    
    if (l < size and arr[l] > arr[largest])
        largest = l;
    
    if (r < size and arr[r] > arr[largest])
        largest = r;
    
    if (largest != i){
        swap(arr[i], arr[largest]);
        maxHeap(arr, size, largest);
    }
}

inline void heapSort(int arr[], int size){
    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeap(arr, size, i);
    
    for (int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        maxHeap(arr, i, 0);
    }
}

inline int partition(int arr[], int p, int q){
    int pivot = arr[q];
    int i = (p - 1);
    
    for (int j = p; j < q; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    
    swap(&arr[i + 1], &arr[q]);
    return (i + 1);
}

inline void quickSort(int arr[], int p, int q){
    if (p < q){
        int part = partition(arr, p, q);
        quickSort(arr, p, part - 1);
        quickSort(arr, part + 1, q);
    }
}

inline int randomizedPartition(int arr[], int p, int q){
    srand((unsigned)time(NULL));
    int i = 0;
    int A[3] = {0};
    for(;i < 3;i++)
        A[i] = arr[p + rand() % (( q + 1 ) - p)];
    int pivot = A[1];
    
    i = (p - 1);
    for (int j = p; j < q; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    
    swap(&arr[i + 1], &arr[q]);
    return (i + 1);
}

inline void randomizedQuckSort(int arr[], int p, int q){
    if (p < q){
        int part = partition(arr, p, q);
        quickSort(arr, p, part - 1);
        quickSort(arr, part + 1, q);
    }
}

inline void countingSort(int arr[], int size){
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i < size; i++){
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    
    int* count = new int[max - min + 1];
    int output[size];
    
    for(int i = 0; i < size; i++)
        count[arr[i] - min]++;
    
    for(int i = 1; i < max - min + 1; i++)
        count[i] += count[i - 1];
    
    for(int i = size - 1; i > -1; i--){
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    for(int i = 0; i < size; i++)
        arr[i] = output[i];
    delete[] count;
}

inline void countSort_Radx(int arr[], int size, int exp){
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

inline void radixSort(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++)
        max = (arr[i] > max) ? arr[i] : max;
    
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort_Radx(arr, size, exp);
}

inline void bucketSort(int arr[], int size) {
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
    cout << std::setw(30) << name << ": " << std::setw(12) << time_span.count();
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
    cout << std::setw(30) << name << ": " << std::setw(12) << time_span.count();
    cout << right;
    cout << std::setw(10) << "seconds" << endl;
}

int main(){
    cout << "***** Test of Wide Range Uniform Distribution Dataset *****" << endl;
    int size = 100000;
    cout << "Number of data: " << size << endl;
    int* arr1 = getRandom(size);
    
    testOfTwoPara(arr1, size, bubbleSort, "BubbleSort");
    testOfTwoPara(arr1, size, recursiveBubbleSort, "RecursiveBubbleSort");
    testOfTwoPara(arr1, size, selectionSort, "SelectionSort");
    testOfTwoPara(arr1, size, insertionSort, "InsertionSort");
    testOfTwoPara(arr1, size, recursiveInsertionSort, "RecursiveInsertionSort");
    testOfThreePara(arr1, size, mergeSort, "MergeSort");
    testOfThreePara(arr1, size, mergeSortSelection, "MergeSort + Selection");
    testOfThreePara(arr1, size, mergeSortInsertion, "MergeSort + Insertion");
    testOfTwoPara(arr1, size, heapSort, "HeapSort");
    testOfThreePara(arr1, size, quickSort, "QuickSort");
    testOfThreePara(arr1, size, randomizedQuckSort, "RandomizedQuckSort");
    testOfTwoPara(arr1, size, countingSort, "CountingSort");
    testOfTwoPara(arr1, size, radixSort, "RadixSort");
    testOfTwoPara(arr1, size, bucketSort, "BucketSort");
    
    return 0;
}

