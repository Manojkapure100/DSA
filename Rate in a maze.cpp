#include<iostream>
#include <vector>
#include "utils.h"

using namespace std;

void getPath(vector<vector<int>> mat, int r, int c, vector<string> &ans, string path){
    int n = mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || mat[r][c] == -1) {
        return;
    }

    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    mat[r][c] = -1;

    getPath(mat, r+1, c, ans, path+"D");
    getPath(mat, r-1, c, ans, path+"U");
    getPath(mat, r, c+1, ans, path+"R");
    getPath(mat, r, c-1, ans, path+"L");

    mat[r][c] = 1;
}

int main(){
    vector<vector<int>> mat = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans = {};
    string path = "";
    getPath(mat, 0, 0, ans, path);
    printVector(ans, "ans: ");
    return 0;
}