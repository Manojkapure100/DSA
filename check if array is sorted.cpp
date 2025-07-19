#include<iostream>
#include <vector>

using namespace std;

bool arrayIsSorted(vector<int> arr, int size){
    if(size == 0 || size == 1){
        return true;
    }
    return arr[size-1] >= arr[size-2] && arrayIsSorted(arr, size-1);
}

int main(){
    vector<int> arr = {1,2,8,4,5};
    if(arrayIsSorted(arr, arr.size())){
        cout << "array is sorted";
    } else {
        cout << "array is not sorted";
    }
    return 0;
}