#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subArrSumEqualToTarget(vector<int> arr, int target)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum = sum + (int)arr[j];
            if (sum == target)
            {
                count++;
            }
        }
    }
    return count;
}

int subArrSumEqualToTargetOptimise(vector<int> nums, int target)
{
    int count = 0;
    vector<int> prefixSum(nums.size(), 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // target = prefixSum[j] - prefixSum[i-1]
    // prefixSum[i-1] = prefixSum[j] - target
    unordered_map<int, int> map;
    for (int j = 0; j < nums.size(); j++)
    {
        if (prefixSum[j] == target)
        {
            count++;
        }

        int value = prefixSum[j] - target;
        if (map.find(value) != map.end())
        {
            count += map[value];
        }

        if (map.find(prefixSum[j]) == map.end())
        {
            map[prefixSum[j]] = 0;
        }

        map[prefixSum[j]]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {2, 9, 22, 1, 2, 3};
    int target = 33;
    // int count = subArrSumEqualToTarget(arr,target);
    int count = subArrSumEqualToTargetOptimise(arr, target);
    cout << "total subarray: " << count << endl;
    return 0;
}