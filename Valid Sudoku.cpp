#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<char>> &board, int row, int col,
            char digit)
{
    // horizontal
    for (int i = 0; i < 9; i++)
    {
        if (i != col && board[row][i] == digit)
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < 9; i++)
    {
        if(i != row && board[i][col] == digit){
            return false;
        }
    }
    

    // grid
    int startingRow = (row / 3) * 3;
    int startingCol = (col / 3) * 3;

    for (int i = startingRow; i < startingRow + 3; i++)
    {
        for (int j = startingCol; j < startingCol + 3; j++)
        {
            if ((i != row || j != col) && board[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true;
}

bool ss(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    if (board[row][col] == '.')
    {
        return ss(board, nextRow, nextCol);
    }
    else
    {
        if (!isSafe(board, row, col, board[row][col]))
        {
            return false;
        }
        else
        {
            return ss(board, nextRow, nextCol);
        }
    }

    return false;
}

bool isValidSudoku(vector<vector<char>> &board) { return ss(board, 0, 0); }

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<vector<char>> board1 = {{'7','.','.','.','4','.','.','.','.'},{'.','.','.','8','6','5','.','.','.'},{'.','1','.','2','.','.','.','.','.'},{'.','.','.','.','.','9','.','.','.'},{'.','.','.','.','5','.','5','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','2','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'}};
    if(isValidSudoku(board1)){
        cout << "valid\n";
    } else {
        cout << "not Valid\n";
    }
    return 0;
}