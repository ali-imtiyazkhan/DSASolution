class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Hashmap to store frequency of prefix sums
        unordered_map<int, int> freq;

        // Base case: prefix sum = 0 occurs once
        // (this allows subarrays starting from index 0 to be counted)
        freq[0] = 1;

        int prefixSum = 0; // running prefix sum
        int count = 0;     // total number of subarrays with sum = k

        for (int num : nums) {
            // update running prefix sum
            prefixSum += num;

            // Check if there is a prefixSum - k seen before
            // If yes, then subarray between that index+1 and current index has sum = k
            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k]; 
            }

            // Store/update the frequency of current prefixSum
            freq[prefixSum]++;
        }

        return count;
    }
};
