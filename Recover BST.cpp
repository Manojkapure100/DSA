#include<iostream>
#include "utils.h"

using namespace std;

//         10
//     8       11 
// 6       12       9

btNode* previous = NULL;
btNode* first = NULL;
btNode* second = NULL;

// void printInorderBinaryTree(btNode* root){
//     if(root == NULL) return;
//     printInorderBinaryTree(root->left);
//     cout << root->val << " ";
//     printInorderBinaryTree(root->right);
// }

void getInorder(btNode* root){
    if(root == NULL) return;
    getInorder(root->left);
    if(previous != NULL && previous->val > root->val){
        if(first == NULL){
            first = previous;
        }
        second = root;
    }
    previous = root;
    getInorder(root->right);
}

btNode* recoverBST(btNode* root){
    getInorder(root);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
    return root;
}

int main(){
    vector<int> arr = {6,3,1,-1,-1,8,-1,-1,4,-1,9,-1,-1};
    vector<int> inorderArr;
    btNode* root = buildTree(arr);
    printInorderBinaryTree(root);
    cout << endl;
    btNode* ans = recoverBST(root);
    printInorderBinaryTree(ans);
    cout << endl;
    return 0;
}