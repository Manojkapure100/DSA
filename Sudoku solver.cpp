#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<char>> &board, int row, int col, char digit)
{
    // horizontal and vertical
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit || board[i][col] == digit)
        {
            return false;
        }
    }

    // vertical
    // for (int i = 0; i < 9; i++)
    // {
    //     if (board[i][col] == digit)
    //     {
    //         return false;
    //     }
    // }

    // grid
    int startingRow = (row / 3) * 3;
    int startingCol = (col / 3) * 3;

    for (int i = startingRow; i < startingRow + 3; i++)
    {
        for (int j = startingCol; j < startingCol + 3; j++)
        {
            if (board[i][j] == digit)
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

    // check if col is last in that row then do row+1 and col=0
    if (nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }

    if (board[row][col] != '.')
    {
        return ss(board, nextRow, nextCol);
    }

    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isSafe(board, row, col, digit))
        {
            board[row][col] = digit;
            if (ss(board, nextRow, nextCol))
            {
                return true;
            } else {
                board[row][col] = '.';
            }
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    if(ss(board, 0, 0)){
        cout << "\nsolved\n";
    } else{
        cout << "\nunsolved\n";
    }
}

int main()
{
    int n = 9;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    vector<vector<char>> board2 = {{'.','.','.','.','.','.','.','.','.'},{'.','9','.','.','1','.','.','3','.'},{'.','.','6','.','2','.','7','.','.'},{'.','.','.','3','.','4','.','.','.'},{'2','1','.','.','.','.','.','9','8'},{'.','.','.','.','.','.','.','.','.'},{'.','.','2','5','.','6','4','.','.'},{'.','8','.','.','.','.','.','1','.'},{'.','.','.','.','.','.','.','.','.'}};
    solveSudoku(board2);
    return 0;
}