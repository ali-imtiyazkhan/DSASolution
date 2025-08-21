class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Map: balance -> first index where this balance was seen
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1; // base case: balance 0 at index -1

        int balance = 0; // running sum: +1 for 1, -1 for 0
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Update balance
            if (nums[i] == 1) balance += 1;
            else balance -= 1;

            // If this balance seen before, subarray sum = 0 exists
            if (firstIndex.find(balance) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[balance]);
            } else {
                // Store the first occurrence of this balance
                firstIndex[balance] = i;
            }
        }

        return maxLen;
    }
};
