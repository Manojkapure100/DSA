#include<iostream>
#include "utils.h"

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    queue<pair<int, pair<int, int>>> q; // contain {distance, {row,column}} //usually we use priority queue in dijski
    vector<vector<int>> distance(rowSize, vector<int>(colSize, -1)); // contain distance of every node from source
    pair<int,int> start = {0,0}; // source
    pair<int,int> end = {rowSize - 1, colSize - 1}; // destination

    if(start == end) return grid[0][0] == 0 ? 1 : -1;
    if(grid[start.first][start.second] == 1) return -1;

    distance[start.first][start.second] = 1;
    q.push({1, start});

    while(!q.empty()){
        auto front = q.front();
        q.pop();

        int parentDistance = front.first;
        int parentRow = front.second.first;
        int parentCol = front.second.second;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newRow = parentRow + i;
                int newCol = parentCol + j;

                if(
                    (i != 0 || j != 0) &&
                    newRow >= 0 && newRow < rowSize &&
                    newCol >= 0 && newCol < colSize &&
                    grid[newRow][newCol] == 0 &&
                    distance[newRow][newCol] == -1
                ){
                    int newDistance = parentDistance + 1;
                    distance[newRow][newCol] = newDistance;
                    if(newRow == end.first && newCol == end.second) return newDistance;
                    q.push({newDistance, {newRow, newCol}});
                }
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> grid;
    // grid = {{0,0,0},{1,1,0},{1,1,0}};
    grid = {{1,0,0},{1,1,0},{1,1,0}};
    int ans = shortestPathBinaryMatrix(grid);
    cout << "Sortest path: " << ans << endl;
    return 0;
}