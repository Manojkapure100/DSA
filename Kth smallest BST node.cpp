#include<iostream>
#include "utils.h"

using namespace std;

int previous = 0;

int kthSmallest(btNode* root, int k) {
    if(root == NULL) return -1;

    // left
    if(root->left != NULL){
        int left = kthSmallest(root->left, k);
        if(left != -1) return left;
    }

    // root
    if(previous + 1 == k) return root->val;
    previous++;

    // right
    if(root->right != NULL){
        int right = kthSmallest(root->right, k);
        if(right != -1) return right;
    }

    return -1;
}

int main(){
    vector<int> arr = {11,9,2,1,-1,-1,-1,10,-1,-1,17,-1,-1};
    btNode* root = buildTree(arr);
    // printBinaryTreeByLevel(root);
    int k = 4;
    int ans = kthSmallest(root, k);
    cout << "ans: " << ans << endl;
    return 0;
}