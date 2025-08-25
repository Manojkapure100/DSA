#include<iostream>
#include "utils.h"

using namespace std;

int widthOfBinaryTree(btNode* root) {
    queue<pair<btNode*, int>> queue;
    queue.push({root, 0});
    int maxWidth = 0;

    while(!queue.empty()){
        int currentWidth = queue.size();
        int firstNodeIndex = queue.front().second;
        int lastNodeIndex = queue.back().second;

        maxWidth = max(maxWidth, lastNodeIndex - firstNodeIndex + 1);

        for (int i = 0; i < currentWidth; i++){
            btNode* currentNode = queue.front().first;
            int currentNodeIndex = queue.front().second;
            queue.pop();

            if(currentNode->left != NULL) queue.push({currentNode->left, currentNodeIndex*2+1});
            if(currentNode->right != NULL) queue.push({currentNode->right, currentNodeIndex*2+2});
        }
    }
    return maxWidth;
}

int main(){
    vector<int> arr = {1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
    btNode* root = buildTree(arr);
    printBinaryTreeByLevel(root);
    cout << endl << endl;
    int ans = widthOfBinaryTree(root);
    cout << "Ans: " << ans << endl;
    return 0;
}