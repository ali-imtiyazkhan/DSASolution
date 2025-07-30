class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        queue<int> q;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                q.push(nums[i]);
            }
        }

        while (count--) {
            q.push(0);
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = q.front();
            q.pop();
        }
    }
};
