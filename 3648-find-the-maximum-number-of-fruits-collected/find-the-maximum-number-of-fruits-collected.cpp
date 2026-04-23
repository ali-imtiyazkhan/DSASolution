class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        const int NEG = -1e9;

        // Child 1: fixed along main diagonal
        int diag = 0;
        for (int i = 0; i < n; i++) diag += fruits[i][i];

        // Child 2: from (0,n-1), moves (i+1,j-1),(i+1,j),(i+1,j+1)
        // Valid region: strictly ABOVE main diagonal (j > i), plus destination
        vector<vector<int>> dp2(n, vector<int>(n, NEG));
        dp2[0][n-1] = fruits[0][n-1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool isDestination = (i == n-1 && j == n-1);
                if (j <= i && !isDestination) continue; // must be strictly above diagonal
                for (int dj : {-1, 0, 1}) {
                    int pj = j - dj;
                    if (pj < 0 || pj >= n || dp2[i-1][pj] == NEG) continue;
                    dp2[i][j] = max(dp2[i][j], dp2[i-1][pj] + fruits[i][j]);
                }
            }
        }

        // Child 3: from (n-1,0), moves (i-1,j+1),(i,j+1),(i+1,j+1)
        // Valid region: strictly BELOW main diagonal (i > j), plus destination
        vector<vector<int>> dp3(n, vector<int>(n, NEG));
        dp3[n-1][0] = fruits[n-1][0];
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n; i++) {
                bool isDestination = (i == n-1 && j == n-1);
                if (i <= j && !isDestination) continue; // must be strictly below diagonal
                for (int di : {-1, 0, 1}) {
                    int pi = i - di;
                    if (pi < 0 || pi >= n || dp3[pi][j-1] == NEG) continue;
                    dp3[i][j] = max(dp3[i][j], dp3[pi][j-1] + fruits[i][j]);
                }
            }
        }

        // dp2 and dp3 both include fruits[n-1][n-1]; diag also includes it → subtract 2×
        return diag + dp2[n-1][n-1] + dp3[n-1][n-1] - 2 * fruits[n-1][n-1];
    }
};