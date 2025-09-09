#include<iostream>
#include "utils.h"

using namespace std;

int rowSize = 0;
int colSize = 0;
vector<vector<int>> visited;
vector<vector<char>> arr;

bool dfs(int row, int col, int parentRow, int parentCol, char ch){
    visited[row][col] = true;

    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dRow[i];    
        int newCol = col + dCol[i];
        
        if(
            newRow >= 0 && newRow < rowSize &&
            newCol >= 0 && newCol < colSize &&
            arr[newRow][newCol] == ch
        ){
            if(visited[newRow][newCol]){
                if(newRow != parentRow || newCol != parentCol){
                    return true;
                }
            } else {
                if(dfs(newRow, newCol, row, col, ch)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    rowSize = grid.size();
    colSize = grid[0].size();
    visited = vector<vector<int>>(rowSize, vector<int>(colSize, 0));
    arr = grid;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if(!visited[i][j]){
                if(dfs(i, j, -1, -1, grid[i][j])){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> arr;
    arr = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    // arr = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    if(containsCycle(arr)){
        cout << "Cycle detected" << endl;
    } else {
        cout << "Cycle not detected" << endl;
    }
    return 0;
}