#include<iostream>
#include "utils.h"
#include <stack>

using namespace std;

class BSTIterator {
public:
    stack<btNode*> myStack;

    void storeAllLefts(btNode* root){
        while(root != NULL){
            myStack.push(root);
            root = root->left;
        }
    }

    BSTIterator(btNode* root) {
        storeAllLefts(root);
    }
    
    int next() {
        btNode* ans = myStack.top();
        myStack.pop();

        storeAllLefts(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return myStack.size() > 0;
    }
};

int main(){
    vector<int> arr = {4,2,1,-1,-1,3,-1,-1,7,6,-1,-1,9,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    cout << endl << endl;
    BSTIterator object = BSTIterator(root);
    cout << object.next() << endl;
    cout << object.next() << endl;
    cout << "has: " << object.hasNext() << endl;
    cout << object.next() << endl;
    return 0;
}