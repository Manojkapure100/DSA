#include<iostream>
#include <vector>
#include "utils.h"
#include <algorithm>

using namespace std;

bool isPelindrome(string str){
    string s2 = str;
    reverse(s2.begin(), s2.end());
    return s2 == str;
}

void getPartitions(string s,vector<string> &part, vector<vector<string>> &ans){
    if(s.size() == 0){
        ans.push_back(part);
        return;
    }

    for (int i = 0; i < s.size(); i++){
        string preStr = s.substr(0, i+1);
        if(isPelindrome(preStr)){
            part.push_back(preStr);
            getPartitions(s.substr(i+1), part, ans);
            part.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> part;
    getPartitions(s, part, ans);
    return ans;
}

int main(){
    string s = "aab";
    vector<vector<string>> allPartition = partition(s);
    printVector(allPartition, "All Partitions: ");
    return 0;
}