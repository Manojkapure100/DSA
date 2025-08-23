#include<iostream>
#include "utils.h"

using namespace std;

btNode* lowestCommonAncestor(btNode* root, btNode* p, btNode* q) {
    if(root == NULL) return NULL;

    if(root->val == p->val || root->val == q->val){
        return root;
    }

    btNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    btNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA){
        return root;
    } else if (leftLCA == NULL){
        return rightLCA;
    } else {
        return leftLCA;
    }
}

int main(){
    vector<int> arr = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};
    vector<int> p = {5,6,-1,-1,2,7,-1,-1,4,-1,-1};
    vector<int> q = {1,0,-1,-1,8,-1,-1};

    btNode* root = buildTree(arr);
    btNode* pRoot = buildTree(p);
    btNode* qRoot = buildTree(q);

    printBinaryTreeByLevel(root);
    cout << endl << endl;
    printBinaryTreeByLevel(pRoot);
    cout << endl << endl;
    printBinaryTreeByLevel(qRoot);
    cout << endl << endl;

    btNode* ans = lowestCommonAncestor(root, pRoot, qRoot);
    cout << "ans: " << ans->val << endl;

    return 0;
}