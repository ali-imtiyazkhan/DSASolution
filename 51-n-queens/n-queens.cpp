class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols, diag1, diag2;

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                res.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) continue;

                board[row][col] = 'Q';
                cols.insert(col);
                diag1.insert(row - col);
                diag2.insert(row + col);

                backtrack(row + 1);

                board[row][col] = '.';
                cols.erase(col);
                diag1.erase(row - col);
                diag2.erase(row + col);
            }
        };

        backtrack(0);
        return res;
    }
};
