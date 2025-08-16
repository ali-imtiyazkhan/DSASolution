class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        
        // prefix sum to sum the fruits in any segment
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }
        
        long long ans = 0;
        int j = 0;
        
        for(int i = 0; i < n; i++){
            // expand the right pointer j while the range is reachable within k steps
            while(j < n){
                long long leftPos  = fruits[i][0];
                long long rightPos = fruits[j][0];
                
                // two options: go to left first or right first
                long long leftFirst  = abs(startPos - leftPos) + (rightPos - leftPos);
                long long rightFirst = abs(startPos - rightPos) + (rightPos - leftPos);
                
                // if both costs > k, break
                if (min(leftFirst, rightFirst) > k) break;
                
                j++;
            }
            
            long long total = prefix[j] - prefix[i];
            ans = max(ans, total);
        }
        
        return (int)ans;
    }
};
