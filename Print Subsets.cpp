#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

    void getSubsets(vector<int> nums,vector<int> subset, vector<vector<int>> &result, int level){
        if(level==nums.size()){
            result.push_back(subset);
            return;
        }
        
        //include
        subset.push_back(nums[level]);
        getSubsets(nums, subset, result, level+1);

        //backtracking
        subset.pop_back();

        //exclude
        getSubsets(nums, subset, result, level+1);
    }

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> result = {};
    vector<int> subset = {};
    getSubsets(arr,subset, result,0);
    printVector(result, "length of "+to_string(result.size()) +" result: ");
    return 0;
}