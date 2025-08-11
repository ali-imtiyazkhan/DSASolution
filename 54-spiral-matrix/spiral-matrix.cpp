class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from Left → Right
            for (int col = left; col <= right; col++)
                result.push_back(matrix[top][col]);
            top++;

            // Traverse from Top → Bottom
            for (int row = top; row <= bottom; row++)
                result.push_back(matrix[row][right]);
            right--;

            // Traverse from Right → Left (if still in bounds)
            if (top <= bottom) {
                for (int col = right; col >= left; col--)
                    result.push_back(matrix[bottom][col]);
                bottom--;
            }

            // Traverse from Bottom → Top (if still in bounds)
            if (left <= right) {
                for (int row = bottom; row >= top; row--)
                    result.push_back(matrix[row][left]);
                left++;
            }
        }

        return result;
    }
};
