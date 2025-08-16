class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // this set will store the last k elements (sliding window)
        set<long long> st;

        for(int i = 0; i < nums.size(); i++){
            long long current = nums[i];

            // find the first value in the set which is >= current - t
            auto it = st.lower_bound(current - t);

            // if such value exists and it is <= current + t, then we found a valid pair
            if(it != st.end() && *it <= current + t) {
                return true;
            }

            // insert the current value into the set
            st.insert(current);

            // keep only k previous elements in the set (remove the (i - k)th element)
            if(i >= k){
                st.erase(nums[i - k]);
            }
        }
        // no valid pair found
        return false;
    }
};
