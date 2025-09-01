class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& obstacles, int lane, int pos) {
        if (pos == n - 1) return 0; // reached end
        if (dp[lane][pos] != -1) return dp[lane][pos];

        // If next cell in the same lane is free → move forward
        if (obstacles[pos + 1] != lane) {
            return dp[lane][pos] = solve(obstacles, lane, pos + 1);
        }

        // Otherwise, need a side jump
        int ans = INT_MAX;
        for (int newLane = 1; newLane <= 3; newLane++) {
            if (newLane != lane && obstacles[pos] != newLane) {
                ans = min(ans, 1 + solve(obstacles, newLane, pos));
            }
        }
        return dp[lane][pos] = ans;
    }

    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        dp.assign(4, vector<int>(n, -1));
        return solve(obstacles, 2, 0); // start from lane 2, pos 0
    }
};
