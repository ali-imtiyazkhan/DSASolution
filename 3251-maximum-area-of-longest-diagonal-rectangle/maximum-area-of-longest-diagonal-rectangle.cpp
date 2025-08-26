class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0, maxArea = 0;
        
        for (auto &d : dimensions) {
            int w = d[0], h = d[1];
            int diag = w * w + h * h;   // diagonal^2
            int area = w * h;
            
            if (diag > maxDiag || (diag == maxDiag && area > maxArea)) {
                maxDiag = diag;
                maxArea = area;
            }
        }
        return maxArea;
    }
};
