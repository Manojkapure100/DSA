#include<iostream>
#include "utils.h"

using namespace std;

int heightOfBinaryTree(btNode* root, int &ans){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfBinaryTree(root->left, ans);
    int rightHeight = heightOfBinaryTree(root->right, ans);
    int currentDiameter = leftHeight + rightHeight;
    ans = max(ans, currentDiameter);
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(btNode* root) {
    int ans = 0;
    heightOfBinaryTree(root, ans);
    return ans;
}

int main(){
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    btNode* root = buildTree(arr);
    int ans = diameterOfBinaryTree(root); // longest road from one leaf node to another leaf node
    cout << "ans: " << ans << endl;
    return 0;
}