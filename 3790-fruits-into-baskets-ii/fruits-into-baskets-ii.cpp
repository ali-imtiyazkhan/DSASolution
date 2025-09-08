class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); // track if a basket is already used
        int ans = n; // assume all fruits are unplaced

        for (int f : fruits) {
            for (int i = 0; i < n; i++) {
                if (!used[i] && baskets[i] >= f) {
                    used[i] = true; // assign this basket
                    ans--;          // one less unplaced fruit
                    break;          // move to next fruit
                }
            }
        }
        return ans;
    }
};
