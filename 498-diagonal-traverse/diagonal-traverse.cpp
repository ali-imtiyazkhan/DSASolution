class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};  // edge case: empty matrix
        
        int m = mat.size();     // number of rows
        int n = mat[0].size();  // number of columns
        vector<int> result;
        result.reserve(m * n);  // reserve space for efficiency
        
        int row = 0, col = 0;   // starting position
        bool up = true;         // direction: true = up-right (↗), false = down-left (↙)
        
        // keep going until we've collected all elements
        while (result.size() < m * n) {
            result.push_back(mat[row][col]); // add current element
            
            if (up) { // moving up-right (↗)
                if (col == n - 1) {     
                    // reached the right boundary, move down
                    row++;
                    up = false; // change direction
                } else if (row == 0) { 
                    // reached the top boundary, move right
                    col++;
                    up = false; // change direction
                } else {
                    // move diagonally up-right
                    row--;
                    col++;
                }
            } 
            else { // moving down-left (↙)
                if (row == m - 1) { 
                    // reached the bottom boundary, move right
                    col++;
                    up = true; // change direction
                } else if (col == 0) { 
                    // reached the left boundary, move down
                    row++;
                    up = true; // change direction
                } else {
                    // move diagonally down-left
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};
