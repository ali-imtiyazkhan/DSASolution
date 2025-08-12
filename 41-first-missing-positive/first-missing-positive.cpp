class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int smallest = 1;
        while (true) {
            if (s.find(smallest) == s.end()) {
                return smallest;
            }
            smallest++;
        }
    }
};
