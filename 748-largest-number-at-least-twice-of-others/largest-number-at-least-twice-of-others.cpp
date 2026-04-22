class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = -1, secondMax = -1;
        int index = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;
                maxVal = nums[i];
                index = i;
            } 
            else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }

        if (maxVal >= 2 * secondMax) {
            return index;
        }

        return -1;
    }
};