#include <iostream>
#include "utils.h"
// #include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

void kthLargest(btNode *root, int level, unordered_map<int, long long> &map)
{
    if (root == NULL) return;
    map[level] += root->val;
    kthLargest(root->left, level + 1, map);
    kthLargest(root->right, level + 1, map);
}

long long kthLargestLevelSum(btNode *root, int k)
{
    unordered_map<int, long long> map; // level, sum
    vector<long long> ans;

    if (root == NULL) return -1;
    kthLargest(root, 0, map);

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (auto &element : map)
    {
        minHeap.push(element.second);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    if(minHeap.size() == k){
        return minHeap.top();
    } else {
        return -1;
    }
}

int main()
{
    vector<int> arr = {5, 8, 2, 4, -1, -1, 6, -1, -1, 1, -1, -1, 9, 3, -1, -1, 7, -1, -1};
    // vector<int> arr = {5,8,2,-1,-1, 1,-1,-1,9,3,-1,-1,7,-1,-1};
    btNode *root = buildTree(arr);
    printBinaryTreeByLevel(root);
    cout << endl << endl;
    int ans = kthLargestLevelSum(root, 2);
    cout << "Kth largest sum: " << ans << endl;
    return 0;
}