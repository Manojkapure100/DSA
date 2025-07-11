#include<iostream>
#include <vector>
#include <unordered_set>
#include "utils.h"

using namespace std;

vector<vector<int>> result;

void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

int main(){
    vector<int> nums = {1,2,3};
    printVector(permute(nums), "All permutations of the array: ");
    return 0;
}