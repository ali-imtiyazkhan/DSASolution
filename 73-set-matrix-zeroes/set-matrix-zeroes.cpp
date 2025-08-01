class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();         // Number of rows
        int n = matrix[0].size();      // Number of columns

        // Flags to indicate if the first row and first column should be set to zero
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if there is any zero in the first row
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if there is any zero in the first column
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and first column as markers.
        // If matrix[i][j] == 0, mark matrix[i][0] and matrix[0][j] as 0.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // Mark row
                    matrix[0][j] = 0;  // Mark column
                }
            }
        }

        // Set elements to 0 based on markers in the first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // If first row had any zero, set the entire first row to 0
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // If first column had any zero, set the entire first column to 0
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
