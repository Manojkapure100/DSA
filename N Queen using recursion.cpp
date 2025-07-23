#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

bool isSafe(vector<string> board, int row, int column, int n){
    // check vertically
    for (int i = 0; i < n; i++)
    {
        if(board[i][column] == 'Q'){
            return false;
        }
    }

    // check horizontally
    for (int i = 0; i < n; i++)
    {
        if(board[row][i] == 'Q'){
            return false;
        }
    }
    

    // check top left
    for(int i=row-1,j=column-1; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // check top right
    for(int i=row-1,j=column+1; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // we will not gonna check botton left/right because we don't have any Queen there yet.

    // everything is good return true
    return true;
}

void NQueen(vector<string> &board, int row, int n, vector<vector<string>> &result){
    if(row == n){
        result.push_back({board});
        return;
    }
    for (int column = 0; column < n; column++)
    {
        if(isSafe(board, row, column, n)){
            board[row][column] = 'Q';
            NQueen(board, row+1, n, result);
            board[row][column] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n,'.'));
    printVector(board, "board: ");
    vector<vector<string>> result;
    int row = 0;
    NQueen(board, row, n, result);
    return result;
}

int main(){
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);
    printVector(result, "result: ");
    return 0;
}