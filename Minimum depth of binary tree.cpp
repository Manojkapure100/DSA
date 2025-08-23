#include<iostream>
#include "utils.h"

using namespace std;

int height(btNode* root){
    if(root == NULL) return 0;

    //handle if 1 is null and another is not null
    if(root->left == NULL) return height(root->right) + 1;
    if(root->right == NULL) return height(root->left) + 1;

    // if both is not null
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return min(leftHeight, rightHeight) + 1;
}

int main(){
    vector<int> arr = {3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    btNode* root = buildTree(arr);
    cout << "Min height: " << height(root) << endl;
    return 0;
}