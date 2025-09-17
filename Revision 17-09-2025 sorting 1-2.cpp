#include <iostream>
#include "utils.h"

using namespace std;

void sortColors(vector<int> &arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[mid], arr[low]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        default:
            break;
        }
    }
}

void nextPermutation(vector<int> &arr){
    int pointer = arr.size() - 1;
    while(pointer > 0 && arr[pointer] < arr[pointer-1]){
        pointer--;
    }
    if(pointer == 0){
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    } else {
        int pivotElement = pointer - 1;
        int lastElement = arr.size() - 1;
        while(arr[pivotElement + 1] < arr[lastElement]){
            lastElement--;
        }
        swap(arr[pivotElement], arr[lastElement]);

        int start = pointer;
        int end = arr.size() - 1;

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