#include<iostream>
#include "utils.h"

using namespace std;

class Info{
public:
    int min;
    int max;
    int size;

    Info(int minimum, int maximum, int s){
        min = minimum;
        max = maximum;
        size = s;
    }
};

Info helper(btNode* root){
    if(root == NULL){
        return Info(INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->val > left.max && root->val < right.min){
        int minimum = min(left.min, root->val);
        int maximum = max(right.max, root->val);
        int size = left.size + right.size + 1;
        return Info(minimum, maximum, size);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int getLargestBST(btNode* root){
    Info info = helper(root);
    return info.size;
}

int main(){
    vector<int> arr = {10,5,1,-1,-1,8,-1,-1,15,-1,20,-1,-1};
    btNode* root = buildTree(arr);
    
    cout << "Largest BST: " << getLargestBST(root) << endl;
    return 0;
}