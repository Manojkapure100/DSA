#include<iostream>
#include "utils.h"

using namespace std;

int searchIndexOfValue(vector<int> &inorder, int findValue, int startPosition, int endPosition){
    for (int i = startPosition; i <= endPosition; i++)
    {
        if (inorder[i] == findValue)
        {
            return i;
        }
    }
    return -1;
}

btNode* buildTreeUsingPreorderInorderArr(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inorderStartPosition, int inorderEndPosition){
    if(inorderStartPosition > inorderEndPosition){
        return NULL;
    }
    
    int rootValue = preorder[preIndex];
    btNode* root = new btNode(rootValue);
    
    int indexOfRootValue = searchIndexOfValue(inorder, rootValue, inorderStartPosition, inorderEndPosition);
    
    preIndex++;
    root->left = buildTreeUsingPreorderInorderArr(preorder, inorder, preIndex, inorderStartPosition, indexOfRootValue - 1);
    root->right = buildTreeUsingPreorderInorderArr(preorder, inorder, preIndex, indexOfRootValue + 1, inorderEndPosition);

    return root;
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    int preIndex = 0;
    int inorderStartPosition = 0;
    int inorderEndPosition = inorder.size() - 1;

    btNode* root = buildTreeUsingPreorderInorderArr(preorder, inorder, preIndex, inorderStartPosition, inorderEndPosition);
    printBinaryTreeByLevel(root);
    
    return 0;
}