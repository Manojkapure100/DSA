#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

static int idx = -1;
btNode* buildTree2(vector<int> arr){
    idx++;
    if(arr[idx] == -1){
        return NULL;
    }
    btNode* newNode = new btNode(arr[idx]);
    newNode->left = buildTree2(arr);
    newNode->right = buildTree2(arr);
    return newNode;
}

void preorderTraversal(btNode* root) { // root, left, right
    if(root == NULL){
        return;
    }
    cout << root->val << "\t";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(btNode* root) { // root, left, right
    if(root == NULL){
        return;
    }
    preorderTraversal(root->left);
    cout << root->val << "\t";
    preorderTraversal(root->right);
}

void postorderTraversal(btNode* root) { // root, left, right
    if(root == NULL){
        return;
    }
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout << root->val << "\t";
}

int main(){
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    btNode* root = buildTree2(arr);
    preorderTraversal(root);
    cout << "\n";
    inorderTraversal(root);
    cout << "\n";
    postorderTraversal(root);
    cout << "\n";
    return 0;
}