class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;

        // sort by absolute value
        vector<int> keys;
        for (auto &p : freq) keys.push_back(p.first);
        sort(keys.begin(), keys.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int x : keys) {
            if (freq[x] > 0) {
                int need = freq[x];
                if (freq[2 * x] < need) return false;
                freq[2 * x] -= need;
            }
        }

        return true;
    }
};
