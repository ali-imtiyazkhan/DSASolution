class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int n = 0; n < numRows; ++n) {
            vector<int> row;
            long long val = 1;

            for (int r = 0; r <= n; ++r) {
                row.push_back((int)val);
                val = val * (n - r) / (r + 1);  // Efficient nCr update
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};
