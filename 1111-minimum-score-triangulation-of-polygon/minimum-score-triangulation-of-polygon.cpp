class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length = gap between i and j
        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 
                                   v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
