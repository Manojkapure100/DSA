#include<iostream>
#include "utils.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> arr, int target){
    unordered_map<int,int> uMap; // value, index;
    for (int i = 0; i < arr.size(); i++)
    {
        int firstValue = arr[i];
        int secondValue = target - firstValue;
        if(uMap.find(secondValue) != uMap.end()){
            return {i, uMap[secondValue]};
        } else {
            uMap[firstValue] = i;
        }
    }
}

vector<vector<int>> threeSum(vector<int> arr, int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int start = i+1;
        int end = arr.size() - 1;
        while(start < end){
            int sum = arr[i] + arr[start] + arr[end];
            if(sum < target){
                start++;
            } else if(sum > target){
                end--;
            } else {
                ans.push_back({arr[i], arr[start], arr[end]});
                start++;
                end--;
                while(start < end && arr[start] == arr[start-1]){
                    start++;
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> arr, int target){
    vector<vector<int>> ans;
    unordered_map<int,int> uMap;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i+1; j < arr.size();)
        {
            int start = j+1;
            int end = arr.size() - 1;
            while(start < end){
                int sum = arr[i] + arr[j] + arr[start] + arr[end];
                if(sum < target){
                    start++;
                } else if (sum > target){
                    end--;
                } else {
                    ans.push_back({arr[i], arr[j], arr[start], arr[end]});
                    start++;
                    end--;

                    while(start < end && arr[start] == arr[start-1]){
                        start++;
                    }
                }
            }
            j++;
            while(j < arr.size() && arr[j] == arr[j-1]){
                j++;
            }
        }
    }
    return ans;
}

int main(){
    // vector<int> twoSumInput = {2,7,11,15};
    // int twoSumTarget = 18;
    // printVector(twoSumInput, "twoSumInput");
    // cout << "TwoSumTarget: " << twoSumTarget << endl;
    // vector<int> twoSumOutput = twoSum(twoSumInput, twoSumTarget);
    // printVector(twoSumOutput, "twoSumOutput");

    // vector<int> threeSumInput = {-1,0,1,2,-1,-4};
    // int threeSumTarget = 0;
    // printVector(threeSumInput, "threeSumInput");
    // cout << "threeSumTarget: " << threeSumTarget << endl;
    // vector<vector<int>> threeSumOutput = threeSum(threeSumInput, threeSumTarget);
    // printVector(threeSumOutput, "threeSumOutput");

    vector<int> fourSumInput = {1, 0, -1, 0, -2, 2};
    printVector(fourSumInput, "fourSumInput");
    int fourSumTarget = 0;
    cout << "fourSumTarget: " << fourSumTarget << endl;
    vector<vector<int>> fourSumOutput = fourSum(fourSumInput, fourSumTarget);
    printVector(fourSumOutput, "fourSumOutput");
    return 0;
}