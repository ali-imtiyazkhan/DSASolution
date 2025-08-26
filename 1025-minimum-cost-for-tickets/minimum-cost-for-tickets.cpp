class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0); // dp[i] = min cost to cover travel from i-th day to end

        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Buy 1-day pass
            int opt1 = costs[0] + dp[i + 1];

            // Option 2: Buy 7-day pass
            int j = i;
            while (j < n && days[j] < days[i] + 7) j++;
            int opt2 = costs[1] + dp[j];

            // Option 3: Buy 30-day pass
            j = i;
            while (j < n && days[j] < days[i] + 30) j++;
            int opt3 = costs[2] + dp[j];

            dp[i] = min({opt1, opt2, opt3});
        }

        return dp[0]; // min cost to cover all days starting from first
    }
};
