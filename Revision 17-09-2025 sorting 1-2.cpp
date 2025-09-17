#include <iostream>
#include "utils.h"

using namespace std;

void sortColors(vector<int> &arr){
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        } else if(arr[mid] == 1){
            mid++;
        } else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

void nextPermutation(vector<int> &arr){
    int arrSize = arr.size();
    int pointer = arrSize - 1;
    while(arr[pointer] < arr[pointer-1]){
        pointer--;
    }
    if(pointer == 0){
        int start = 0;
        int end = arrSize - 1;
        while(start <= end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    } else {
        int pivotPointer = pointer - 1; //larger value
        int lastPointer = arrSize - 1;
        while(arr[pivotPointer + 1] < arr[lastPointer]){
            lastPointer--;
        }
        swap(arr[pivotPointer], arr[lastPointer]);

        int start = pointer;
        int end = arrSize - 1;
        while(start <= end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}

int main()
{
    vector<int> arr1 = {2, 0, 2, 1, 1, 0};
    sortColors(arr1);
    printVector(arr1, "Arr: ");
    cout << endl;
    vector<int> arr2 = {1,2,3};
    nextPermutation(arr2);
    printVector(arr2, "Arr: ");
    cout << endl;
    return 0;
}