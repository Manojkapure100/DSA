#include<iostream>
#include "utils.h"

using namespace std;

btNode* inorderPrecedor(btNode* root){ // left most of right subtree
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

btNode* deleteNode(btNode* root, int val){
    if(root == NULL) return NULL;
    if(val < root->val){
        root->left = deleteNode(root->left, val);
    } else if(val > root->val){
        root->right = deleteNode(root->right, val);
    } else { // single child
        if(root->left == NULL){
            btNode* tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == NULL){
            btNode* tmp = root->left;
            delete root;
            return tmp;
        } else { // 2 child
            btNode* precedor = inorderPrecedor(root->right);
            root->val = precedor->val;
            root->right = deleteNode(root->right, precedor->val);
        }
    }
    return root;
}

bool searchNode(btNode* root, int search){
    if(root == NULL) return false;
    if(search < root->val){
        return searchNode(root->left, search);
    } else if(search > root->val){
        return searchNode(root->right, search);
    } else {
        return true;
    }
}

void printInorderTree(btNode* root){
    if(root == NULL) return;
    printInorderTree(root->left);
    cout << root->val << " ";
    printInorderTree(root->right);
}

btNode* insert(btNode* root, int val){
    if(root == NULL) return new btNode(val);
    if(val < root->val){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

btNode* buildBST(vector<int> arr){
    btNode* root = NULL;
    for (int value : arr) {
        root = insert(root, value);
    }
    return root;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    btNode* root = buildBST(arr);
    printInorderTree(root);
    cout << endl;
    int searchNumber = 8;
    cout << "is " << searchNumber << " available: " << (searchNode(root, searchNumber) ? "Yes" : "No") << endl;
    int deleteNumber = 3;
    deleteNode(root, deleteNumber);
    printInorderTree(root);
    return 0;
}