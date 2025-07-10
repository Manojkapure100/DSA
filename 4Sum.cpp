#include <iostream>
#include <vector>
#include "utils.h"
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> pairs = {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size();)
        {
            int start = j + 1;
            int end = nums.size() - 1;
            while (start < end)
            {
                long long ans = (long long)nums[i] + (long long)nums[j] + (long long)nums[start] + (long long)nums[end];
                if (ans < target)
                {
                    start++;
                }
                else if (ans > target)
                {
                    end--;
                }
                else
                {
                    vector<int> pair = {nums[i], nums[j], nums[start],
                                        nums[end]};
                    pairs.push_back(pair);
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1])
                    {
                        start++;
                    }
                }
            }
            j++;
            while (j < nums.size() && nums[j] == nums[j - 1])
                j++;
        }
    }
    return pairs;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    printVector(ans, "ans:");
    return 0;
}