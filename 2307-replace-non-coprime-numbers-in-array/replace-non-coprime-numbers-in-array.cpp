class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> res; // use long long to avoid overflow
        
        for (int num : nums) {
            long long x = num;
            // Merge with previous numbers if not coprime
            while (!res.empty() && gcd(res.back(), x) > 1) {
                x = lcm(res.back(), x);
                res.pop_back();
            }
            res.push_back(x);
        }
        
        // Convert back to int
        return vector<int>(res.begin(), res.end());
    }
};
