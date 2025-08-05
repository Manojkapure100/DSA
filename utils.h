// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
