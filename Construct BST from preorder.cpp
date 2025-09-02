#include<iostream>
#include "utils.h"

using namespace std;

btNode* helper(vector<int> &arr, int &i, int maxValue){
    if(i >= arr.size() || arr[i] > maxValue) return NULL;

    btNode* newNode = new btNode(arr[i]);
    i++;
    
    newNode->left = helper(arr, i, newNode->val);
    newNode->right = helper(arr, i, maxValue);
    return newNode;
}

btNode* buildBSTFromPreorderArray(vector<int> &arr){
    int i = 0;
    int maxValue = INT_MAX;
    return helper(arr, i, maxValue);
}

int main(){
    vector<int> arr = {8,5,1,7,10,12};
    btNode* root = buildBSTFromPreorderArray(arr);
    printBinaryTreeByLevel(root);
    return 0;
}