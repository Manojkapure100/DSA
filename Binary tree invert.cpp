#include<iostream>
#include "utils.h"

using namespace std;

btNode* invertBinaryTree(btNode* root){
    if(root == NULL) return NULL;
    btNode* left = invertBinaryTree(root->left);
    btNode* right = invertBinaryTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int main(){
    vector<int> arr = {4,2,1,-1,-1,3,-1,-1,7,6,-1,-1,9,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    cout << endl << endl;
    btNode* ans = invertBinaryTree(root);
    printBinaryTreeByLevel(ans);
    cout << endl << endl;
    return 0;
}