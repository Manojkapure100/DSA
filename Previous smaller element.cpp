#include<iostream>
#include <vector>
#include <stack>
#include "utils.h"

using namespace std;

vector<int> previousSmallerElement(vector<int> element){
    vector<int> ans(element.size(), 0);
    stack<int> stack;
    for (int i = 0; i < element.size(); i++)
    {
        while(stack.size() > 0 && stack.top() >= element[i]){
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

int main(){
    vector<int> elements = {3,1,0,8,6};
    vector<int> ans = previousSmallerElement(elements);
    printVector(ans, "ans");
    return 0;
}