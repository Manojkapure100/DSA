#include<iostream>
#include<vector>
#include "utils.h"

using namespace std;

void getsubsets(vector<int> arr, vector<int> subset, int level, vector<vector<int>> &result){
    if(level == arr.size()){
        result.push_back(subset);
        return;
    }

    //include
    subset.push_back(arr[level]);
    getsubsets(arr, subset, level+1, result);

    // backtracking
    subset.pop_back();

    //exclude all repeating value
    int idx = level + 1;
    while(idx < arr.size() && arr[idx] == arr[idx-1]){
        idx++;
    }
    getsubsets(arr, subset, idx, result);
}

int main(){
    vector<int> arr = {1,2,2};
    vector<int> subset = {};
    int level = 0;
    vector<vector<int>> result = {};
    getsubsets(arr, subset, level, result);
    printVector(result, "length of result: "+ to_string(result.size())+" and arr: ");
    return 0;
}