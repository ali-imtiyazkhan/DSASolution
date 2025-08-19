class Solution {
public:
    // Helper function that returns the number of subarrays
    // with at most k distinct integers
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;                 // no valid subarrays if k < 0

        unordered_map<int,int> freq;        // keeps the frequency of each element in the current window
        int left = 0;                       // left pointer of sliding window
        int ans = 0;                        // hold total number of valid subarrays

        // iterate using the right pointer
        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;            // add current element to the window

            // if we have more than k distinct numbers, shrink window from the left
            while (freq.size() > k) {
                freq[nums[left]]--;         // decrease freq of leftmost element
                if (freq[nums[left]] == 0)  // if its freq becomes 0 remove it completely
                    freq.erase(nums[left]);
                left++;                     // move the left pointer
            }

            // after shrinking the window, all subarrays ending at 'right' are valid
            // count them by (right - left + 1)
            ans += (right - left + 1);
        }
        return ans;
    }

    // Main function: number of subarrays with exactly k distinct numbers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly K = (At Most K) - (At Most K - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
