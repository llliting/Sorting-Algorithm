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
    
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
        return errno;
    
    string dataPath = std::string(cCurrentPath) + "/tools";

    cout << dataPath << endl;
    
    string data(dataPath + "/0-1.csv");
    
    cout << data << endl;

    fstream fin;

    fin.open(data, ios::in);
    
    string temp;
    int size = 0;
    fin >> temp;
    vector<double> vec;
    while(fin >> temp and size < 10){
        cout << temp.substr(2) << endl;
        vec.push_back(stod(temp.substr(2)));
        size++;
    }
    double* arr = new double[size];
    copy(vec.begin(), vec.end(), arr);
    printArray(arr, size);
    testOfTwoPara(arr, size, bubbleSort, "BubbleSort");
    
    return 0;
}
