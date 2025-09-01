#include<iostream>
#include "utils.h"

using namespace std;

btNode* lowestCommonAncestor(btNode* root, btNode* p, btNode* q) {
    if(root == NULL) return NULL;

    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    } else if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
}

int main(){
    vector<int> root = {6,2,0,-1,-1,4,3,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1};
    vector<int> p = {2,0,-1,-1,4,3,-1,-1,5,-1,-1};
    vector<int> q = {8,7,-1,-1,9,-1,-1};

    btNode* rootNode = buildTree(root);
    btNode* pNode = buildTree(p);
    btNode* qNode = buildTree(q);

    printBinaryTreeByLevel(rootNode);
    cout << endl;
    printBinaryTreeByLevel(pNode);
    cout << endl;
    printBinaryTreeByLevel(qNode);
    cout << endl;
    
    btNode* ans = lowestCommonAncestor(rootNode, pNode, qNode);
    cout << "Ans: " << ans->val << endl;
    return 0;
}