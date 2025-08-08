#include<iostream>
#include <vector>
#include <stack>
#include "utils.h"

using namespace std;

vector<int> way2(vector<int> element){
    vector<int> ans(element.size(),0);
    stack<int> stack;
    for (int i = 0; i < element.size(); i++)
    {
        while((!stack.empty()) && element[i] > element[stack.top()]){
            stack.pop();
        }
        if(stack.empty()){
            ans[i] = i + 1;
        } else {
            ans[i] = i - stack.top();
        }
        stack.push(i);
    }
    
    return ans;
}

vector<int> way1(vector<int> element){
    vector<int> ans(element.size(), 1);
    stack<int> stack;
    for(int i=0; i<element.size();i++){
        if(stack.empty()){
            ans[i] = 1;
        } else {
            while((!stack.empty()) && element[i] > element[stack.top()]){
                stack.pop();
            }
            if(stack.empty()){
                ans[i] = i - 0;
            } else{
                ans[i] = i - stack.top();
            }
        }
        stack.push(i);
    }
    return ans;
}

int main(){
    // vector<int> element = {100,80,60,70,60,75,85};
    vector<int> element = {85,75,60,70,60,80,100};
    printVector(element, "Elements: ");
    // vector<int> ans = way1(element);
    vector<int> ans = way2(element);
    printVector(ans, "ans: ");
    return 0;
}