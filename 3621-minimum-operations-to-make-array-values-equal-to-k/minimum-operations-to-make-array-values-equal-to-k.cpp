class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> greaterVals;
        
        for (int num : nums) {
            if (num < k) return -1;
            if (num > k) greaterVals.insert(num);
        }
        
        return greaterVals.size();
    }
};
