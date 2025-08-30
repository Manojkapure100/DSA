#include<iostream>
#include "utils.h"

using namespace std;

btNode* previous = NULL;
int ans = INT_MAX;
int minDistance(btNode* root){
    if(root == NULL) return INT_MAX;
    if(root->left != NULL){
        int left = minDistance(root->left);
        ans = min(ans, left);
    }
    if(previous != NULL){
        int diff = root->val - previous->val;
        ans = min(ans, diff);
    }
    previous = root;
    if(root->right != NULL){
        int right = minDistance(root->right);
        ans = min(ans, right);
    }
    return ans;
}

int main(){
    vector<int> arr = {4,2,1,-1,-1,3,-1,-1,6,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTree(root);
    cout << endl << "min distance: " << minDistance(root) << endl;
    return 0;
}