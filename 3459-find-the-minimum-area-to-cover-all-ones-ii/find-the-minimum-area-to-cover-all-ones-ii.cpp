#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = m * n; // upper bound

        // Case A: choose a top band [0..i], then split the remainder into left/right
        for (int i = 0; i < m; ++i) {
            int top = minimumArea(grid, 0, i, 0, n - 1);
            for (int j = 0; j < n; ++j) {
                ans = min(ans,
                          top
                          + minimumArea(grid, i + 1, m - 1, 0, j)         // bottom-left
                          + minimumArea(grid, i + 1, m - 1, j + 1, n - 1)  // bottom-right
                );
            }
        }

        // Case B: choose a bottom band [i..m-1], split the top into left/right
        for (int i = 0; i < m; ++i) {
            int bottom = minimumArea(grid, i, m - 1, 0, n - 1);
            for (int j = 0; j < n; ++j) {
                ans = min(ans,
                          bottom
                          + minimumArea(grid, 0, i - 1, 0, j)            // top-left
                          + minimumArea(grid, 0, i - 1, j + 1, n - 1)     // top-right
                );
            }
        }

        // Case C: choose a left band [0..j], then split the remainder into top/bottom
        for (int j = 0; j < n; ++j) {
            int left = minimumArea(grid, 0, m - 1, 0, j);
            for (int i = 0; i < m; ++i) {
                ans = min(ans,
                          left
                          + minimumArea(grid, 0, i, j + 1, n - 1)       // top-right
                          + minimumArea(grid, i + 1, m - 1, j + 1, n - 1)// bottom-right
                );
            }
        }

        // Case D: choose a right band [j..n-1], split the left into top/bottom
        for (int j = 0; j < n; ++j) {
            int right = minimumArea(grid, 0, m - 1, j, n - 1);
            for (int i = 0; i < m; ++i) {
                ans = min(ans,
                          right
                          + minimumArea(grid, 0, i, 0, j - 1)           // top-left
                          + minimumArea(grid, i + 1, m - 1, 0, j - 1)    // bottom-left
                );
            }
        }

        // Case E: three horizontal slices (two row cuts i1 < i2)
        for (int i1 = 0; i1 < m; ++i1)
            for (int i2 = i1 + 1; i2 < m; ++i2)
                ans = min(ans,
                          minimumArea(grid, 0, i1, 0, n - 1) +
                          minimumArea(grid, i1 + 1, i2, 0, n - 1) +
                          minimumArea(grid, i2 + 1, m - 1, 0, n - 1));

        // Case F: three vertical slices (two column cuts j1 < j2)
        for (int j1 = 0; j1 < n; ++j1)
            for (int j2 = j1 + 1; j2 < n; ++j2)
                ans = min(ans,
                          minimumArea(grid, 0, m - 1, 0, j1) +
                          minimumArea(grid, 0, m - 1, j1 + 1, j2) +
                          minimumArea(grid, 0, m - 1, j2 + 1, n - 1));

        return ans;
    }

private:
    // Bounding-box area of 1s in [si..ei] x [sj..ej]; 0 if no 1s.
    int minimumArea(const vector<vector<int>>& g, int si, int ei, int sj, int ej) {
        if (si > ei || sj > ej) return 0;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
        for (int i = si; i <= ei; ++i)
            for (int j = sj; j <= ej; ++j)
                if (g[i][j] == 1) {
                    x1 = min(x1, i); y1 = min(y1, j);
                    x2 = max(x2, i); y2 = max(y2, j);
                }
        if (x1 == INT_MAX) return 0; // no ones here
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};
