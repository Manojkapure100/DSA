#include<iostream>
#include "utils.h"
#include<vector>
#include <set>

using namespace std;

void getCombination(const vector<int> &element, int target, int level, vector<int> &combination, set<vector<int>> &set){
    if(level == element.size() || target < 0){
        return;
    }

    if(target == 0){
        if(set.find(combination) == set.end()){
            set.insert(combination);
        }
        return;
    }

    combination.push_back(element[level]);
    getCombination(element, target - element[level], level+1, combination, set); // single include
    getCombination(element, target - element[level], level, combination, set); // multiple include
    combination.pop_back();
    getCombination(element, target, level+1, combination, set); // exclude
}

int main(){
    vector<int> element = {2,3,5};
    int target = 8;
    vector<int> combination;
    set<vector<int>> set = {};
    int level = 0;
    getCombination(element, target, level, combination, set);
    vector<vector<int>> ans(set.begin(), set.end());
    printVector(ans, "All combinations: ");
    return 0;
}