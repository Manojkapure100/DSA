#include<iostream>
#include "utils.h"

using namespace std;

btNode* helper(vector<int> &arr, int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = start + (end - start) / 2;
    btNode* root = new btNode(arr[mid]);
    root->left = helper(arr, start, mid - 1);
    root->right = helper(arr, mid + 1, end);
    return root;
}

btNode* buildHeightBalancedBinaryTree(vector<int> &arr){
    int start = 0;
    int end = arr.size() - 1;
    return helper(arr, start, end);
}

int main(){
    vector<int> arr = {-10, -3, 0, 3, 10};
    btNode* root = buildHeightBalancedBinaryTree(arr);
    printBinaryTreeByLevel(root);
    return 0;
}