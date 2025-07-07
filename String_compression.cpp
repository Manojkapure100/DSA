#include<iostream>
#include "utils.h"

using namespace std;

vector<string> stringCompression1stWay(vector<string> arr){
    vector<string> ans;
    string lastCharacter = arr[0];
    int number = 1;
    ans.push_back(lastCharacter);
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == lastCharacter){
            number++;
        } else {
            if(number>1){
                ans.push_back(to_string(number));
            }
            ans.push_back(arr[i]);
            lastCharacter = arr[i];
            number = 1;
        }
        if(i==arr.size()-1 && number > 1){
            ans.push_back(to_string(number));
        }
    }
    return ans;
}

vector<string> stringCompression2ndWay(vector<string> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        string lastElement = arr[i];
        while(i < arr.size() - 1 && arr[i]==lastElement){
            count++;
            if(lastElement == arr[i+1]) {
                arr.erase(arr.begin() + (i+1));
                count ++;
            }
            i++;
        }
        if(i < arr.size() - 1 && count > 1) arr.insert(arr.begin() + i, to_string(count));
        if(i == arr.size() -1 ){
            if(count > 1) {
                arr.insert(arr.begin() + (i+1), to_string(count));
            }
            break;
        }
    }
    return arr;
}

vector<char> onlineWay(vector<char> arr){
    int idx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        char ch = arr[i];

        while(ch == arr[i]){
            i++;
            count++;
        }

        if(count == 1) arr[idx++] = ch;
        if(count > 1){
            arr[idx++] = ch;
            for(char ch: to_string(count)){
                arr[idx++] = ch;
            }
        }
        i--;
    }
    arr.resize(idx);
    return arr;
}

int main(){
    vector<string> arr = {"a","b","b","c"};
    printVector(arr, "intial");
    vector<char> arr1 = {'a','b','b','c'};
    printVector(arr1, "intial arr1");
    
    vector<char> ans1 = {};
    // ans = stringCompression1stWay(arr);
    // ans = stringCompression2ndWay(arr);
    ans1 = onlineWay(arr1);
    printVector(ans1, "result");
    return 0;
}