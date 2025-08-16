class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, long long>> dq; // index, prefix_sum
        long long sum = 0;
        int shortest = INT_MAX;

        // Add prefix sum 0 at "index -1"
        dq.push_back({-1, 0});

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            // Remove from front if subarray sum >= k
            while (!dq.empty() && (sum - dq.front().second >= k)) {
                shortest = min(shortest, i - dq.front().first);
                dq.pop_front();
            }

            // Maintain monotonic increasing deque
            while (!dq.empty() && dq.back().second >= sum) {
                dq.pop_back();
            }

            // Add current prefix sum
            dq.push_back({i, sum});
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};
