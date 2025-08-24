#include<iostream>
#include "utils.h"

using namespace std;

void PrintBinaryTreePath(btNode* root, vector<int> store, vector<string> &str){
    if(root == NULL) return;
    store.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        string tmp;
        for(int s : store){
            tmp += to_string(s) + "->";
        }
        tmp.resize(tmp.size() - 2);
        str.push_back(tmp);
        return;
    }
    PrintBinaryTreePath(root->left, store, str);
    PrintBinaryTreePath(root->right, store, str);
}

int main(){
    vector<int> arr = {1,2,-1,5,-1,-1,3,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    cout << endl << endl;
    vector<int> store;
    vector<string> str;
    PrintBinaryTreePath(root, store, str);
    printVector(str, "strings: ");
    return 0;
}