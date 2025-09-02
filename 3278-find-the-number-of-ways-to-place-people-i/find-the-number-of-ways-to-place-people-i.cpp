class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort points:
        // 1. Ascending by x
        // 2. If x is same → descending by y
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        int ans = 0;

        // Check pairs (i, j)
        for (int i = 0; i < n; i++) {
            int maxY = -1; // track maximum y encountered
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1]) {
                    // candidate rectangle (points[i], points[j])
                    if (points[j][1] > maxY) {
                        ans++;
                        maxY = points[j][1]; 
                    }
                }
            }
        }
        return ans;
    }
};
