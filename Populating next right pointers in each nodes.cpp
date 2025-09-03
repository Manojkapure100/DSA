#include<iostream>
#include "utils.h"

using namespace std;

struct btNodeWithNext{
    int val;
    btNodeWithNext* left;
    btNodeWithNext* right;
    btNodeWithNext* next;

    btNodeWithNext(int value){
        val = value;
        left = right = next = NULL;
    }
};

btNodeWithNext* pointToNext(btNodeWithNext* root){
    if (root == NULL || root->left == NULL || root->right == NULL) return root;
    queue<btNodeWithNext*> queue;

    queue.push(root);
    queue.push(NULL);

    btNodeWithNext* prev = NULL;
    while(!queue.empty()){
        btNodeWithNext* current = queue.front();
        queue.pop();

        if(current == NULL){
            if(queue.empty()) break;
            queue.push(NULL);
        } else {
            if(current->left != NULL) queue.push(current->left);
            if(current->right != NULL) queue.push(current->right);

            if(prev != NULL) prev->next = current;
        }
        prev = current;
    }

    return root;
}

static int buildTreeIdxWithNext = -1;
btNodeWithNext* buildTreeWithNext(vector<int> arr){
    buildTreeIdxWithNext++;
    if(arr[buildTreeIdxWithNext] == -1){
        if(buildTreeIdxWithNext == arr.size() - 1) buildTreeIdxWithNext = -1;
        return NULL;
    }
    btNodeWithNext* newNode = new btNodeWithNext(arr[buildTreeIdxWithNext]);
    newNode->left = buildTreeWithNext(arr);
    newNode->right = buildTreeWithNext(arr);
    return newNode;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1, 5,-1,-1,3,6,-1,-1,7,-1,-1};
    btNodeWithNext* root = buildTreeWithNext(arr);
    btNodeWithNext* ans = pointToNext(root);
    return 0;
}