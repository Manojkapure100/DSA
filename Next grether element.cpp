#include<iostream>
#include <vector>
#include <stack>
#include "utils.h"
#include <unordered_map>

using namespace std;

vector<int> nextGretherElement(vector<int> element){
    vector<int> ans(element.size(), 0);
    stack<int> stack;
    for (int i = element.size() - 1; i >= 0; i--)
    {
        while(stack.size() > 0 && stack.top() <= element[i]){
            stack.pop();
        }
        if(stack.empty()){
            ans[i] = -1;
        } else {
            ans[i] = stack.top();
        }
        stack.push(element[i]);
    }
    
    return ans;
}

vector<int> nextGreaterElement1(vector<int>& element1, vector<int>& element2) {
    vector<int> ans(element1.size(), 0);
    unordered_map<int,int> map;

    stack<int> stack;
    for (int i = element2.size() - 1; i >= 0; i--)
    {
        while(stack.size() > 0 && stack.top() <= element2[i]){
            stack.pop();
        }
        if(stack.empty()){
            map[element2[i]] = -1;
        } else {
            map[element2[i]] = stack.top();
        }
        stack.push(element2[i]);
    }
    
    for (int i = 0; i < element1.size(); i++)
    {
        if(map.find(element1[i]) != map.end()){
            ans[i] = map[element1[i]];
        } else {
            ans[i] = -1;
        }
    }

    return ans;        
}

int main(){
    vector<int> element = {6,8,0,1,3};
    vector<int> element1 = {4,1,2};
    vector<int> element2 = {1,3,4,2};
    // vector<int> ans = nextGretherElement(element);
    vector<int> ans = nextGreaterElement1(element1, element2);
    printVector(ans, "ans");
    return 0;
}