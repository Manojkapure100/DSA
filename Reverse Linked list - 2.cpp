#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    for(int i=1; i<left; i++){
        prev = prev->next;
    }

    ListNode* current = prev->next;

    for(int i=0;i<right-left;i++){
        ListNode* tmp = current->next;
        current->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }

    return dummy->next;

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

    ListNode* ans = reverseBetween(l1, 2, 4);
    ListNode* tmp = ans;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
    return 0;
}