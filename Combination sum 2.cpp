#include<iostream>
#include "utils.h"
#include<vector>
#include <set>
#include <algorithm>

using namespace std;

void getCombination(const vector<int> &element, int target, int level, vector<int> &combination, set<vector<int>> &set){
    if(target == 0){
        set.insert(combination);
        return;
    }

    if(level == element.size() || target < 0){
        return;
    }


    combination.push_back(element[level]);
    getCombination(element, target - element[level], level+1, combination, set); // single include
    combination.pop_back();
    int next = level+1;
    while(next < element.size() && element[next] == element[level]){
        next++;
    }
    getCombination(element, target, next, combination, set); // exclude
}

int main(){
    vector<int> element = {10,1,2,7,6,1,5};
    sort(element.begin(), element.end());
    int target = 8;
    vector<int> combination;
    set<vector<int>> set = {};
    int level = 0;
    getCombination(element, target, level, combination, set);
    vector<vector<int>> ans(set.begin(), set.end());
    printVector(ans, "All combinations: ");
    return 0;
}