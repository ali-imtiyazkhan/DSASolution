#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // tails[i] = min possible tail for LIS length i+1
        for (int num : nums) {
            // find first position >= num
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num); // num is bigger than all tails
            } else {
                *it = num; // replace to maintain minimal tail
            }
        }
        return tails.size();
    }
};
