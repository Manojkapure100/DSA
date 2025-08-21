#include<iostream>
#include<vector>
#include "utils.h"
#include <map>

using namespace std;

vector<int> topViewOfBinaryTree(btNode* root){
    queue<pair<btNode*, int>> queue; // (node, Horizontal Position)
    queue.push({root, 0}); // root start with zero
    map<int, int> map; // to store hash but with sortly

    while(!queue.empty()){
        btNode* currentNode = queue.front().first;
        int horizontalPosition = queue.front().second;
        queue.pop();

        if(map.find(horizontalPosition) == map.end()){
            map[horizontalPosition] = currentNode->val;
        }

        if(currentNode->left != NULL) queue.push({currentNode->left, horizontalPosition - 1});
        if(currentNode->right != NULL) queue.push({currentNode->right, horizontalPosition + 1});
    }

    vector<int> ans;
    for (pair<int, int> element : map)
    {
        ans.push_back(element.second);
    }
    
    return ans;
}

int main(){
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    btNode* root = buildTree(arr);
    // printBinaryTreeByLevel(root);
    vector<int> ans = topViewOfBinaryTree(root);
    printVector(ans, "ans: ");
    return 0;
}