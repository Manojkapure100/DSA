#include<iostream>
#include<vector>
#include<unordered_set>

int getMissingValue(int n, std::vector<std::vector<int>> grid, int repeatingValue, int actualSum){
    // find sum of 1 to n length of array = n * ( n + 1) / 2
    // we do have n^2 because we have 2 dimensional array
    // find sum of 1 to n^2 length of array = n^2 * ( n^2 + 1 ) / 2
    int expectedSum = (n*n)*((n*n)+1) / 2;
    // actualSum - repeatedValue + missingValue = expectedSum
    // missingValue = expectedSum + repeatedValue - actualSum
    int missingValue = expectedSum + repeatingValue - actualSum;
    return missingValue;
}

void findMissingAndRepeatingValue(std::vector<std::vector<int>> grid){
    int n = grid.size();
    int RepeatingValue = -1;
    int missingValue = -1;
    int actualSum = 0;
    std::vector<int> ans = {};
    std::unordered_set<int> set;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            actualSum += grid[i][j];
            if(set.find(grid[i][j]) != set.end()){
                RepeatingValue = grid[i][j];
            }
            set.insert(grid[i][j]);
        }
    }
    missingValue = getMissingValue(n, grid, RepeatingValue, actualSum);
    std::cout << "\nRepeating value: " << RepeatingValue << "\n";
    std::cout << "\nMissing value: " << missingValue << "\n";
}

int main(){
    std::vector<std::vector<int>> grid = {{1,2,3},{4,5,4},{7,8,9}};
    std::vector<int> ans;
    findMissingAndRepeatingValue(grid);
}