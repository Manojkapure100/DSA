#include<iostream>
#include<vector>
#include "utils.h"
#include <map>

using namespace std;


void rightViewOfBinaryTree(btNode* root, int level, map<int,int> &orderedMap){
    if(root == NULL){
        return;
    }
    orderedMap[level] = root->val;
    rightViewOfBinaryTree(root->left, level+1, orderedMap);
    rightViewOfBinaryTree(root->right, level+1, orderedMap);
}

int main(){
    vector<int> ans;
    map<int,int> orderedMap;
    vector<int> arr1 = {1,2,-1,5,-1,-1,3,-1,4,-1,-1};
    vector<int> arr2 = {1,2,4,5,-1,-1,-1,-1,3,-1,-1};
    btNode* root = buildTree(arr1);
    printBinaryTreeByLevel(root);
    rightViewOfBinaryTree(root, 0, orderedMap);
    for (auto omap : orderedMap)
    {
        ans.push_back(omap.second);
    }
    printVector(ans, "ans: ");
    return 0;
}