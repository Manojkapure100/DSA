#include<iostream>
#include "utils.h"

using namespace std;

// 1->2->3->4
// 
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode* prev = NULL;
    ListNode* first = head;
    ListNode* second = head->next;

    while(first != NULL && second != NULL){
        ListNode* next = second->next;
        // swapping
        second->next = first;
        first->next = next;
    
        if(prev != NULL){
            prev->next = second;
        } else {
            // only when run first time
            head = second;
        }

        // moving forward for next iteration
        prev = first;
        first = next;
        if(next != NULL){
            second = next->next;
        } else {
            second = NULL;
        }
    }

    return head;
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

    ListNode* ans = swapPairs(l1);
    printLinkedNodes(ans);
    return 0;
}