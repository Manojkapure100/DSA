#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1,2,3,4,5
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tmp = head;
    int count = 0;
    while(count < k){
        if(tmp == NULL){
            return head;
        }
        tmp = tmp->next;
        count++;
    }

    ListNode* newNode = reverseKGroup(tmp, k);
    tmp = head;
    count = 0;
    while(count < k){
        ListNode* next = tmp->next;
        tmp->next = newNode;
        newNode = tmp; // moving to left
        tmp = next; // preparing next value to process in next iteration
        count++;
    }
    return newNode;
}

int main(){
    ListNode* l1 = new ListNode(10);
    ListNode* l2 = new ListNode(20);
    ListNode* l3 = new ListNode(30);
    ListNode* l4 = new ListNode(40);
    ListNode* l5 = new ListNode(50);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode* ans = reverseKGroup(l1,2);
    ListNode* tmp = ans;
    while(tmp != NULL){
        cout << tmp->val << "-->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    return 0;
}