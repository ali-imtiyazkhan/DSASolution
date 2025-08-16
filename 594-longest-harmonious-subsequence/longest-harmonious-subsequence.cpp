class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        // count frequency of each number
        for(int x : nums) {
            freq[x]++;
        }

        int ans = 0;
        // look for pairs where key+1 exists
        for(auto &p : freq) {
            int num = p.first;
            if(freq.count(num+1)) {
                ans = max(ans, p.second + freq[num+1]);
            }
        }
        return ans;
    }
};
