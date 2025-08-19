class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long curr = 0;

        for(int num : nums) {
            if(num == 0) {
                curr++;
                ans += curr;
            } else {
                curr = 0;
            }
        }

        return ans;
    }
};
