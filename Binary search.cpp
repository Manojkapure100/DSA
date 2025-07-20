#include<iostream>
#include <vector>

using namespace std;

int binarySearchUsingRecursion(vector<int> arr, int tar, int start, int end){
    if(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == tar) return mid;
        if(arr[mid] <= tar){
            return binarySearchUsingRecursion(arr,tar,mid+1, end);
        } else {
            return binarySearchUsingRecursion(arr,tar,start, mid-1);
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1,0,3,5,9,12};
    int target = 5;
    int resultIndex = binarySearchUsingRecursion(arr,target, 0, arr.size() - 1);
    cout << "Index: " << resultIndex << endl;
    return 0;
}