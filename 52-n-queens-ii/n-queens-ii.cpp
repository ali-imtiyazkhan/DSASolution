class Solution {
public:
    int result = 0;

    bool isSafe(int row, int col, vector<string> &board, int n){
        // check in same column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }
        // upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        // upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve(int row, vector<string> &board, int n){
        if(row == n){
            result++;
            return;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(row + 1, board, n);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return result;
    }
};
