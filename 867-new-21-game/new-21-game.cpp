class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If k == 0 or n >= k - 1 + maxPts, probability is 1
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0; // sum of the previous maxPts dp values
        double ans = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            // If we haven't reached k yet, we can draw more → add to window
            if (i < k) {
                windowSum += dp[i];
            } else {
                // Otherwise it's a final state → add to answer
                ans += dp[i];
            }

            // Remove the dp that falls out of the window of size maxPts
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }

        return ans;
    }
};
