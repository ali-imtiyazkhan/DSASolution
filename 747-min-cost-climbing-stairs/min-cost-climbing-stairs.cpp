class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp0 = cost[0];
        int dp1 = cost[1];
        
        for (int i = 2; i < n; i++) {
            int dpi = cost[i] + min(dp0, dp1);
            dp0 = dp1;
            dp1 = dpi;
        }
        
        // Answer: min cost to reach last step or second last step
        return min(dp0, dp1);
    }
};
