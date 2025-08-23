#include<iostream>
#include "utils.h"
#include <map>

using namespace std;

int maxLevelSum(btNode* root) {
    map<int,int> map;
    queue<btNode*> queue;
    int level = 0;

    queue.push(root);
    queue.push(NULL);
    level++;

    while(!queue.empty()){
        btNode* current = queue.front();
        queue.pop();

        if(current == NULL){
            if(queue.empty()){
                break;
            } else {
                queue.push(NULL);
                level++;
                continue;
            }
        }

        map[level] += current->val;
        if(current->left != NULL) queue.push(current->left);
        if(current->right != NULL) queue.push(current->right);
    }

    int index = 1;
    int max = map[index];
    for(auto& m : map){
        if(max < m.second){
            index = m.first;
            max = m.second;
        }
        cout << m.first << " " << m.second << endl;
    }
    return index;
}

int main(){
    vector<int> arr = {1,7,7,-1,-1,-8,-1,-1,0,-1,-1};
    btNode* root = buildTree(arr);
    int ans = maxLevelSum(root);
    cout << "Max level is: " << ans << endl;
    return 0;
}