class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag; // key = i - j

        // collect diagonal elements
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                diag[i - j].push_back(grid[i][j]);

        // sort each diagonal with the correct order:
        // key >= 0 -> bottom-left & main diagonal -> non-increasing (descending)
        // key <  0 -> top-right -> non-decreasing (ascending)
        for (auto &entry : diag) {
            int key = entry.first;
            auto &v = entry.second;
            if (key >= 0) sort(v.begin(), v.end(), greater<int>()); // descending
            else          sort(v.begin(), v.end());                 // ascending
        }

        // put values back (use an index map per diagonal)
        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = i - j;
                grid[i][j] = diag[k][idx[k]++];
            }
        }
        return grid;
    }
};
