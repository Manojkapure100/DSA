#include<iostream>
#include "utils.h"

using namespace std;

void flatten(btNode* &root, btNode* &current) {
    if(root == NULL) return;
    // process right
    flatten(root->right, current);
    // process left
    flatten(root->left, current);
    // connect root
    root->left = NULL;
    root->right = current;
    current = root;
}

int main(){
    vector<int> arr = {1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    btNode* current = NULL;
    flatten(root, current);
    printBinaryTreeByLevel(root);
    return 0;
}