#include<iostream>
#include "utils.h"

using namespace std;

vector<int> morrisInorder(btNode* root){
    vector<int> ans;
    btNode* current = root;

    while(current != NULL){
        if(current->left == NULL){ // if left is null then print current and go to right
            ans.push_back(current->val);
            current = current->right;
        } else { // if left is there, find the IP
            btNode* ip = current->left;
            while(ip->right != NULL && ip->right != current){
                ip = ip->right;
            }

            if(ip->right == NULL){ // just make connection
                ip->right = current;
                current = current->left;
            } else { // break it, print current and go to right
                ip->right = NULL;
                ans.push_back(current->val);
                current = current->right;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,6,-1,-1,7,-1,-1,3,-1,8,9,-1,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    vector<int> ans = morrisInorder(root);
    printVector(ans, "ans: ");
    return 0;
}