#include<iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& arr, int target) {
    int totalRow = arr.size();
    int totalColumn = arr[0].size();
    int row = 0;
    int column = totalColumn - 1;
    while(row < totalRow && column >= 0){
        if(arr[row][column] == target){
            return true;
        }
        if(arr[row][column] < target){
            row ++;
        } else {
            column --;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> arr =
    {
        {1,4,  7, 11,15},
        {2,5,  8, 12,19},
        {3,6,  9, 16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 9;
    int result = searchMatrix(arr,target);
    cout << "result: " << result << endl;
    return 0;
}