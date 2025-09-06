#include<iostream>
#include "utils.h"

using namespace std;

btNode* getRightMostOfLeftNode(btNode* root){
    btNode* rightMost = root;
    while(root != NULL){
        rightMost = root;
        root = root->right;
    }
    return rightMost;
}

btNode* getLeftMostOfRightNode(btNode* root){
    btNode* leftMost = root;
    while(root != NULL){
        leftMost = root;
        root = root->left;
    }
    return leftMost;
}

vector<int> getPredecessorAndSucessorOfBST(btNode* root, int targetValue){
    btNode* pred = NULL;
    btNode* suc = NULL;
    btNode* current = root;
    while(current != NULL){
        if(targetValue < current->val){
            suc = current;
            current = current->left;
        } else if(targetValue > current->val){
            pred = current;
            current = current->right;
        } else {
            pred = getRightMostOfLeftNode(current->left);
            suc = getLeftMostOfRightNode(current->right);
            break;
        }
    }
    return {pred->val, suc->val};
}

int main(){
    vector<int> arr = {6,4,1,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1};
    int targetValue = 8;
    btNode* root = buildTree(arr);
    printInorderBinaryTree(root);
    cout << endl;
    vector<int> ans = getPredecessorAndSucessorOfBST(root, targetValue);
    cout << "Value: " << targetValue << endl;
    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;
    return 0;
}