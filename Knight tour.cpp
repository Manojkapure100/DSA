#include<iostream>
#include "utils.h"
#include<vector>

using namespace std;

bool isValid(vector<vector<int>> &arr, int row, int col, int expectedVal){
    if(row < 0 || col < 0 || row >= arr.size() || col >= arr.size() || arr[row][col] != expectedVal){
        return false;
    }

    if(arr[row][col] == expectedVal && expectedVal == (arr.size()*arr.size()) - 1){ // n^2-1
        return true;
    }

    int ans1 = isValid(arr, row-1, col-2, expectedVal+1);
    int ans2 = isValid(arr, row-1, col+2, expectedVal+1);
    int ans3 = isValid(arr, row+1, col-2, expectedVal+1);
    int ans4 = isValid(arr, row+1, col+2, expectedVal+1);
    int ans5 = isValid(arr, row-2, col-1, expectedVal+1);
    int ans6 = isValid(arr, row-2, col+1, expectedVal+1);
    int ans7 = isValid(arr, row+2, col-1, expectedVal+1);
    int ans8 = isValid(arr, row+2, col+1, expectedVal+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool IsKnightTourValid(vector<vector<int>> &arr){
    int row = 0;
    int col = 0;
    int expectedVal = 0;
    return isValid(arr, row, col, expectedVal);
}

int main(){
    vector<vector<int>> arr = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    if(IsKnightTourValid(arr)){
        cout << "Valid\n";
    } else {
        cout << "Valid\n";
    }

    return 0;
}