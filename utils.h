// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct btNode {
    int val;
    btNode* left;
    btNode* right;
    btNode(int v){
        val = v;
        left = right = NULL;
    }
};

static int buildTreeIdx = -1;
btNode* buildTree(vector<int> arr){
    buildTreeIdx++;
    if(arr[buildTreeIdx] == -1){
        return NULL;
    }
    btNode* newNode = new btNode(arr[buildTreeIdx]);
    newNode->left = buildTree(arr);
    newNode->right = buildTree(arr);
    return newNode;
}

void printBinaryTree(btNode* root) { // root, left, right
    if(root == NULL){
        return;
    }
    cout << root->val << "\t";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

void printBinaryTreeByLevel(btNode *root)
{
    queue<btNode *> queue;

    queue.push(root);
    queue.push(NULL);

    while (!queue.empty())
    {
        btNode *currentNode = queue.front();
        queue.pop();

        if (currentNode == NULL)
        {
            if (queue.empty())
            {
                break;
            }
            else
            {
                cout << endl;
                queue.push(NULL);
                continue;
            }
        }

        cout << currentNode->val << "\t";
        if (currentNode->left != NULL)
            queue.push(currentNode->left);
        if (currentNode->right != NULL)
            queue.push(currentNode->right);
    }
}

template<typename T>
void printVector(vector<T> arr, string msg="") {
    cout << endl;
    if(msg.size() > 0){
        cout << msg << " ";
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void printVector(vector<vector<T>> arr, string msg="") {
    cout << endl;
    if(msg.size() > 0){
        cout << msg << " ";
    }
    cout << "\n[\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << "\t";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j];
        }
        cout << ",\n";
    }
    cout << "]" << endl;
}

template<typename T>
void swapElement(vector<T> &arr, int first, int second) {
    T tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

void printLinkedNodes(ListNode* head){
    while(head != NULL){
        cout << head->val << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

#endif
