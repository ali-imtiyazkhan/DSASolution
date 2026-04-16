class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            vector<int>& v = mp[nums[q]];
            
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            int m = v.size();
            
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int res = INT_MAX;
            
            int prev = v[(pos - 1 + m) % m];
            int d1 = abs(q - prev);
            res = min(res, min(d1, n - d1));
            
            int next = v[(pos + 1) % m];
            int d2 = abs(q - next);
            res = min(res, min(d2, n - d2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};