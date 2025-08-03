#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int x){
        val = x;
        next = NULL;
        child = NULL;
    }
};

Node* flatten(Node* head) {
    if(head == NULL){
        return head;
    }

    Node* current = head;

    while(current != NULL){
        if(current->child != NULL){
            Node* next = current->next;
            Node* flattenNodes = flatten(current->child);
            current->next = flattenNodes;
            flattenNodes->prev = current;
            current->child = NULL;
            
            while(flattenNodes->next != NULL){
                flattenNodes = flattenNodes->next;
            }
            
            if(next != NULL){
                flattenNodes->next = next;
                next->prev = flattenNodes;
            }
        }
        current = current->next;
    }
    return head;
}

int main(){
    Node* l1 = new Node(10);
    Node* l2 = new Node(20);
    l1->next = l2;
    Node* l3 = new Node(30);
    l2->next = l3;
    Node* l4 = new Node(40);
    l3->next = l4;
    Node* l11 = new Node(110);
    l4->next = l11;
    Node* l12 = new Node(120);
    l11->next = l12;
    
    Node* l5 = new Node(50);
    l3->child = l5;

    Node* l6 = new Node(60);
    l5->next = l6;
    Node* l7 = new Node(70);
    l6->next = l7;

    Node* l8 = new Node(80);
    l6->child = l8;

    Node* l9 = new Node(90);
    l8->next = l9;
    Node* l10 = new Node(100);
    l9->next = l10;

    Node* ans = flatten(l1);

    Node* tmp = ans;
    while(tmp != NULL){
        cout << tmp->val << " <--> ";
        // cout << ((tmp->random == NULL) ? 0 : tmp->random->val) << ", ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;

    return 0;
}