#include<iostream>
#include<stack>
#include<vector>
#include "utils.h"

using namespace std;

vector<int> nextGretherElementCircular2(vector<int> element){
    vector<int> ans(element.size(), -1);
    int n = element.size();
    stack<int> stack;
    for(int i = 2*n-1; i >= 0; i--){
        while(stack.size() > 0 && element[stack.top()] <= element[i%n]){
            stack.pop();
        }
        if(stack.empty()){
            ans[i%n] = -1;
        } else{
            ans[i%n] = element[stack.top()];
        }
        stack.push(i%n);
    }
    return ans;
}

vector<int> nextGretherElementCircular(vector<int> element){
    vector<int> ans(element.size(), -1);
    int count = element.size();
    for (int i = 0; i < element.size(); i++)
    {
        if(count == 0){
            break;
        }
        int j = i+1;
        while(element.size() != j)
        {
            if(element[j] > element[i]){
                ans[i] = element[j];
                break;
            } else {
                j++;
            }
        }
        element.push_back(element[i]);
        count--;
    }
    return ans;
}

vector<int> nextGretherElement(vector<int> element){
    vector<int> ans(element.size(), 0);
    stack<int> stack;
    int count = element.size();
    for (int i = element.size()-1; i >=0; i--)
    {
        while((!stack.empty()) && stack.top() <= element[i]){
            stack.pop();
        }
        if(stack.empty()){
            ans[i] = -1;
        } else{
            ans[i] = stack.top();
        }
        stack.push(element[i]);
    }
    return ans;
}

int main(){
    vector<int> element = {1,2,3,4,3};
    printVector(element, "element: ");
    // vector<int> ans = nextGretherElement(element);
    vector<int> ans = nextGretherElementCircular2(element);
    printVector(ans, "ans: ");
    return 0;
}