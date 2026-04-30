class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0, j = n - 1;

        for (int cnt = 0; cnt < candidates && i <= j; cnt++) {
            left.push(costs[i++]);
        }

        for (int cnt = 0; cnt < candidates && i <= j; cnt++) {
            right.push(costs[j--]);
        }

        long long total = 0;

        while (k--) {
            int l = left.empty() ? INT_MAX : left.top();
            int r = right.empty() ? INT_MAX : right.top();

            if (l <= r) {
                total += l;
                left.pop();

                if (i <= j) {
                    left.push(costs[i++]);
                }
            } else {
                total += r;
                right.pop();

                if (i <= j) {
                    right.push(costs[j--]);
                }
            }
        }

        return total;
    }
};