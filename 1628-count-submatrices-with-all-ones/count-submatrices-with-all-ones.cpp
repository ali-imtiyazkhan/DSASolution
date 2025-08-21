class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            // update histogram heights
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j] += 1;
            }

            // count submatrices ending at row i
            for (int j = 0; j < n; j++) {
                int minHeight = heights[j];
                for (int k = j; k >= 0 && minHeight > 0; k--) {
                    minHeight = min(minHeight, heights[k]);
                    ans += minHeight;
                }
            }
        }

        return ans;
    }
};
