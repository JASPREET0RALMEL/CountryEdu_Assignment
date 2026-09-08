#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(int row, int n, vector<string>& board, vector<vector<string>> & result,vector<bool> &cols, vector<bool>& mainDiag, vector<bool>&antiDiag) {
    //Base Case: All queens are placed
    if(row == n) {
        result. push_back(board);
        return;
    }

    for(int col = 0; col < n; ++col) {
        int md = row - col + (n - 1);
        int ad = row + col;

        //Check safety in 0(1)
        if(!cols[col] && !mainDiag[md] && !antiDiag[ad]) {
            //Place queen
            board[row][col] = 'Q';
            cols[col] = mainDiag[md] = antiDiag[ad] = true;  

            //Recurse fro next row
            solve(row +1, n, board, result, cols, mainDiag, antiDiag);

            //Backtrack
            board[row][col] = '#';
            cols[col] = mainDiag[md] = antiDiag[ad] = false;
        }
    }
}

int totalNQueens(int n) {
    vector<vector<string>> result;
    vector<string>board(n, string(n, '#'));
