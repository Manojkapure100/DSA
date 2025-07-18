#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

// 1    2   3   4
// 5    6   7   8
// 9    10  11  12

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int startRow = 0;
    int startCol = 0;
    int endRow = matrix.size() - 1;
    int endCol = matrix[0].size() - 1;
    vector<int> result = {};

    while(startRow <= endRow && startCol <= endCol){
        for (int i = startCol; i <= endCol; i++) // top
        {
            result.push_back(matrix[startRow][i]);
        }
        for (int i = startRow+1; i <= endRow; i++){ // right
            result.push_back(matrix[i][endCol]);
        }
        for (int i = endCol-1; i >= startCol; i--) // bottom
        {
            if(startRow==endRow){
                break;
            }
            result.push_back(matrix[endRow][i]);
        }
        for (int i = endRow - 1; i >= startRow+1; i--) // left
        {
            if(startCol==endCol){
                break;
            }
            result.push_back(matrix[i][startCol]);
        }
        startRow++;
        startCol++;
        endRow--;
        endCol--;
    }
    return result;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = spiralOrder(matrix);
    printVector(result, "result: ");
    return 0;
}