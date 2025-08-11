#include<iostream>
#include <vector>
#include <stack>

using namespace std;

int getCelebrity(vector<vector<int>> &arr){
    stack<int> stack;
    for (int i = 0; i < arr.size(); i++)
    {
        stack.push(i);
    }
    
    while(stack.size() > 1){
        int left = stack.top(); stack.pop();
        int right = stack.top(); stack.pop();

        if(arr[left][right] == 0){
            stack.push(left);
        } else {
            stack.push(right);
        }
    }

    int celebrity = stack.top();

    for (int i = 0; i < arr.size(); i++)
    {
        if(i!=celebrity && (arr[i][celebrity] == 0 || arr[celebrity][i] == 1)){
            return -1;
        }
    }

    return celebrity;
}

int main(){
    vector<vector<int>> arr = { {0,1,0}, {0,0,0}, {0,1,0} };
    int ans = getCelebrity(arr);
    cout << "Celebrity: " << ans << endl;
    return 0;
}