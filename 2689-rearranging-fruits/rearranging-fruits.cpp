class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        for (int fruit : basket1) freq[fruit]++;
        for (int fruit : basket2) freq[fruit]--;

        vector<int> from1, from2;

        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;
            int times = abs(count) / 2;
            if (count > 0) {
                while (times--) from1.push_back(fruit);
            } else {
                while (times--) from2.push_back(fruit);
            }
        }

        if (from1.size() != from2.size()) return -1;

        sort(from1.begin(), from1.end());
        sort(from2.rbegin(), from2.rend()); // descending

        int minFruit = *min_element(basket1.begin(), basket1.end());
        minFruit = min(minFruit, *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < from1.size(); i++) {
            cost += min((long long)min(from1[i], from2[i]), 2LL * minFruit);
        }

        return cost;
    }
};
