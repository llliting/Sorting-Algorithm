//
//  interactive.cpp
//  
//
//  Created by Zhengyi Xiao on 10/11/19.
//

#include <stdio.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include "Sorting-Algorithm.cpp"
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    char cCurrentPath[FILENAME_MAX];
    
    string sampleData[] = {"/uniform.csv", "/norm.csv", "/gamma.csv", "/expon.csv", "/poisson.csv", "/binom.csv", "/bernoulli.csv", "/0-1.csv", "/bestCase.csv", "/worstCase.csv"};
    
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
        return errno;
    
    string dataPath = std::string(cCurrentPath) + "/tools";
    
    for(int j = 0; j < 7; j ++){
        string data(dataPath + sampleData[j]);
        cout << "***** Test of " << sampleData[j].substr(1) << " Distribution Dataset *****" << endl;

        fstream fin;

        fin.open(data, ios::in);
        
        string temp;
        int size = 0;
        int i = 0;
        fin >> temp;
        vector<double> vec;

        while(fin >> temp){
            i = 0;
            while(temp.substr(i, 1) != ","){
                i++;
            }
            i += 1;
            vec.push_back(stod(temp.substr(i)));
            size++;
        }
        double* arr = new double[size];
        copy(vec.begin(), vec.end(), arr);

        //testOfTwoPara(arr, size, bubbleSort, "BubbleSort");
        //testOfTwoPara(arr, size, recursiveBubbleSort, "RecursiveBubbleSort");
        testOfTwoPara(arr, size, selectionSort, "SelectionSort");
        testOfTwoPara(arr, size, insertionSort, "InsertionSort");
        testOfTwoPara(arr, size, recursiveInsertionSort, "RecursiveInsertionSort");
        testOfThreePara(arr, size, mergeSort, "MergeSort");
        testOfThreePara(arr, size, mergeSortSelection, "MergeSort + Selection");
        testOfThreePara(arr, size, mergeSortInsertion, "MergeSort + Insertion");
        testOfTwoPara(arr, size, heapSort, "HeapSort");
        testOfThreePara(arr, size, quickSort, "QuickSort");
        testOfThreePara(arr, size, randomizedQuckSort, "RandomizedQuckSort");
        delete[] arr;
    }
    for(int j = 7; j < 10; j ++){
        string data(dataPath + sampleData[j]);
        cout << "***** Test of " << sampleData[j].substr(1) << " Distribution Dataset *****" << endl;
        
        fstream fin;
        
        fin.open(data, ios::in);
        
        string temp;
        int size = 0;
        int i = 0;
        fin >> temp;
        vector<double> vec;
        
        while(fin >> temp){
            i = 0;
            while(temp.substr(i, 1) != ","){
                i++;
            }
            i += 1;
            vec.push_back(stod(temp.substr(i)));
            size++;
        }
        double* arr = new double[size];
        copy(vec.begin(), vec.end(), arr);
        int* arr2 = new int[size];
        copy(vec.begin(), vec.end(), arr2);
        
        testOfTwoPara(arr, size, bubbleSort, "BubbleSort");
        testOfTwoPara(arr, size, recursiveBubbleSort, "RecursiveBubbleSort");
        testOfTwoPara(arr, size, selectionSort, "SelectionSort");
        testOfTwoPara(arr, size, insertionSort, "InsertionSort");
        testOfTwoPara(arr, size, recursiveInsertionSort, "RecursiveInsertionSort");
        testOfThreePara(arr, size, mergeSort, "MergeSort");
        testOfThreePara(arr, size, mergeSortSelection, "MergeSort + Selection");
        testOfThreePara(arr, size, mergeSortInsertion, "MergeSort + Insertion");
        testOfTwoPara(arr, size, heapSort, "HeapSort");
        testOfThreePara(arr, size, quickSort, "QuickSort");
        testOfThreePara(arr, size, randomizedQuckSort, "RandomizedQuckSort");
        testOfTwoPara(arr2, size, countingSort, "CountingSort");
        testOfTwoPara(arr2, size, radixSort, "RadixSort");
        testOfTwoPara(arr2, size, bucketSort, "BucketSort");
        delete[] arr;
        delete[] arr2;
    }
    return 0;
}
