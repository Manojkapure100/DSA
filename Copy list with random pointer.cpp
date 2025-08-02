#include<iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

Node* copyRandomList(Node* head) {
    if(head == NULL){
        return NULL;
    }
    
    Node* newHead = new Node(head->val);
    unordered_map<Node*,Node*> m;
    m[head] = newHead; // for mapping

    // One iteration from start, for "next" connections 
    Node* oldTmp = head->next;
    Node* newTmp = newHead;

    while(oldTmp != NULL){
        Node* newNode = new Node(oldTmp->val);
        newTmp->next = newNode;

        m[oldTmp] = newNode; // for mapping

        oldTmp = oldTmp->next;
        newTmp = newTmp->next;
    }

    // again one iteration from start, for "random" connections 
    oldTmp = head;
    newTmp = newHead;

    while(oldTmp != NULL){
        newTmp->random=m[oldTmp->random]; // use of mapping

        oldTmp=oldTmp->next;
        newTmp=newTmp->next;
    }

    return newHead;
}

int main(){
    Node* l1 = new Node(10);
    Node* l2 = new Node(20);
    l1->next = l2;
    Node* l3 = new Node(30);
    l2->next = l3;
    Node* l4 = new Node(40);
    l3->next = l4;
    Node* l5 = new Node(50);
    l4->next = l5;
    Node* l6 = new Node(60);
    l5->next = l6;

    l1->random = NULL;
    l2->random = l5;
    l3->random = l6;
    l4->random = l2;
    l5->random = l1;
    l6->random = l3;

    Node* ans = copyRandomList(l1);
    Node* tmp = ans;
    while(tmp != NULL){
        cout << tmp->val << ", ";
        // cout << ((tmp->random == NULL) ? 0 : tmp->random->val) << ", ";
        tmp = tmp->next;
    }
    cout << endl;
    tmp = l1;
    while(tmp != NULL){
        cout << tmp->val << ", ";
        // cout << ((tmp->random == NULL) ? 0 : tmp->random->val) << ", ";
        tmp = tmp->next;
    }
    return 0;
}