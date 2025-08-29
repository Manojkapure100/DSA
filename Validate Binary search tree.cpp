#include<iostream>
#include "utils.h"

using namespace std;

bool helper(btNode* root, btNode* min, btNode* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->val <= min->val){
        return false;
    } else if(max != NULL && root->val >= max->val){
        return false;
    } else {
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
}

bool isBSTValid(btNode* root){
    btNode* min = NULL;
    btNode* max = NULL;
    return helper(root, min, max);
}

int main(){
    // vector<int> arr = {2,1,-1,-1,3,-1,-1};
    vector<int> arr = {5,1,-1,-1,7,6,-1,-1,9,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    cout << endl;
    if(isBSTValid(root)){
        cout << "valid";
    } else {
        cout << "Invalid";
    }
    cout << endl;
    return 0;
}