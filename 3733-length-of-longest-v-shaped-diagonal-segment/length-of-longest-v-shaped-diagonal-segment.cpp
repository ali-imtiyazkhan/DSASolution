class Solution {
public:
    int m, n;
    vector<vector<int>> grid;

    // Directions: ↘, ↗, ↙, ↖
    vector<pair<int,int>> dirs = {{1,1}, {-1,1}, {1,-1}, {-1,-1}};

    // Function to get next expected digit in sequence 1 -> 2 -> 0 -> 2 -> ...
    int nextDigit(int val) {
        if (val == 1) return 2;
        if (val == 2) return 0;
        return 2; // if 0 then next must be 2
    }

    // DFS to explore path
    int dfs(int i, int j, int di, int dj, bool turned) {
        int length = 1;
        int expected = nextDigit(grid[i][j]);

        // continue in same direction
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == expected) {
            length = max(length, 1 + dfs(ni, nj, di, dj, turned));
        }

        // try turning once (clockwise 90°)
        if (!turned) {
            int tdi = dj, tdj = -di; // rotate
            int ti = i + tdi, tj = j + tdj;
            if (ti >= 0 && ti < m && tj >= 0 && tj < n && grid[ti][tj] == expected) {
                length = max(length, 1 + dfs(ti, tj, tdi, tdj, true));
            }
        }
        return length;
    }

    int lenOfVDiagonal(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        // Start from each '1'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (auto [di, dj] : dirs) {
                        ans = max(ans, dfs(i, j, di, dj, false));
                    }
                }
            }
        }
        return ans;
    }
};
