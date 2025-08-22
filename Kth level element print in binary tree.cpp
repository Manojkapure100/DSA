#include<iostream>
#include "utils.h"

using namespace std;

void printKthLevelElements(btNode* root, int remainlevel){
    if(root == NULL) return;
    if(remainlevel == 1){
        cout << root->val << "\t";
        return;
    }
    printKthLevelElements(root->left, remainlevel - 1);
    printKthLevelElements(root->right, remainlevel - 1);
}

int main(){
    vector<int> arr = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    btNode* root = buildTree(arr);
    printKthLevelElements(root, 3);
    return 0;
}