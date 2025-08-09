class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        // Binary search for the minimum
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is greater than the rightmost, min must be to the right
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else { // Min could be at mid or to the left
                right = mid;
            }
        }

        // left == right is the index of the smallest value
        return nums[left];
    }
};
