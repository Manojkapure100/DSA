#include<iostream>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s) {
    stack<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            stack.push(s[i]);
        } else if ( s[i]=='}' || s[i]==')' || s[i]==']' ){
            if(stack.size() == 0){
                return false;
            }
            if(
                (s[i] == '}' && stack.top() == '{') ||
                (s[i] == ')' && stack.top() == '(') ||
                (s[i] == ']' && stack.top() == '[') 
            ){
                stack.pop();
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return stack.size() == 0;
}

int main(){
    string s = "{[()]}]]]";
    if(isValid(s)){
        cout << "valid\n";
    } else {
        cout << "not valid\n";
    }
    return 0;
}