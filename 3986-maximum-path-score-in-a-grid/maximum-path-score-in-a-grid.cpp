class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        auto get = [&](int val) {
            if (val == 0) return pair<int,int>{0,0};
            if (val == 1) return pair<int,int>{1,1};
            return pair<int,int>{2,1};
        };

        auto [s, c] = get(grid[0][0]);
        if (c <= k) dp[0][0][c] = s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int cost = 0; cost <= k; cost++) {
                    if (dp[i][j][cost] == -1) continue;

                    if (j + 1 < n) {
                        auto [ns, nc] = get(grid[i][j + 1]);
                        int newCost = cost + nc;
                        if (newCost <= k) {
                            dp[i][j + 1][newCost] = max(
                                dp[i][j + 1][newCost],
                                dp[i][j][cost] + ns
                            );
                        }
                    }

                    if (i + 1 < m) {
                        auto [ns, nc] = get(grid[i + 1][j]);
                        int newCost = cost + nc;
                        if (newCost <= k) {
                            dp[i + 1][j][newCost] = max(
                                dp[i + 1][j][newCost],
                                dp[i][j][cost] + ns
                            );
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m-1][n-1][c]);
        }

        return ans;
    }
};