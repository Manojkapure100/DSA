#include<iostream>
#include <vector>

// 1,2,3
// 5,6,7
// 10,11,12

using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target) {
    int rowStart = 0;
    int rowEnd = arr.size() - 1;
    while(rowStart <= rowEnd){
        int rowMid = rowStart + (rowEnd-rowStart) / 2;
        int size = arr[rowMid].size();
        if(arr[rowMid][0] <= target && target <= arr[rowMid][size-1]){
            int start = 0;
            int end = size - 1;
            while(start <= end){
                int mid = start + (end-start) / 2;
                if(arr[rowMid][mid] == target){
                    return true;
                }
                if(arr[rowMid][mid] < target){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        if(arr[rowMid][size-1] < target) {
            rowStart = rowMid + 1;
        } else {
            rowEnd = rowMid - 1;
        }
    }
    return false;
}

int main(){
    // vector<vector<int>> arr = {{1,2,3},{5,6,7},{10,11,12}};
    vector<vector<int>> arr = {{-8,-7,-5,-3,-3,-1,1},{2,2,2,3,3,5,7},{8,9,11,11,13,15,17},{18,18,18,20,20,20,21},{23,24,26,26,26,27,27},{28,29,29,30,32,32,34}};
    int target = -5;
    bool res = searchMatrix(arr,target);
    cout << "res: " << res << endl;
    return 0;
}