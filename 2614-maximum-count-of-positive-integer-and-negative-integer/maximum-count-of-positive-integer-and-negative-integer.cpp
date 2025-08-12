class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0;
        int negCount = 0;

        for (int i : nums) {
            if (i > 0) {
                posCount++;
            }
            else if (i < 0) {
                negCount++;
            }
        }

        return max(posCount, negCount);
    }
};
