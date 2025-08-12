#include<iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        if(s1.empty()){
            return -1;
        }
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){
    MyQueue mq;
    mq.push(1);
    cout << mq.peek() << endl;
    mq.push(2);
    cout << mq.peek() << endl;
    mq.pop();
    cout << mq.peek() << endl;
    mq.pop();
    cout << mq.peek() << endl;
    return 0;
}