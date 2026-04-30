class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        sort(v.rbegin(), v.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;

        for (auto& [n2, n1] : v) {
            pq.push(n1);
            sum += n1;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * n2);
            }
        }

        return ans;
    }
};