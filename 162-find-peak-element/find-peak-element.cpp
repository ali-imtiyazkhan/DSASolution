class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // You are in the decreasing part, so peak is to the left (including mid)
                high = mid;
            } else {
                // You are in the increasing part, so peak is to the right
                low = mid + 1;
            }
        }
        return low;  // or high, both are equal
    }
};
