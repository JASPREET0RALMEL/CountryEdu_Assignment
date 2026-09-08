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

    vector<bool> cols(n, false);
    vector<bool> mainDiag(2 * n - 1, false);
    vector<bool> antiDiag(2 * n - 1, false);

    solve(0, n, board, result, cols, mainDiag, antiDiag);

    //Print Solutions
    for(int i = 0; i<result.size(); ++i) {
        cout<<"[";
        for(int r = 0; r < n; ++r) {
            cout<<"\"" << result[i][r] <<"\"" <<(r == n-1 ? "" : ", ");
        }
        cout<<"]"<<endl;
    }

    return result.size();
}

int main() {
    int n = 4;
     int count = totalNQueens(n);
     cout<<"Total Count: "<<count<<endl;
     return 0;
}