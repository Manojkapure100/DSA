#include <iostream>
#include <vector>
#include "utils.h"
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> get3SumByBruthforce(vector<int> arr, int target)
{
    vector<vector<int>> pairs = {};
    set<vector<int>> orderSet = {};

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == target)
                {
                    vector<int> pair = {arr[i], arr[j], arr[k]};
                    sort(pair.begin(), pair.end());

                    if (orderSet.find(pair) == orderSet.end())
                    {
                        pairs.push_back(pair);
                        orderSet.insert(pair);
                    }
                }
            }
        }
    }
    cout << "target: " << target << "\n";
    printVector(pairs, "Pairs: ");
    return pairs;
}

vector<vector<int>> get3SumByBetterWay(vector<int> arr, int target)
{
    vector<vector<int>> result;
    int size = arr.size();
    set<vector<int>> biggerSet;
    // a+b+c=0
    // b+c = 0 + -a
    // b+c = smallTarget
    // c = smallTarget - b
    for (int i = 0; i < size; i++)
    {
        int smallTarget = target - arr[i];
        set<int> smallSet;
        for (int j = i + 1; j < size; j++)
        {
            int third = smallTarget - arr[j];
            if (smallSet.find(third) != smallSet.end())
            {
                vector<int> pair = {arr[i], arr[j], third};
                sort(pair.begin(), pair.end());
                if (biggerSet.find(pair) == biggerSet.end())
                {
                    result.push_back(pair);
                    biggerSet.insert(pair);
                }
            }
            smallSet.insert(arr[j]);
        }
    }
    printVector(result, "Pairs: ");
    return result;
}

vector<vector<int>> get3SumByOptimiseWay(vector<int> arr, int target)
{
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue; // ignore if previous value same
        int start = i + 1;
        int end = arr.size() - 1;
        while (start < end)
        {
            int sum = arr[i] + arr[start] + arr[end];
            if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                vector<int> pair = {arr[i], arr[start], arr[end]};
                result.push_back(pair);
                start++;
                end--;
                while (start < end && arr[start] == arr[start - 1])
                    start++; // ignore if previous value same
            }
        }
    }
    printVector(result, "Pairs: ");
    return result;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    vector<vector<int>> result;
    // result = get3SumByBruthforce(arr, target);
    // result = get3SumByBetterWay(arr, target);
    result = get3SumByOptimiseWay(arr, target);
    return 0;
}