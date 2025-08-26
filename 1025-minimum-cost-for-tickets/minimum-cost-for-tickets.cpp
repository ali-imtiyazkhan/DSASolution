class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        if (index >= days.size()) return 0;   // base case

        if (dp[index] != -1) return dp[index];

        // Option 1: Buy 1-day pass
        int opt1 = costs[0] + solve(days, costs, index + 1, dp);

        // Option 2: Buy 7-day pass
        int i = index;
        while (i < days.size() && days[i] < days[index] + 7) {
            i++;
        }
        int opt2 = costs[1] + solve(days, costs, i, dp);

        // Option 3: Buy 30-day pass
        i = index;
        while (i < days.size() && days[i] < days[index] + 30) {
            i++;
        }
        int opt3 = costs[2] + solve(days, costs, i, dp);

        return dp[index] = min({opt1, opt2, opt3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, costs, 0, dp);
    }
};
