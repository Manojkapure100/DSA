#include<iostream>
#include <vector>
#include "utils.h"
#include <deque>

using namespace std;

vector<int> maxSlidingWindowSimple(vector<int>& arr, int k) {
    vector<int> ans;
    for (int i = 0; i < arr.size()-k+1; i++)
    {
        int maxElement = arr[i];
        for (int j = i; j < i+k; j++)
        {
            maxElement = max(maxElement, arr[j]);
        }
        ans.push_back(maxElement);
    }
    return ans;
}

// 12,23,56,32,67,54,78
vector<int> maxSlidingWindow(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        // remove who is small in current window
        while(dq.size() > 0 && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        // push the current
        dq.push_back(i);   
    }
    for (int i = k; i < n; i++)
    {
        // push the front one which is biggest one into the ans
        ans.push_back(arr[dq.front()]);
        // remove who is not in current window
        while(dq.size() > 0 && dq.front() <= i-k){
            dq.pop_front();
        }
        // remove who is small in current window
        while(dq.size() > 0 && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        // push the current
        dq.push_back(i);
    }
    // push the front one which is biggest one into the ans
    ans.push_back(arr[dq.front()]);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    // vector<int> arr = {12,23,56,32,67,54,78};
    int k = 3;
    vector<int> ans;
    // ans = maxSlidingWindowSimple(arr, k);
    ans = maxSlidingWindow(arr, k);
    printVector(arr, "arr: ");
    printVector(ans, "ans: ");
    return 0;
}