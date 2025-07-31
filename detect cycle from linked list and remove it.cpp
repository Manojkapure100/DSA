#include<iostream>
#include<vector>
#include "utils.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;
        ListNode* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // removed cycle
        return head;
    }

int main(){
    ListNode* l1 = new ListNode(10);
    ListNode* l2 = new ListNode(20);
    l1->next = l2;
    ListNode* l3 = new ListNode(30);
    l2->next = l3;
    ListNode* l4 = new ListNode(40);
    l3->next = l4;
    ListNode* l5 = new ListNode(50);
    l4->next = l5;
    ListNode* l6 = new ListNode(60);
    l5->next = l6;
    l6->next = l3;

    ListNode* ans = removeCycle(l1);
    ListNode* tmp = ans;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
    return 0;
        
    return 0;
}