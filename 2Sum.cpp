#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> getTwoSumWithBruthForce(std::vector<int> array, int target){
    int ans1 = 0;
    int ans2 = 0;
    std::vector<int> ans = {};
    for (int i = 0; i < array.size(); i++){
        ans1 = array[i];
        for (int j = i+1; j < array.size(); j++){
            ans2 = array[j];
            if(ans1+ans2 == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

std::vector<int> getTwoSumWithTwoPointer(std::vector<int> array, int target){
    std::sort(array.begin(),array.end());
    int start = 0;
    int end = array.size()-1;
    std::vector<int> ans = {};
    while(array[start]+array[end] != target){
        if(array[start]+array[end] > target){
            end-=1; 
        } else {
            start+=1;
        }
    }
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

std::vector<int> getTwoSumWithWithHashing(std::vector<int> array, int target){
    std::vector<int> ans = {};
    std::unordered_map<int,int> hash;
    for (int i = 0; i < array.size(); i++){
        int firstValue = array[i];
        int secondValue = target - firstValue;
        if(hash.find(secondValue) != hash.end()){
            std::cout << "\nHello\n";
            ans.push_back(i);
            ans.push_back(hash[secondValue]);
            break;
        }
        hash[firstValue] = i;
    }
    return ans;
}

int main(){
    std::vector<int> array = {2,5,7,4,6};
    int target = 11;
    // std::vector<int> ans = getTwoSumWithBruthForce(array, target);    
    // std::vector<int> ans = getTwoSumWithTwoPointer(array, target);    
    std::vector<int> ans = getTwoSumWithWithHashing(array, target);

    std::cout << "\npair of 2 sum: " << ans[0] << " and " << ans[1] << "\n";
    return 0;
}