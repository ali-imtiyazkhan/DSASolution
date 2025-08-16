class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        int n = nums.size(); 
        int i = 0; 
        int ans = 0; 
        for(int j = 0; j<n; j++){
            while(nums[j]-nums[i]>1){
                i++; 
            }
            if(nums[j]-nums[i] == 1){
                ans = max(ans,j-i+1); 
            }
        }
        return ans;
    }
};