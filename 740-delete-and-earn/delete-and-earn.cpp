class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        vector<int> points(maxVal + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        int prev2 = 0, prev1 = 0;

        for (int i = 0; i <= maxVal; i++) {
            int take = prev2 + points[i];
            int skip = prev1;

            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};