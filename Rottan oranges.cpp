#include <iostream>
#include "utils.h"

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();
    queue<pair<int, pair<int, int>>> q;                             // {min, {row, col}}
    vector<vector<int>> visited(rowSize, vector<int>(colSize, -1)); // visited = min size, not visited = -1

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                visited[i][j] = 0;
            }
        }
    }

    int maxMinute = 0;
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        int parentRow = front.second.first;
        int parentCol = front.second.second;
        int parentMin = front.first;
        int newMin = parentMin + 1;

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = parentRow + dRow[i];
            int newCol = parentCol + dCol[i];

            if (
                newRow >= 0 && newRow < rowSize &&
                newCol >= 0 && newCol < colSize &&
                grid[newRow][newCol] == 1 &&
                visited[newRow][newCol] == -1)
            {
                q.push({newMin, {newRow, newCol}});
                visited[newRow][newCol] = newMin;
                maxMinute = newMin;
            }
        }
    }

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == -1)
            {
                return -1;
            }
        }
    }
    return maxMinute;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int ans = orangesRotting(grid);
    cout << "ans: " << ans << endl;
    return 0;
}