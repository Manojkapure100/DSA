#include<iostream>
#include<list>
#include<vector>
#include "utils.h"

using namespace std;

void dfs4Directional(int row, int column, vector<vector<char>> &grid, vector<vector<int>> &visited){
    int rowSize = grid.size();
    int colSize = grid[0].size();

    visited[row][column] = 1;

    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};
    for(int i=0; i<4; i++){
        int newRow = row + dRow[i];
        int newCol = column + dCol[i];
        if(
            newRow >=0 && newRow < rowSize &&
            newCol >=0 && newCol < colSize &&
            grid[newRow][newCol] == '1' &&
            !visited[newRow][newCol]
        ){
            dfs4Directional(newRow, newCol, grid, visited);
        }
    }
}

void dfs8Directional(int row, int column, vector<vector<char>> &grid, vector<vector<int>> &visited){
    int totalRow = grid.size();
    int totalCol = grid[0].size();
    visited[row][column] = 1;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int newRow = row + i;
            int newCol = column + j;
            if(
                newRow >= 0 && newRow < totalRow &&
                newCol >= 0 && newCol < totalCol &&
                grid[newRow][newCol] == '1' && 
                !visited[newRow][newCol]
            ){
                dfs8Directional(newRow, newCol, grid, visited);
            }
        }
    } 
}

int numIslands(vector<vector<char>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
    int count = 0;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if(grid[i][j] == '1' && !visited[i][j]){
                count++;
                dfs4Directional(i,j, grid, visited);
            }   
        }
    }
    return count;
}

int main(){
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    printVector(grid);
    int ans = numIslands(grid);
    cout << "Ans: " << ans << endl;
    return 0;
}