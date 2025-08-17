#include<iostream>

using namespace std;

struct btNode {
    int val;
    btNode *left;
    btNode *right;
    btNode(int v){
        val = v;
        left = right = NULL;
    } 
};

bool isSame(btNode *node1, btNode *node2){
    if(node1 == NULL || node2 == NULL){
        return node1 == node2;
    }
    bool isLeftSame = isSame(node1->left, node2->left);
    bool isRightSame = isSame(node1->right, node2->right);
    return isLeftSame && isRightSame && node1->val == node2->val;
}

int main(){
    btNode *node1 = new btNode(1);
    node1->left = new btNode(2);
    node1->right = new btNode(3);

    btNode *node2 = new btNode(1);
    node2->left = new btNode(2);
    node2->right = new btNode(3);

    bool ans = isSame(node1, node2);
    cout << "isSame: " << ans << endl;
    return 0;
}