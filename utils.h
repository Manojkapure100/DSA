// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printVector(vector<T> arr, string msg="") {
    cout << endl;
    if(msg.size() > 0){
        cout << msg << " ";
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapVectorElement(vector<int> &arr, int first, int second){
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

#endif
