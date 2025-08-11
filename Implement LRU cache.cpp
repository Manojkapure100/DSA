#include<iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    struct Node {
        int key;
        int value;

        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1,-1); // head->next means frequenty used node
    Node* tail = new Node(-1,-1); // tail->prev means not-frequenty used node

    int limit;
    unordered_map<int, Node*> map; // <key, node address>

    LRUCache(int capacity) {
        // to set limit and connect head and tail
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* nodeToAdd){
        // get the next of head call it oldHead, put new in between head and and oldHead
        Node* oldHead = head->next;

        head->next = nodeToAdd;
        nodeToAdd->prev = head;

        nodeToAdd->next = oldHead;
        oldHead->prev = nodeToAdd;
    }

    void deleteNode(Node* nodeToDelete){
        // get the prev and next of that Node and connect them
        Node* oldNext = nodeToDelete->next;
        Node* oldPrev = nodeToDelete->prev;

        oldNext->prev = oldPrev;
        oldPrev->next = oldNext;
    }
    
    int get(int key) {
        // return if key is not available in map
        if(map.find(key) == map.end()){
            return -1;
        }

        // if available then, return value but also make it frequent, by deleting it and adding it again.
        Node* sameNode = map[key];

        map.erase(key);
        deleteNode(sameNode);

        addNode(sameNode);
        map[key] = sameNode;

        return sameNode->value;
    }
    
    void put(int key, int value) {
        // if old node found with the same key in map, then delete old node using map[key] and insert new one.
        if(map.find(key) != map.end()){
            Node* oldNode = map[key];
            deleteNode(oldNode);
            map.erase(key);
        }

        // if capacity is full, then delete node which is not recently used (tail->prev).
        if(map.size() == limit){
            Node* oldNode = tail->prev;
            map.erase(tail->prev->key);
            deleteNode(oldNode);
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        map[key] = newNode;
    }
};

int main(){
    LRUCache obj(2);
    obj.put(1,10);
    obj.put(2,20);
    obj.put(3,30);
    cout << "obj.get(3): " << obj.get(3) << endl;
    return 0;
}