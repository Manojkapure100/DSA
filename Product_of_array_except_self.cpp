#include<iostream>
#include<vector>
#include "utils.h"

using namespace std;

vector<int> getProductOfArrayExceptSelf(vector<int> arr){
    vector<int> ans = {};

    for (int i = 0; i < arr.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < arr.size(); j++)
        {
            if(i!=j){
                product = product * arr[j];
            }
        }
        ans.push_back(product);
    }
    return ans;
} 

vector<int> getProductOfArrayExceptSelfOptimiseByTimeAndSpace(vector<int> arr){
    vector<int> ans(arr.size(), 1);
    // find prefix
    for (int i = 1; i < arr.size(); i++)
    {
        ans[i] = ans[i-1] * arr[i-1];
    }
    printVector(ans, "Prefix");
     
    // find suffix
    int suffix = 1;
    for (int i = arr.size()-2; i >= 0; i--)
    {
        ans[i] = (ans[i]) * suffix * arr[i+1];
        suffix = suffix * arr[i+1];
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4};
    printVector(arr, "Original Array");
    vector<int> ans = {};
    ans = getProductOfArrayExceptSelf(arr);
    ans = getProductOfArrayExceptSelfOptimiseByTimeAndSpace(arr);
    printVector(ans, "Product of array except self");
    return 0;
}