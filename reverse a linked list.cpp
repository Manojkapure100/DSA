#include<iostream>
#include<algorithm>

using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x): value(x), next(nullptr) {
        cout << "hello: " << x << endl;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = NULL;
    ListNode* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    return previous;
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

    ListNode* result = reverseList(l1);
    cout << "result: " << result->value << endl;
    return 0;
}