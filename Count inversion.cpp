#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

int merge(vector<int> &arr, int start, int mid, int end){
    vector<int> tmp;
    int i = start;
    int j = mid+1;
    int count = 0;

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            tmp.push_back(arr[i]);
            i++;
        } else {
            tmp.push_back(arr[j]);
            j++;
            count += (mid-i+1);
        }
    }

    while(i<=mid){
        tmp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        tmp.push_back(arr[j]);
        j++;
    }

    for(int k = 0; k<tmp.size(); k++){
        arr[start+k] = tmp[k];
    }
    return count;
}

int mergeSort(vector<int> &arr, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        int left = mergeSort(arr, start, mid);
        int right = mergeSort(arr, mid+1, end);

        int countInversion = merge(arr, start, mid, end);
        return left + right + countInversion;
    }
    return 0;
}

int main(){
    vector<int> arr = {6,3,5,2,7};
    int start = 0;
    int end = arr.size() - 1;
    int ans = mergeSort(arr, start, end);
    cout << "Count inversion: " << ans << endl;
    return 0;
}