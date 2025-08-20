#include<iostream>
#include "utils.h"

using namespace std;

bool isIdentical(btNode* root1, btNode* root2){
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    return root1->val == root2->val 
            && isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right);
}

bool isSubTree(btNode* treeRoot, btNode* subTreeRoot){
    if(treeRoot == NULL || subTreeRoot == NULL){
        return treeRoot == subTreeRoot;
    }
    if(treeRoot->val == subTreeRoot->val && isIdentical(treeRoot, subTreeRoot)){
        return true;
    }
    return isSubTree(treeRoot->left, subTreeRoot)
            || isSubTree(treeRoot->right, subTreeRoot);
}

int main(){
    vector<int> tree = {3,4,1,-1,-1,2,-1,-1,5,-1,-1};
    vector<int> subTree = {4,1,-1,-1,2,-1,-1};
    btNode* treeRoot = buildTree(tree);
    btNode* subTreeRoot = buildTree(subTree);
    printBinaryTreeByLevel(treeRoot);
    cout << endl << endl;
    printBinaryTreeByLevel(subTreeRoot);
    cout << endl << endl;
    bool ans = isSubTree(treeRoot, subTreeRoot);
    cout << (ans ? "same" : "not Same");
    return 0;
}